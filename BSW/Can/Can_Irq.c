/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* STARTSINGLE_OF_MULTIPLE */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file     Can.c / Can_Irq.c / Can_Local.h
 *  \brief    Implementation of the CAN driver
 *  \details  see functional description below
 *
 *********************************************************************************************************************/
/* ***************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Her          Peter Herrmann            Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Rse          Robert Schelkle           Vector Informatik GmbH
| Huo          Chao Huo                  Vector Informatik GmbH
| Hum          Markus Iversen Huse       Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Version Author Description
| ---------  ------- ------ --------------------------------------------------
| 2012-04-13 1.00.00  Her - Initial revision (alpha version)
| 2012-08-28 1.00.01  Her - Initial revision (beta version )
| 2013-02-01 1.01.00  Her - ESCAN00065098: Initial release version
| 2013-03-18 1.02.00  Her - ESCAN00065594: Additional (High End) features
| 2013-06-03 1.03.00  Her - ESCAN00068062: Rx Dedicated Buffers support
|                     Her - ESCAN00068305: Reduce RAM resource consumption by tailoring the configuration
|                     Her - ESCAN00068956: CAN messages to be transmitted are missing
| 2013-07-26 1.03.80  Her - ESCAN00069335: CAN-FD Bitrate Switching Prototype
| 2013-08-08 1.04.00  Her - ESCAN00069461: Further transmissions are not accepted but a memory violation is reported
|                     Her - ESCAN00069673: Conditional ECC initialization of the embedded CAN Message RAM
|                     Her - ESCAN00069937: GHS support
| 2013-09-27 1.05.00  Her - ESCAN00070770: Use Overrun in Status
|                     Her - ESCAN00070771: Compiler error: "finishRxFullCan" undefined
| 2013-10-17 1.06.00  Her - ESCAN00070952: Support customer specific post initialization
|                     Her - ESCAN00071166: AR4-328: Predefined Runtime Measurement Points
|                     Her - ESCAN00071326: Delayed overrun notification
|                     Her - ESCAN00071493: Message processed in wrong (interrupt or task ) context 
| 2013-11-20 1.07.00  Her - ESCAN00073084: Improvements on derivative handling
| 2014-02-12 1.08.00  Her - ESCAN00073939: Enhanced CAN-FD (Full) support
| 2014-03-17 1.09.00  Her - ESCAN00074327: Support embedded assembler for DiabData
| 2014-06-13 1.10.00  Her - ESCAN00076201: Support MPC5777C derivative
| 2014-10-30 2.00.00  Her - ESCAN00079193: AR4-R11 Update using ComStackLib
| 2015-01-30 2.01.00  Her - ESCAN00079800: Added CBD support (for Traveo derivative)
| 2015-02-20 2.02.00  Her - ESCAN00081372: AR4-R11 Update using ComStackLib (support Spc58xx)
| 2015-03-18 2.02.01  Her - ESCAN00081884: compile error
| 2015-04-02 2.02.02  Her - ESCAN00082190: Power Down (sleep mode) correction
|                     Her - ESCAN00082291: Memory access misalignment exception
| 2015-04-16 2.02.03  Her - ESCAN00082521: Extended Id Type not correct detected
|                     Her - ESCAN00082722: CANbedded only: Memory access misalignment exception
|                     Her - ESCAN00082724: Speed up TxCopyToCan
| 2015-07-06 2.02.04  Her - ESCAN00083815: Tx Confirmation gets lost
|                     Her - ESCAN00088481: Compiler error occurs
| 2015-07-30 2.03.00  Her - ESCAN00084313: Support MCAN Core release 3.1.0 ff.
|                     Her - ESCAN00084515: Use generated FullCAN masks
|                     Her - ESCAN00084650: Support ARM Cortex-Mx Data Memory Barrier
|                     Her - ESCAN00084814: Compiler error due to nested macro construction
| 2015-10-09 2.03.01  Her - ESCAN00085813: Endless loop during reception of messages
| 2015-11-11 2.04.00  Her - ESCAN00086128: Dynamic Rx FullCAN Message filtering failure
|                     Her - ESCAN00086359: Bosch Errata - support of workaround
| 2015-12-02 2.04.01  Her - ESCAN00086934: Support Keil compiler
|                     Her - ESCAN00087003: Missing pre-processor constants
|                     Her - ESCAN00087005: Re-Initialization fails
|                     Her - ESCAN00087056: Erroneous cancel notification
| 2015-12-03 2.05.00  Her - ESCAN00087255: Restructured due to AR4/R14
|                     Her - ESCAN00087256: Compile warning (erratum_013)
| 2016-01-21 2.05.01  Her - ESCAN00087586: Memory overwrite during RAM check
|                     Her - ESCAN00087612: Wrong mailbox checked
| 2016-02-19 2.06.00  Her - ESCAN00088392: Support 8 CAN channels (only Organi affected)
|                     Her - ESCAN00088519: Support more than 255 Dynamic Rx Objects
|                     Her - ESCAN00088756: Reserved bits may only be written with "0"
|                     Her - ESCAN00088813: Incorrect switching between Normal CAN and CAN-FD
|                     Her - ESCAN00089048: Support Mirror Mode (CBD)
|                     Her - ESCAN00089049: Assertion causes compile error
|                     Her - ESCAN00089131: Dynamic Rx objects compile error
| 2016-04-12 2.06.01  Her - ESCAN00089406: AR4/R14 adaptations to AR3
| 2016-04-22 2.06.02  Her - ESCAN00089587: Memory overwrite during RAM check
|                     Her - ESCAN00089610: CAN-ID Rx access macros
| 2016-04-28 2.07.00  Her - ESCAN00089867: MISRA improvements
|            2.08.xx  Her - ESCAN00092200: Will be used for Silent branch
| 2016-06-22 2.09.00  Her - ESCAN00090584: Function call with missing parameter
|                     Her - ESCAN00090761: Generated filter for dynamic Rx objects must be disabled by default
|                     Her - ESCAN00090825: Omit obsolete cancellation delay 
|                     Her - ESCAN00091096: Support AR4/R16
|                     Her - ESCAN00091328: Support Mirror Mode (ASR)
|                     Her - ESCAN00091329: CAN-FD Bit Rate Switch always active
| 2016-08-24 2.10.00  Her - ESCAN00091681: Support dynamic MCAN Revision adaptation
|                     Her - ESCAN00092569: Compiler error: identifier "pduInfo_var_id" is undefined
|                     Her - ESCAN00092315: Compiler warning: function "CanLL_WakeUpHandling" was declared but never referenced
|                     Her - ESCAN00092713: Preprocessor parse error
| 2016-10-28 2.11.00  Pl  - ESCAN00092591: Support Aurix Plus with AR4/R16
| 2016-11-24 2.12.00  Her - ESCAN00092995: CAN-FD message without BRS will not be received
|                     Her - ESCAN00093167: Compiler error "maybe misaligned memory access"
|                     Pl  - ESCAN00093244: CAN Interrupt lock work not correct (Aurix Plus only)
| 2017-01-25 2.13.00  Pl  - ESCAN00093483: CAN communication only possible with channels CAN0, CAN4, CAN8 (Aurix Plus only)
|                     Pl  - ESCAN00093726: Support C_ENABLE_USE_OS_INTERRUPT_CONTROL (Aurix Plus only)
| 2017-02-02 2.13.01  Her - ESCAN00093849: CAN data bytes containing wrong content 
|                     Her - ESCAN00093852: Support Extended ID Masking
| 2017-03-09 2.14.00  Rse - ESCAN00094323: Support TeleChips Tcc802x derivatives for CANbedded
| 2017-04-19 2.14.01  Pl  - ESCAN00094085: Implementation of workaround for MCMCAN_TC.003_EPN Corruption of transmitted CAN Frame
| 2017-05-10 2.15.00  Her - ESCAN00094883: Improper workaround for MCAN Erratum #10 
| 2017-05-11 2.16.00  Her - ESCAN00094518: MCAN SafeBSW Support
| 2017-08-10 2.16.01  Her - STORYC-2289  : FEAT-2738 (silent mode), FEAT-2888 (selective multiplexedTx)
| 2017-08-25 2.17.00  Pl  - STORYC-2250  : M-CAN: Support new platform Telemaco3P with ARM DS5 compiler with CFG5
|                     Her - STORYC-2289  : Support derivatives TCC8021, SAMCA1E for CANbedded
| 2017-09-12 2.20.00  Her - STORYC-2729  : Support derivatives SPC5777M with AR4/R19, MCAN SafeBSW Support
|                     Her - STORYC-2780  : Stop Mode transition behaviour improved
|                     Her - ESCAN00097246: Pending Tx requests block transition to stop mode
|                     Her - ESCAN00097151: Incomplete Mirror Data
| 2017-10-27 2.21.00  Her - STORYC-2729  : MCAN SafeBSW Support (continued and ExtRamCheck Beta)
| 2017-12-01 3.00.00  Pl  - STORYC-3153  : Add infixing to support multiple driver instanced
|                     Her - STORYC-3325  : AR3/GENy adaptation
|                     Huo - ESCAN00098069: Add external PIA
| 2018-01-25 3.01.00  Hum - STORYC-4102  : Support Extended Ram Check
|                     Her - ESCAN00097602: OS assertion "CAN interrupt lost"
|                     Hum - ESCAN00098469: TCF Init enabled regardless of CANCEL_IN_HW
|                     Hum - ESCAN00098470: TDCR write not performed correctly in correspondance with dynamic MCAN revision. CAN_BOSCH_ERRATUM_012
|                     Hum - ESCAN00098467: Missing ampersand in RAM check resulting in a DET error.
| 2018-03-07 3.02.00  Pl  - STORYC-4771  : Support TC38X for Tricore 
|                     Her - ESCAN00098887: static variable "mirrorData" linker section issue, 
|                     Her - ESCAN00098890: use kCanLoopStop instead of kCanLoopSleep (AR3 issue)
| 2018-03-28 3.03.00  Huo - STORYC-4711  : Support TDA3x additional registers
|                     Hum - STORYC-4584  : Infixing improvements
|************************************************************************** */

/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
#define C_DRV_INTERNAL
#define CAN_IRQ_SOURCE     /* testability */

/* PRQA S 0850 EOF */ /* MD_Can_0850 */
/* PRQA S 0828 EOF */ /* MD_Can_0828 */
/* PRQA S 0857 EOF */ /* MD_Can_0857 */

#include "Can.h"
#if defined(V_OSTYPE_OSEK) /* COV_CAN_OS_USAGE */
# include "osek.h"
#endif
/* \trace SPEC-1408 */
#if defined(V_OSTYPE_AUTOSAR) /* COV_CAN_OS_USAGE */
# include "Os.h"
#endif

/* ECO_IGNORE_BLOCK_END */

/***************************************************************************/
/* Version Check                                                           */
/***************************************************************************/
/* \trace SPEC-20329 */
/* not the SW version but all file versions that represent the SW version are checked */
#if (CAN_COREVERSION           != 0x0600u) /* \trace SPEC-1699, SPEC-3837 */
# error "Header file are inconsistent!"
#endif
#if (CAN_RELEASE_COREVERSION   != 0x00u)
# error "Header file are inconsistent!"
#endif
#if( DRVCAN_MPC5700MCANASR_VERSION != 0x0303)
 #error "Source and Header file are inconsistent!"
#endif

#if( DRVCAN_MPC5700MCANASR_RELEASE_VERSION != 0x00)
 #error "Source and Header file are inconsistent!"
#endif

#if defined( CAN_GEN_Mpc5700McanAsr_VERSION )  /* COV_CAN_VERSION_CHECK */
# if( CAN_GEN_Mpc5700McanAsr_VERSION != 0x0100)     /* CFG5 */
#  error "Generated Data are inconsistent!"
# endif
#else
# define CAN_GEN_Mpc5700McanAsr_VERSION          CAN_GEN_MPC5700MCANASR_VERSION
# if( CAN_GEN_MPC5700MCANASR_VERSION != 0x0100)
#  error "Generated Data are inconsistent!"
# endif
#endif

/***************************************************************************/
/* external declarations and compatibility defines                         */
/***************************************************************************/
#if defined(C_ENABLE_MULTI_ECU_CONFIG) /* COV_CAN_MULTI_ECU_CONFIG */
V_DEF_VAR(extern, uint16, VAR_NOINIT) canActiveIdentityMsk; /* PRQA S 3447,3210 */ /* MD_Can_Asr_3447,MD_Can_Asr_Unused */
V_DEF_VAR(extern, uint8, VAR_NOINIT)  canActiveIdentityLog; /* PRQA S 3447,3210 */ /* MD_Can_Asr_3447,MD_Can_Asr_Unused */

# if defined V_ACTIVE_IDENTITY_MSK
#  undef V_ACTIVE_IDENTITY_MSK  /* this define from v_cfg.h is replaced and no more used (but header may included by other module) */ /* PRQA S 0841 */ /* MD_Can_0841 */
# endif
# define V_ACTIVE_IDENTITY_MSK                canActiveIdentityMsk
# if defined V_ACTIVE_IDENTITY_LOG
#  undef V_ACTIVE_IDENTITY_LOG  /* this define from v_cfg.h is replaced and no more used (but header may included by other module) */ /* PRQA S 0841 */ /* MD_Can_0841 */
# endif
# define V_ACTIVE_IDENTITY_LOG                canActiveIdentityLog
#endif

#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
# define CAN_START_SEC_VAR_INIT_UNSPECIFIED  /*-----------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_DEF_P2CONST (extern, Can_ConfigType, VAR_INIT, CONST_PBCFG) Can_ConfigDataPtr; /* PRQA S 3447,3451,3210 */ /* MD_Can_Asr_3447,MD_Can_Asr_3451,MD_Can_Asr_Unused */
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED  /*------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/***************************************************************************/
/* Interrupt Service Routine                                               */
/***************************************************************************/
#define CAN_START_SEC_CODE  /*-----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* \trace SPEC-1579, SPEC-1395, SPEC-1567 */
#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CanPhysToLogChannel_0
# define CanPhysToLogChannelIndex_0
# define CanPhysToLogChannel_1
# define CanPhysToLogChannelIndex_1
# define CanPhysToLogChannel_2
# define CanPhysToLogChannelIndex_2
# define CanPhysToLogChannel_3
# define CanPhysToLogChannelIndex_3
# define CanPhysToLogChannel_4
# define CanPhysToLogChannelIndex_4
#else
# define CanPhysToLogChannel_0       kCanPhysToLogChannelIndex_0
# define CanPhysToLogChannelIndex_0  kCanPhysToLogChannelIndex_0,
# define CanPhysToLogChannel_1       kCanPhysToLogChannelIndex_1
# define CanPhysToLogChannelIndex_1  kCanPhysToLogChannelIndex_1,
# define CanPhysToLogChannel_2       kCanPhysToLogChannelIndex_2
# define CanPhysToLogChannelIndex_2  kCanPhysToLogChannelIndex_2,
# define CanPhysToLogChannel_3       kCanPhysToLogChannelIndex_3
# define CanPhysToLogChannelIndex_3  kCanPhysToLogChannelIndex_3,
# define CanPhysToLogChannel_4       kCanPhysToLogChannelIndex_4
# define CanPhysToLogChannelIndex_4  kCanPhysToLogChannelIndex_4,
#endif

#if !defined(CAN_POSTBUILD_VARIANT_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#if defined(CAN_GEN_COM_STACK_LIB) /* COV_CAN_MICROSAR_VERSION */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
#  define CAN_USE_PHYSTOLOG_MAPPING
# endif
#else
# if defined(C_ENABLE_MULTI_ECU_CONFIG)
#  define CAN_USE_PHYSTOLOG_MAPPING
# endif
#endif

#if defined( C_ENABLE_ISR_MANDATORY )  /* ISR necessary; no pure polling configuration*/
/* **************************************************************************
| NAME:             CanIsr<Name>_0
| CALLED BY:        HLL, ASR: Interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "", "Rx", "Tx", "RxTx", "Wakeup", "Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
************************************************************************** */

/* CODE CATEGORY 1 START */
#   if defined( kCanPhysToLogChannelIndex_0 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
/* CODE CATEGORY 1 START */
#    if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 ) /* COV_CAN_OS_USAGE */
#     if defined (osdIsrCanIsr_0Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_0Cat != 2)
#        error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
ISR( CanIsr_0 )    /* PRQA S 3408 */ /* ISR prototypes must be provided by OSEK header file */
#    else
#     if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_0Cat != 1)
#       error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
#     if defined ( C_ENABLE_ISRVOID )
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_0( void )
#     else
#      if defined(V_COMP_GHS) && !defined(MISRA_CHECK) /* COV_CAN_COMPILER_SWITCH */
#       pragma ghs interrupt
#      endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_0( void )
#     endif
#    endif /* C_ENABLE_OSEK_OS */
{
#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif

#    if defined( CAN_USE_PHYSTOLOG_MAPPING )
    CanInterrupt(Can_GetPhysToLogChannel(0));    /* call Interrupthandling with identity dependend logical channel */
#    else
    CanInterrupt(kCanPhysToLogChannelIndex_0);                      /* call Interrupthandling with logical channel */
#    endif

#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif
} /* END OF CanISR */
#   endif /* (kCanPhysToLogChannelIndex_0) */
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
#   if defined( kCanPhysToLogChannelIndex_1 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
/* CODE CATEGORY 1 START */
#    if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 ) /* COV_CAN_OS_USAGE */
#     if defined (osdIsrCanIsr_1Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_1Cat != 2)
#        error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
ISR( CanIsr_1 )    /* PRQA S 3408 */ /* ISR prototypes must be provided by OSEK header file */
#    else
#     if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_1Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_1Cat != 1)
#       error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
#     if defined ( C_ENABLE_ISRVOID )
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_1( void )
#     else
#      if defined(V_COMP_GHS) && !defined(MISRA_CHECK) /* COV_CAN_COMPILER_SWITCH */
#       pragma ghs interrupt
#      endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_1( void )
#     endif
#    endif /* C_ENABLE_OSEK_OS */
{
#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif

#    if defined( CAN_USE_PHYSTOLOG_MAPPING )
    CanInterrupt(Can_GetPhysToLogChannel(1));    /* call Interrupthandling with identity dependend logical channel */
#    else
    CanInterrupt(kCanPhysToLogChannelIndex_1);                      /* call Interrupthandling with logical channel */
#    endif

#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif
} /* END OF CanISR */
#   endif /* (kCanPhysToLogChannelIndex_1) */
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
#   if defined( kCanPhysToLogChannelIndex_2 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
/* CODE CATEGORY 1 START */
#    if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 ) /* COV_CAN_OS_USAGE */
#     if defined (osdIsrCanIsr_2Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_2Cat != 2)
#        error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
ISR( CanIsr_2 )    /* PRQA S 3408 */ /* ISR prototypes must be provided by OSEK header file */
#    else
#     if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_2Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_2Cat != 1)
#       error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
#     if defined ( C_ENABLE_ISRVOID )
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_2( void )
#     else
#      if defined(V_COMP_GHS) && !defined(MISRA_CHECK) /* COV_CAN_COMPILER_SWITCH */
#       pragma ghs interrupt
#      endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_2( void )
#     endif
#    endif /* C_ENABLE_OSEK_OS */
{
#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif

#    if defined( CAN_USE_PHYSTOLOG_MAPPING )
    CanInterrupt(Can_GetPhysToLogChannel(2));    /* call Interrupthandling with identity dependend logical channel */
#    else
    CanInterrupt(kCanPhysToLogChannelIndex_2);                      /* call Interrupthandling with logical channel */
#    endif

#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif
} /* END OF CanISR */
#   endif /* (kCanPhysToLogChannelIndex_2) */
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
#   if defined( kCanPhysToLogChannelIndex_3 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
/* CODE CATEGORY 1 START */
#    if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 ) /* COV_CAN_OS_USAGE */
#     if defined (osdIsrCanIsr_3Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_3Cat != 2)
#        error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
ISR( CanIsr_3 )    /* PRQA S 3408 */ /* ISR prototypes must be provided by OSEK header file */
#    else
#     if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_3Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_3Cat != 1)
#       error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
#     if defined ( C_ENABLE_ISRVOID )
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_3( void )
#     else
#      if defined(V_COMP_GHS) && !defined(MISRA_CHECK) /* COV_CAN_COMPILER_SWITCH */
#       pragma ghs interrupt
#      endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_3( void )
#     endif
#    endif /* C_ENABLE_OSEK_OS */
{
#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif

#    if defined( CAN_USE_PHYSTOLOG_MAPPING )
    CanInterrupt(Can_GetPhysToLogChannel(3));    /* call Interrupthandling with identity dependend logical channel */
#    else
    CanInterrupt(kCanPhysToLogChannelIndex_3);                      /* call Interrupthandling with logical channel */
#    endif

#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif
} /* END OF CanISR */
#   endif /* (kCanPhysToLogChannelIndex_3) */
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
#   if defined( kCanPhysToLogChannelIndex_4 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
/* CODE CATEGORY 1 START */
#    if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 ) /* COV_CAN_OS_USAGE */
#     if defined (osdIsrCanIsr_4Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_4Cat != 2)
#        error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
ISR( CanIsr_4 )    /* PRQA S 3408 */ /* ISR prototypes must be provided by OSEK header file */
#    else
#     if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_4Cat) /* COV_CAN_OSCAT_CONFIG_CHECK */
#      if (osdIsrCanIsr_4Cat != 1)
#       error "inconsistent configuration of Osek-OS interrupt category between GENy and OIL-configurator (CanIsr)"
#      endif
#     endif
#     if defined ( C_ENABLE_ISRVOID )
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_4( void )
#     else
#      if defined(V_COMP_GHS) && !defined(MISRA_CHECK) /* COV_CAN_COMPILER_SWITCH */
#       pragma ghs interrupt
#      endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_4( void )
#     endif
#    endif /* C_ENABLE_OSEK_OS */
{
#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif

#    if defined( CAN_USE_PHYSTOLOG_MAPPING )
    CanInterrupt(Can_GetPhysToLogChannel(4));    /* call Interrupthandling with identity dependend logical channel */
#    else
    CanInterrupt(kCanPhysToLogChannelIndex_4);                      /* call Interrupthandling with logical channel */
#    endif

#    if !defined(MISRA_CHECK)  /* COV_CAN_MISRA */
#    endif
} /* END OF CanISR */
#   endif /* (kCanPhysToLogChannelIndex_4) */
/* CODE CATEGORY 1 END */

#endif  /* Not a pure polling configuration */

#define CAN_STOP_SEC_CODE  /*------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

