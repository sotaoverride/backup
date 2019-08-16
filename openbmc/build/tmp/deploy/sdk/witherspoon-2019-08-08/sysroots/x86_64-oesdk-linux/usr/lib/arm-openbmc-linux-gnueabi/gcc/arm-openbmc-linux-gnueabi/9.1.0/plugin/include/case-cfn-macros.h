#define CASE_CFN_ACOS                                                          \
    case CFN_ACOS:                                                             \
    case CFN_BUILT_IN_ACOSF:                                                   \
    case CFN_BUILT_IN_ACOS:                                                    \
    case CFN_BUILT_IN_ACOSL
#define CASE_CFN_ACOSH                                                         \
    case CFN_ACOSH:                                                            \
    case CFN_BUILT_IN_ACOSHF:                                                  \
    case CFN_BUILT_IN_ACOSH:                                                   \
    case CFN_BUILT_IN_ACOSHL
#define CASE_CFN_ASIN                                                          \
    case CFN_ASIN:                                                             \
    case CFN_BUILT_IN_ASINF:                                                   \
    case CFN_BUILT_IN_ASIN:                                                    \
    case CFN_BUILT_IN_ASINL
#define CASE_CFN_ASINH                                                         \
    case CFN_ASINH:                                                            \
    case CFN_BUILT_IN_ASINHF:                                                  \
    case CFN_BUILT_IN_ASINH:                                                   \
    case CFN_BUILT_IN_ASINHL
#define CASE_CFN_ATAN                                                          \
    case CFN_ATAN:                                                             \
    case CFN_BUILT_IN_ATANF:                                                   \
    case CFN_BUILT_IN_ATAN:                                                    \
    case CFN_BUILT_IN_ATANL
#define CASE_CFN_ATAN2                                                         \
    case CFN_ATAN2:                                                            \
    case CFN_BUILT_IN_ATAN2F:                                                  \
    case CFN_BUILT_IN_ATAN2:                                                   \
    case CFN_BUILT_IN_ATAN2L
#define CASE_CFN_ATANH                                                         \
    case CFN_ATANH:                                                            \
    case CFN_BUILT_IN_ATANHF:                                                  \
    case CFN_BUILT_IN_ATANH:                                                   \
    case CFN_BUILT_IN_ATANHL
#define CASE_CFN_CBRT                                                          \
    case CFN_BUILT_IN_CBRTF:                                                   \
    case CFN_BUILT_IN_CBRT:                                                    \
    case CFN_BUILT_IN_CBRTL
#define CASE_CFN_CEIL                                                          \
    case CFN_CEIL:                                                             \
    case CFN_BUILT_IN_CEILF:                                                   \
    case CFN_BUILT_IN_CEIL:                                                    \
    case CFN_BUILT_IN_CEILL
#define CASE_CFN_CEIL_FN                                                       \
    case CFN_BUILT_IN_CEILF16:                                                 \
    case CFN_BUILT_IN_CEILF32:                                                 \
    case CFN_BUILT_IN_CEILF64:                                                 \
    case CFN_BUILT_IN_CEILF128:                                                \
    case CFN_BUILT_IN_CEILF32X:                                                \
    case CFN_BUILT_IN_CEILF64X:                                                \
    case CFN_BUILT_IN_CEILF128X
#define CASE_CFN_CEIL_ALL                                                      \
    case CFN_BUILT_IN_CEILF:                                                   \
    case CFN_BUILT_IN_CEIL:                                                    \
    case CFN_BUILT_IN_CEILL:                                                   \
    case CFN_BUILT_IN_CEILF16:                                                 \
    case CFN_BUILT_IN_CEILF32:                                                 \
    case CFN_BUILT_IN_CEILF64:                                                 \
    case CFN_BUILT_IN_CEILF128:                                                \
    case CFN_BUILT_IN_CEILF32X:                                                \
    case CFN_BUILT_IN_CEILF64X:                                                \
    case CFN_BUILT_IN_CEILF128X
#define CASE_CFN_COPYSIGN                                                      \
    case CFN_COPYSIGN:                                                         \
    case CFN_BUILT_IN_COPYSIGNF:                                               \
    case CFN_BUILT_IN_COPYSIGN:                                                \
    case CFN_BUILT_IN_COPYSIGNL
#define CASE_CFN_COPYSIGN_FN                                                   \
    case CFN_BUILT_IN_COPYSIGNF16:                                             \
    case CFN_BUILT_IN_COPYSIGNF32:                                             \
    case CFN_BUILT_IN_COPYSIGNF64:                                             \
    case CFN_BUILT_IN_COPYSIGNF128:                                            \
    case CFN_BUILT_IN_COPYSIGNF32X:                                            \
    case CFN_BUILT_IN_COPYSIGNF64X:                                            \
    case CFN_BUILT_IN_COPYSIGNF128X
#define CASE_CFN_COPYSIGN_ALL                                                  \
    case CFN_BUILT_IN_COPYSIGNF:                                               \
    case CFN_BUILT_IN_COPYSIGN:                                                \
    case CFN_BUILT_IN_COPYSIGNL:                                               \
    case CFN_BUILT_IN_COPYSIGNF16:                                             \
    case CFN_BUILT_IN_COPYSIGNF32:                                             \
    case CFN_BUILT_IN_COPYSIGNF64:                                             \
    case CFN_BUILT_IN_COPYSIGNF128:                                            \
    case CFN_BUILT_IN_COPYSIGNF32X:                                            \
    case CFN_BUILT_IN_COPYSIGNF64X:                                            \
    case CFN_BUILT_IN_COPYSIGNF128X
#define CASE_CFN_COS                                                           \
    case CFN_COS:                                                              \
    case CFN_BUILT_IN_COSF:                                                    \
    case CFN_BUILT_IN_COS:                                                     \
    case CFN_BUILT_IN_COSL
#define CASE_CFN_COSH                                                          \
    case CFN_COSH:                                                             \
    case CFN_BUILT_IN_COSHF:                                                   \
    case CFN_BUILT_IN_COSH:                                                    \
    case CFN_BUILT_IN_COSHL
#define CASE_CFN_DREM                                                          \
    case CFN_BUILT_IN_DREMF:                                                   \
    case CFN_BUILT_IN_DREM:                                                    \
    case CFN_BUILT_IN_DREML
#define CASE_CFN_ERF                                                           \
    case CFN_BUILT_IN_ERFF:                                                    \
    case CFN_BUILT_IN_ERF:                                                     \
    case CFN_BUILT_IN_ERFL
#define CASE_CFN_ERFC                                                          \
    case CFN_BUILT_IN_ERFCF:                                                   \
    case CFN_BUILT_IN_ERFC:                                                    \
    case CFN_BUILT_IN_ERFCL
#define CASE_CFN_EXP                                                           \
    case CFN_EXP:                                                              \
    case CFN_BUILT_IN_EXPF:                                                    \
    case CFN_BUILT_IN_EXP:                                                     \
    case CFN_BUILT_IN_EXPL
#define CASE_CFN_EXP10                                                         \
    case CFN_EXP10:                                                            \
    case CFN_BUILT_IN_EXP10F:                                                  \
    case CFN_BUILT_IN_EXP10:                                                   \
    case CFN_BUILT_IN_EXP10L
#define CASE_CFN_EXP2                                                          \
    case CFN_EXP2:                                                             \
    case CFN_BUILT_IN_EXP2F:                                                   \
    case CFN_BUILT_IN_EXP2:                                                    \
    case CFN_BUILT_IN_EXP2L
#define CASE_CFN_EXPM1                                                         \
    case CFN_EXPM1:                                                            \
    case CFN_BUILT_IN_EXPM1F:                                                  \
    case CFN_BUILT_IN_EXPM1:                                                   \
    case CFN_BUILT_IN_EXPM1L
#define CASE_CFN_FABS                                                          \
    case CFN_BUILT_IN_FABSF:                                                   \
    case CFN_BUILT_IN_FABS:                                                    \
    case CFN_BUILT_IN_FABSL
#define CASE_CFN_FABS_FN                                                       \
    case CFN_BUILT_IN_FABSF16:                                                 \
    case CFN_BUILT_IN_FABSF32:                                                 \
    case CFN_BUILT_IN_FABSF64:                                                 \
    case CFN_BUILT_IN_FABSF128:                                                \
    case CFN_BUILT_IN_FABSF32X:                                                \
    case CFN_BUILT_IN_FABSF64X:                                                \
    case CFN_BUILT_IN_FABSF128X
#define CASE_CFN_FABS_ALL                                                      \
    case CFN_BUILT_IN_FABSF:                                                   \
    case CFN_BUILT_IN_FABS:                                                    \
    case CFN_BUILT_IN_FABSL:                                                   \
    case CFN_BUILT_IN_FABSF16:                                                 \
    case CFN_BUILT_IN_FABSF32:                                                 \
    case CFN_BUILT_IN_FABSF64:                                                 \
    case CFN_BUILT_IN_FABSF128:                                                \
    case CFN_BUILT_IN_FABSF32X:                                                \
    case CFN_BUILT_IN_FABSF64X:                                                \
    case CFN_BUILT_IN_FABSF128X
#define CASE_CFN_FDIM                                                          \
    case CFN_BUILT_IN_FDIMF:                                                   \
    case CFN_BUILT_IN_FDIM:                                                    \
    case CFN_BUILT_IN_FDIML
#define CASE_CFN_FLOOR                                                         \
    case CFN_FLOOR:                                                            \
    case CFN_BUILT_IN_FLOORF:                                                  \
    case CFN_BUILT_IN_FLOOR:                                                   \
    case CFN_BUILT_IN_FLOORL
#define CASE_CFN_FLOOR_FN                                                      \
    case CFN_BUILT_IN_FLOORF16:                                                \
    case CFN_BUILT_IN_FLOORF32:                                                \
    case CFN_BUILT_IN_FLOORF64:                                                \
    case CFN_BUILT_IN_FLOORF128:                                               \
    case CFN_BUILT_IN_FLOORF32X:                                               \
    case CFN_BUILT_IN_FLOORF64X:                                               \
    case CFN_BUILT_IN_FLOORF128X
#define CASE_CFN_FLOOR_ALL                                                     \
    case CFN_BUILT_IN_FLOORF:                                                  \
    case CFN_BUILT_IN_FLOOR:                                                   \
    case CFN_BUILT_IN_FLOORL:                                                  \
    case CFN_BUILT_IN_FLOORF16:                                                \
    case CFN_BUILT_IN_FLOORF32:                                                \
    case CFN_BUILT_IN_FLOORF64:                                                \
    case CFN_BUILT_IN_FLOORF128:                                               \
    case CFN_BUILT_IN_FLOORF32X:                                               \
    case CFN_BUILT_IN_FLOORF64X:                                               \
    case CFN_BUILT_IN_FLOORF128X
#define CASE_CFN_FMA                                                           \
    case CFN_FMA:                                                              \
    case CFN_BUILT_IN_FMAF:                                                    \
    case CFN_BUILT_IN_FMA:                                                     \
    case CFN_BUILT_IN_FMAL
#define CASE_CFN_FMA_FN                                                        \
    case CFN_BUILT_IN_FMAF16:                                                  \
    case CFN_BUILT_IN_FMAF32:                                                  \
    case CFN_BUILT_IN_FMAF64:                                                  \
    case CFN_BUILT_IN_FMAF128:                                                 \
    case CFN_BUILT_IN_FMAF32X:                                                 \
    case CFN_BUILT_IN_FMAF64X:                                                 \
    case CFN_BUILT_IN_FMAF128X
#define CASE_CFN_FMA_ALL                                                       \
    case CFN_BUILT_IN_FMAF:                                                    \
    case CFN_BUILT_IN_FMA:                                                     \
    case CFN_BUILT_IN_FMAL:                                                    \
    case CFN_BUILT_IN_FMAF16:                                                  \
    case CFN_BUILT_IN_FMAF32:                                                  \
    case CFN_BUILT_IN_FMAF64:                                                  \
    case CFN_BUILT_IN_FMAF128:                                                 \
    case CFN_BUILT_IN_FMAF32X:                                                 \
    case CFN_BUILT_IN_FMAF64X:                                                 \
    case CFN_BUILT_IN_FMAF128X
#define CASE_CFN_FMAX                                                          \
    case CFN_FMAX:                                                             \
    case CFN_BUILT_IN_FMAXF:                                                   \
    case CFN_BUILT_IN_FMAX:                                                    \
    case CFN_BUILT_IN_FMAXL
#define CASE_CFN_FMAX_FN                                                       \
    case CFN_BUILT_IN_FMAXF16:                                                 \
    case CFN_BUILT_IN_FMAXF32:                                                 \
    case CFN_BUILT_IN_FMAXF64:                                                 \
    case CFN_BUILT_IN_FMAXF128:                                                \
    case CFN_BUILT_IN_FMAXF32X:                                                \
    case CFN_BUILT_IN_FMAXF64X:                                                \
    case CFN_BUILT_IN_FMAXF128X
#define CASE_CFN_FMAX_ALL                                                      \
    case CFN_BUILT_IN_FMAXF:                                                   \
    case CFN_BUILT_IN_FMAX:                                                    \
    case CFN_BUILT_IN_FMAXL:                                                   \
    case CFN_BUILT_IN_FMAXF16:                                                 \
    case CFN_BUILT_IN_FMAXF32:                                                 \
    case CFN_BUILT_IN_FMAXF64:                                                 \
    case CFN_BUILT_IN_FMAXF128:                                                \
    case CFN_BUILT_IN_FMAXF32X:                                                \
    case CFN_BUILT_IN_FMAXF64X:                                                \
    case CFN_BUILT_IN_FMAXF128X
#define CASE_CFN_FMIN                                                          \
    case CFN_FMIN:                                                             \
    case CFN_BUILT_IN_FMINF:                                                   \
    case CFN_BUILT_IN_FMIN:                                                    \
    case CFN_BUILT_IN_FMINL
#define CASE_CFN_FMIN_FN                                                       \
    case CFN_BUILT_IN_FMINF16:                                                 \
    case CFN_BUILT_IN_FMINF32:                                                 \
    case CFN_BUILT_IN_FMINF64:                                                 \
    case CFN_BUILT_IN_FMINF128:                                                \
    case CFN_BUILT_IN_FMINF32X:                                                \
    case CFN_BUILT_IN_FMINF64X:                                                \
    case CFN_BUILT_IN_FMINF128X
#define CASE_CFN_FMIN_ALL                                                      \
    case CFN_BUILT_IN_FMINF:                                                   \
    case CFN_BUILT_IN_FMIN:                                                    \
    case CFN_BUILT_IN_FMINL:                                                   \
    case CFN_BUILT_IN_FMINF16:                                                 \
    case CFN_BUILT_IN_FMINF32:                                                 \
    case CFN_BUILT_IN_FMINF64:                                                 \
    case CFN_BUILT_IN_FMINF128:                                                \
    case CFN_BUILT_IN_FMINF32X:                                                \
    case CFN_BUILT_IN_FMINF64X:                                                \
    case CFN_BUILT_IN_FMINF128X
#define CASE_CFN_FMOD                                                          \
    case CFN_FMOD:                                                             \
    case CFN_BUILT_IN_FMODF:                                                   \
    case CFN_BUILT_IN_FMOD:                                                    \
    case CFN_BUILT_IN_FMODL
#define CASE_CFN_FREXP                                                         \
    case CFN_BUILT_IN_FREXPF:                                                  \
    case CFN_BUILT_IN_FREXP:                                                   \
    case CFN_BUILT_IN_FREXPL
#define CASE_CFN_GAMMA                                                         \
    case CFN_BUILT_IN_GAMMAF:                                                  \
    case CFN_BUILT_IN_GAMMA:                                                   \
    case CFN_BUILT_IN_GAMMAL
#define CASE_CFN_HUGE_VAL                                                      \
    case CFN_BUILT_IN_HUGE_VALF:                                               \
    case CFN_BUILT_IN_HUGE_VAL:                                                \
    case CFN_BUILT_IN_HUGE_VALL
#define CASE_CFN_HUGE_VAL_FN                                                   \
    case CFN_BUILT_IN_HUGE_VALF16:                                             \
    case CFN_BUILT_IN_HUGE_VALF32:                                             \
    case CFN_BUILT_IN_HUGE_VALF64:                                             \
    case CFN_BUILT_IN_HUGE_VALF128:                                            \
    case CFN_BUILT_IN_HUGE_VALF32X:                                            \
    case CFN_BUILT_IN_HUGE_VALF64X:                                            \
    case CFN_BUILT_IN_HUGE_VALF128X
#define CASE_CFN_HUGE_VAL_ALL                                                  \
    case CFN_BUILT_IN_HUGE_VALF:                                               \
    case CFN_BUILT_IN_HUGE_VAL:                                                \
    case CFN_BUILT_IN_HUGE_VALL:                                               \
    case CFN_BUILT_IN_HUGE_VALF16:                                             \
    case CFN_BUILT_IN_HUGE_VALF32:                                             \
    case CFN_BUILT_IN_HUGE_VALF64:                                             \
    case CFN_BUILT_IN_HUGE_VALF128:                                            \
    case CFN_BUILT_IN_HUGE_VALF32X:                                            \
    case CFN_BUILT_IN_HUGE_VALF64X:                                            \
    case CFN_BUILT_IN_HUGE_VALF128X
#define CASE_CFN_HYPOT                                                         \
    case CFN_HYPOT:                                                            \
    case CFN_BUILT_IN_HYPOTF:                                                  \
    case CFN_BUILT_IN_HYPOT:                                                   \
    case CFN_BUILT_IN_HYPOTL
#define CASE_CFN_ICEIL                                                         \
    case CFN_BUILT_IN_ICEILF:                                                  \
    case CFN_BUILT_IN_ICEIL:                                                   \
    case CFN_BUILT_IN_ICEILL
#define CASE_CFN_IFLOOR                                                        \
    case CFN_BUILT_IN_IFLOORF:                                                 \
    case CFN_BUILT_IN_IFLOOR:                                                  \
    case CFN_BUILT_IN_IFLOORL
#define CASE_CFN_ILOGB                                                         \
    case CFN_BUILT_IN_ILOGBF:                                                  \
    case CFN_BUILT_IN_ILOGB:                                                   \
    case CFN_BUILT_IN_ILOGBL
#define CASE_CFN_INF                                                           \
    case CFN_BUILT_IN_INFF:                                                    \
    case CFN_BUILT_IN_INF:                                                     \
    case CFN_BUILT_IN_INFL
#define CASE_CFN_INF_FN                                                        \
    case CFN_BUILT_IN_INFF16:                                                  \
    case CFN_BUILT_IN_INFF32:                                                  \
    case CFN_BUILT_IN_INFF64:                                                  \
    case CFN_BUILT_IN_INFF128:                                                 \
    case CFN_BUILT_IN_INFF32X:                                                 \
    case CFN_BUILT_IN_INFF64X:                                                 \
    case CFN_BUILT_IN_INFF128X
#define CASE_CFN_INF_ALL                                                       \
    case CFN_BUILT_IN_INFF:                                                    \
    case CFN_BUILT_IN_INF:                                                     \
    case CFN_BUILT_IN_INFL:                                                    \
    case CFN_BUILT_IN_INFF16:                                                  \
    case CFN_BUILT_IN_INFF32:                                                  \
    case CFN_BUILT_IN_INFF64:                                                  \
    case CFN_BUILT_IN_INFF128:                                                 \
    case CFN_BUILT_IN_INFF32X:                                                 \
    case CFN_BUILT_IN_INFF64X:                                                 \
    case CFN_BUILT_IN_INFF128X
#define CASE_CFN_IRINT                                                         \
    case CFN_BUILT_IN_IRINTF:                                                  \
    case CFN_BUILT_IN_IRINT:                                                   \
    case CFN_BUILT_IN_IRINTL
#define CASE_CFN_IROUND                                                        \
    case CFN_BUILT_IN_IROUNDF:                                                 \
    case CFN_BUILT_IN_IROUND:                                                  \
    case CFN_BUILT_IN_IROUNDL
#define CASE_CFN_J0                                                            \
    case CFN_BUILT_IN_J0F:                                                     \
    case CFN_BUILT_IN_J0:                                                      \
    case CFN_BUILT_IN_J0L
#define CASE_CFN_J1                                                            \
    case CFN_BUILT_IN_J1F:                                                     \
    case CFN_BUILT_IN_J1:                                                      \
    case CFN_BUILT_IN_J1L
#define CASE_CFN_JN                                                            \
    case CFN_BUILT_IN_JNF:                                                     \
    case CFN_BUILT_IN_JN:                                                      \
    case CFN_BUILT_IN_JNL
#define CASE_CFN_LCEIL                                                         \
    case CFN_BUILT_IN_LCEILF:                                                  \
    case CFN_BUILT_IN_LCEIL:                                                   \
    case CFN_BUILT_IN_LCEILL
#define CASE_CFN_LDEXP                                                         \
    case CFN_LDEXP:                                                            \
    case CFN_BUILT_IN_LDEXPF:                                                  \
    case CFN_BUILT_IN_LDEXP:                                                   \
    case CFN_BUILT_IN_LDEXPL
#define CASE_CFN_LFLOOR                                                        \
    case CFN_BUILT_IN_LFLOORF:                                                 \
    case CFN_BUILT_IN_LFLOOR:                                                  \
    case CFN_BUILT_IN_LFLOORL
#define CASE_CFN_LGAMMA                                                        \
    case CFN_BUILT_IN_LGAMMAF:                                                 \
    case CFN_BUILT_IN_LGAMMA:                                                  \
    case CFN_BUILT_IN_LGAMMAL
#define CASE_CFN_LLCEIL                                                        \
    case CFN_BUILT_IN_LLCEILF:                                                 \
    case CFN_BUILT_IN_LLCEIL:                                                  \
    case CFN_BUILT_IN_LLCEILL
#define CASE_CFN_LLFLOOR                                                       \
    case CFN_BUILT_IN_LLFLOORF:                                                \
    case CFN_BUILT_IN_LLFLOOR:                                                 \
    case CFN_BUILT_IN_LLFLOORL
#define CASE_CFN_LLRINT                                                        \
    case CFN_BUILT_IN_LLRINTF:                                                 \
    case CFN_BUILT_IN_LLRINT:                                                  \
    case CFN_BUILT_IN_LLRINTL
#define CASE_CFN_LLROUND                                                       \
    case CFN_BUILT_IN_LLROUNDF:                                                \
    case CFN_BUILT_IN_LLROUND:                                                 \
    case CFN_BUILT_IN_LLROUNDL
#define CASE_CFN_LOG                                                           \
    case CFN_LOG:                                                              \
    case CFN_BUILT_IN_LOGF:                                                    \
    case CFN_BUILT_IN_LOG:                                                     \
    case CFN_BUILT_IN_LOGL
#define CASE_CFN_LOG10                                                         \
    case CFN_LOG10:                                                            \
    case CFN_BUILT_IN_LOG10F:                                                  \
    case CFN_BUILT_IN_LOG10:                                                   \
    case CFN_BUILT_IN_LOG10L
#define CASE_CFN_LOG1P                                                         \
    case CFN_LOG1P:                                                            \
    case CFN_BUILT_IN_LOG1PF:                                                  \
    case CFN_BUILT_IN_LOG1P:                                                   \
    case CFN_BUILT_IN_LOG1PL
#define CASE_CFN_LOG2                                                          \
    case CFN_LOG2:                                                             \
    case CFN_BUILT_IN_LOG2F:                                                   \
    case CFN_BUILT_IN_LOG2:                                                    \
    case CFN_BUILT_IN_LOG2L
#define CASE_CFN_LOGB                                                          \
    case CFN_LOGB:                                                             \
    case CFN_BUILT_IN_LOGBF:                                                   \
    case CFN_BUILT_IN_LOGB:                                                    \
    case CFN_BUILT_IN_LOGBL
#define CASE_CFN_LRINT                                                         \
    case CFN_BUILT_IN_LRINTF:                                                  \
    case CFN_BUILT_IN_LRINT:                                                   \
    case CFN_BUILT_IN_LRINTL
#define CASE_CFN_LROUND                                                        \
    case CFN_BUILT_IN_LROUNDF:                                                 \
    case CFN_BUILT_IN_LROUND:                                                  \
    case CFN_BUILT_IN_LROUNDL
#define CASE_CFN_MODF                                                          \
    case CFN_BUILT_IN_MODFF:                                                   \
    case CFN_BUILT_IN_MODF:                                                    \
    case CFN_BUILT_IN_MODFL
#define CASE_CFN_NAN                                                           \
    case CFN_BUILT_IN_NANF:                                                    \
    case CFN_BUILT_IN_NAN:                                                     \
    case CFN_BUILT_IN_NANL
#define CASE_CFN_NAN_FN                                                        \
    case CFN_BUILT_IN_NANF16:                                                  \
    case CFN_BUILT_IN_NANF32:                                                  \
    case CFN_BUILT_IN_NANF64:                                                  \
    case CFN_BUILT_IN_NANF128:                                                 \
    case CFN_BUILT_IN_NANF32X:                                                 \
    case CFN_BUILT_IN_NANF64X:                                                 \
    case CFN_BUILT_IN_NANF128X
#define CASE_CFN_NAN_ALL                                                       \
    case CFN_BUILT_IN_NANF:                                                    \
    case CFN_BUILT_IN_NAN:                                                     \
    case CFN_BUILT_IN_NANL:                                                    \
    case CFN_BUILT_IN_NANF16:                                                  \
    case CFN_BUILT_IN_NANF32:                                                  \
    case CFN_BUILT_IN_NANF64:                                                  \
    case CFN_BUILT_IN_NANF128:                                                 \
    case CFN_BUILT_IN_NANF32X:                                                 \
    case CFN_BUILT_IN_NANF64X:                                                 \
    case CFN_BUILT_IN_NANF128X
#define CASE_CFN_NANS                                                          \
    case CFN_BUILT_IN_NANSF:                                                   \
    case CFN_BUILT_IN_NANS:                                                    \
    case CFN_BUILT_IN_NANSL
#define CASE_CFN_NANS_FN                                                       \
    case CFN_BUILT_IN_NANSF16:                                                 \
    case CFN_BUILT_IN_NANSF32:                                                 \
    case CFN_BUILT_IN_NANSF64:                                                 \
    case CFN_BUILT_IN_NANSF128:                                                \
    case CFN_BUILT_IN_NANSF32X:                                                \
    case CFN_BUILT_IN_NANSF64X:                                                \
    case CFN_BUILT_IN_NANSF128X
#define CASE_CFN_NANS_ALL                                                      \
    case CFN_BUILT_IN_NANSF:                                                   \
    case CFN_BUILT_IN_NANS:                                                    \
    case CFN_BUILT_IN_NANSL:                                                   \
    case CFN_BUILT_IN_NANSF16:                                                 \
    case CFN_BUILT_IN_NANSF32:                                                 \
    case CFN_BUILT_IN_NANSF64:                                                 \
    case CFN_BUILT_IN_NANSF128:                                                \
    case CFN_BUILT_IN_NANSF32X:                                                \
    case CFN_BUILT_IN_NANSF64X:                                                \
    case CFN_BUILT_IN_NANSF128X
#define CASE_CFN_NEARBYINT                                                     \
    case CFN_NEARBYINT:                                                        \
    case CFN_BUILT_IN_NEARBYINTF:                                              \
    case CFN_BUILT_IN_NEARBYINT:                                               \
    case CFN_BUILT_IN_NEARBYINTL
#define CASE_CFN_NEARBYINT_FN                                                  \
    case CFN_BUILT_IN_NEARBYINTF16:                                            \
    case CFN_BUILT_IN_NEARBYINTF32:                                            \
    case CFN_BUILT_IN_NEARBYINTF64:                                            \
    case CFN_BUILT_IN_NEARBYINTF128:                                           \
    case CFN_BUILT_IN_NEARBYINTF32X:                                           \
    case CFN_BUILT_IN_NEARBYINTF64X:                                           \
    case CFN_BUILT_IN_NEARBYINTF128X
#define CASE_CFN_NEARBYINT_ALL                                                 \
    case CFN_BUILT_IN_NEARBYINTF:                                              \
    case CFN_BUILT_IN_NEARBYINT:                                               \
    case CFN_BUILT_IN_NEARBYINTL:                                              \
    case CFN_BUILT_IN_NEARBYINTF16:                                            \
    case CFN_BUILT_IN_NEARBYINTF32:                                            \
    case CFN_BUILT_IN_NEARBYINTF64:                                            \
    case CFN_BUILT_IN_NEARBYINTF128:                                           \
    case CFN_BUILT_IN_NEARBYINTF32X:                                           \
    case CFN_BUILT_IN_NEARBYINTF64X:                                           \
    case CFN_BUILT_IN_NEARBYINTF128X
#define CASE_CFN_NEXTAFTER                                                     \
    case CFN_BUILT_IN_NEXTAFTERF:                                              \
    case CFN_BUILT_IN_NEXTAFTER:                                               \
    case CFN_BUILT_IN_NEXTAFTERL
#define CASE_CFN_NEXTTOWARD                                                    \
    case CFN_BUILT_IN_NEXTTOWARDF:                                             \
    case CFN_BUILT_IN_NEXTTOWARD:                                              \
    case CFN_BUILT_IN_NEXTTOWARDL
#define CASE_CFN_POW                                                           \
    case CFN_POW:                                                              \
    case CFN_BUILT_IN_POWF:                                                    \
    case CFN_BUILT_IN_POW:                                                     \
    case CFN_BUILT_IN_POWL
#define CASE_CFN_POW10                                                         \
    case CFN_BUILT_IN_POW10F:                                                  \
    case CFN_BUILT_IN_POW10:                                                   \
    case CFN_BUILT_IN_POW10L
#define CASE_CFN_POWI                                                          \
    case CFN_BUILT_IN_POWIF:                                                   \
    case CFN_BUILT_IN_POWI:                                                    \
    case CFN_BUILT_IN_POWIL
#define CASE_CFN_REMAINDER                                                     \
    case CFN_REMAINDER:                                                        \
    case CFN_BUILT_IN_REMAINDERF:                                              \
    case CFN_BUILT_IN_REMAINDER:                                               \
    case CFN_BUILT_IN_REMAINDERL
#define CASE_CFN_REMQUO                                                        \
    case CFN_BUILT_IN_REMQUOF:                                                 \
    case CFN_BUILT_IN_REMQUO:                                                  \
    case CFN_BUILT_IN_REMQUOL
#define CASE_CFN_RINT                                                          \
    case CFN_RINT:                                                             \
    case CFN_BUILT_IN_RINTF:                                                   \
    case CFN_BUILT_IN_RINT:                                                    \
    case CFN_BUILT_IN_RINTL
#define CASE_CFN_RINT_FN                                                       \
    case CFN_BUILT_IN_RINTF16:                                                 \
    case CFN_BUILT_IN_RINTF32:                                                 \
    case CFN_BUILT_IN_RINTF64:                                                 \
    case CFN_BUILT_IN_RINTF128:                                                \
    case CFN_BUILT_IN_RINTF32X:                                                \
    case CFN_BUILT_IN_RINTF64X:                                                \
    case CFN_BUILT_IN_RINTF128X
#define CASE_CFN_RINT_ALL                                                      \
    case CFN_BUILT_IN_RINTF:                                                   \
    case CFN_BUILT_IN_RINT:                                                    \
    case CFN_BUILT_IN_RINTL:                                                   \
    case CFN_BUILT_IN_RINTF16:                                                 \
    case CFN_BUILT_IN_RINTF32:                                                 \
    case CFN_BUILT_IN_RINTF64:                                                 \
    case CFN_BUILT_IN_RINTF128:                                                \
    case CFN_BUILT_IN_RINTF32X:                                                \
    case CFN_BUILT_IN_RINTF64X:                                                \
    case CFN_BUILT_IN_RINTF128X
#define CASE_CFN_ROUND                                                         \
    case CFN_ROUND:                                                            \
    case CFN_BUILT_IN_ROUNDF:                                                  \
    case CFN_BUILT_IN_ROUND:                                                   \
    case CFN_BUILT_IN_ROUNDL
#define CASE_CFN_ROUND_FN                                                      \
    case CFN_BUILT_IN_ROUNDF16:                                                \
    case CFN_BUILT_IN_ROUNDF32:                                                \
    case CFN_BUILT_IN_ROUNDF64:                                                \
    case CFN_BUILT_IN_ROUNDF128:                                               \
    case CFN_BUILT_IN_ROUNDF32X:                                               \
    case CFN_BUILT_IN_ROUNDF64X:                                               \
    case CFN_BUILT_IN_ROUNDF128X
#define CASE_CFN_ROUND_ALL                                                     \
    case CFN_BUILT_IN_ROUNDF:                                                  \
    case CFN_BUILT_IN_ROUND:                                                   \
    case CFN_BUILT_IN_ROUNDL:                                                  \
    case CFN_BUILT_IN_ROUNDF16:                                                \
    case CFN_BUILT_IN_ROUNDF32:                                                \
    case CFN_BUILT_IN_ROUNDF64:                                                \
    case CFN_BUILT_IN_ROUNDF128:                                               \
    case CFN_BUILT_IN_ROUNDF32X:                                               \
    case CFN_BUILT_IN_ROUNDF64X:                                               \
    case CFN_BUILT_IN_ROUNDF128X
#define CASE_CFN_SCALB                                                         \
    case CFN_SCALB:                                                            \
    case CFN_BUILT_IN_SCALBF:                                                  \
    case CFN_BUILT_IN_SCALB:                                                   \
    case CFN_BUILT_IN_SCALBL
#define CASE_CFN_SCALBLN                                                       \
    case CFN_BUILT_IN_SCALBLNF:                                                \
    case CFN_BUILT_IN_SCALBLN:                                                 \
    case CFN_BUILT_IN_SCALBLNL
#define CASE_CFN_SCALBN                                                        \
    case CFN_BUILT_IN_SCALBNF:                                                 \
    case CFN_BUILT_IN_SCALBN:                                                  \
    case CFN_BUILT_IN_SCALBNL
#define CASE_CFN_SIGNBIT                                                       \
    case CFN_BUILT_IN_SIGNBITF:                                                \
    case CFN_BUILT_IN_SIGNBIT:                                                 \
    case CFN_BUILT_IN_SIGNBITL
#define CASE_CFN_SIGNIFICAND                                                   \
    case CFN_SIGNIFICAND:                                                      \
    case CFN_BUILT_IN_SIGNIFICANDF:                                            \
    case CFN_BUILT_IN_SIGNIFICAND:                                             \
    case CFN_BUILT_IN_SIGNIFICANDL
#define CASE_CFN_SIN                                                           \
    case CFN_SIN:                                                              \
    case CFN_BUILT_IN_SINF:                                                    \
    case CFN_BUILT_IN_SIN:                                                     \
    case CFN_BUILT_IN_SINL
#define CASE_CFN_SINCOS                                                        \
    case CFN_BUILT_IN_SINCOSF:                                                 \
    case CFN_BUILT_IN_SINCOS:                                                  \
    case CFN_BUILT_IN_SINCOSL
#define CASE_CFN_SINH                                                          \
    case CFN_SINH:                                                             \
    case CFN_BUILT_IN_SINHF:                                                   \
    case CFN_BUILT_IN_SINH:                                                    \
    case CFN_BUILT_IN_SINHL
#define CASE_CFN_SQRT                                                          \
    case CFN_SQRT:                                                             \
    case CFN_BUILT_IN_SQRTF:                                                   \
    case CFN_BUILT_IN_SQRT:                                                    \
    case CFN_BUILT_IN_SQRTL
#define CASE_CFN_SQRT_FN                                                       \
    case CFN_BUILT_IN_SQRTF16:                                                 \
    case CFN_BUILT_IN_SQRTF32:                                                 \
    case CFN_BUILT_IN_SQRTF64:                                                 \
    case CFN_BUILT_IN_SQRTF128:                                                \
    case CFN_BUILT_IN_SQRTF32X:                                                \
    case CFN_BUILT_IN_SQRTF64X:                                                \
    case CFN_BUILT_IN_SQRTF128X
#define CASE_CFN_SQRT_ALL                                                      \
    case CFN_BUILT_IN_SQRTF:                                                   \
    case CFN_BUILT_IN_SQRT:                                                    \
    case CFN_BUILT_IN_SQRTL:                                                   \
    case CFN_BUILT_IN_SQRTF16:                                                 \
    case CFN_BUILT_IN_SQRTF32:                                                 \
    case CFN_BUILT_IN_SQRTF64:                                                 \
    case CFN_BUILT_IN_SQRTF128:                                                \
    case CFN_BUILT_IN_SQRTF32X:                                                \
    case CFN_BUILT_IN_SQRTF64X:                                                \
    case CFN_BUILT_IN_SQRTF128X
#define CASE_CFN_TAN                                                           \
    case CFN_TAN:                                                              \
    case CFN_BUILT_IN_TANF:                                                    \
    case CFN_BUILT_IN_TAN:                                                     \
    case CFN_BUILT_IN_TANL
#define CASE_CFN_TANH                                                          \
    case CFN_TANH:                                                             \
    case CFN_BUILT_IN_TANHF:                                                   \
    case CFN_BUILT_IN_TANH:                                                    \
    case CFN_BUILT_IN_TANHL
#define CASE_CFN_TGAMMA                                                        \
    case CFN_BUILT_IN_TGAMMAF:                                                 \
    case CFN_BUILT_IN_TGAMMA:                                                  \
    case CFN_BUILT_IN_TGAMMAL
#define CASE_CFN_TRUNC                                                         \
    case CFN_TRUNC:                                                            \
    case CFN_BUILT_IN_TRUNCF:                                                  \
    case CFN_BUILT_IN_TRUNC:                                                   \
    case CFN_BUILT_IN_TRUNCL
#define CASE_CFN_TRUNC_FN                                                      \
    case CFN_BUILT_IN_TRUNCF16:                                                \
    case CFN_BUILT_IN_TRUNCF32:                                                \
    case CFN_BUILT_IN_TRUNCF64:                                                \
    case CFN_BUILT_IN_TRUNCF128:                                               \
    case CFN_BUILT_IN_TRUNCF32X:                                               \
    case CFN_BUILT_IN_TRUNCF64X:                                               \
    case CFN_BUILT_IN_TRUNCF128X
#define CASE_CFN_TRUNC_ALL                                                     \
    case CFN_BUILT_IN_TRUNCF:                                                  \
    case CFN_BUILT_IN_TRUNC:                                                   \
    case CFN_BUILT_IN_TRUNCL:                                                  \
    case CFN_BUILT_IN_TRUNCF16:                                                \
    case CFN_BUILT_IN_TRUNCF32:                                                \
    case CFN_BUILT_IN_TRUNCF64:                                                \
    case CFN_BUILT_IN_TRUNCF128:                                               \
    case CFN_BUILT_IN_TRUNCF32X:                                               \
    case CFN_BUILT_IN_TRUNCF64X:                                               \
    case CFN_BUILT_IN_TRUNCF128X
#define CASE_CFN_Y0                                                            \
    case CFN_BUILT_IN_Y0F:                                                     \
    case CFN_BUILT_IN_Y0:                                                      \
    case CFN_BUILT_IN_Y0L
#define CASE_CFN_Y1                                                            \
    case CFN_BUILT_IN_Y1F:                                                     \
    case CFN_BUILT_IN_Y1:                                                      \
    case CFN_BUILT_IN_Y1L
#define CASE_CFN_YN                                                            \
    case CFN_BUILT_IN_YNF:                                                     \
    case CFN_BUILT_IN_YN:                                                      \
    case CFN_BUILT_IN_YNL
#define CASE_CFN_CABS                                                          \
    case CFN_BUILT_IN_CABSF:                                                   \
    case CFN_BUILT_IN_CABS:                                                    \
    case CFN_BUILT_IN_CABSL
#define CASE_CFN_CACOS                                                         \
    case CFN_BUILT_IN_CACOSF:                                                  \
    case CFN_BUILT_IN_CACOS:                                                   \
    case CFN_BUILT_IN_CACOSL
#define CASE_CFN_CACOSH                                                        \
    case CFN_BUILT_IN_CACOSHF:                                                 \
    case CFN_BUILT_IN_CACOSH:                                                  \
    case CFN_BUILT_IN_CACOSHL
#define CASE_CFN_CARG                                                          \
    case CFN_BUILT_IN_CARGF:                                                   \
    case CFN_BUILT_IN_CARG:                                                    \
    case CFN_BUILT_IN_CARGL
#define CASE_CFN_CASIN                                                         \
    case CFN_BUILT_IN_CASINF:                                                  \
    case CFN_BUILT_IN_CASIN:                                                   \
    case CFN_BUILT_IN_CASINL
#define CASE_CFN_CASINH                                                        \
    case CFN_BUILT_IN_CASINHF:                                                 \
    case CFN_BUILT_IN_CASINH:                                                  \
    case CFN_BUILT_IN_CASINHL
#define CASE_CFN_CATAN                                                         \
    case CFN_BUILT_IN_CATANF:                                                  \
    case CFN_BUILT_IN_CATAN:                                                   \
    case CFN_BUILT_IN_CATANL
#define CASE_CFN_CATANH                                                        \
    case CFN_BUILT_IN_CATANHF:                                                 \
    case CFN_BUILT_IN_CATANH:                                                  \
    case CFN_BUILT_IN_CATANHL
#define CASE_CFN_CCOS                                                          \
    case CFN_BUILT_IN_CCOSF:                                                   \
    case CFN_BUILT_IN_CCOS:                                                    \
    case CFN_BUILT_IN_CCOSL
#define CASE_CFN_CCOSH                                                         \
    case CFN_BUILT_IN_CCOSHF:                                                  \
    case CFN_BUILT_IN_CCOSH:                                                   \
    case CFN_BUILT_IN_CCOSHL
#define CASE_CFN_CEXP                                                          \
    case CFN_BUILT_IN_CEXPF:                                                   \
    case CFN_BUILT_IN_CEXP:                                                    \
    case CFN_BUILT_IN_CEXPL
#define CASE_CFN_CEXPI                                                         \
    case CFN_BUILT_IN_CEXPIF:                                                  \
    case CFN_BUILT_IN_CEXPI:                                                   \
    case CFN_BUILT_IN_CEXPIL
#define CASE_CFN_CIMAG                                                         \
    case CFN_BUILT_IN_CIMAGF:                                                  \
    case CFN_BUILT_IN_CIMAG:                                                   \
    case CFN_BUILT_IN_CIMAGL
#define CASE_CFN_CLOG                                                          \
    case CFN_BUILT_IN_CLOGF:                                                   \
    case CFN_BUILT_IN_CLOG:                                                    \
    case CFN_BUILT_IN_CLOGL
#define CASE_CFN_CLOG10                                                        \
    case CFN_BUILT_IN_CLOG10F:                                                 \
    case CFN_BUILT_IN_CLOG10:                                                  \
    case CFN_BUILT_IN_CLOG10L
#define CASE_CFN_CONJ                                                          \
    case CFN_BUILT_IN_CONJF:                                                   \
    case CFN_BUILT_IN_CONJ:                                                    \
    case CFN_BUILT_IN_CONJL
#define CASE_CFN_CPOW                                                          \
    case CFN_BUILT_IN_CPOWF:                                                   \
    case CFN_BUILT_IN_CPOW:                                                    \
    case CFN_BUILT_IN_CPOWL
#define CASE_CFN_CPROJ                                                         \
    case CFN_BUILT_IN_CPROJF:                                                  \
    case CFN_BUILT_IN_CPROJ:                                                   \
    case CFN_BUILT_IN_CPROJL
#define CASE_CFN_CREAL                                                         \
    case CFN_BUILT_IN_CREALF:                                                  \
    case CFN_BUILT_IN_CREAL:                                                   \
    case CFN_BUILT_IN_CREALL
#define CASE_CFN_CSIN                                                          \
    case CFN_BUILT_IN_CSINF:                                                   \
    case CFN_BUILT_IN_CSIN:                                                    \
    case CFN_BUILT_IN_CSINL
#define CASE_CFN_CSINH                                                         \
    case CFN_BUILT_IN_CSINHF:                                                  \
    case CFN_BUILT_IN_CSINH:                                                   \
    case CFN_BUILT_IN_CSINHL
#define CASE_CFN_CSQRT                                                         \
    case CFN_BUILT_IN_CSQRTF:                                                  \
    case CFN_BUILT_IN_CSQRT:                                                   \
    case CFN_BUILT_IN_CSQRTL
#define CASE_CFN_CTAN                                                          \
    case CFN_BUILT_IN_CTANF:                                                   \
    case CFN_BUILT_IN_CTAN:                                                    \
    case CFN_BUILT_IN_CTANL
#define CASE_CFN_CTANH                                                         \
    case CFN_BUILT_IN_CTANHF:                                                  \
    case CFN_BUILT_IN_CTANH:                                                   \
    case CFN_BUILT_IN_CTANHL
#define CASE_CFN_CLZ                                                           \
    case CFN_CLZ:                                                              \
    case CFN_BUILT_IN_CLZ:                                                     \
    case CFN_BUILT_IN_CLZL:                                                    \
    case CFN_BUILT_IN_CLZLL:                                                   \
    case CFN_BUILT_IN_CLZIMAX
#define CASE_CFN_CTZ                                                           \
    case CFN_CTZ:                                                              \
    case CFN_BUILT_IN_CTZ:                                                     \
    case CFN_BUILT_IN_CTZL:                                                    \
    case CFN_BUILT_IN_CTZLL:                                                   \
    case CFN_BUILT_IN_CTZIMAX
#define CASE_CFN_CLRSB                                                         \
    case CFN_CLRSB:                                                            \
    case CFN_BUILT_IN_CLRSB:                                                   \
    case CFN_BUILT_IN_CLRSBL:                                                  \
    case CFN_BUILT_IN_CLRSBLL:                                                 \
    case CFN_BUILT_IN_CLRSBIMAX
#define CASE_CFN_FFS                                                           \
    case CFN_FFS:                                                              \
    case CFN_BUILT_IN_FFS:                                                     \
    case CFN_BUILT_IN_FFSL:                                                    \
    case CFN_BUILT_IN_FFSLL:                                                   \
    case CFN_BUILT_IN_FFSIMAX
#define CASE_CFN_FINITE                                                        \
    case CFN_BUILT_IN_FINITEF:                                                 \
    case CFN_BUILT_IN_FINITE:                                                  \
    case CFN_BUILT_IN_FINITEL
#define CASE_CFN_ISINF                                                         \
    case CFN_BUILT_IN_ISINFF:                                                  \
    case CFN_BUILT_IN_ISINF:                                                   \
    case CFN_BUILT_IN_ISINFL
#define CASE_CFN_ISNAN                                                         \
    case CFN_BUILT_IN_ISNANF:                                                  \
    case CFN_BUILT_IN_ISNAN:                                                   \
    case CFN_BUILT_IN_ISNANL
#define CASE_CFN_PARITY                                                        \
    case CFN_PARITY:                                                           \
    case CFN_BUILT_IN_PARITY:                                                  \
    case CFN_BUILT_IN_PARITYL:                                                 \
    case CFN_BUILT_IN_PARITYLL:                                                \
    case CFN_BUILT_IN_PARITYIMAX
#define CASE_CFN_POPCOUNT                                                      \
    case CFN_POPCOUNT:                                                         \
    case CFN_BUILT_IN_POPCOUNT:                                                \
    case CFN_BUILT_IN_POPCOUNTL:                                               \
    case CFN_BUILT_IN_POPCOUNTLL:                                              \
    case CFN_BUILT_IN_POPCOUNTIMAX
