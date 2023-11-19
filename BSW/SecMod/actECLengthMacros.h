/****************************************************************************
 **
 ** $HeadURL: https://subversion/svn/library-ES/branches/library-es/1.2.0-VectorInformatik/development/common/actCLib/local_include/actECLengthMacros.h $
 ** $Revision: 2689 $
 ** $Date: 2018-02-08 13:48:51 +0100 (Do, 08 Feb 2018) $
 ** $Author: mneuhaus $
 **
 ** \copyright(cv cryptovision GmbH, 1999-2018)
 **
 ** \version(cv library/es 1.2)
 **
 ***************************************************************************/

/****************************************************************************
 **
 **     Part of the actCLibrary
 **
 **     Layer: Core Module
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: ECC length information for internal use.
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **   actEC_DOMAIN_WKSP
 **   actEC_TMP_WKSP
 **   actEC_POINT_WKSP
 **   actEC_POINT_AFFINE_WKSP
 **
 **   actEC_BASIC_WKSP
 **   actEC_KG_WKSP
 **   actEC_DHp_WKSP
 **   actEC_DH_WKSP
 **   actEC_DSASp_WKSP
 **   actEC_DSAVp_WKSP
 **
 ** functions:
 **
 ***************************************************************************/


#ifndef     __actECLengthMacros_h__
    #define __actECLengthMacros_h__

    #include "actITypes.h"
    #include "actECPoint.h"


    /* ----------------------------------------------------------------------
     |  the long number scratch required (in actBNDIGIT units)
     |  is calculated from the context input vars:
     |    p_length, n_length
     --------------------------------------------------------------------- */

    /*  ECC domain parameters       */
    /*    p, R^2 in GF(p)           */
    /*    n, R^2 in GF(n)           */
    #define actEC_DOMAIN_WKSP(p_length, n_length)           \
            (2* (p_length) +                                \
             2* (n_length))

    /* temporary long numbers of length (max (p_length, n_length) +1) */
    #define actEC_TMP_WKSP(p_length, n_length)              \
            (actEC_BIGNUM_TMP * (actMax ((n_length), (p_length)) +1))

    /*  Point (projective)          */
    /*   coordinates: X, Y, Z       */
    #define actEC_POINT_WKSP(p_length)                      \
            (3* (p_length))

    /*  Point (affine)              */
    /*   coordinates: X, Y          */
    #define actEC_POINT_AFFINE_WKSP(p_length)               \
            (2* (p_length))

    /*  basic ECC work space        */
    /*    ECC domain parameters     */
    /*    temporary long numbers    */
    #define actEC_BASIC_WKSP(p_length, n_length)            \
            (actEC_DOMAIN_WKSP ((p_length), (n_length)) +   \
             actEC_TMP_WKSP ((p_length), (n_length)))


    /*  key-generation work space   */
    /*    basic ECC work space      */
    /*    d                         */
    /*    Q = d * G                 */
    /*    G (pre-computed X & Y)    */
    #define actEC_KG_WKSP(p_length, n_length)               \
            (actEC_BASIC_WKSP ((p_length), (n_length)) +    \
             (n_length) +                                   \
             actEC_POINT_WKSP (p_length) +                  \
             actEC_POINT_AFFINE_WKSP (p_length))

    /*  EC-D/H (prim.) work space   */
    /*    basic ECC work space      */
    /*    d (own private key)       */
    /*    Q (others public key)     */
    /*    d * Q                     */
    #define actEC_DHp_WKSP(p_length, n_length)              \
            (actEC_BASIC_WKSP ((p_length), (n_length)) +    \
             (n_length) +                                   \
             actEC_POINT_AFFINE_WKSP (p_length) +           \
             actEC_POINT_WKSP (p_length))

    /*  EC-D/H work space           */
    /*    D/H (prim) work space     */
    /*    common secret             */
    #define actEC_DH_WKSP(p_length, n_length)               \
            (actEC_DHp_WKSP((p_length), (n_length)) +       \
             (p_length))

    /*  signature work space        */
    /*    basic ECC work space      */
    /*    e, d, r, s                */
    /*    k                         */
    /*    Q = (k * G)               */
    /*    G (pre-computed X & Y)    */
    #define actEC_DSASp_WKSP(p_length, n_length)            \
            (actEC_BASIC_WKSP ((p_length), (n_length)) +    \
             4* (n_length) +                                \
             1* (n_length) +                                \
             actEC_POINT_WKSP (p_length) +                  \
             actEC_POINT_AFFINE_WKSP (p_length))

    /*  verification work space     */
    /*    basic ECC work space      */
    /*    e, r, s                   */
    /*    Q                         */
    /*    u1, u2                    */
    /*    G                         */
    /*    (G+Q), (u1*G + u2*Q)      */
    #define actEC_DSAVp_WKSP(p_length, n_length)            \
            (actEC_BASIC_WKSP ((p_length), (n_length)) +    \
             3* (n_length) +                                \
             1* actEC_POINT_AFFINE_WKSP (p_length) +        \
             2* ((n_length) +1) +                           \
             1* actEC_POINT_AFFINE_WKSP (p_length) +        \
             2* actEC_POINT_WKSP (p_length))


    /*  EC-B/D work space           */
    /*    basic ECC work space      */
    /*    ai                        */
    /*    Zi = ai * G               */  /* also used for K */
    /*    Xi = (Zi(r) - Zi (l))     */
    /*    TP (temp. point)          */
    #define actEC_BDKA_WKSP(p_length, n_length)             \
            (actEC_BASIC_WKSP ((p_length), (n_length)) +    \
             1* (n_length) +                                \
             actEC_POINT_WKSP (p_length) +                  \
             actEC_POINT_WKSP (p_length) +                  \
             actEC_POINT_WKSP (p_length))

#endif  /*  __actECLengthMacros_h__  */
