/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/ecerr.h>
#include <openssl/err.h>

#ifndef OPENSSL_NO_ERR

static const ERR_STRING_DATA EC_str_functs[] = {
    {ERR_PACK(ERR_LIB_EC, EC_F_BN_TO_FELEM, 0), "BN_to_felem"},
    {ERR_PACK(ERR_LIB_EC, EC_F_D2I_ECPARAMETERS, 0), "d2i_ECParameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_D2I_ECPKPARAMETERS, 0), "d2i_ECPKParameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_D2I_ECPRIVATEKEY, 0), "d2i_ECPrivateKey"},
    {ERR_PACK(ERR_LIB_EC, EC_F_DO_EC_KEY_PRINT, 0), "do_EC_KEY_print"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDH_CMS_DECRYPT, 0), "ecdh_cms_decrypt"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDH_CMS_SET_SHARED_INFO, 0),
     "ecdh_cms_set_shared_info"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDH_COMPUTE_KEY, 0), "ECDH_compute_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDH_SIMPLE_COMPUTE_KEY, 0),
     "ecdh_simple_compute_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_DO_SIGN_EX, 0), "ECDSA_do_sign_ex"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_DO_VERIFY, 0), "ECDSA_do_verify"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_SIGN_EX, 0), "ECDSA_sign_ex"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_SIGN_SETUP, 0), "ECDSA_sign_setup"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_SIG_NEW, 0), "ECDSA_SIG_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECDSA_VERIFY, 0), "ECDSA_verify"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECD_ITEM_VERIFY, 0), "ecd_item_verify"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PARAM2TYPE, 0), "eckey_param2type"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PARAM_DECODE, 0), "eckey_param_decode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PRIV_DECODE, 0), "eckey_priv_decode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PRIV_ENCODE, 0), "eckey_priv_encode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PUB_DECODE, 0), "eckey_pub_decode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_PUB_ENCODE, 0), "eckey_pub_encode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECKEY_TYPE2PARAM, 0), "eckey_type2param"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECPARAMETERS_PRINT, 0), "ECParameters_print"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECPARAMETERS_PRINT_FP, 0),
     "ECParameters_print_fp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECPKPARAMETERS_PRINT, 0),
     "ECPKParameters_print"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECPKPARAMETERS_PRINT_FP, 0),
     "ECPKParameters_print_fp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_GET_AFFINE, 0),
     "ecp_nistz256_get_affine"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_INV_MOD_ORD, 0),
     "ecp_nistz256_inv_mod_ord"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_MULT_PRECOMPUTE, 0),
     "ecp_nistz256_mult_precompute"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_POINTS_MUL, 0),
     "ecp_nistz256_points_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_PRE_COMP_NEW, 0),
     "ecp_nistz256_pre_comp_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECP_NISTZ256_WINDOWED_MUL, 0),
     "ecp_nistz256_windowed_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECX_KEY_OP, 0), "ecx_key_op"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECX_PRIV_ENCODE, 0), "ecx_priv_encode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_ECX_PUB_ENCODE, 0), "ecx_pub_encode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_ASN1_GROUP2CURVE, 0), "ec_asn1_group2curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_ASN1_GROUP2FIELDID, 0),
     "ec_asn1_group2fieldid"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_MONTGOMERY_POINT_MULTIPLY, 0),
     "ec_GF2m_montgomery_point_multiply"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_FIELD_INV, 0),
     "ec_GF2m_simple_field_inv"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_GROUP_CHECK_DISCRIMINANT, 0),
     "ec_GF2m_simple_group_check_discriminant"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_GROUP_SET_CURVE, 0),
     "ec_GF2m_simple_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_LADDER_POST, 0),
     "ec_GF2m_simple_ladder_post"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_LADDER_PRE, 0),
     "ec_GF2m_simple_ladder_pre"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_OCT2POINT, 0),
     "ec_GF2m_simple_oct2point"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_POINT2OCT, 0),
     "ec_GF2m_simple_point2oct"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_POINTS_MUL, 0),
     "ec_GF2m_simple_points_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_POINT_GET_AFFINE_COORDINATES, 0),
     "ec_GF2m_simple_point_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_POINT_SET_AFFINE_COORDINATES, 0),
     "ec_GF2m_simple_point_set_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GF2M_SIMPLE_SET_COMPRESSED_COORDINATES, 0),
     "ec_GF2m_simple_set_compressed_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_DECODE, 0),
     "ec_GFp_mont_field_decode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_ENCODE, 0),
     "ec_GFp_mont_field_encode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_INV, 0),
     "ec_GFp_mont_field_inv"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_MUL, 0),
     "ec_GFp_mont_field_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_SET_TO_ONE, 0),
     "ec_GFp_mont_field_set_to_one"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_FIELD_SQR, 0),
     "ec_GFp_mont_field_sqr"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_MONT_GROUP_SET_CURVE, 0),
     "ec_GFp_mont_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP224_GROUP_SET_CURVE, 0),
     "ec_GFp_nistp224_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP224_POINTS_MUL, 0),
     "ec_GFp_nistp224_points_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP224_POINT_GET_AFFINE_COORDINATES, 0),
     "ec_GFp_nistp224_point_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP256_GROUP_SET_CURVE, 0),
     "ec_GFp_nistp256_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP256_POINTS_MUL, 0),
     "ec_GFp_nistp256_points_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP256_POINT_GET_AFFINE_COORDINATES, 0),
     "ec_GFp_nistp256_point_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP521_GROUP_SET_CURVE, 0),
     "ec_GFp_nistp521_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP521_POINTS_MUL, 0),
     "ec_GFp_nistp521_points_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NISTP521_POINT_GET_AFFINE_COORDINATES, 0),
     "ec_GFp_nistp521_point_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NIST_FIELD_MUL, 0),
     "ec_GFp_nist_field_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NIST_FIELD_SQR, 0),
     "ec_GFp_nist_field_sqr"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_NIST_GROUP_SET_CURVE, 0),
     "ec_GFp_nist_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_BLIND_COORDINATES, 0),
     "ec_GFp_simple_blind_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_FIELD_INV, 0),
     "ec_GFp_simple_field_inv"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_GROUP_CHECK_DISCRIMINANT, 0),
     "ec_GFp_simple_group_check_discriminant"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_GROUP_SET_CURVE, 0),
     "ec_GFp_simple_group_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_MAKE_AFFINE, 0),
     "ec_GFp_simple_make_affine"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_OCT2POINT, 0),
     "ec_GFp_simple_oct2point"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_POINT2OCT, 0),
     "ec_GFp_simple_point2oct"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_POINTS_MAKE_AFFINE, 0),
     "ec_GFp_simple_points_make_affine"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_POINT_GET_AFFINE_COORDINATES, 0),
     "ec_GFp_simple_point_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_POINT_SET_AFFINE_COORDINATES, 0),
     "ec_GFp_simple_point_set_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GFP_SIMPLE_SET_COMPRESSED_COORDINATES, 0),
     "ec_GFp_simple_set_compressed_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_CHECK, 0), "EC_GROUP_check"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_CHECK_DISCRIMINANT, 0),
     "EC_GROUP_check_discriminant"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_COPY, 0), "EC_GROUP_copy"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_CURVE, 0), "EC_GROUP_get_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_CURVE_GF2M, 0),
     "EC_GROUP_get_curve_GF2m"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_CURVE_GFP, 0),
     "EC_GROUP_get_curve_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_DEGREE, 0), "EC_GROUP_get_degree"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_ECPARAMETERS, 0),
     "EC_GROUP_get_ecparameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_ECPKPARAMETERS, 0),
     "EC_GROUP_get_ecpkparameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_PENTANOMIAL_BASIS, 0),
     "EC_GROUP_get_pentanomial_basis"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_GET_TRINOMIAL_BASIS, 0),
     "EC_GROUP_get_trinomial_basis"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_NEW, 0), "EC_GROUP_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_NEW_BY_CURVE_NAME, 0),
     "EC_GROUP_new_by_curve_name"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_NEW_FROM_DATA, 0),
     "ec_group_new_from_data"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_NEW_FROM_ECPARAMETERS, 0),
     "EC_GROUP_new_from_ecparameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_NEW_FROM_ECPKPARAMETERS, 0),
     "EC_GROUP_new_from_ecpkparameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_SET_CURVE, 0), "EC_GROUP_set_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_SET_CURVE_GF2M, 0),
     "EC_GROUP_set_curve_GF2m"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_SET_CURVE_GFP, 0),
     "EC_GROUP_set_curve_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_SET_GENERATOR, 0),
     "EC_GROUP_set_generator"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_GROUP_SET_SEED, 0), "EC_GROUP_set_seed"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_CHECK_KEY, 0), "EC_KEY_check_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_COPY, 0), "EC_KEY_copy"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_GENERATE_KEY, 0), "EC_KEY_generate_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_NEW, 0), "EC_KEY_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_NEW_METHOD, 0), "EC_KEY_new_method"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_OCT2PRIV, 0), "EC_KEY_oct2priv"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_PRINT, 0), "EC_KEY_print"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_PRINT_FP, 0), "EC_KEY_print_fp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_PRIV2BUF, 0), "EC_KEY_priv2buf"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_PRIV2OCT, 0), "EC_KEY_priv2oct"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_SET_PUBLIC_KEY_AFFINE_COORDINATES, 0),
     "EC_KEY_set_public_key_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_SIMPLE_CHECK_KEY, 0),
     "ec_key_simple_check_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_SIMPLE_OCT2PRIV, 0),
     "ec_key_simple_oct2priv"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_KEY_SIMPLE_PRIV2OCT, 0),
     "ec_key_simple_priv2oct"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_PKEY_CHECK, 0), "ec_pkey_check"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_PKEY_PARAM_CHECK, 0), "ec_pkey_param_check"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINTS_MAKE_AFFINE, 0),
     "EC_POINTs_make_affine"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINTS_MUL, 0), "EC_POINTs_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_ADD, 0), "EC_POINT_add"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_BN2POINT, 0), "EC_POINT_bn2point"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_CMP, 0), "EC_POINT_cmp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_COPY, 0), "EC_POINT_copy"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_DBL, 0), "EC_POINT_dbl"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_GET_AFFINE_COORDINATES, 0),
     "EC_POINT_get_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_GET_AFFINE_COORDINATES_GF2M, 0),
     "EC_POINT_get_affine_coordinates_GF2m"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_GET_AFFINE_COORDINATES_GFP, 0),
     "EC_POINT_get_affine_coordinates_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_GET_JPROJECTIVE_COORDINATES_GFP, 0),
     "EC_POINT_get_Jprojective_coordinates_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_INVERT, 0), "EC_POINT_invert"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_IS_AT_INFINITY, 0),
     "EC_POINT_is_at_infinity"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_IS_ON_CURVE, 0),
     "EC_POINT_is_on_curve"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_MAKE_AFFINE, 0),
     "EC_POINT_make_affine"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_NEW, 0), "EC_POINT_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_OCT2POINT, 0), "EC_POINT_oct2point"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_POINT2BUF, 0), "EC_POINT_point2buf"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_POINT2OCT, 0), "EC_POINT_point2oct"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_AFFINE_COORDINATES, 0),
     "EC_POINT_set_affine_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_AFFINE_COORDINATES_GF2M, 0),
     "EC_POINT_set_affine_coordinates_GF2m"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_AFFINE_COORDINATES_GFP, 0),
     "EC_POINT_set_affine_coordinates_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_COMPRESSED_COORDINATES, 0),
     "EC_POINT_set_compressed_coordinates"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_COMPRESSED_COORDINATES_GF2M, 0),
     "EC_POINT_set_compressed_coordinates_GF2m"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_COMPRESSED_COORDINATES_GFP, 0),
     "EC_POINT_set_compressed_coordinates_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_JPROJECTIVE_COORDINATES_GFP, 0),
     "EC_POINT_set_Jprojective_coordinates_GFp"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_POINT_SET_TO_INFINITY, 0),
     "EC_POINT_set_to_infinity"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_PRE_COMP_NEW, 0), "ec_pre_comp_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_SCALAR_MUL_LADDER, 0),
     "ec_scalar_mul_ladder"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_WNAF_MUL, 0), "ec_wNAF_mul"},
    {ERR_PACK(ERR_LIB_EC, EC_F_EC_WNAF_PRECOMPUTE_MULT, 0),
     "ec_wNAF_precompute_mult"},
    {ERR_PACK(ERR_LIB_EC, EC_F_I2D_ECPARAMETERS, 0), "i2d_ECParameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_I2D_ECPKPARAMETERS, 0), "i2d_ECPKParameters"},
    {ERR_PACK(ERR_LIB_EC, EC_F_I2D_ECPRIVATEKEY, 0), "i2d_ECPrivateKey"},
    {ERR_PACK(ERR_LIB_EC, EC_F_I2O_ECPUBLICKEY, 0), "i2o_ECPublicKey"},
    {ERR_PACK(ERR_LIB_EC, EC_F_NISTP224_PRE_COMP_NEW, 0),
     "nistp224_pre_comp_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_NISTP256_PRE_COMP_NEW, 0),
     "nistp256_pre_comp_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_NISTP521_PRE_COMP_NEW, 0),
     "nistp521_pre_comp_new"},
    {ERR_PACK(ERR_LIB_EC, EC_F_O2I_ECPUBLICKEY, 0), "o2i_ECPublicKey"},
    {ERR_PACK(ERR_LIB_EC, EC_F_OLD_EC_PRIV_DECODE, 0), "old_ec_priv_decode"},
    {ERR_PACK(ERR_LIB_EC, EC_F_OSSL_ECDH_COMPUTE_KEY, 0),
     "ossl_ecdh_compute_key"},
    {ERR_PACK(ERR_LIB_EC, EC_F_OSSL_ECDSA_SIGN_SIG, 0), "ossl_ecdsa_sign_sig"},
    {ERR_PACK(ERR_LIB_EC, EC_F_OSSL_ECDSA_VERIFY_SIG, 0),
     "ossl_ecdsa_verify_sig"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_ECD_CTRL, 0), "pkey_ecd_ctrl"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_ECD_DIGESTSIGN, 0), "pkey_ecd_digestsign"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_ECD_DIGESTSIGN25519, 0),
     "pkey_ecd_digestsign25519"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_ECD_DIGESTSIGN448, 0),
     "pkey_ecd_digestsign448"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_ECX_DERIVE, 0), "pkey_ecx_derive"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_CTRL, 0), "pkey_ec_ctrl"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_CTRL_STR, 0), "pkey_ec_ctrl_str"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_DERIVE, 0), "pkey_ec_derive"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_INIT, 0), "pkey_ec_init"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_KDF_DERIVE, 0), "pkey_ec_kdf_derive"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_KEYGEN, 0), "pkey_ec_keygen"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_PARAMGEN, 0), "pkey_ec_paramgen"},
    {ERR_PACK(ERR_LIB_EC, EC_F_PKEY_EC_SIGN, 0), "pkey_ec_sign"},
    {ERR_PACK(ERR_LIB_EC, EC_F_VALIDATE_ECX_DERIVE, 0), "validate_ecx_derive"},
    {0, NULL}};

static const ERR_STRING_DATA EC_str_reasons[] = {
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_ASN1_ERROR), "asn1 error"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_BAD_SIGNATURE), "bad signature"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_BIGNUM_OUT_OF_RANGE), "bignum out of range"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_BUFFER_TOO_SMALL), "buffer too small"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_CANNOT_INVERT), "cannot invert"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_COORDINATES_OUT_OF_RANGE),
     "coordinates out of range"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_CURVE_DOES_NOT_SUPPORT_ECDH),
     "curve does not support ecdh"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_CURVE_DOES_NOT_SUPPORT_SIGNING),
     "curve does not support signing"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_D2I_ECPKPARAMETERS_FAILURE),
     "d2i ecpkparameters failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_DECODE_ERROR), "decode error"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_DISCRIMINANT_IS_ZERO),
     "discriminant is zero"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_EC_GROUP_NEW_BY_NAME_FAILURE),
     "ec group new by name failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_FIELD_TOO_LARGE), "field too large"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_GF2M_NOT_SUPPORTED), "gf2m not supported"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_GROUP2PKPARAMETERS_FAILURE),
     "group2pkparameters failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_I2D_ECPKPARAMETERS_FAILURE),
     "i2d ecpkparameters failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INCOMPATIBLE_OBJECTS),
     "incompatible objects"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_ARGUMENT), "invalid argument"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_COMPRESSED_POINT),
     "invalid compressed point"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_COMPRESSION_BIT),
     "invalid compression bit"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_CURVE), "invalid curve"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_DIGEST), "invalid digest"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_DIGEST_TYPE), "invalid digest type"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_ENCODING), "invalid encoding"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_FIELD), "invalid field"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_FORM), "invalid form"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_GROUP_ORDER), "invalid group order"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_KEY), "invalid key"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_OUTPUT_LENGTH),
     "invalid output length"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_PEER_KEY), "invalid peer key"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_PENTANOMIAL_BASIS),
     "invalid pentanomial basis"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_PRIVATE_KEY), "invalid private key"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_INVALID_TRINOMIAL_BASIS),
     "invalid trinomial basis"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_KDF_PARAMETER_ERROR), "kdf parameter error"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_KEYS_NOT_SET), "keys not set"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_LADDER_POST_FAILURE), "ladder post failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_LADDER_PRE_FAILURE), "ladder pre failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_LADDER_STEP_FAILURE), "ladder step failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_MISSING_PARAMETERS), "missing parameters"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_MISSING_PRIVATE_KEY), "missing private key"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NEED_NEW_SETUP_VALUES),
     "need new setup values"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NOT_A_NIST_PRIME), "not a NIST prime"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NOT_IMPLEMENTED), "not implemented"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NOT_INITIALIZED), "not initialized"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NO_PARAMETERS_SET), "no parameters set"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_NO_PRIVATE_VALUE), "no private value"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_OPERATION_NOT_SUPPORTED),
     "operation not supported"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_PASSED_NULL_PARAMETER),
     "passed null parameter"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_PEER_KEY_ERROR), "peer key error"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_PKPARAMETERS2GROUP_FAILURE),
     "pkparameters2group failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_POINT_ARITHMETIC_FAILURE),
     "point arithmetic failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_POINT_AT_INFINITY), "point at infinity"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_POINT_COORDINATES_BLIND_FAILURE),
     "point coordinates blind failure"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_POINT_IS_NOT_ON_CURVE),
     "point is not on curve"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_RANDOM_NUMBER_GENERATION_FAILED),
     "random number generation failed"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_SHARED_INFO_ERROR), "shared info error"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_SLOT_FULL), "slot full"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNDEFINED_GENERATOR), "undefined generator"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNDEFINED_ORDER), "undefined order"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNKNOWN_COFACTOR), "unknown cofactor"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNKNOWN_GROUP), "unknown group"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNKNOWN_ORDER), "unknown order"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_UNSUPPORTED_FIELD), "unsupported field"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_WRONG_CURVE_PARAMETERS),
     "wrong curve parameters"},
    {ERR_PACK(ERR_LIB_EC, 0, EC_R_WRONG_ORDER), "wrong order"},
    {0, NULL}};

#endif

int ERR_load_EC_strings(void)
{
#ifndef OPENSSL_NO_ERR
    if (ERR_func_error_string(EC_str_functs[0].error) == NULL)
    {
        ERR_load_strings_const(EC_str_functs);
        ERR_load_strings_const(EC_str_reasons);
    }
#endif
    return 1;
}