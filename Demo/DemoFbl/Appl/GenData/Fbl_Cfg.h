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
 *            Module: Fbl
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Cfg.h
 *   Generation Time: 2018-08-03 10:16:22
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


#if !defined(__FBL_CFG_H__)
#define __FBL_CFG_H__

/* Global Constant Macros ********************************************************************************************/
#ifndef FBL_USE_DUMMY_FUNCTIONS
#define FBL_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FBL_USE_DUMMY_STATEMENT
#define FBL_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FBL_DUMMY_STATEMENT
#define FBL_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FBL_DUMMY_STATEMENT_CONST
#define FBL_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FBL_ATOMIC_VARIABLE_ACCESS
#define FBL_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FBL_PROCESSOR_RH850_1374
#define FBL_PROCESSOR_RH850_1374
#endif
#ifndef FBL_COMP_GREENHILLS
#define FBL_COMP_GREENHILLS
#endif
#ifndef FBL_GEN_GENERATOR_MSR
#define FBL_GEN_GENERATOR_MSR
#endif
#ifndef FBL_CPUTYPE_BITORDER_LSB2MSB
#define FBL_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FBL_CONFIGURATION_VARIANT_PRECOMPILE
#define FBL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FBL_CONFIGURATION_VARIANT_LINKTIME
#define FBL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FBL_CONFIGURATION_VARIANT
#define FBL_CONFIGURATION_VARIANT FBL_CONFIGURATION_VARIANT_LINKTIME
#endif
#ifndef FBL_POSTBUILD_VARIANT_SUPPORT
#define FBL_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* FblOem__base ******************************************************************************************************/
#define FBL_DISABLE_STAY_IN_BOOT 
#define FBL_USE_OWN_MEMCPY 
#define FBL_WATCHDOG_ON 
#define FBL_WATCHDOG_TIME                        (1 / FBL_REPEAT_CALL_CYCLE) 
#define FBL_HEADER_ADDRESS                       0x00001800UL 
#define FBL_ENABLE_APPL_TIMER_TASK 
#define FBL_ENABLE_APPL_TASK 
#define FBL_DISABLE_APPL_STATE_TASK 
#define SWM_DATA_MAX_NOAR                        10 
#define FBL_DIAG_BUFFER_LENGTH                   4095 
#define FBL_DIAG_TIME_P2MAX                      (50 / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_P3MAX                      (5000 / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DISABLE_SLEEPMODE 
#define FBL_SLEEP_TIME                           300000 
#define FBL_DISABLE_GAP_FILL 
#define kFillChar                                0xFFU 
#define FBL_DISABLE_GATEWAY_SUPPORT 
#define FBL_DISABLE_PRESENCE_PATTERN 
#define FBL_ENABLE_FBL_START 
#define FBL_ENABLE_COMMON_DATA 
#define FBL_ENABLE_RESPONSE_AFTER_RESET 
#define FBL_DISABLE_USERSUBFUNCTION 
#define FBL_ENABLE_USERSERVICE 
#define FBL_DISABLE_USERROUTINE 
#define FBL_DIAG_TIME_S3EXT                      (5000 / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_S3PRG                      (5000 / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_DISABLE_FLASHDRV_DOWNLOAD 
#define FBL_DIAG_ENABLE_FLASHDRV_ROM 
#define FBL_DISABLE_DATA_PROCESSING 
#define FBL_DISABLE_ENCRYPTION_MODE 
#define FBL_DISABLE_COMPRESSION_MODE 
#define FBL_INTEGRATION                          2 
#define FBL_PRODUCTION                           1 
#define FBL_PROJECT_STATE                        FBL_INTEGRATION 
#define FBL_ENABLE_SYSTEM_CHECK 
#define FBL_ENABLE_DEBUG_STATUS 
#define FBL_ENABLE_ASSERTION 
#define FBL_MEM_PROC_BUFFER_SIZE                 256 
#define FBL_MEM_DISABLE_VERIFY_INPUT 
#define FBL_MEM_DISABLE_VERIFY_PROCESSED 
#define FBL_MEM_DISABLE_VERIFY_PIPELINED 
#define FBL_MEM_ENABLE_VERIFY_OUTPUT 
#define FBL_MEM_VERIFY_SEGMENTATION              64 
#define FBL_DISABLE_ADAPTIVE_DATA_TRANSFER_RCRRP 
#define FBL_DISABLE_PIPELINED_PROGRAMMING 
#define FBL_DISABLE_SUSPEND_PROGRAMMING 
#define FBL_MEM_WRITE_SEGMENTATION               256 
#define FBL_ENABLE_UNALIGNED_DATA_TRANSFER 

/* FblHal ************************************************************************************************************/
#include "FblHal_Cfg.h"
/* FblOem_Fca *****************************************************************************************************/
#define FBL_ENABLE_SEC_ACCESS_DELAY 
#define FBL_SEC_ACCESS_DELAY_TIME                       1000 
#define FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS 
#define FBL_APPL_DISABLE_STARTUP_DEPENDENCY_CHECK 

/* User Config File **************************************************************************************************/
/* User Config File Start */
/* Wait time in FBL after abnormal shutdown */
#define FBL_DIAG_BOOT_TIMOUT_COUNTER   25

/* Flash erased detection, skip erase process if logical block is already erased */
#define FBL_ENABLE_FLASH_ERASED_DETECTION

/* Number of bytes in dummy EEPROM / NVM */
#define EEP_BUFFER_SIZE 0x200u

/* Bootmanager */
#define FBL_BM_ENABLE_BOOTMANAGER
extern void _usr_init( void );
#define FBL_STARTUP_ADDR _usr_init

/* User Config File End */


/* User Section ******************************************************************************************************/

#endif /* __FBL_CFG_H__ */

