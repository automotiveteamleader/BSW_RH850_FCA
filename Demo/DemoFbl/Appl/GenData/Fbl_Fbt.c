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
 *              File: Fbl_Fbt.c
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


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[] =
{
  {
    0x00010000UL /*  Flash Bank A Block8 (32KB)  */ , 
    0x00017FFFUL
  }, 
  {
    0x00018000UL /*  Flash Bank A Block9 (32KB)  */ , 
    0x0001FFFFUL
  }, 
  {
    0x00020000UL /*  Flash Bank A Block10 (32KB)  */ , 
    0x00027FFFUL
  }, 
  {
    0x00028000UL /*  Flash Bank A Block11 (32KB)  */ , 
    0x0002FFFFUL
  }, 
  {
    0x00030000UL /*  Flash Bank A Block12 (32KB)  */ , 
    0x00037FFFUL
  }, 
  {
    0x00038000UL /*  Flash Bank A Block13 (32KB)  */ , 
    0x0003FFFFUL
  }, 
  {
    0x00040000UL /*  Flash Bank A Block14 (32KB)  */ , 
    0x00047FFFUL
  }, 
  {
    0x00048000UL /*  Flash Bank A Block15 (32KB)  */ , 
    0x0004FFFFUL
  }, 
  {
    0x00050000UL /*  Flash Bank A Block16-17 (64KB)  */ , 
    0x0005FFFFUL
  }, 
  {
    0x00060000UL /*  Flash Bank A Block18-19 (64KB)  */ , 
    0x0006FFFFUL
  }, 
  {
    0x00070000UL /*  Flash Bank A Block20-21 (64KB)  */ , 
    0x0007FFFFUL
  }, 
  {
    0x00080000UL /*  Flash Bank A Block22-23 (64KB)  */ , 
    0x0008FFFFUL
  }, 
  {
    0x00090000UL /*  Flash Bank A Block24-25 (64KB)  */ , 
    0x0009FFFFUL
  }, 
  {
    0x000A0000UL /*  Flash Bank A Block26-27 (64KB)  */ , 
    0x000AFFFFUL
  }, 
  {
    0x000B0000UL /*  Flash Bank A Block28-29 (64KB)  */ , 
    0x000BFFFFUL
  }, 
  {
    0x000C0000UL /*  Flash Bank A Block30-31 (64KB)  */ , 
    0x000CFFFFUL
  }, 
  {
    0x000D0000UL /*  Flash Bank A Block32-33 (64KB)  */ , 
    0x000DFFFFUL
  }, 
  {
    0x000E0000UL /*  Flash Bank A Block34-35 (64KB)  */ , 
    0x000EFFFFUL
  }, 
  {
    0x000F0000UL /*  Flash Bank A Block36-37 (64KB)  */ , 
    0x000FFFFFUL
  }, 
  {
    0x01000000UL /*  Extended User Area (32KB)  */ , 
    0x01007FFFUL
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock = sizeof(FlashBlock) / sizeof(FlashBlock[0]);


/* Try to check consistency between memory device driver
 * header files (e.g. flashdrv.h) and Cfg5 configuration */
#if defined( FLASH_SEGMENT_SIZE )
# if ( FLASH_SEGMENT_SIZE != 256 )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

#if defined( FBL_FLASH_DELETED )
# if ( FBL_FLASH_DELETED != 0xFFU )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif



