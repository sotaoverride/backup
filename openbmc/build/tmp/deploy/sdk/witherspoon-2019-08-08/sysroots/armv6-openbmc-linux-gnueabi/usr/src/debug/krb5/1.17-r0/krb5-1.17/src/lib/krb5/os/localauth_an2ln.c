/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* lib/krb5/os/localauth_an2ln.c - an2ln localauth module */
/*
 * Copyright (C) 2013 by the Massachusetts Institute of Technology.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <krb5/localauth_plugin.h>

#include "k5-int.h"
#include "os-proto.h"

#define MAX_USERNAME 65

static krb5_error_code an2ln_userok(krb5_context context,
                                    krb5_localauth_moddata data,
                                    krb5_const_principal aname,
                                    const char* lname)
{
    krb5_error_code ret;
    char kuser[MAX_USERNAME];

    ret = krb5_aname_to_localname(context, aname, sizeof(kuser), kuser);
    return (ret == 0 && strcmp(kuser, lname) == 0) ? 0 : KRB5_PLUGIN_NO_HANDLE;
}

krb5_error_code localauth_an2ln_initvt(krb5_context context, int maj_ver,
                                       int min_ver, krb5_plugin_vtable vtable)
{
    krb5_localauth_vtable vt = (krb5_localauth_vtable)vtable;

    vt->name = "an2ln";
    vt->userok = an2ln_userok;
    return 0;
}
