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
 *              File: Fbl_Lbt.c
 *   Generation Time: 2018-08-01 10:02:27
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


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable =
{
  FBL_MTAB_MAGIC_FLAG, 
  {
    0x01U
  } /*  Disposability bit field (mandatory/optional)  */ , 
  FBL_MTAB_NO_OF_BLOCKS, 
  {
    {
      0, 
      0x00000000UL /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x00020000UL /*  Block Start Address  */ , 
      0x00030000UL /*  Block Length (End Address = 0x0004FFFFUL)  */ , 
      0x0000U /*  Max Prog Attempts  */ , 
      (tExportFct)SecM_VerifySignature /*  Input Verification  */ , 
      (tExportFct)SecM_VerifySignature /*  Processed Verification  */ , 
      (tExportFct)SecM_VerifySignature /*  Pipelined Verification  */ , 
      (tExportFct)SecM_Verification /*  Output Verification  */ 
    } /*  Name 'DemoAppl', Mandatory  */ 
  }
};

