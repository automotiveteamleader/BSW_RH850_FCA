/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Smh
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecM_cfg.h
 *   Generation Time: 2018-07-26 12:56:48
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD1800284_D00
 *      Tool Version: DaVinci Configurator (beta) 5.17.51 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#if !defined(__SECM_CFG_H__)
#define __SECM_CFG_H__

#define SEC_CLASS_DDD                         0u
#define SEC_CLASS_C                           1u
#define SEC_CLASS_CCC                         2u
#define SEC_CLASS_VENDOR                      3u
#define SEC_DEVELOPMENT                       1u
#define SEC_PRODUCTION                        2u
#define SEC_ADDRESS                           1u
#define SEC_FILE                              2u
#define SEC_CRC_SPEED_OPTIMIZED               0u
#define SEC_CRC_SIZE_OPTIMIZED                1u
#define SEC_RIPEMD160                         0u
#define SEC_SHA1                              1u
#define SEC_SHA256                            2u
#define SEC_SHA512                            3u
#define SEC_AES128                            0u
#define SEC_AES192                            1u
#define SEC_AES256                            2u
#define SEC_CRC32                             0u
#define SEC_CRC16_CCITT                       1u
#define SEC_CHECKSUM_TYPE_CRC                 0u
#define SEC_CHECKSUM_TYPE_HASH                1u
#define SEC_RSA_KEY_LENGTH_1024               0u
#define SEC_RSA_KEY_LENGTH_1536               1u
#define SEC_RSA_KEY_LENGTH_2048               2u
#define SEC_RSA_KEY_LENGTH_3072               3u
#define SEC_RSA_KEY_LENGTH_4096               4u
#define SEC_SIGNATURE_SCHEME_RSA_V15          0u
#define SEC_SIGNATURE_SCHEME_RSA_PSS          1u
#define SEC_SIGNATURE_SCHEME_ECDSA_CURVE25519 2u

#define SEC_MODE                                    SEC_PRODUCTION 
#define SEC_WATCHDOG_CYCLE_COUNT                    0x00000001UL 
#define SEC_DISABLE_KEY_LOCATION_RAM 
#define SEC_DISABLE_WORKSPACE_EXTERNAL 
#define SEC_ENABLE_WORKSPACE_INTERNAL 
#define SEC_RSA_KEY_LENGTH                          SEC_RSA_KEY_LENGTH_1024 
#define SEC_CRC_TYPE                                SEC_CRC32 
#define SEC_CRC_OPT                                 SEC_CRC_SPEED_OPTIMIZED 
#define SEC_DISABLE_DECRYPTION 
#define SEC_DISABLE_ENCRYPTION 
#define SEC_DECRYPTION_ALGORITHM                    SEC_AES256 
#define SEC_DISABLE_DECRYPTION_KEY_EXTERNAL 
#define SEC_ENABLE_DECRYPTION_KEY_INTERNAL 
#define SEC_ECU_KEY                                 0xFFFFFFFFUL 
#define SEC_KEY_TIMEOUT                             0 
#define SEC_CALL_CYCLE                              10 
#define SEC_DISABLE_SEEDKEY_KEY_EXTERNAL 
#define SEC_ENABLE_SEEDKEY_KEY_INTERNAL 
#define SEC_CHECKSUM_TYPE                           SEC_CHECKSUM_TYPE_CRC 
#define SEC_HASH_ALGORITHM                          SEC_RIPEMD160 
#define SEC_DISABLE_VERIFICATION_DISCRETE_HASH_CALC 
#define SEC_SIGNATURE_SCHEME                        SEC_SIGNATURE_SCHEME_RSA_V15 
#define SEC_DISABLE_SECURITY_CLASS_DDD 
#define SEC_DISABLE_SECURITY_CLASS_C 
#define SEC_ENABLE_SECURITY_CLASS_CCC 
#define SEC_DISABLE_SECURITY_CLASS_VENDOR 
#define SEC_DISABLE_VERIFICATION_KEY_EXTERNAL 
#define SEC_ENABLE_VERIFICATION_KEY_INTERNAL 
#define SEC_SIZE_CHECKSUM_VENDOR                    1 
#define SEC_SECURITY_CLASS_VERIFICATION             SEC_CLASS_CCC 
#define SEC_SECURITY_CLASS                          SEC_SECURITY_CLASS_VERIFICATION 
#define SEC_MEMORY_ACCESS                           SEC_ADDRESS 
#define SEC_VERIFY_BYTES                            64 
#define SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH 
#define SEC_DISABLE_CRC_TOTAL 
#define SEC_DISABLE_CRC_WRITTEN 
#define SEC_DISABLE_VENDOR_CHECKSUM 
#define SEC_VER_SIG_OFFSET                          2 
#define SEC_VER_CRC_OFFSET                          0 
#define SEC_DISABLE_VERIFICATION_ASSERT_READ_COUNT 
#define SEC_DISABLE_VERIFICATION_RANGE_CHECK 
#define SEC_DISABLE_VERIFICATION_WRAPPER 
#define SEC_VER_MAX_CONFIG_COUNT                    4 
#define SEC_SECURITY_CLASS_VERIFY                   SEC_CLASS_CCC 
#define SEC_DISABLE_VERIFICATION_DATA_LENGTH 



#endif /* __SECM_CFG_H__ */

