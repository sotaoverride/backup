/* Read or write system information.  Linux version.
   Copyright (C) 1996-2019 Free Software Foundation, Inc.
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

#include <errno.h>
#include <string.h> /* For the real memset prototype.  */
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <sysdep.h>

int __sysctl(int* name, int nlen, void* oldval, size_t* oldlenp, void* newval,
             size_t newlen)
{
    struct __sysctl_args args = {.name = name,
                                 .nlen = nlen,
                                 .oldval = oldval,
                                 .oldlenp = oldlenp,
                                 .newval = newval,
                                 .newlen = newlen};

    return INLINE_SYSCALL(_sysctl, 1, &args);
}
libc_hidden_def(__sysctl) weak_alias(__sysctl, sysctl)