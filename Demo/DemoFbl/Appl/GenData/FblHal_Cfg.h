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
 *            Module: FblHal
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblHal_Cfg.h
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


#if !defined(__FBL_HAL_H__)
#define __FBL_HAL_H__

/* FblHal__base ******************************************************************************************************/
#define FBL_FLASH_DISABLE_ECC_SAFE_READ 
#define FLASH_SIZE                      6700 
#define FBL_TIMER_RELOAD_VALUE          19999 
#define FBL_TIMER_PRESCALER_VALUE       0 

/* Derivative Specific Defines */
#define V_COMP_GHS
#define V_COMP_GHS_RH850
#define C_COMP_GHS_RH850_MCAN
#define V_CPU_RH850
#define C_CPUTYPE_32BIT
#define C_CPUTYPE_LITTLEENDIAN
#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#define VGEN_ENABLE_CANFBL
#define V_ENABLE_CAN_ASR_ABSTRACTION
#define C_PROCESSOR_P1M_C
#define V_PROCESSOR_P1M_C

/* FblHal_Rh850 ******************************************************************************************************/
#define FBL_SYSTEM_FREQUENCY 80 



#endif /* __FBL_HAL_H__ */

