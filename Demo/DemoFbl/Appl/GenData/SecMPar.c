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
 *              File: SecMPar.c
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


#include "Sec_Inc.h"

#define SECMPAR_START_SEC_DATA
#include "MemMap.h"

/* Public verification key exponent */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 SecM_RsaExp[2] = {0x9DU, 0x85U}; /* Verification key exponent */

/* Public verification key modulus */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 SecM_RsaMod[128] = {0xF7U, 0x24U, 0x2FU, 0x3BU, 0xB8U, 0x69U, 0x7EU, 0xE5U, 0xC3U, 0xACU, 0xAFU, 0x80U, 0x0BU, 0xA1U, 0xC8U, 0x4EU, 0x3CU, 0x89U, 0xEAU, 0x37U, 0x39U, 0x87U, 0x07U, 0x3DU, 0x97U, 0x1EU, 0x91U, 0xF8U, 0x3AU, 0xD4U, 0x36U, 0xF6U, 0x09U, 0xBBU, 0xBBU, 0x8FU, 0xBFU, 0x25U, 0x03U, 0x98U, 0x86U, 0x0BU, 0xB2U, 0x0CU, 0x63U, 0x0BU, 0xA1U, 0x24U, 0xD9U, 0x34U, 0x8BU, 0xE0U, 0xBAU, 0x61U, 0xF9U, 0x43U, 0x66U, 0x21U, 0x20U, 0x5EU, 0x02U, 0x89U, 0xAEU, 0x23U, 0x8DU, 0xDAU, 0xBDU, 0x16U, 0xEBU, 0xB7U, 0x15U, 0xEAU, 0x85U, 0xDDU, 0xB9U, 0x88U, 0xCCU, 0x31U, 0xD3U, 0x74U, 0xD7U, 0xC5U, 0x80U, 0x0AU, 0x74U, 0xF6U, 0xDAU, 0x68U, 0x11U, 0x06U, 0xD0U, 0xA6U, 0x3DU, 0x50U, 0xBAU, 0x1FU, 0xEAU, 0x4FU, 0xC2U, 0x02U, 0x95U, 0x0FU, 0x58U, 0x2EU, 0x12U, 0xE0U, 0xBAU, 0xF6U, 0xFFU, 0xE0U, 0xF4U, 0xC5U, 0xE2U, 0x76U, 0xA5U, 0xAAU, 0xDAU, 0xE7U, 0xB8U, 0x77U, 0x34U, 0x76U, 0xD0U, 0x9BU, 0x0BU, 0x88U, 0x3AU, 0x83U}; /* Verification key modulus */

#define SECMPAR_STOP_SEC_DATA
#include "MemMap.h"

