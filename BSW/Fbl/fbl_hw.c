/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Hardware-specific module for:
 *                  NXP MPC57xx / ST SPC57x / NXP Vybrid
 *                  ST SPC58xx
 *                  Spansion Traveo
 *                  Renesas Rh850/P1x-C
 *                  Infineon TC3xx
 *                  Microchip SAMC21/SAMV70/SAMV71
 *                  Broadcom BCM8910x
 *                 Provides the CAN-Interface and timer operations
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Dennis O'Donnell              Dod           Vector North America, Inc.
 *  Torben Stoessel               TnS           Vector Informatik GmbH
 *  Quetty Palacios               QPs           Vector Informatik GmbH
 *  Thomas Mueller                ThM           Vector Informatik GmbH
 *  Johannes Krimmel              KJs           Vector Informatik GmbH
 *  Daniel Koebel                 DKl           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  Sebastian Loos                Shs           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2014-07-18  Ach     -                Initial version
 *  01.01.00   2015-04-30  Ach     ESCAN00082734    Synchronized file with FlexCAN3 1.09.00
 *  01.02.00   2015-06-12  AWh     ESCAN00083227    Add Spansion Traveo
 *  01.02.01   2015-09-25  AWh     ESCAN00085490    No changes
 *  01.03.00   2016-01-28  Dod     ESCAN00085772    Added support for Renesas Rh850/P1x-C
 *                         AWh     ESCAN00086117    No changes
 *                         Ach     ESCAN00086967    Result of start message content check is not returned
 *                                 ESCAN00087164    Reworked CAN memory handling
 *  01.04.00   2016-02-01  TnS     ESCAN00087576    Replacement of unlock sequence for Traveo pin configuration
 *  01.05.00   2016-03-01  QPs     ESCAN00088688    Added support for Atmel SAMC21x
 *  01.06.00   2016-03-23  ThM     ESCAN00089063    No changes
 *                                 ESCAN00088816    Corrected parameter passing of bit timings for GM
 *  01.07.00   2016-04-15  KJs     ESCAN00089376    No changes
 *  01.08.00   2016-04-27  QPs     ESCAN00089758    Added support for SPC58ECx
 *  01.09.00   2016-10-26  AWh     ESCAN00090796    No changes
 *                                 ESCAN00091228    No changes
 *  01.09.01   2016-11-24  ThM     ESCAN00093004    No changes
 *  01.10.00   2016-12-30  DKl     ESCAN00093431    No changes
 *  01.11.00   2017-10-19  Ach     ESCAN00093985    Synchronize with FlexCAN implementation
 *                                 ESCAN00094027    Support Aurix+
 *                         KJs     ESCAN00096812    Support ATSAMV70/71
 *  01.11.01   2017-11-15  Ach     ESCAN00097217    No changes
 *  01.12.00   2017-12-01  Ach     ESCAN00097588    Adaptions to keep evaluation of switch FBL_ENABLE_BUSTYPE_CAN
 *  01.12.01   2018-05-04  Rie     ESCAN00099314    No changes
 *  01.13.00   2018-05-02  Dod     ESCAN00099284    Added support for BCM8910x
 *             2018-06-14  Shs     ESCAN00099682    No changes
 *                                 ESCAN00099686    No changes
 *  01.14.00   2018-07-03  Ach     ESCAN00099883    Add configuration switches for message RAM parameters
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLDRVCAN_MPC5700MCANCRX_VERSION != 0x0114u ) || \
    ( FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION != 0x00u )
# error "Error in fbl_hw.c: Source and header file are inconsistent!"
#endif
#if ( FBLDRVCAN_MPC5700MCANCRX_VERSION != _FBLDRVCAN_VERSION ) || \
    ( FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION != _FBLDRVCAN_RELEASE_VERSION )
# error "Error in fbl_hw.c: Source and v_ver.h are inconsistent!"
#endif

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TIMER HANDLING FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblTimerInit
 **********************************************************************************************************************/
/*! \brief       Initialize system timer
 **********************************************************************************************************************/
void FblTimerInit( void )
{
   /* CNT0 for 1ms timer
      CNT2 for free running timer */

   /* PRQA S 0303 9 */ /* MD_FblHwMpc57xx_0303 */
   FBL_STM0TT = 0x05u; /* Stop counter CNT0, CNT2 */

   FBL_STM0CKSEL = 0x0u; /* CKSEL0 = 0, CKSEL1 = 0; PCLK is used */
   FBL_STM0CNT0L = 0x0u; /* Timer value = 0. Lower 32 Bits of the 64Bit Timer */
   FBL_STM0CNT0H = 0x0u; /* Timer value = 0. Upper 32 Bits of the 64Bit Timer */
   FBL_STM0CMP0AL = FBL_TIMER_RELOAD_VALUE; /* Lower 32Bit of the compare match register (CM0A) */
   FBL_STM0CMP0AH = 0x0u; /* Upper 32Bit of the compare match register (CM0A) */

   FBL_STM0TS = 0x05u; /* Start counter CNT0, CNT2 */
}

#define FBLHW_RAMCODE_START_SEC_CODE
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  FblGetTimerValue
 **********************************************************************************************************************/
/*! \brief       Returns free running timer value
 *  \pre         Timer must be initialized
 *  \return      Current timer value
 **********************************************************************************************************************/
vuint16 FblGetTimerValue(void)
{
   volatile vuint32 tempCount;

   /* Force 32 Bit access to timer value registers */
   tempCount = FBL_STM0CNT2; /* PRQA S 0303 */ /* MD_FblHwMpc57xx_0303 */

   return (vuint16)(tempCount & 0x0000FFFFul);
}

#define FBLHW_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  MEMORY HANDLING FUNCTIONS
 **********************************************************************************************************************/

# if defined( FBL_USE_OWN_MEMCPY )
#  define MEMCPY_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  FblOwnMemcpy
 **********************************************************************************************************************/
/*! \brief       Copies a given amount of bytes.
 *  \details     This function copies a given amount of bytes. The Bootloader watchdog handling is called during
 *               copying. Can be used instead of a compiler library memcpy if watchdog handling is needed.
 *  \param[out]  dest Pointer to destination
 *  \param[in]   source Pointer to source
 *  \param[in]   count Copy length in Byte
 *  \return      Pointer to destination
 **********************************************************************************************************************/
/* PRQA S 5013 1 */ /* MD_FblHwMpc57xx_5013 */
void* FblOwnMemcpy(void *dest, const void *source, unsigned int count)
{
   vuint8* localDest;
   const vuint8* localSource;
   vuint32 i;

   /* Initialize variables */
   localDest = (vuint8*)dest;
   localSource = (const vuint8*)source;

   for (i = 0u; i < count; i++)
   {
      if ((i & 0x3Fu) == 0u)
      {
         (void)FblLookForWatchdog();
      }
      localDest[i] = localSource[i];
   }

   return dest;
}
#  define MEMCPY_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* FBL_USE_OWN_MEMCPY */

/***********************************************************************************************************************
 *  FblReadByte
 **********************************************************************************************************************/
/*! \brief          This function can be used to read one byte from the given address.
 *  \param[in]      Read address.
 *  \return         Byte at memory location 'address'
 **********************************************************************************************************************/
vuint8 FblReadByte( tFblAddress address )
{
   return *(V_MEMROM1_FAR vuint8 V_MEMROM2_FAR V_MEMROM3 *)address; /* PRQA S 0306 */ /* MD_FblHwMpc57xx_0306 */
}

/***********************************************************************************************************************
 *  FblReadBlock
 **********************************************************************************************************************/
/*! \brief          This function reads a given amount of bytes from an address.
 *  \param[in]      address Memory address to read out
 *  \param[out]     buffer Target buffer
 *  \param[in]      length Number of bytes to read
 *  \return         Number of actually copied bytes
 **********************************************************************************************************************/
tFblLength FblReadBlock( tFblAddress address, vuint8 *buffer, tFblLength length )
{
   (void)MEMCPY(buffer, address, length); /* PRQA S 0306 */ /* MD_FblHwMpc57xx_0306 */
   return length;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (PLATFORM SPECIFIC)
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblHwMpc57xx_2214:
      Reason:     This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
                  be no need to extend the amount of statements, so the current usage is accepted.
      Risk:       Unintended debugging code behavior could result, through adding further statements,
      Prevention: A comment is in place to avoid that further statements are added to the if condition.

   MD_FblHwMpc57xx_0303:
      Reason:     [I] Cast between a pointer to volatile object and an integral type.
      Risk:       No identifiable risk as casts are used to define SFRs here.
      Prevention: No prevention required.

   MD_FblHwMpc57xx_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblHwMpc57xx_0883:
      Reason:     QAC does not recognize #elif statements and concludes that the header file is not protected against
                  repeated inclusion.
      Risk:       The repeated inclusion protection is missing.
      Prevention: Correctness of repeated inclusion protection has to be verified by code inspection.

   MD_FblHwMpc57xx_3109:
      Reason:     Multi-line macros encapsulated in curly brackets to reduce side-effects. Results in empty statement after
                  the closing bracket.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblHwMpc57xx_5013:
      Reason:     Used types should indicate size and signedness in code. Basic types are used here because called
                  memcpy function uses these types as well.
      Risk:       Types are redefined by a different compiler.
      Prevention: Correctness has to be checked during implementation/code review.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_HW.C
 **********************************************************************************************************************/
