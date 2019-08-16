/* Copyright (C) 1991-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* This file defines one of the deprecated scanf variants.  */
#include <features.h>
#undef __GLIBC_USE_DEPRECATED_SCANF
#define __GLIBC_USE_DEPRECATED_SCANF 1

#include <libioP.h>
#include <stdarg.h>
#include <stdio.h>

/* Read formatted input from stdin according to the format string FORMAT.  */
/* VARARGS1 */
int __scanf(const char* format, ...)
{
    va_list arg;
    int done;

    va_start(arg, format);
    done = __vfscanf_internal(stdin, format, arg, 0);
    va_end(arg);

    return done;
}
ldbl_strong_alias(__scanf, scanf)
