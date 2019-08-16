/* Copyright (C) 1995-2019 Free Software Foundation, Inc.
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

#include <wchar.h>

#ifdef WCSCHRNUL
#define __wcschrnul WCSCHRNUL
#endif

/* Find the first occurrence of WC in WCS.  */
wchar_t* __wcschrnul(const wchar_t* wcs, const wchar_t wc)
{
    while (*wcs != L'\0')
        if (*wcs == wc)
            break;
        else
            ++wcs;

    return (wchar_t*)wcs;
}
#ifndef WCSCHRNUL
weak_alias(__wcschrnul, wcschrnul)
#endif
