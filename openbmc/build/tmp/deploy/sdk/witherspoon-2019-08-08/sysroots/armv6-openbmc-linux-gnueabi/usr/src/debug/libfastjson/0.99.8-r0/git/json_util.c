/*
 * Copyright (c) 2004, 2005 Metaparadigm Pte. Ltd.
 * Michael Clark <michael@metaparadigm.com>
 * Copyright (c) 2016 Adiscon GmbH
 * Rainer Gerhards <rgerhards@adiscon.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See COPYING for details.
 *
 */

#include "config.h"
#undef realloc

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif /* HAVE_SYS_TYPES_H */

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif /* HAVE_SYS_STAT_H */

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif /* HAVE_FCNTL_H */

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#if !defined(HAVE_SNPRINTF)
#error You do not have snprintf on your system.
#endif /* HAVE_SNPRINTF */

#include "debug.h"
#include "json_object.h"
#include "json_tokener.h"
#include "json_util.h"
#include "printbuf.h"

static int sscanf_is_broken = 0;
static int sscanf_is_broken_testdone = 0;
static void sscanf_is_broken_test(void);

/*
 * Create a JSON object from already opened file descriptor.
 *
 * This function can be helpful, when you opened the file already,
 * e.g. when you have a temp file.
 * Note, that the fd must be readable at the actual position, i.e.
 * use lseek(fd, 0, SEEK_SET) before.
 */
struct fjson_object* fjson_object_from_fd(int fd)
{
    struct printbuf* pb;
    struct fjson_object* obj;
    char buf[FJSON_FILE_BUF_SIZE];
    int ret;

    if (!(pb = printbuf_new()))
    {
        MC_ERROR("fjson_object_from_file: printbuf_new failed\n");
        return NULL;
    }
    while ((ret = read(fd, buf, FJSON_FILE_BUF_SIZE)) > 0)
    {
        printbuf_memappend(pb, buf, ret);
    }
    if (ret < 0)
    {
        MC_ERROR("fjson_object_from_fd: error reading fd %d: %s\n", fd,
                 strerror(errno));
        printbuf_free(pb);
        return NULL;
    }
    obj = fjson_tokener_parse(pb->buf);
    printbuf_free(pb);
    return obj;
}

struct fjson_object* fjson_object_from_file(const char* filename)
{
    struct fjson_object* obj;
    int fd;

    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        MC_ERROR("fjson_object_from_file: error opening file %s: %s\n",
                 filename, strerror(errno));
        return NULL;
    }
    obj = fjson_object_from_fd(fd);
    close(fd);
    return obj;
}

/* extended "format and write to file" function */

int fjson_object_to_file_ext(const char* filename, struct fjson_object* obj,
                             int flags)
{
    const char* fjson_str;
    int fd, ret;
    unsigned int wpos, wsize;

    if (!obj)
    {
        MC_ERROR("fjson_object_to_file: object is null\n");
        return -1;
    }

    if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0)
    {
        MC_ERROR("fjson_object_to_file: error opening file %s: %s\n", filename,
                 strerror(errno));
        return -1;
    }

    if (!(fjson_str = fjson_object_to_json_string_ext(obj, flags)))
    {
        close(fd);
        return -1;
    }

    wsize = (unsigned int)(strlen(fjson_str) &
                           UINT_MAX); /* CAW: probably unnecessary, but the most
                                         64bit safe */
    wpos = 0;
    while (wpos < wsize)
    {
        if ((ret = write(fd, fjson_str + wpos, wsize - wpos)) < 0)
        {
            close(fd);
            MC_ERROR("fjson_object_to_file: error writing file %s: %s\n",
                     filename, strerror(errno));
            return -1;
        }

        /* because of the above check for ret < 0, we can safely cast and add */
        wpos += (unsigned int)ret;
    }

    close(fd);
    return 0;
}

// backwards compatible "format and write to file" function

int fjson_object_to_file(const char* filename, struct fjson_object* obj)
{
    return fjson_object_to_file_ext(filename, obj, FJSON_TO_STRING_PLAIN);
}

int fjson_parse_double(const char* buf, double* retval)
{
    return (sscanf(buf, "%lf", retval) == 1 ? 0 : 1);
}

/*
 * Not all implementations of sscanf actually work properly.
 * Check whether the one we're currently using does, and if
 * it's broken, enable the workaround code.
 */
static void sscanf_is_broken_test(void)
{
    int64_t num64;
    int ret_errno, is_int64_min, ret_errno2, is_int64_max;

    (void)sscanf(" -01234567890123456789012345", "%" SCNd64, &num64);
    ret_errno = errno;
    is_int64_min = (num64 == INT64_MIN);

    (void)sscanf(" 01234567890123456789012345", "%" SCNd64, &num64);
    ret_errno2 = errno;
    is_int64_max = (num64 == INT64_MAX);

    if (ret_errno != ERANGE || !is_int64_min || ret_errno2 != ERANGE ||
        !is_int64_max)
    {
        MC_DEBUG("sscanf_is_broken_test failed, enabling workaround code\n");
        sscanf_is_broken = 1;
    }
}

int fjson_parse_int64(const char* buf, int64_t* retval)
{
    int64_t num64;
    const char* buf_sig_digits;
    int orig_has_neg;
    int saved_errno;

    if (!sscanf_is_broken_testdone)
    {
        sscanf_is_broken_test();
        sscanf_is_broken_testdone = 1;
    }

    // Skip leading spaces
    while (isspace((int)*buf) && *buf)
        buf++;

    errno = 0; // sscanf won't always set errno, so initialize
    if (sscanf(buf, "%" SCNd64, &num64) != 1)
    {
        MC_DEBUG("Failed to parse, sscanf != 1\n");
        return 1;
    }

    saved_errno = errno;
    buf_sig_digits = buf;
    orig_has_neg = 0;
    if (*buf_sig_digits == '-')
    {
        buf_sig_digits++;
        orig_has_neg = 1;
    }

    // Not all sscanf implementations actually work
    if (sscanf_is_broken && saved_errno != ERANGE)
    {
        char buf_cmp[100];
        char* buf_cmp_start = buf_cmp;
        int recheck_has_neg = 0;
        int buf_cmp_len;

        // Skip leading zeros, but keep at least one digit
        while (buf_sig_digits[0] == '0' && buf_sig_digits[1] != '\0')
            buf_sig_digits++;
        if (num64 == 0)       // assume all sscanf impl's will parse -0 to 0
            orig_has_neg = 0; // "-0" is the same as just plain "0"

        snprintf(buf_cmp_start, sizeof(buf_cmp), "%" PRId64, num64);
        if (*buf_cmp_start == '-')
        {
            recheck_has_neg = 1;
            buf_cmp_start++;
        }
        // No need to skip leading spaces or zeros here.

        buf_cmp_len = strlen(buf_cmp_start);
        /**
         * If the sign is different, or
         * some of the digits are different, or
         * there is another digit present in the original string
         * then we have NOT successfully parsed the value.
         */
        if (orig_has_neg != recheck_has_neg ||
            strncmp(buf_sig_digits, buf_cmp_start, strlen(buf_cmp_start)) !=
                0 ||
            ((int)strlen(buf_sig_digits) != buf_cmp_len &&
             isdigit((int)buf_sig_digits[buf_cmp_len])))
        {
            saved_errno = ERANGE;
        }
    }

    // Not all sscanf impl's set the value properly when out of range.
    // Always do this, even for properly functioning implementations,
    // since it shouldn't slow things down much.
    if (saved_errno == ERANGE)
    {
        if (orig_has_neg)
            num64 = INT64_MIN;
        else
            num64 = INT64_MAX;
    }
    *retval = num64;
    return 0;
}

#define NELEM(a) (sizeof(a) / sizeof(a[0]))
static const char* fjson_type_name[] = {
    /* If you change this, be sure to update the enum fjson_type definition too
     */
    "null", "boolean", "double", "int", "object", "array", "string",
};

const char* fjson_type_to_name(enum fjson_type o_type)
{
    int o_type_int = (int)o_type;
    if (o_type_int < 0 || o_type_int >= (int)NELEM(fjson_type_name))
    {
        MC_ERROR("fjson_type_to_name: type %d is out of range [0,%zu]\n",
                 o_type, NELEM(fjson_type_name));
        return NULL;
    }
    return fjson_type_name[o_type];
}
