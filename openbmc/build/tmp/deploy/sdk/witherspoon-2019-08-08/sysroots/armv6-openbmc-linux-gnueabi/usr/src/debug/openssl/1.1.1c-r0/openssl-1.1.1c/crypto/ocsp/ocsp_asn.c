/*
 * Copyright 2000-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/ocsp.h>

#include "ocsp_lcl.h"

ASN1_SEQUENCE(OCSP_SIGNATURE) = {ASN1_EMBED(OCSP_SIGNATURE, signatureAlgorithm,
                                            X509_ALGOR),
                                 ASN1_SIMPLE(OCSP_SIGNATURE, signature,
                                             ASN1_BIT_STRING),
                                 ASN1_EXP_SEQUENCE_OF_OPT(
                                     OCSP_SIGNATURE, certs, X509,
                                     0)} ASN1_SEQUENCE_END(OCSP_SIGNATURE)

    IMPLEMENT_ASN1_FUNCTIONS(OCSP_SIGNATURE)

        ASN1_SEQUENCE(
            OCSP_CERTID) = {ASN1_EMBED(OCSP_CERTID, hashAlgorithm, X509_ALGOR),
                            ASN1_EMBED(OCSP_CERTID, issuerNameHash,
                                       ASN1_OCTET_STRING),
                            ASN1_EMBED(OCSP_CERTID, issuerKeyHash,
                                       ASN1_OCTET_STRING),
                            ASN1_EMBED(
                                OCSP_CERTID, serialNumber,
                                ASN1_INTEGER)} ASN1_SEQUENCE_END(OCSP_CERTID)

            IMPLEMENT_ASN1_FUNCTIONS(OCSP_CERTID)

                ASN1_SEQUENCE(
                    OCSP_ONEREQ) = {ASN1_SIMPLE(OCSP_ONEREQ, reqCert,
                                                OCSP_CERTID),
                                    ASN1_EXP_SEQUENCE_OF_OPT(
                                        OCSP_ONEREQ, singleRequestExtensions,
                                        X509_EXTENSION,
                                        0)} ASN1_SEQUENCE_END(OCSP_ONEREQ)

                    IMPLEMENT_ASN1_FUNCTIONS(OCSP_ONEREQ)

                        ASN1_SEQUENCE(OCSP_REQINFO) =
                            {ASN1_EXP_OPT(OCSP_REQINFO, version, ASN1_INTEGER,
                                          0),
                             ASN1_EXP_OPT(OCSP_REQINFO, requestorName,
                                          GENERAL_NAME, 1),
                             ASN1_SEQUENCE_OF(OCSP_REQINFO, requestList,
                                              OCSP_ONEREQ),
                             ASN1_EXP_SEQUENCE_OF_OPT(
                                 OCSP_REQINFO, requestExtensions,
                                 X509_EXTENSION,
                                 2)} ASN1_SEQUENCE_END(OCSP_REQINFO)

                                IMPLEMENT_ASN1_FUNCTIONS(OCSP_REQINFO)

                                    ASN1_SEQUENCE(OCSP_REQUEST) =
                                        {ASN1_EMBED(OCSP_REQUEST, tbsRequest,
                                                    OCSP_REQINFO),
                                         ASN1_EXP_OPT(
                                             OCSP_REQUEST, optionalSignature,
                                             OCSP_SIGNATURE,
                                             0)} ASN1_SEQUENCE_END(OCSP_REQUEST)

                                            IMPLEMENT_ASN1_FUNCTIONS(
                                                OCSP_REQUEST)

    /* OCSP_RESPONSE templates */

    ASN1_SEQUENCE(
        OCSP_RESPBYTES) = {ASN1_SIMPLE(OCSP_RESPBYTES, responseType,
                                       ASN1_OBJECT),
                           ASN1_SIMPLE(
                               OCSP_RESPBYTES, response,
                               ASN1_OCTET_STRING)} ASN1_SEQUENCE_END(OCSP_RESPBYTES)

        IMPLEMENT_ASN1_FUNCTIONS(OCSP_RESPBYTES)

            ASN1_SEQUENCE(
                OCSP_RESPONSE) = {ASN1_SIMPLE(OCSP_RESPONSE, responseStatus,
                                              ASN1_ENUMERATED),
                                  ASN1_EXP_OPT(
                                      OCSP_RESPONSE, responseBytes,
                                      OCSP_RESPBYTES,
                                      0)} ASN1_SEQUENCE_END(OCSP_RESPONSE)

                IMPLEMENT_ASN1_FUNCTIONS(OCSP_RESPONSE)

                    ASN1_CHOICE(
                        OCSP_RESPID) = {ASN1_EXP(OCSP_RESPID, value.byName,
                                                 X509_NAME, 1),
                                        ASN1_EXP(
                                            OCSP_RESPID, value.byKey,
                                            ASN1_OCTET_STRING,
                                            2)} ASN1_CHOICE_END(OCSP_RESPID)

                        IMPLEMENT_ASN1_FUNCTIONS(OCSP_RESPID)

                            ASN1_SEQUENCE(
                                OCSP_REVOKEDINFO) = {ASN1_SIMPLE(OCSP_REVOKEDINFO,
                                                                 revocationTime, ASN1_GENERALIZEDTIME),
                                                     ASN1_EXP_OPT(
                                                         OCSP_REVOKEDINFO, revocationReason, ASN1_ENUMERATED, 0)} ASN1_SEQUENCE_END(OCSP_REVOKEDINFO)

                                IMPLEMENT_ASN1_FUNCTIONS(OCSP_REVOKEDINFO)

                                    ASN1_CHOICE(OCSP_CERTSTATUS) =
                                        {ASN1_IMP(OCSP_CERTSTATUS, value.good,
                                                  ASN1_NULL,
                                                  0),
                                         ASN1_IMP(OCSP_CERTSTATUS,
                                                  value.revoked,
                                                  OCSP_REVOKEDINFO, 1),
                                         ASN1_IMP(
                                             OCSP_CERTSTATUS,
                                             value.unknown,
                                             ASN1_NULL,
                                             2)} ASN1_CHOICE_END(OCSP_CERTSTATUS)

                                            IMPLEMENT_ASN1_FUNCTIONS(
                                                OCSP_CERTSTATUS)

                                                ASN1_SEQUENCE(OCSP_SINGLERESP) =
                                                    {ASN1_SIMPLE(
                                                         OCSP_SINGLERESP,
                                                         certId,
                                                         OCSP_CERTID),
                                                     ASN1_SIMPLE(
                                                         OCSP_SINGLERESP,
                                                         certStatus,
                                                         OCSP_CERTSTATUS),
                                                     ASN1_SIMPLE(
                                                         OCSP_SINGLERESP,
                                                         thisUpdate,
                                                         ASN1_GENERALIZEDTIME),
                                                     ASN1_EXP_OPT(
                                                         OCSP_SINGLERESP,
                                                         nextUpdate,
                                                         ASN1_GENERALIZEDTIME,
                                                         0),
                                                     ASN1_EXP_SEQUENCE_OF_OPT(
                                                         OCSP_SINGLERESP,
                                                         singleExtensions,
                                                         X509_EXTENSION,
                                                         1)} ASN1_SEQUENCE_END(OCSP_SINGLERESP)

                                                        IMPLEMENT_ASN1_FUNCTIONS(
                                                            OCSP_SINGLERESP)

                                                            ASN1_SEQUENCE(
                                                                OCSP_RESPDATA) =
                                                                {ASN1_EXP_OPT(
                                                                     OCSP_RESPDATA,
                                                                     version,
                                                                     ASN1_INTEGER,
                                                                     0),
                                                                 ASN1_EMBED(
                                                                     OCSP_RESPDATA,
                                                                     responderId,
                                                                     OCSP_RESPID),
                                                                 ASN1_SIMPLE(
                                                                     OCSP_RESPDATA,
                                                                     producedAt,
                                                                     ASN1_GENERALIZEDTIME),
                                                                 ASN1_SEQUENCE_OF(
                                                                     OCSP_RESPDATA,
                                                                     responses,
                                                                     OCSP_SINGLERESP),
                                                                 ASN1_EXP_SEQUENCE_OF_OPT(
                                                                     OCSP_RESPDATA,
                                                                     responseExtensions,
                                                                     X509_EXTENSION,
                                                                     1)} ASN1_SEQUENCE_END(OCSP_RESPDATA)

                                                                    IMPLEMENT_ASN1_FUNCTIONS(
                                                                        OCSP_RESPDATA)

                                                                        ASN1_SEQUENCE(
                                                                            OCSP_BASICRESP) =
                                                                            {ASN1_EMBED(
                                                                                 OCSP_BASICRESP,
                                                                                 tbsResponseData,
                                                                                 OCSP_RESPDATA),
                                                                             ASN1_EMBED(
                                                                                 OCSP_BASICRESP,
                                                                                 signatureAlgorithm,
                                                                                 X509_ALGOR),
                                                                             ASN1_SIMPLE(
                                                                                 OCSP_BASICRESP,
                                                                                 signature,
                                                                                 ASN1_BIT_STRING),
                                                                             ASN1_EXP_SEQUENCE_OF_OPT(
                                                                                 OCSP_BASICRESP,
                                                                                 certs,
                                                                                 X509,
                                                                                 0)} ASN1_SEQUENCE_END(OCSP_BASICRESP)

                                                                                IMPLEMENT_ASN1_FUNCTIONS(
                                                                                    OCSP_BASICRESP)

                                                                                    ASN1_SEQUENCE(
                                                                                        OCSP_CRLID) =
                                                                                        {ASN1_EXP_OPT(
                                                                                             OCSP_CRLID,
                                                                                             crlUrl,
                                                                                             ASN1_IA5STRING,
                                                                                             0),
                                                                                         ASN1_EXP_OPT(
                                                                                             OCSP_CRLID,
                                                                                             crlNum,
                                                                                             ASN1_INTEGER,
                                                                                             1),
                                                                                         ASN1_EXP_OPT(
                                                                                             OCSP_CRLID,
                                                                                             crlTime,
                                                                                             ASN1_GENERALIZEDTIME,
                                                                                             2)} ASN1_SEQUENCE_END(OCSP_CRLID)

                                                                                            IMPLEMENT_ASN1_FUNCTIONS(
                                                                                                OCSP_CRLID)

                                                                                                ASN1_SEQUENCE(
                                                                                                    OCSP_SERVICELOC) =
                                                                                                    {ASN1_SIMPLE(
                                                                                                         OCSP_SERVICELOC,
                                                                                                         issuer,
                                                                                                         X509_NAME),
                                                                                                     ASN1_SEQUENCE_OF_OPT(
                                                                                                         OCSP_SERVICELOC,
                                                                                                         locator,
                                                                                                         ACCESS_DESCRIPTION)} ASN1_SEQUENCE_END(OCSP_SERVICELOC)

                                                                                                        IMPLEMENT_ASN1_FUNCTIONS(
                                                                                                            OCSP_SERVICELOC)
