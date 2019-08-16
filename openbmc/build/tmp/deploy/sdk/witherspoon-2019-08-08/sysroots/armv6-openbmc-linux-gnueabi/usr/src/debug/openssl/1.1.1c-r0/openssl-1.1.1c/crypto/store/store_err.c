/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/err.h>
#include <openssl/storeerr.h>

#ifndef OPENSSL_NO_ERR

static const ERR_STRING_DATA OSSL_STORE_str_functs[] = {
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_CTRL, 0), "file_ctrl"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_FIND, 0), "file_find"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_GET_PASS, 0),
     "file_get_pass"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_LOAD, 0), "file_load"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_LOAD_TRY_DECODE, 0),
     "file_load_try_decode"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_NAME_TO_URI, 0),
     "file_name_to_uri"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_FILE_OPEN, 0), "file_open"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_ATTACH_PEM_BIO, 0),
     "ossl_store_attach_pem_bio"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_EXPECT, 0),
     "OSSL_STORE_expect"},
    {ERR_PACK(ERR_LIB_OSSL_STORE,
              OSSL_STORE_F_OSSL_STORE_FILE_ATTACH_PEM_BIO_INT, 0),
     "ossl_store_file_attach_pem_bio_int"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_FIND, 0),
     "OSSL_STORE_find"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_GET0_LOADER_INT, 0),
     "ossl_store_get0_loader_int"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_GET1_CERT, 0),
     "OSSL_STORE_INFO_get1_CERT"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_GET1_CRL, 0),
     "OSSL_STORE_INFO_get1_CRL"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_GET1_NAME, 0),
     "OSSL_STORE_INFO_get1_NAME"},
    {ERR_PACK(ERR_LIB_OSSL_STORE,
              OSSL_STORE_F_OSSL_STORE_INFO_GET1_NAME_DESCRIPTION, 0),
     "OSSL_STORE_INFO_get1_NAME_description"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_GET1_PARAMS, 0),
     "OSSL_STORE_INFO_get1_PARAMS"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_GET1_PKEY, 0),
     "OSSL_STORE_INFO_get1_PKEY"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_CERT, 0),
     "OSSL_STORE_INFO_new_CERT"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_CRL, 0),
     "OSSL_STORE_INFO_new_CRL"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_EMBEDDED, 0),
     "ossl_store_info_new_EMBEDDED"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_NAME, 0),
     "OSSL_STORE_INFO_new_NAME"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_PARAMS, 0),
     "OSSL_STORE_INFO_new_PARAMS"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INFO_NEW_PKEY, 0),
     "OSSL_STORE_INFO_new_PKEY"},
    {ERR_PACK(ERR_LIB_OSSL_STORE,
              OSSL_STORE_F_OSSL_STORE_INFO_SET0_NAME_DESCRIPTION, 0),
     "OSSL_STORE_INFO_set0_NAME_description"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_INIT_ONCE, 0),
     "ossl_store_init_once"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_LOADER_NEW, 0),
     "OSSL_STORE_LOADER_new"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_OPEN, 0),
     "OSSL_STORE_open"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_OPEN_INT, 0), ""},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_REGISTER_LOADER_INT,
              0),
     "ossl_store_register_loader_int"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_SEARCH_BY_ALIAS, 0),
     "OSSL_STORE_SEARCH_by_alias"},
    {ERR_PACK(ERR_LIB_OSSL_STORE,
              OSSL_STORE_F_OSSL_STORE_SEARCH_BY_ISSUER_SERIAL, 0),
     "OSSL_STORE_SEARCH_by_issuer_serial"},
    {ERR_PACK(ERR_LIB_OSSL_STORE,
              OSSL_STORE_F_OSSL_STORE_SEARCH_BY_KEY_FINGERPRINT, 0),
     "OSSL_STORE_SEARCH_by_key_fingerprint"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_SEARCH_BY_NAME, 0),
     "OSSL_STORE_SEARCH_by_name"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_OSSL_STORE_UNREGISTER_LOADER_INT,
              0),
     "ossl_store_unregister_loader_int"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_TRY_DECODE_PARAMS, 0),
     "try_decode_params"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_TRY_DECODE_PKCS12, 0),
     "try_decode_PKCS12"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, OSSL_STORE_F_TRY_DECODE_PKCS8ENCRYPTED, 0),
     "try_decode_PKCS8Encrypted"},
    {0, NULL}};

static const ERR_STRING_DATA OSSL_STORE_str_reasons[] = {
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_AMBIGUOUS_CONTENT_TYPE),
     "ambiguous content type"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_BAD_PASSWORD_READ),
     "bad password read"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_ERROR_VERIFYING_PKCS12_MAC),
     "error verifying pkcs12 mac"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0,
              OSSL_STORE_R_FINGERPRINT_SIZE_DOES_NOT_MATCH_DIGEST),
     "fingerprint size does not match digest"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_INVALID_SCHEME),
     "invalid scheme"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_IS_NOT_A), "is not a"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_LOADER_INCOMPLETE),
     "loader incomplete"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_LOADING_STARTED),
     "loading started"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_NOT_A_CERTIFICATE),
     "not a certificate"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_NOT_A_CRL), "not a crl"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_NOT_A_KEY), "not a key"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_NOT_A_NAME), "not a name"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_NOT_PARAMETERS),
     "not parameters"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_PASSPHRASE_CALLBACK_ERROR),
     "passphrase callback error"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_PATH_MUST_BE_ABSOLUTE),
     "path must be absolute"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0,
              OSSL_STORE_R_SEARCH_ONLY_SUPPORTED_FOR_DIRECTORIES),
     "search only supported for directories"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0,
              OSSL_STORE_R_UI_PROCESS_INTERRUPTED_OR_CANCELLED),
     "ui process interrupted or cancelled"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_UNREGISTERED_SCHEME),
     "unregistered scheme"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_UNSUPPORTED_CONTENT_TYPE),
     "unsupported content type"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_UNSUPPORTED_OPERATION),
     "unsupported operation"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_UNSUPPORTED_SEARCH_TYPE),
     "unsupported search type"},
    {ERR_PACK(ERR_LIB_OSSL_STORE, 0, OSSL_STORE_R_URI_AUTHORITY_UNSUPPORTED),
     "uri authority unsupported"},
    {0, NULL}};

#endif

int ERR_load_OSSL_STORE_strings(void)
{
#ifndef OPENSSL_NO_ERR
    if (ERR_func_error_string(OSSL_STORE_str_functs[0].error) == NULL)
    {
        ERR_load_strings_const(OSSL_STORE_str_functs);
        ERR_load_strings_const(OSSL_STORE_str_reasons);
    }
#endif
    return 1;
}
