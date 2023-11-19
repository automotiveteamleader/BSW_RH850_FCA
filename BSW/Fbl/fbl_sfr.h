/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Register definitions for Renesas RH850/P1x-C
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
 *  Thomas Mueller                ThM           Vector Informatik GmbH
 *  Johannes Krimmel              KJs           Vector Informatik GmbH
 *  Quetty Palacios               QPs           Vector Informatik GmbH
 *  Daniel Koebel                 DKl           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  Sebastian Loos                Shs           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.03.00   2016-01-28  Dod     ESCAN00085772    Initial version
 *                         AWh     ESCAN00086117    No changes
 *                         Ach     ESCAN00086967    No changes
 *                                 ESCAN00087164    No changes
 *  01.04.00   2016-02-01  TnS     ESCAN00087576    No changes
 *  01.05.00   2016-03-01  QPs     ESCAN00088688    No changes
 *  01.06.00   2016-03-23  ThM     ESCAN00089063    No changes
 *                                 ESCAN00088816    No changes
 *  01.07.00   2016-04-15  KJs     ESCAN00089376    No changes
 *  01.08.00   2016-04-27  QPs     ESCAN00089758    No changes
 *  01.09.00   2016-10-26  AWh     ESCAN00090796    No changes
 *                                 ESCAN00091228    No changes
 *  01.09.01   2016-11-24  ThM     ESCAN00093004    No changes
 *  01.10.00   2016-12-30  DKl     ESCAN00093431    Added support for P1x-C derivativ
 *  01.11.00   2017-10-19  Ach     ESCAN00093985    No changes
 *                                 ESCAN00094027    No changes
 *                         KJs     ESCAN00096812    No changes
 *  01.11.01   2017-11-15  Ach     ESCAN00097217    No changes
 *  01.12.00   2017-12-01  Ach     ESCAN00097588    No changes
 *  01.12.01   2018-05-04  Rie     ESCAN00099314    No changes
 *  01.13.00   2018-05-02  Dod     ESCAN00099284    No changes
 *             2018-06-14  Shs     ESCAN00099682    No changes
 *                                 ESCAN00099686    No changes
 *  01.14.00   2018-07-03  Ach     ESCAN00099883    No changes
 **********************************************************************************************************************/
#ifndef __FBL_SFR_H__
#define __FBL_SFR_H__

/* PRQA S 3453 TAG_SfrDefinitionMacros */ /* MD_MSR_19.7 */

/* ---- Clock Generation and PLL related section -------------------------------------------------------------------- */
#define FBL_CLKD0DIV   (*(volatile vuint32*)0xFFF88800ul)  /**< Clock divider 0 divisor register */
#define FBL_CLKD0STAT  (*(volatile vuint32*)0xFFF88804ul)  /**< Clock divider 0 status register */
#define FBL_CLKD1DIV   (*(volatile vuint32*)0xFFF88808ul)  /**< Clock divider 1 divisor register */
#define FBL_CLKD1STAT  (*(volatile vuint32*)0xFFF8880Cul)  /**< Clock divider 1 status register */
#define FBL_CKSC0C     (*(volatile vuint32*)0xFFF89000ul)  /**< Clock selector 0 control register */
#define FBL_CKSC0S     (*(volatile vuint32*)0xFFF89008ul)  /**< Clock selector 0 status register */

/* Flash related registers ------------------------------------------------------------------------------------------ */
#define FBL_FLMDCNT    (*(volatile vuint32*)0xFFA00000ul)  /**< FLMD cnt register */
#define FBL_FLMDPCMD   (*(volatile vuint32*)0xFFA00004ul)  /**< FLMD protection command register */
#define FBL_FLMDPS     (*(volatile vuint32*)0xFFA00008ul)  /**< FLMD protection error status register */

/* System Error Notification Setting Registers ----------------------------------------------------- */
#define FBL_SEG_CONT   (*(volatile vuint16*)0xFFFEE980ul)  /**< Error Notification Control Register */
#define FBL_SEG_FLAG   (*(volatile vuint16*)0xFFFEE982ul)  /**< Error Occurence Retention Registers */

/* Code flash ECC flag positions in SEG_CONT and SEG_FLAG registers */
#define kSegContRome   0x0010u                             /**< VCIE Flag */
#define kSegFlagRomf   0x0010u                             /**< VCIF Flag */

/* Code Flash ECC related registers --------------------------------------------------------------------------------- */
#define kEccProtWrite            0x4000u
#define kEccNotificationDisable  0x00u
#define kEccCorrectionDisable    0x0002u
#define kEccClearErrorSed        0x0Fu
#define kEccClearErrorDed        0x01u
#define kEccUncorrectableError   0x0001u

/* Configure only ECC safe read relevant registers - Bootloader specific handling */
#define FBL_CODE_FLASH_ECC_ERRINT       (*(volatile tFblEccErrInt*) 0xFFC62000ul)  /**< Code flash ECC error information control register (UCFERRINT) */
#define FBL_CODE_FLASH_ECC_UCFSERSTCLR  (*(volatile vuint32*)       0xFFC62004ul)  /**< Code flash ECC SED status clear register */
#define FBL_CODE_FLASH_ECC_UCFDERSTCLR  (*(volatile vuint32*)       0xFFC62008ul)  /**< Code flash ECC DED/Address parity error status clear register */
#define FBL_CODE_FLASH_ECC_FSTERSTR     (*(volatile vuint32*)       0xFFC62030ul)  /**< Code flash ECC DED/Address parity error status register (UCFDERSTR) */
#define FBL_CODE_FLASH_ECC_CTL          (*(volatile tFblEccCtl*)    0xFFC62400ul)  /**< Code flash ECC control register (CFECCCTL_PE1) */

/* FBL_CODE_FLASH_ECC_ERROR_CLEAR clears error status, error overflow and error address */
#define FBL_CODE_FLASH_ECC_ERROR_CLEAR()                    \
   {                                                        \
      FBL_CODE_FLASH_ECC_UCFSERSTCLR = kEccClearErrorSed;   \
      FBL_CODE_FLASH_ECC_UCFDERSTCLR = kEccClearErrorDed;   \
   }  /* PRQA S 3458 */ /* MD_MSR_19.4 */

typedef vuint32 tFblEccCtl;
typedef vuint32 tFblEccErrInt;

/* Flash write/erase enable registers ------------------------------------------------------------------------------- */
#define FBL_FHVE3      (*(volatile vuint32*)0xFFF82410ul)  /**< FHVE3 control register */
#define FBL_FHVE15     (*(volatile vuint32*)0xFFF8A430ul)  /**< FHVE15 control register */

/** Access macro to write to protected register */
#define FBL_PROT_WRITEX(protreg, statreg, reg, val)               \
   {                                                              \
      do                                                          \
      {                                                           \
         (protreg) = 0xA5ul; /* unlock protection */              \
         (reg) = (vuint32)(val); /* Write value */                \
         (reg) = FblInvert32Bit(val); /* Write inverse value */   \
         (reg) = (vuint32)(val); /* Write value */                \
      }                                                           \
      /* Repeat until write is succesful */                       \
      while (((statreg) & 0x01u) == 0x01u);                       \
   } /* PRQA S 3458 */ /* MD_MSR_19.4 */

/* FLMDPCMD -> FLMDCNT */ /* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FBL_PROT_WRITE_FLMDCNT(val)  FBL_PROT_WRITEX(FBL_FLMDPCMD, FBL_FLMDPS, FBL_FLMDCNT, val) /* Protected write macro FLMDCNT*/

/* Port registers --------------------------------------------------------------------------------------------------- */
#define FBL_PORTn_base 0xFFC10000ul

/* PRQA S 3453 12 */ /* MD_MSR_19.7 */
#define FBL_P(n)       (*(volatile vuint16*)(FBL_PORTn_base + 0x0000u + ((n)*0x40u))) /**< Pn Port register */
#define FBL_PSR(n)     (*(volatile vuint16*)(FBL_PORTn_base + 0x0004u + ((n)*0x40u))) /**< Pn Port set/reset register */
#define FBL_PNOT(n)    (*(volatile vuint16*)(FBL_PORTn_base + 0x0008u + ((n)*0x40u))) /**< Pn Port NOT register */
#define FBL_PPR(n)     (*(volatile vuint16*)(FBL_PORTn_base + 0x000Cu + ((n)*0x40u))) /**< Pn Port pin read register */
#define FBL_PM(n)      (*(volatile vuint16*)(FBL_PORTn_base + 0x0010u + ((n)*0x40u))) /**< Pn Port mode register */
#define FBL_PMC(n)     (*(volatile vuint16*)(FBL_PORTn_base + 0x0014u + ((n)*0x40u))) /**< Pn Port mode control register */
#define FBL_PFC(n)     (*(volatile vuint16*)(FBL_PORTn_base + 0x0018u + ((n)*0x40u))) /**< Pn Port function control register */
#define FBL_PFCE(n)    (*(volatile vuint16*)(FBL_PORTn_base + 0x001Cu + ((n)*0x40u))) /**< Pn Port function expansion register */
#define FBL_PFCAE(n)   (*(volatile vuint16*)(FBL_PORTn_base + 0x0028u + ((n)*0x40u))) /**< Pn Port function addition expansion register */
#define FBL_PIBC(n)    (*(volatile vuint16*)(FBL_PORTn_base + 0x4000u + ((n)*0x40u))) /**< Pn Port input buffer control register */
#define FBL_PIPC(n)    (*(volatile vuint16*)(FBL_PORTn_base + 0x4008u + ((n)*0x40u))) /**< Pn Port IP control register */
#define FBL_PU(n)      (*(volatile vuint16*)(FBL_PORTn_base + 0x400Cu + ((n)*0x40u))) /**< Pn Pull Up */

/* Timer registers -------------------------------------------------------------------------------------------------- */
/* System Timer STM0 */
#define TIMER_BASE_ADDRESS   (0xFFDD8000ul)                                /**< System timer 0 base address */
#define FBL_STM0CKSEL  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x00ul)) /**< Timer counter source clock selection Register */
#define FBL_STM0TS     (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x10ul)) /**< Timer counter start register */
#define FBL_STM0TT     (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x14ul)) /**< Timer counter stop register */
#define FBL_STM0CSTR   (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x18ul)) /**< Timer counter status register */
#define FBL_STM0STR    (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x20ul)) /**< Timer status register */
#define FBL_STM0STC    (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x24ul)) /**< Timer status clear register */
#define FBL_STM0IS     (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x30ul)) /**< Timer interrupt selection register */
#define FBL_STM0RM     (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x34ul)) /**< Timer SW reset mask Register */
#define FBL_STM0CNT0L  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x40ul)) /**< Timer (CNT0) Counter register L */
#define FBL_STM0CNT0H  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x44ul)) /**< Timer (CNT0) Counter register H */
#define FBL_STM0CMP0AL (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x50ul)) /**< Timer (CNT0) Compare match register AL */
#define FBL_STM0CMP0AH (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x54ul)) /**< Timer (CNT0) Compare match register AH */
#define FBL_STM0CMP0BL (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x58ul)) /**< Timer (CNT0) Compare match register BL */
#define FBL_STM0CMP0BH (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x5Cul)) /**< Timer (CNT0) Compare match register BH */
#define FBL_STM0CMP0CL (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x60ul)) /**< Timer (CNT0) Compare match register CL */
#define FBL_STM0CMP0CH (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x64ul)) /**< Timer (CNT0) Compare match register CH */
#define FBL_STM0CMP0DL (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x68ul)) /**< Timer (CNT0) Compare match register DL */
#define FBL_STM0CMP0DH (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x6Cul)) /**< Timer (CNT0) Compare match register DL */
#define FBL_STM0CNT1   (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x70ul)) /**< Timer (CNT1) Counter register */
#define FBL_STM0CMP1A  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x80ul)) /**< Timer (CNT1) Compare match register A */
#define FBL_STM0CMP1B  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x84ul)) /**< Timer (CNT1) Compare match register B */
#define FBL_STM0CMP1C  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x88ul)) /**< Timer (CNT1) Compare match register C */
#define FBL_STM0CMP1D  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x8Cul)) /**< Timer (CNT1) Compare match register D */
#define FBL_STM0CNT2   (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0x90ul)) /**< Timer (CNT2) Counter register */
#define FBL_STM0CMP2A  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xA0ul)) /**< Timer (CNT2) Compare match register A */
#define FBL_STM0CMP2B  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xA4ul)) /**< Timer (CNT2) Compare match register B */
#define FBL_STM0CMP2C  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xA8ul)) /**< Timer (CNT2) Compare match register C */
#define FBL_STM0CMP2D  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xACul)) /**< Timer (CNT2) Compare match register D */
#define FBL_STM0CNT3   (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xB0ul)) /**< Timer (CNT3) Counter register */
#define FBL_STM0CMP3A  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xC0ul)) /**< Timer (CNT3) Compare match register A */
#define FBL_STM0CMP3B  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xC4ul)) /**< Timer (CNT3) Compare match register B */
#define FBL_STM0CMP3C  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xC8ul)) /**< Timer (CNT3) Compare match register C */
#define FBL_STM0CMP3D  (*(volatile vuint32*)(TIMER_BASE_ADDRESS + 0xCCul)) /**< Timer (CNT3) Compare match register D */

/* Reset cause registers -------------------------------------------------------------------------------------------- */
#define FBL_RESF       (*(volatile vuint32*)0xFFF81000ul)  /**< Reset factor register */
#define FBL_RESFC      (*(volatile vuint32*)0xFFF81008ul)  /**< Reset factor clear register */
#define FBL_SWARESA0   (*(volatile vuint32*)0xFFF81200ul)  /**< Software application reset assertion register */
#define FBL_STAC_LM0   (*(volatile vuint32*)0xFFF81520ul)  /**< RAM init control register for PE1 */

/* Software Reset --------------------------------------------------------------------------------------------------- */
#define FBL_SW_RESET() (FBL_SWARESA0 = 0x00000001ul) /* Cause software reset */

/* Watchdog related registers --------------------------------------------------------------------------------------- */
#define FBL_WDTA0 (0xFFED0000ul) /* WDTA base addresses */

/* WDTA0 */
#define FBL_WDTA0WDTE  (*(volatile vuint8 *)(FBL_WDTA0 + 0x00u)) /**< WDTA enable register */
#define FBL_WDTA0EVAC  (*(volatile vuint8 *)(FBL_WDTA0 + 0x04u)) /**< WDTA enable VAC register */
#define FBL_WDTA0REF   (*(volatile vuint8 *)(FBL_WDTA0 + 0x08u)) /**< WDTA reference value register */
#define FBL_WDTA0MD    (*(volatile vuint8 *)(FBL_WDTA0 + 0x0Cu)) /**< WDTA mode register */

/* Standby registers ------------------------------------------------------------------------------------------------ */
#define STANDBY_BASE_ADDRESS (0xFFF81410ul)
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FBL_MSR_LM(n)  (*(volatile vuint32*)(STANDBY_BASE_ADDRESS + 0x0000u + ((n)*0x100u)))

/* PRQA L:TAG_SfrDefinitionMacros */

#endif /* __FBL_SFR_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_SFR.H
 **********************************************************************************************************************/
