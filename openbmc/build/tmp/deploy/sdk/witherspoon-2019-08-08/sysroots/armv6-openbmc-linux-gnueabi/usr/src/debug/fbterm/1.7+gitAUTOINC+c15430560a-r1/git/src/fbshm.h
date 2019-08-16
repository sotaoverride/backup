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

#ifndef FBSHM_H
#define FBSHM_H

#include "screen.h"

class FbShm : public Screen
{
  private:
    friend class Screen;
    static FbShm* initFbShm();
    static int parse_shm_desc(const char* desc, char** file, int* rows,
                              int* cols, int* bpp);
    int mFD;

    FbShm(int fd, int rows, int cols, int bpp);
    ~FbShm();

    virtual const s8* drvId();
};
#endif
