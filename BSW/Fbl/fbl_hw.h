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
 *                         Ach     ESCAN00086967    No changes
 *                                 ESCAN00087164    Reworked CAN memory handling
 *  01.04.00   2016-02-01  TnS     ESCAN00087576    Replacement of unlock sequence for Traveo pin configuration
 *  01.05.00   2016-03-01  QPs     ESCAN00088688    Added support for Atmel SAMC21x
 *  01.06.00   2016-03-23  ThM     ESCAN00089063    Added context restore macros for use with FblMain 3.xx
 *                                 ESCAN00088816    No changes
 *  01.07.00   2016-04-15  KJs     ESCAN00089376    No changes
 *  01.08.00   2016-04-27  QPs     ESCAN00089758    Added support for SPC58ECx
 *  01.09.00   2016-10-26  AWh     ESCAN00090796    No changes
 *                                 ESCAN00091228    Add Implementation of FblHwRestoreFblContext() for Traveo
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
 *                                 ESCAN00099686    Add compiler intrinsics macro abstraction
 *  01.14.00   2018-07-03  Ach     ESCAN00099883    No changes
 **********************************************************************************************************************/

#ifndef __FBL_HW_H__
#define __FBL_HW_H__

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#if defined( FBL_USE_OWN_MEMCPY )
#else
# include <string.h>
#endif
#include "fbl_sfr.h"    /* Special function register definition */
/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblDrvCan_Mpc5700McanCrx CQComponent : Implementation */
#define FBLDRVCAN_MPC5700MCANCRX_VERSION          0x0114u
#define FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION  0x00u

/* RI1.1: Reference implementation version */
#define FBLDRVCAN_REFERENCE_IMPLEMENTATION        0x0101u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* PRQA S 0883 1 */ /* MD_FblHwMpc57xx_0883 */
/* Address definition for jump macros */
# define RESETVECT                         0x0u                                            /**< Bootloader startup code */
# define APPLSTART                         (*((volatile vuint32 *)&ApplIntJmpTable[1]))    /**< Startup code of application */
# define FblCheckBootVectTableIsValid()    (((volatile vuint32*)ApplIntJmpTable)[0] == APPLVECT_FROM_BOOT)

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

#if defined( FBL_USE_OWN_MEMCPY )
/* PRQA S 3453, 5013 1 */ /* MD_MSR_19.7, MD_FblHwMpc57xx_5013 */
# define MEMCPY(dst, src, len) FblOwnMemcpy( (void *)(dst), (const void  *)(src), (unsigned int)(len))
#else /* FBL_USE_OWN_MEMCPY */
# define MEMCPY(dst, src, len) memcpy((void *)(dst), (const void *)(src), (size_t)(len))
#endif /* FBL_USE_OWN_MEMCPY */

# define FblInterruptDisable()         __asm("  di")
# define FblInterruptEnable()          __asm("  ei")

#if defined( FBL_ENABLE_FBL_START )
/* Restore base pointer register of FBL context */
#   define FblHwRestoreFblContext() {           \
    /* Restore base pointers of FBL */          \
    __asm(" .extern __tp ");                    \
    __asm(" .extern __gp ");                    \
    /* Initialisation of the global pointer) */ \
    __asm(" movhi hi(__gp),zero,gp");           \
    __asm(" movea lo(__gp),gp,gp");             \
    /* Initialisation of the text pointer*/     \
    __asm(" movhi hi(__tp),zero,tp");           \
    __asm(" movea lo(__tp),tp,tp");             \
                                    }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
#endif /* FBL_ENABLE_FBL_START */

/* FblFlashXXXGetXBytes macros could not be implemented as typecast to 32 Bit
   pointer because of possible misalignment of diag buffer.
   diagPtr must always be 8 Bit pointer
*/
/* Diag buffer access macros */
/* PRQA S 3453 TAG_AddressHandlingMacros */ /* MD_MSR_19.7 */
# define FblArrayTo3Bytes(a)              (((a)[0] << 16u) | ((a)[1] << 8u) | (a)[2])
# define FblFlashAddressGet3Bytes(a)      (tFblAddress)FblArrayTo3Bytes(a)
# define FblDownloadLengthGet3Bytes(a)    (tFblLength)FblArrayTo3Bytes(a)
# define FblArrayTo4Bytes(a)              (((a)[0] << 24u) | ((a)[1] << 16u) | ((a)[2] << 8u) | (a)[3])
# define FblFlashAddressGet4Bytes(a)      (tFblAddress)FblArrayTo4Bytes(a)
# define FblDownloadLengthGet4Bytes(a)    (tFblLength)FblArrayTo4Bytes(a)
/* PRQA L:TAG_AddressHandlingMacros */

/* Timer access macros */

# define FblTimerGet()           ((FBL_STM0STR & 0x0001u) == 0x0001u)
# define FblTimerReset()         {                                                                                \
                                    FBL_STM0TT = 0x1u; /* Stop counter CNT0 */                                    \
                                    FBL_STM0STC = 0x1u; /* Reset compare match flag of compare register (CM0A) */ \
                                    FBL_STM0CNT0L = 0x0u; /* Timer value = 0. Lower 32 Bits of the 64Bit Timer */ \
                                    FBL_STM0CNT0H = 0x0u; /* Timer value = 0. Upper 32 Bits of the 64Bit Timer */ \
                                    FBL_STM0TS = 0x1u; /* Start coJSRunter CNT0 */                                   \
                                 } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define FblTimerStopp()         {                                                        \
                                    FBL_STM0TT = 0x05u; /* Stop counters */               \
                                    FBL_STM0STC = 0x000FFFFFu; /* Clear counter events */ \
                                 } /* PRQA S 3458 */ /* MD_MSR_19.4 */

/*****************************************************************************/
/* Macros for jumps                                                          */
/*****************************************************************************/

/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define JSR(x)          (((void(*)(void))(x))())   /**< Jump to subroutine */

#define JSR_APPL()      JSR(APPLSTART)             /**< Application start */
#define JSR_RESET()     JSR(RESETVECT)             /**< Reset entry */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLHW_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
vuint16 FblGetTimerValue(void);
#define FBLHW_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

void    FblTimerInit( void );

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTAYPE_CAN */

/* Memory access functions */
extern tFblLength FblReadBlock(tFblAddress address, vuint8 *buffer, tFblLength length);
extern vuint8 FblReadByte(tFblAddress address);
# if defined( FBL_USE_OWN_MEMCPY )
#   define MEMCPY_START_SEC_CODE
#   include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* PRQA S 5013 1 */ /* MD_FblHwMpc57xx_5013 */
void* FblOwnMemcpy(void *dest, const void *source, unsigned int count);
#   define MEMCPY_STOP_SEC_CODE
#   include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif  /* FBL_USE_OWN_MEMCPY */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (PLATFORM SPECIFIC)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

# if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

#endif /* __FBL_HW_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_HW.H
 **********************************************************************************************************************/
