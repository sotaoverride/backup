/*
 *   Copyright © 2018 IBM Corporation
 *   This file is part of FbTerm.
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include "fbshm.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "fbconfig.h"

int FbShm::parse_shm_desc(const char* desc, char** file, int* rows, int* cols,
                          int* bpp)
{
    char *str, *sep, *endp;
    unsigned long tmp;

    str = strdup(desc);

    /* <file>:<cols>x<rows>@<bpp> */

    /* file */
    sep = strchr(str, ':');
    if (!sep)
        goto err_free;

    *file = str;
    *sep = '\0';

    /* cols */
    str = sep + 1;
    sep = strchr(str, 'x');
    if (!sep)
    {
        fprintf(stderr, "can't parse shm descriptor %s: no geom\n", desc);
        goto err_free;
    }
    *sep = '\0';

    tmp = strtoul(str, &endp, 10);
    if (endp != sep)
    {
        fprintf(stderr, "can't parse shm descriptor %s: invalid cols %s\n",
                desc, str);
        goto err_free;
    }

    *cols = (int)(tmp & 0xffffffff);

    /* rows */
    str = sep + 1;
    sep = strchr(str, '@');
    if (!sep)
    {
        fprintf(stderr, "can't parse shm descriptor %s: no geom\n", desc);
        goto err_free;
    }
    *sep = '\0';

    tmp = strtoul(str, &endp, 10);
    if (endp != sep)
    {
        fprintf(stderr, "can't parse shm descriptor %s: invalid rows %s\n",
                desc, str);
        goto err_free;
    }

    *rows = (int)(tmp & 0xffffffff);

    /* bpp */
    tmp = strtoul(sep + 1, &endp, 10);
    if (*endp != '\0' || endp == str)
    {
        fprintf(stderr, "can't parse shm descriptor %s: invalid bpp\n", desc);
        goto err_free;
    }

    *bpp = (int)(tmp & 0xff);

    printf("%s: rows %d, cols %d, bpp %d\n", *file, *rows, *cols, *bpp);

    return 0;

err_free:
    free(str);
    return -1;
}

FbShm* FbShm::initFbShm()
{
    int rows, cols, bpp;
    s8 *file, desc[4096];
    int fd;

    Config::instance()->getOption("shared-mem", desc, sizeof(desc));

    if (!strlen(desc))
        return 0;

    if (parse_shm_desc(desc, &file, &rows, &cols, &bpp))
        return 0;

    fd = open(file, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "can't open frame buffer shm %s: %m\n", file);
        free(file);
        return 0;
    }

    free(file);

    return new FbShm(fd, rows, cols, bpp);
}

FbShm::FbShm(int fd, int rows, int cols, int bpp)
{
    mWidth = cols;
    mHeight = rows;
    mBitsPerPixel = bpp;
    mBytesPerLine = cols * (bpp >> 3);
    mFD = fd;

    mVMemBase = (u8*)mmap(0, mHeight * mBytesPerLine, PROT_READ | PROT_WRITE,
                          MAP_SHARED, fd, 0);
}

FbShm::~FbShm()
{
    munmap(mVMemBase, mHeight * mBytesPerLine);
    close(mFD);
}

const s8* FbShm::drvId()
{
    return "shm";
}
