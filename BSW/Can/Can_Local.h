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

#if !defined(CAN_LOCAL_H)
#define  CAN_LOCAL_H

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/
#include "Can.h"         /* include also all needed types */
/* \trace SPEC-1583 */
#include "SchM_Can.h"

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
/* compatibility defines                                                   */
/***************************************************************************/
#define C_ENABLE_COPY_TX_DATA

#if defined(C_ENABLE_MIXED_ID) || defined(C_ENABLE_EXTENDED_ID)
# define CAN_ID_IDE_MASK            0x80000000UL
# define CAN_ID_FD_MASK             0x40000000UL /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x1FFFFFFFUL
# define CAN_ID_MASK_STD            0x000007FFUL
# define CAN_ID_UNUSED_MASK         0x20000000UL
#else
# define CAN_ID_IDE_MASK            0x0000U
# define CAN_ID_FD_MASK             0x4000U /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x07FFU
# define CAN_ID_MASK_STD            0x07FFU
# define CAN_ID_UNUSED_MASK         0x3800U
#endif
#define kCanAllChannels             ((CanChannelHandle)0xFFU)

#if !defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
# error "Can_Local.h should only be included by Can.c"
#endif
#if defined(kCanNumberOfChannels) /* COV_CAN_COMPATIBILITY */
# undef kCanNumberOfChannels /* may happen for MultiDirverInstance */ /* PRQA S 0841 */ /* MD_Can_0841 */
#endif
/* real amount of controllers in this system (LT and PB) */
#define kCanNumberOfChannels Can_GetControllerMax()
/* if kCanNumberOfChannels used to declare a table/dimension this table has to be generated to be also Link-Time-capable */
/*  -> see ESCAN00028069 controller-amount has to be Link-Time-capable */
#if defined(kCanNumberOfHwChannels) /* COV_CAN_COMPATIBILITY */
# undef kCanNumberOfHwChannels /* may happen for MultiDirverInstance */ /* PRQA S 0841 */ /* MD_Can_0841 */
#endif
/* compatibility to common-can drivers */
/* real amount of controllers in this system (LT and PB) */
#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COM_STACK_LIB */ /* COV_CAN_MICROSAR_VERSION */
#  define kCanNumberOfHwChannels kCanNumberOfChannels
#else
# if ( CAN_COMMON_CAN == STD_ON )
#  define kCanNumberOfHwChannels CAN_GLOBAL_CONFIG(CanHwChannelMax)
# else
#  define kCanNumberOfHwChannels CAN_GLOBAL_CONFIG(CanControllerMax)
# endif
#endif

#if defined( C_SINGLE_RECEIVE_CHANNEL )
/* have to be done here to avoid declaration of "channel" in Can.h */
# define channel                                ((CanChannelHandle)0)
# define canHwChannel                           ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        ((CanChannelHandle)0)
#else
# define channel                                Controller
#  define canHwChannel                          Controller
#  define CAN_HL_HW_CHANNEL_STARTINDEX(ch)      (ch)
#  define CAN_HL_HW_CHANNEL_STOPINDEX(ch)       (ch)
#endif

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) /* COV_CAN_MICROSAR_VERSION */
# if !defined(CAN_EMULATE_SLEEP) /* COV_CAN_COMPATIBILITY */
#  define CAN_EMULATE_SLEEP STD_ON /* always on for AutoSar4 */
# endif
# if !defined(CAN_TRANSITION_CHECK) /* COV_CAN_COMPATIBILITY */
#  define CAN_TRANSITION_CHECK STD_ON /* default may be deactivated by user configuration */
# endif
#else
# if !defined(CAN_EMULATE_SLEEP) /* COV_CAN_COMPATIBILITY */
#  define CAN_EMULATE_SLEEP STD_OFF
# endif
# if !defined(CAN_TRANSITION_CHECK) /* COV_CAN_COMPATIBILITY */
#  define CAN_TRANSITION_CHECK STD_OFF
# endif
#endif
#if !defined(CAN_REINIT_START) /* COV_CAN_COMPATIBILITY */
# define CAN_REINIT_START STD_OFF
#endif

#if !defined(CAN_OS_TICK2MS) /* COV_CAN_COMPATIBILITY */
# if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
#  error "CAN_OS_TICK2MS() should be defined to OS_TICKS2MS_<counterShortName>() macro from OS"
# endif
# define CAN_OS_TICK2MS(tick) (tick) /* used direct by 401 implementation */
#endif
#if !defined(CAN_OS_COUNTER_ID) /* COV_CAN_COMPATIBILITY */
# if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
#  error "CAN_OS_COUNTER_ID should be defined to 'counterShortName' from OS"
# endif
# define CAN_OS_COUNTER_ID CanTimeoutDurationCounterId /* used direct by 401 implementation */
#endif

#if !defined(CAN_RX_BASICCAN_TYPE) /* compatibility Cfg5 to GENy */ /* COV_CAN_COMPATIBILITY */
# define CAN_RX_BASICCAN_TYPE    RxBasicCANType
# define CAN_RX_FULLCAN_TYPE     RxFullCANType
# define CAN_TX_BASICCAN_TYPE    TxBasicCANType
# define CAN_TX_FULLCAN_TYPE     TxFullCANType
# define CAN_UNUSED_CAN_TYPE     UnusedCANType
#endif
#if !defined(CAN_TX_BASICCAN_MUX_TYPE) /* COV_CAN_COMPATIBILITY */
# define CAN_TX_BASICCAN_MUX_TYPE   TxBasicCANType /* not supported in GENy for now */
#endif

#if !defined(CAN_ID_MASK_IN_GENERIC_CALLOUT) /* COV_CAN_COMPATIBILITY */
# define CAN_ID_MASK_IN_GENERIC_CALLOUT (CAN_ID_IDE_MASK | CAN_ID_FD_MASK | CAN_ID_MASK)
/* May be changed to mask out FD-bit: (CAN_ID_IDE_MASK | CAN_ID_MASK) */
#endif

/* MCAN Version */

#if !defined ( CAN_C_ENABLE_MPC5700_MCAN_MAJOR_CREL )     /* MCAN Core Release */
# error "Derivative not defined."
#endif
#if !defined ( C_ENABLE_MPC5700_MCAN_CREL_STEP )          /* COV_CAN_HW_SPECIFIC */
# define C_ENABLE_MPC5700_MCAN_CREL_STEP       0u         /* Step of MCAN Core Release */
#endif
#if !defined ( C_ENABLE_MPC5700_MCAN_CREL_SSTEP )         /* COV_CAN_HW_SPECIFIC */
# define C_ENABLE_MPC5700_MCAN_CREL_SSTEP      0u         /* Sub-Step of MCAN Core Release */
#endif
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() > 3u )    /* COV_CAN_HW_SPECIFIC */
# error "MCAN Revision not supported yet."
#endif

#if defined(CAN_MCAN_REVISION) /* COV_CAN_INTERNAL */
#else
# if(   ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 2u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP() >= 1u ))   /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0321u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 2u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0320u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 1u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP() >= 5u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0315u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 1u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0310u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ))    /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0300u
# elif(   Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 2u )     /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0200u
#  if defined(C_ENABLE_CAN_FD_FULL)                             /* COV_CAN_HW_SPECIFIC */
#   error "This MCAN Revision does not support full CAN-FD!"
#  endif
# elif(   Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 1u )     /* COV_CAN_HW_SPECIFIC */
#  error "This MCAN Revision is no longer supported."
# else
#  error "Unknown MCAN Revision detected."
# endif
#endif /* CAN_MCAN_REVISION */

/* MCAN Errata */
/* Erratum #16:  "Configuration of NBTP.NTSEG2 = '0' not allowed." 
                  Relevant for MCAN Rel. 3.1.0, 3.2.0, 3.2.1    */
# if ( CAN_MCAN_REVISION >= 0x0315u )  /* COV_CAN_HW_SPECIFIC */
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1, 3.1.0 */ 
# if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_011       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.6, 3.0.0, 3.0.1, 3.1.0 */
# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_OFF
# endif

#elif ( CAN_MCAN_REVISION >= 0x0310u )  /* COV_CAN_HW_SPECIFIC */
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1, 3.1.0 */ 
# if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_011       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.6, 3.0.0, 3.0.1, 3.1.0 */
# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_ON
# endif

#else
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_ON
# endif

# if ( CAN_MCAN_REVISION >= 0x0300u )  /* COV_CAN_HW_SPECIFIC */
#  if !defined CAN_BOSCH_ERRATUM_011
#   define CAN_BOSCH_ERRATUM_011      STD_ON
#  endif
# else
#  if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#   define CAN_BOSCH_ERRATUM_011      STD_OFF /* MRAF exists since 3.0.0 */
#  endif
# endif

# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_OFF /* PXHD exists since 3.1.0 */
# endif
#endif

#if !defined( CAN_ECC_INIT_SHM )
# define C_ENABLE_CAN_ECC_INIT_SHM
#else
# if ( CAN_ECC_INIT_SHM == STD_ON )
#  define C_ENABLE_CAN_ECC_INIT_SHM
# endif
#endif

#if( (!defined(C_ENABLE_EXTENDED_ID)) || (defined(C_ENABLE_MIXED_ID)) )
# define C_ENABLE_STD_ID
#endif

#if( (defined( C_ENABLE_GENERATE_FULLCAN_MASK ))  || (defined( C_DISABLE_GENERATE_FULLCAN_MASK )) || (defined( CAN_C_ENABLE_GENERATE_FULLCAN_MASK )) ) /* COV_CAN_GENTOOL_SPECIFIC */
# define C_ENABLE_FULLCAN_FILTER_GENERATION
#else
# error "Inconsistent Generation Tool. Please update GENy DLL Hw_Mpc5700McanCpuCan to version 1.09.00 or later."
#endif

#if !defined (kCanNumberOfStandardFilter) /* COV_CAN_COMPATIBILITY */
# if defined( CAN_SIDFEUSEDOFSIDFC )      /* COV_CAN_COMPATIBILITY */
#  if( CAN_SIDFEUSEDOFSIDFC == STD_ON )
#   define kCanNumberOfStandardFilter  1
#  else
#   define kCanNumberOfStandardFilter  0
#  endif
# else
#  define kCanNumberOfStandardFilter  1  /* GENy */
# endif
#endif

#if !defined (kCanNumberOfExtendedFilter) /* COV_CAN_COMPATIBILITY */
# if defined( CAN_XIDFEUSEDOFXIDFC )      /* COV_CAN_COMPATIBILITY */
#  if( CAN_XIDFEUSEDOFXIDFC == STD_ON )
#   define kCanNumberOfExtendedFilter  1
#  else
#   define kCanNumberOfExtendedFilter  0
#  endif
# else
#  define kCanNumberOfExtendedFilter  1   /* GENy */
# endif
#endif

#if !defined(CAN_STATIC) /* COV_CAN_COMPATIBILITY */
# if defined(STATIC) /* COV_CAN_COMPATIBILITY */
#  define CAN_STATIC  STATIC   /* standard by AutoSar 3.x */
# else
#  define CAN_STATIC  static   /* standard AutoSar 4.x define */
# endif
#endif
#if !defined(CAN_LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
# if defined(LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
#  define CAN_LOCAL_INLINE  LOCAL_INLINE
# else
#  define CAN_LOCAL_INLINE  
# endif
#endif



/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
/* for variable Can_ActiveSendState */
#define CAN_FREE_OBJ                (uint8)0xFF     /* mark objects as free */
#define kCanBufferFree              CAN_FREE_OBJ    /* compatibility for cancel in HW task */
#define CAN_CANCEL_OBJ              (uint8)0xFE     /* mark object as currently cancelling */
#define kCanBufferCancel            CAN_CANCEL_OBJ  /* compatibility for LL cancel interrupt / task */
#define CAN_CANCEL_OBJ_SW           (uint8)0xFD
#define CAN_SEND_OBJ                (uint8)0x01     /* occupied send object */

#if defined(C_ENABLE_CAN_RAM_CHECK)
/* for variable Can_MailboxState */
# define CAN_ENABLE_OBJ             (uint8)0x00     /* enabled mailbox */
# define CAN_DISABLED_OBJ           (uint8)0x01     /* disabled mailbox */
#endif

/* general return values */
#define kCanFailed                  CAN_NOT_OK
#define kCanOk                      CAN_OK
#define kCanNotSupported            CAN_NOT_SUPPORTED
#define kCanRequested               CAN_REQUESTED

#define kCanTrue                    0x01
#define kCanFalse                   0x00

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COM_STACK_LIB */ /* COV_CAN_MICROSAR_VERSION */
# define Can_GetControllerMax()                         Can_GetSizeOfControllerData()

# define Can_GetCanControllerDefaultBaudrate(Index)     Can_GetCanControllerDefaultBaudrateOfControllerConfig(Index)
# define Can_GetCanControllerDefaultBaudrateIdx(Index)  Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(Index)
# if !defined(Can_GetMailboxRxBasicLengthOfControllerConfig) /* If no Object is available ComStackLib do not generate start-stop index */
#  define Can_GetMailboxRxBasicLengthOfControllerConfig(Index) 0
#  define Can_GetMailboxRxBasicStartIdxOfControllerConfig(Index) 0
#  define Can_GetMailboxRxBasicEndIdxOfControllerConfig(Index) 0
# endif
# define Can_GetRxBasicHandleMax(Index)                 Can_GetMailboxRxBasicLengthOfControllerConfig(Index)
# define Can_GetRxBasicHandleStart(Index)               (Can_HwHandleType)Can_GetMailboxRxBasicStartIdxOfControllerConfig(Index)
# define Can_GetRxBasicHandleStop(Index)                (Can_HwHandleType)Can_GetMailboxRxBasicEndIdxOfControllerConfig(Index)
# define Can_GetRxBasicHwStart(Index)                   Can_GetRxBasicHwStartOfControllerConfig(Index)
# define Can_GetRxBasicHwStop(Index)                    Can_GetRxBasicHwStopOfControllerConfig(Index)
# if !defined(Can_GetMailboxRxFullLengthOfControllerConfig)
#  define Can_GetMailboxRxFullLengthOfControllerConfig(Index) 0
#  define Can_GetMailboxRxFullStartIdxOfControllerConfig(Index) 0
#  define Can_GetMailboxRxFullEndIdxOfControllerConfig(Index) 0
# endif
# define Can_GetRxFullHandleMax(Index)                  Can_GetMailboxRxFullLengthOfControllerConfig(Index)
# define Can_GetRxFullHandleStart(Index)                (Can_HwHandleType)Can_GetMailboxRxFullStartIdxOfControllerConfig(Index)
# define Can_GetRxFullHandleStop(Index)                 (Can_HwHandleType)Can_GetMailboxRxFullEndIdxOfControllerConfig(Index)
# define Can_GetRxFullHwStart(Index)                    Can_GetRxFullHwStartOfControllerConfig(Index)
# define Can_GetRxFullHwStop(Index)                     Can_GetRxFullHwStopOfControllerConfig(Index)
# if !defined(Can_GetMailboxTxBasicLengthOfControllerConfig) /* COV_CAN_GENDATA_FAILURE */
#  define Can_GetMailboxTxBasicLengthOfControllerConfig(Index) 0
#  define Can_GetMailboxTxBasicStartIdxOfControllerConfig(Index) 0
#  define Can_GetMailboxTxBasicEndIdxOfControllerConfig(Index) 0
# endif
# define Can_GetTxBasicHandleMax(Index)                 Can_GetMailboxTxBasicLengthOfControllerConfig(Index)
# define Can_GetTxBasicHandleStart(Index)               (Can_HwHandleType)Can_GetMailboxTxBasicStartIdxOfControllerConfig(Index)
# define Can_GetTxBasicHandleStop(Index)                (Can_HwHandleType)Can_GetMailboxTxBasicEndIdxOfControllerConfig(Index)
# define Can_GetTxBasicHwStart(Index)                   Can_GetTxBasicHwStartOfControllerConfig(Index)
# define Can_GetTxBasicHwStop(Index)                    Can_GetTxBasicHwStopOfControllerConfig(Index)
# if !defined(Can_GetMailboxTxFullLengthOfControllerConfig)
#  define Can_GetMailboxTxFullLengthOfControllerConfig(Index) 0
#  define Can_GetMailboxTxFullStartIdxOfControllerConfig(Index) 0
#  define Can_GetMailboxTxFullEndIdxOfControllerConfig(Index) 0
# endif
# define Can_GetTxFullHandleMax(Index)                  Can_GetMailboxTxFullLengthOfControllerConfig(Index)
# define Can_GetTxFullHandleStart(Index)                (Can_HwHandleType)Can_GetMailboxTxFullStartIdxOfControllerConfig(Index)
# define Can_GetTxFullHandleStop(Index)                 (Can_HwHandleType)Can_GetMailboxTxFullEndIdxOfControllerConfig(Index)
# define Can_GetTxFullHwStart(Index)                    Can_GetTxFullHwStartOfControllerConfig(Index)
# define Can_GetTxFullHwStop(Index)                     Can_GetTxFullHwStopOfControllerConfig(Index)
# if !defined(Can_GetMailboxUnusedLengthOfControllerConfig)  /* COV_CAN_GENDATA_FAILURE */
#  define Can_GetMailboxUnusedLengthOfControllerConfig(Index) 0
#  define Can_GetMailboxUnusedStartIdxOfControllerConfig(Index) 0
#  define Can_GetMailboxUnusedEndIdxOfControllerConfig(Index) 0
# endif
# define Can_GetUnusedHandleMax(Index)                  Can_GetMailboxUnusedLengthOfControllerConfig(Index)
# define Can_GetUnusedHandleStart(Index)                (Can_HwHandleType)Can_GetMailboxUnusedStartIdxOfControllerConfig(Index)
# define Can_GetUnusedHandleStop(Index)                 (Can_HwHandleType)Can_GetMailboxUnusedEndIdxOfControllerConfig(Index)
# define Can_GetUnusedHwStart(Index)                    Can_GetUnusedHwStartOfControllerConfig(Index)
# define Can_GetUnusedHwStop(Index)                     Can_GetUnusedHwStopOfControllerConfig(Index)

# define Can_GetDLC_FIFO(Index)                         Can_GetDLC_FIFOOfMailbox(Index)
# define Can_GetHwHandle(Index)                         Can_GetHwHandleOfMailbox(Index)
# define Can_GetIDValue(Index)                          Can_GetIDValueOfMailbox(Index)
# define Can_GetMailboxType(Index)                      Can_GetMailboxTypeOfMailbox(Index)
# define Can_GetMailboxDataLen(Index)                   Can_GetMaxDataLenOfMailbox(Index)
# define Can_GetMailboxFdPadding(Index)                 Can_GetFdPaddingOfMailbox(Index)
# define Can_GetMailboxController(Index)                (CanChannelHandle)Can_GetControllerConfigIdxOfMailbox(Index)

# if defined(CAN_HWOBJINDIVPOLLINGSTART)
#  define Can_GetCanHwObjIndivPolling(ch,Index)          Can_GetHwObjIndivPolling((Can_GetHwObjIndivPollingStart(ch))+(Index))
# else
#  define Can_GetCanHwObjIndivPolling(ch,Index)          Can_GetHwObjIndivPolling((Index))
# endif

# define Can_GetCanToCanIfChannelMapping(Index)          Can_GetCanIfChannelId((Index))

/* VAR */
# define Can_GetLastInitObject(Index)                   Can_GetLastInitObjectOfControllerData(Index)
# define Can_SetLastInitObject(Index,Value)             Can_SetLastInitObjectOfControllerData(Index,Value)
# define Can_GetCanInterruptOldStatus(Index)            Can_GetCanInterruptOldStatusOfControllerData(Index)
# define Can_SetCanInterruptOldStatus(Index,Value)      Can_SetCanInterruptOldStatusOfControllerData(Index,Value)
# define Can_GetCanInterruptCounter(Index)              Can_GetCanInterruptCounterOfControllerData(Index)
# define Can_SetCanInterruptCounter(Index,Value)        Can_SetCanInterruptCounterOfControllerData(Index,Value)
# define Can_IsIsWakeup(Index)                          Can_IsIsWakeupOfControllerData(Index)
# define Can_SetIsWakeup(Index,Value)                   Can_SetIsWakeupOfControllerData(Index,Value)
# define Can_IsIsBusOff(Index)                          Can_IsIsBusOffOfControllerData(Index)
# define Can_SetIsBusOff(Index,Value)                   Can_SetIsBusOffOfControllerData(Index,Value)
# define Can_GetStatusReq(Index)                        Can_GetStatusReqOfControllerData(Index)
# define Can_SetStatusReq(Index,Value)                  Can_SetStatusReqOfControllerData(Index,Value)
# define Can_GetLogStatus(Index)                        Can_GetLogStatusOfControllerData(Index)
# define Can_SetLogStatus(Index,Value)                  Can_SetLogStatusOfControllerData(Index,Value)
# define Can_GetCanLoopTimeout(ch, Index)               (Can_GetLoopTimeoutOfControllerData(ch))[(Index)]
# define Can_IsIsHardwareCanceled(Index)                Can_IsIsHardwareCanceledOfControllerData(Index)
# define Can_SetIsHardwareCanceled(Index,Value)         Can_SetIsHardwareCanceledOfControllerData(Index,Value)
# define Can_GetMirrorModeState(Index)                  Can_GetMirrorModeStateOfControllerData(Index)
# define Can_SetMirrorModeState(Index,Value)            Can_SetMirrorModeStateOfControllerData(Index,Value)
# define Can_GetSilentModeState(Index)                  Can_GetSilentModeStateOfControllerData(Index)
# define Can_SetSilentModeState(Index,Value)            Can_SetSilentModeStateOfControllerData(Index,Value)

# define Can_GetCanTxBasicDataBuffer(ch,muxTx)          (Can_GetTxBasicDataBuffer(ch))[(muxTx)]

# define Can_GetActiveSendPdu(Index)                    Can_GetPduOfActiveSendObject(Index)
# define Can_SetActiveSendPdu(Index,Value)              Can_SetPduOfActiveSendObject(Index,Value)
# define Can_GetActiveSendState(Index)                  Can_GetStateOfActiveSendObject(Index)
# define Can_SetActiveSendState(Index,Value)            Can_SetStateOfActiveSendObject(Index,Value)
# define Can_GetActiveSendPduInfo(Index)                Can_GetPduInfoOfActiveSendObject(Index)
# define Can_GetActiveSendId(Index)                     (Can_GetPduInfoOfActiveSendObject(Index)).id
# define Can_SetActiveSendId(Index,Value)               (Can_GetPduInfoOfActiveSendObject(Index)).id = (Value)
# define Can_GetActiveSendLength(Index)                 (Can_GetPduInfoOfActiveSendObject(Index)).length
# define Can_SetActiveSendLength(Index,Value)           (Can_GetPduInfoOfActiveSendObject(Index)).length = (Value)
# define Can_GetActiveSendSdu(Index)                    (Can_GetPduInfoOfActiveSendObject(Index)).sdu
# define Can_SetActiveSendSdu(Index,Value)              (Can_GetPduInfoOfActiveSendObject(Index)).sdu = (Value)
# define Can_GetActiveSendSwPduHandle(Index)            (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle
# define Can_SetActiveSendSwPduHandle(Index,Value)      (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle = (Value)

#else /* without ComStackLib */

# if defined(CAN_ENABLE_SELECTABLE_PB)
/* \trace SPEC-1727 */
/* Pointer parameter of initialization function used (selectable Post-Build) */
#  define CAN_GLOBAL_CONFIG(x)                          Can_ConfigDataPtr->x      /* PRQA S 3410 */ /* MD_Can_3410 */
#  define CAN_CONTROLLER_CONFIG_INIT                    (Can_ConfigDataPtr->CanControllerConfig_TabPtr)
#  define CAN_CONTROLLER_CONFIG(hwch)                   (Can_ConfigDataPtr->CanControllerConfig_TabPtr[(hwch)])
#  define CAN_MAILBOX                                   (Can_ConfigDataPtr->CanMailbox_TabPtr)
#  define CAN_INIT_OBJ_START_IDX                        (Can_ConfigDataPtr->CanInitObjectStartIndex_TabPtr)
#  define CAN_INIT_OBJ_BAUDRATE                         (Can_ConfigDataPtr->CanInitObjectBaudrate_TabPtr)
#  define CAN_INIT_OBJ_FD_BRS_CONFIG                    (Can_ConfigDataPtr->CanInitObjectFdConfig_TabPtr)
#  define CanHwObjIndivPolling                          (Can_ConfigDataPtr->CanHwObjIndivPolling_TabPtr) /* PRQA S 3436 */ /* MD_Can_3436 */
#  define CAN_PARTIAL_NET                               (Can_ConfigDataPtr->CanPartialNetwork_TabPtr)
/* hardware specific starts here */
#define CanBTP            (Can_ConfigDataPtr->CanBTP_TabPtr)
#define CanFBTP           (Can_ConfigDataPtr->CanFBTP_TabPtr)
#define CanGFC            (Can_ConfigDataPtr->CanGFC_TabPtr)
#if( ((!defined(C_ENABLE_EXTENDED_ID)) || ((defined(C_ENABLE_EXTENDED_ID)) && (defined(C_ENABLE_MIXED_ID)))) )
# define CanSIDFC               (Can_ConfigDataPtr->CanSIDFC_TabPtr)
# define CanSIDFE               (Can_ConfigDataPtr->CanSIDFE_TabPtr) 
# define CanSIDFE_StartIndex    (Can_ConfigDataPtr->CanSIDFE_StartIndex_TabPtr)
#else
# define CanSIDFC               0
# define CanSIDFE               0
# define CanSIDFE_StartIndex    0
#endif
#if defined(C_ENABLE_EXTENDED_ID)
# define CanXIDFC               (Can_ConfigDataPtr->CanXIDFC_TabPtr)
# define CanXIDFE               (Can_ConfigDataPtr->CanXIDFE_TabPtr)
# define CanXIDFE_StartIndex    (Can_ConfigDataPtr->CanXIDFE_StartIndex_TabPtr)
#else
# define CanXIDFC               0
# define CanXIDFE               0
# define CanXIDFE_StartIndex    0
#endif
#define CanXIDAM          (Can_ConfigDataPtr->CanXIDAM_TabPtr)
#define CanRXF0C          (Can_ConfigDataPtr->CanRXF0C_TabPtr)
#if defined( C_ENABLE_MULTIPLE_BASICCAN )
#define CanRXF1C          (Can_ConfigDataPtr->CanRXF1C_TabPtr)
#else
#define CanRXF1C          0
#endif
#define CanTXBC           (Can_ConfigDataPtr->CanTXBC_TabPtr)
# else
/* \trace SPEC-1728 */
/* Pointer parameter of initialization function not used (no selectable Post-Build or Link-Time configuration) */
#  if defined(C_ENABLE_MULTI_ECU_CONFIG) /* COV_CAN_MULTI_ECU_CONFIG */
#   define CAN_GLOBAL_CONFIG(x)                         Can_ConfigDataPtr->x      /* PRQA S 3410 */ /* MD_Can_3410 */
#  else
#   define CAN_GLOBAL_CONFIG(x)                         CanConfig.x               /* PRQA S 3410 */ /* MD_Can_3410 */
#  endif
#  define CAN_CONTROLLER_CONFIG_INIT                    CanControllerConfig
#  define CAN_CONTROLLER_CONFIG(hwch)                   CanControllerConfig[(hwch)]
#  define CAN_MAILBOX                                   CanMailbox
#  define CAN_INIT_OBJ_START_IDX                        CanInitObjectStartIndex
#  define CAN_INIT_OBJ_BAUDRATE                         CanInitObjectBaudrate
#  define CAN_INIT_OBJ_FD_BRS_CONFIG                    CanInitObjectFdConfig
#  define CAN_PARTIAL_NET                               CanPartialNetwork
# endif

/* CONST PB */
# define Can_GetBaseDll_GeneratorVersion()              CAN_GLOBAL_CONFIG(Can_BaseDll_GeneratorVersion)
# define Can_GetPlatformDll_GeneratorVersion()          CAN_GLOBAL_CONFIG(Can_PlatformDll_GeneratorVersion)
# define Can_GetPrecompileCRC()                         CAN_GLOBAL_CONFIG(Can_ePrecompileCRC)
# define Can_GetLinktimeCRC()                           CAN_GLOBAL_CONFIG(Can_eLinktimeCRC)
# define Can_GetIdentitySelected()                      CAN_GLOBAL_CONFIG(IdentitySelected)
# define Can_GetControllerMax()                         CAN_GLOBAL_CONFIG(CanControllerMax)
# define Can_GetHwChannelMax()                          CAN_GLOBAL_CONFIG(CanHwChannelMax)
# define Can_GetMaxRxDataLen()                          CAN_GLOBAL_CONFIG(CanMaxRxDataLen)
# define Can_GetMaxTxDataLen()                          CAN_GLOBAL_CONFIG(CanMaxTxDataLen)
# define Can_GetFinalMagicNumber()                      CAN_GLOBAL_CONFIG(FinalMagicNumber)

# define Can_GetCanControllerDefaultBaudrate(Index)     CAN_CONTROLLER_CONFIG(Index).CanControllerDefaultBaudrate
# define Can_GetCanControllerDefaultBaudrateIdx(Index)  CAN_CONTROLLER_CONFIG(Index).CanControllerDefaultBaudrateIdx
# define Can_GetRxBasicHandleMax(Index)                 CAN_CONTROLLER_CONFIG(Index).RxBasicHandleMax
# define Can_GetRxBasicHandleStart(Index)               CAN_CONTROLLER_CONFIG(Index).RxBasicHandleStart
# define Can_GetRxBasicHandleStop(Index)                CAN_CONTROLLER_CONFIG(Index).RxBasicHandleStop
# define Can_GetRxBasicHwStart(Index)                   CAN_CONTROLLER_CONFIG(Index).RxBasicHwStart
# define Can_GetRxBasicHwStop(Index)                    CAN_CONTROLLER_CONFIG(Index).RxBasicHwStop
# define Can_GetRxFullHandleMax(Index)                  CAN_CONTROLLER_CONFIG(Index).RxFullHandleMax
# define Can_GetRxFullHandleStart(Index)                CAN_CONTROLLER_CONFIG(Index).RxFullHandleStart
# define Can_GetRxFullHandleStop(Index)                 CAN_CONTROLLER_CONFIG(Index).RxFullHandleStop
# define Can_GetRxFullHwStart(Index)                    CAN_CONTROLLER_CONFIG(Index).RxFullHwStart
# define Can_GetRxFullHwStop(Index)                     CAN_CONTROLLER_CONFIG(Index).RxFullHwStop
# define Can_GetTxBasicHandleMax(Index)                 CAN_CONTROLLER_CONFIG(Index).TxBasicHandleMax
# define Can_GetTxBasicHandleStart(Index)               CAN_CONTROLLER_CONFIG(Index).TxBasicHandleStart
# define Can_GetTxBasicHandleStop(Index)                CAN_CONTROLLER_CONFIG(Index).TxBasicHandleStop
# define Can_GetTxBasicHwStart(Index)                   CAN_CONTROLLER_CONFIG(Index).TxBasicHwStart
# define Can_GetTxBasicHwStop(Index)                    CAN_CONTROLLER_CONFIG(Index).TxBasicHwStop
# define Can_GetTxFullHandleMax(Index)                  CAN_CONTROLLER_CONFIG(Index).TxFullHandleMax
# define Can_GetTxFullHandleStart(Index)                CAN_CONTROLLER_CONFIG(Index).TxFullHandleStart
# define Can_GetTxFullHandleStop(Index)                 CAN_CONTROLLER_CONFIG(Index).TxFullHandleStop
# define Can_GetTxFullHwStart(Index)                    CAN_CONTROLLER_CONFIG(Index).TxFullHwStart
# define Can_GetTxFullHwStop(Index)                     CAN_CONTROLLER_CONFIG(Index).TxFullHwStop
# define Can_GetUnusedHandleMax(Index)                  CAN_CONTROLLER_CONFIG(Index).UnusedHandleMax
# define Can_GetUnusedHandleStart(Index)                CAN_CONTROLLER_CONFIG(Index).UnusedHandleStart
# define Can_GetUnusedHandleStop(Index)                 CAN_CONTROLLER_CONFIG(Index).UnusedHandleStop
# define Can_GetUnusedHwStart(Index)                    CAN_CONTROLLER_CONFIG(Index).UnusedHwStart
# define Can_GetUnusedHwStop(Index)                     CAN_CONTROLLER_CONFIG(Index).UnusedHwStop

# define Can_GetDLC_FIFO(Index)                         CAN_MAILBOX[(Index)].DLC_FIFO
# define Can_GetHwHandle(Index)                         CAN_MAILBOX[(Index)].HwHandle
# define Can_GetIDValue(Index)                          CAN_MAILBOX[(Index)].IDValue
# define Can_GetMailboxType(Index)                      CAN_MAILBOX[(Index)].MailboxType
# define Can_GetMailboxDataLen(Index)                   8 /* just for DET check against maximum value - FD-mode2 not supported for GENy */
# define Can_GetMailboxController(Index)                CAN_MAILBOX[(Index)].MsgController

# define Can_GetInitObjectStartIndex(Index)             CAN_INIT_OBJ_START_IDX[(Index)]
# define Can_GetInitObjectBaudrate(Index)               CAN_INIT_OBJ_BAUDRATE[(Index)]
# define Can_GetInitObjectFdBrsConfig(Index)            CAN_INIT_OBJ_FD_BRS_CONFIG[(Index)]

# define Can_GetPartialNetwork(Index)                   CAN_PARTIAL_NET[(Index)] /* only CAN_MSR3 */

# define Can_GetCanHwObjIndivPolling(ch,Index)          CanHwObjIndivPolling[ch][(Index)]

/* CONST */
# define Can_GetWakeupSourceRef(Index)                  CanWakeupSourceRef[(Index)]
# define Can_GetControllerBaudrateConfig(Index)         Can_ControllerBaudrateConfig[(Index)] /* only CAN_MSR40 */
# define Can_GetHwChannelStartIndex(Index)              CanHwChannelStartIndex[(Index)]
# define Can_GetHwChannelToChannel(Index)               CanHwChannelToChannel[(Index)]
# define Can_GetChannelIdentityAssignment(Index)        CanChannelIdentityAssignment[(Index)]
# define Can_GetCanToCanIfChannelMapping(Index)         (Index)
# define Can_GetTxOffsetHwToLog(Index)                  canTxOffsetHwToLog[(Index)]

/* VAR */
# define Can_GetSizeOfRxQueueBuffer()                   kCanRxQueueSize

# define Can_GetActiveSendPdu(Index)                    CanActiveSendPdu[(Index)]
# define Can_SetActiveSendPdu(Index,Value)              CanActiveSendPdu[(Index)] = (Value)
# define Can_GetActiveSendState(Index)                  CanActiveSendState[(Index)]
# define Can_SetActiveSendState(Index,Value)            CanActiveSendState[(Index)] = (Value)
# define Can_GetActiveSendPduInfo(Index)                CanActiveSendId[(Index)]
# define Can_GetActiveSendId(Index)                     CanActiveSendId[(Index)].id
# define Can_SetActiveSendId(Index,Value)               CanActiveSendId[(Index)].id = (Value)
# define Can_GetActiveSendLength(Index)                 CanActiveSendId[(Index)].length
# define Can_SetActiveSendLength(Index,Value)           CanActiveSendId[(Index)].length = (Value)
# define Can_GetActiveSendSdu(Index)                    CanActiveSendId[(Index)].sdu
# define Can_SetActiveSendSdu(Index,Value)              CanActiveSendId[(Index)].sdu = (Value)
# define Can_GetActiveSendSwPduHandle(Index)            CanActiveSendId[(Index)].swPduHandle
# define Can_SetActiveSendSwPduHandle(Index,Value)      CanActiveSendId[(Index)].swPduHandle = (Value)

# define Can_GetLastInitObject(Index)                   lastInitObject[(Index)]
# define Can_SetLastInitObject(Index,Value)             lastInitObject[(Index)] = (Value)
# define Can_GetCanInterruptOldStatus(Index)            canCanInterruptOldStatus[(Index)]
# define Can_SetCanInterruptOldStatus(Index,Value)      canCanInterruptOldStatus[(Index)] = (Value)
# define Can_GetCanInterruptCounter(Index)              canInterruptCounter[(Index)]
# define Can_SetCanInterruptCounter(Index,Value)        canInterruptCounter[(Index)] = (Value)
# define Can_IsIsWakeup(Index)                          (canIsWakeup[(Index)] != FALSE)
# define Can_SetIsWakeup(Index,Value)                   canIsWakeup[(Index)] = (Value)
# define Can_IsIsBusOff(Index)                          (canIsBusOff[(Index)] != FALSE)
# define Can_SetIsBusOff(Index,Value)                   canIsBusOff[(Index)] = (Value)
# define Can_GetStatusReq(Index)                        canStatusReq[(Index)] /* only CAN_MSR4 or RAM_CHECK */
# define Can_SetStatusReq(Index,Value)                  canStatusReq[(Index)] = (Value) /* only CAN_MSR4 or RAM_CHECK */
# define Can_GetLogStatus(Index)                        canStatus[(Index)]
# define Can_SetLogStatus(Index,Value)                  canStatus[(Index)] = (Value)
# define Can_GetCanLoopTimeout(ch, Index)               canLoopTimeout[(ch)][(Index)]
# define Can_IsIsHardwareCanceled(Index)                (canIsHardwareCanceled[(Index)] != FALSE)
# define Can_SetIsHardwareCanceled(Index,Value)         canIsHardwareCanceled[(Index)] = (Value)
# define Can_GetMirrorModeState(Index)                  canMirrorMode[(Index)]             /* GENy will be generated by platforms that support this feature */
# define Can_SetMirrorModeState(Index,Value)            canMirrorMode[(Index)] = (Value)   /* GENy will be generated by platforms that support this feature */
# define Can_GetSilentModeState(Index)                  canSilentMode[(Index)]             /* GENy will be generated by platforms that support this feature */
# define Can_SetSilentModeState(Index,Value)            canSilentMode[(Index)] = (Value)   /* GENy will be generated by platforms that support this feature */
# define Can_GetMailboxState(Index)                     canMailboxState[(Index)] /* only RAM_CHECK */
# define Can_SetMailboxState(Index,Value)               canMailboxState[(Index)] = (Value) /* only RAM_CHECK */

# define Can_GetCanTxBasicDataBuffer(ch,muxTx)          canTxBasicDataBuffer[(ch)][(muxTx)]
# define Can_GetRxQueueInfo()                           (canRxQueueInfo)
# define Can_GetRxQueueBuffer(Index)                    (canRxQueueBuffer[(Index)])
# define Can_IsTimeoutCall(Index)                       (canTimeoutCall[(Index)] != FALSE) /* only CAN_MSR3 */
# define Can_SetTimeoutCall(Index,Value)                canTimeoutCall[(Index)] = (Value)

#endif


/***************************************************************************/
/* Default switches                                                        */
/* Automatic define settings, depending on user configuration in can_cfg.h */
/***************************************************************************/
#define C_HL_ENABLE_OVERRUN_IN_STATUS

#define C_HL_ENABLE_HW_RANGES_FILTER

#define C_HL_ENABLE_IDTYPE_IN_ID


/* if defined (C_HL_ENABLE_IDTYPE_IN_ID) */
/* Specify the ID tables which contain the ID type */
# define C_LL_RX_IDTYPE_TABLE      CanRxId0
# define C_LL_TX_IDTYPE_TABLE      CanTxId0

#define C_HL_DISABLE_DUMMY_FCT_CALL


#define C_HL_ENABLE_TX_MSG_DESTROYED


#define C_HL_DISABLE_CANCEL_IN_HW_TASK   /* anyway disabled, this is checked using the MCAN TOC */


#define C_HL_DISABLE_HW_EXIT_TRANSMIT 

#if defined( C_ENABLE_CAN_RAM_CHECK ) && defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
# define C_HL_ENABLE_LAST_INIT_OBJ
#else
# define C_HL_DISABLE_LAST_INIT_OBJ
#endif

#define C_HL_ENABLE_CAN_IRQ_DISABLE

#define C_HL_DISABLE_ADJUST_RXHANDLE


#define C_HL_DISABLE_REJECT_UNWANTED_IDTYPE

#define C_HL_DISABLE_REJECT_REMOTE_FRAME

#define C_HL_DISABLE_REJECT_REMOTE_FRAME_FULLCAN

#define C_HL_DISABLE_COPROCESSOR_SUPPORT


#define C_ENABLE_DRIVER_STATUS

#define C_HL_ENABLE_RETRANSMIT_FCT

#define C_HL_ENABLE_RETRANSMIT_CONF_ISR

#define C_HL_DISABLE_AVOID_REENTRANT_APPLCANCANCELNOTIFICATION

/* Possibility to disable the prototypes of interrupt service routines in the driver header file */

/* Tx Actual macros for bus mirroring are implemented */
#define C_ENABLE_TX_ACTUAL_MACROS



/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/

#if defined( C_ENABLE_DYNAMIC_MCAN_REVISION )
# define CanGetMcanRevision(ch)         Can_McanRevision[(ch)] /* PRQA S 3453  */ /* MD_Can_3453 */
#endif

#if defined (MISRA_CHECK) /* COV_CAN_MISRA */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptDisable",      0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptRestore",      0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsStop",                 0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsPassive",              0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsWarning",              0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsBusOff",               0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "Cn",                             0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CnX",                            0303           /* MD_Can_0303_HWaccess */
# pragma PRQA_MACRO_MESSAGES_OFF "Shm",                            0303           /* MD_Can_0303_HWaccess */

# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualDLC",                 0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualExtId",               0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualStdId",               0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualIdType",              0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualFdType",              0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_DECODE_DLI",                 0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualExtId",               0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualStdId",               0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              0310           /* MD_Can_0310 */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualFdType",              0310           /* MD_Can_0310 */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0312           /* MD_Can_0312 */

# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_ApplCanTimerStart",        432
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_ApplCanTimerEnd",          432

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualDLC",                 0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualExtId",               0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualStdId",               0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualIdType",              0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualFdType",              0488           /* MD_Can_0488_LL */

# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptDisable",      1006           /* MD_Can_1006_inlineASM */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptRestore",      1006           /* MD_Can_1006_inlineASM */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_SYNCP",                           1006           /* MD_Can_1006_inlineASM */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualData",                0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_DECODE_DLI",                 0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualFdType",              0488           /* MD_Can_0488_LL */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdRaw0",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdRaw1",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualExtId",               3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualStdId",               3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 3305           /* MD_Can_3305_LL */
#endif



/* macros to set DLC and ID in RX-,TX-structures -------------------------- */
/* MK... macros are used by the generation tool to fill the RX and TX structures */
/* In case the IDE bit is located in the ID registers, this bit has to be handled as must match.
   In general, this is done by setting the IDE bit to 0 in the .._MASK_.. macros.
*/

#define MK_RX_RANGE_MASK_IDSTD0(id)   ( MK_STDID0((id)) )
#define MK_RX_RANGE_CODE_IDSTD0(id)   ( MK_STDID0((id)) )
#define MK_RX_RANGE_MASK_IDEXT0(id)   ( MK_EXTID0((id)) & (~(kCanIdTypeExt)) )
#define MK_RX_RANGE_CODE_IDEXT0(id)   ( MK_EXTID0((id)) )
#define MK_STDID0(id)                 (vuint32) (((vuint32)(((vuint32)(id)) << 18))       & 0x1FFC0000u)    /* Tx/Rx-Buffer   */
#define MK_EXTID0(id)                 (vuint32) ((vuint32)((id) | (vuint32)kCanIdTypeExt) & 0x5FFFFFFFu)    /* Tx/Rx-Buffer   */

/* Message Configuration Register:
 * Example C16x:
 * DLC3 DLC2 DLC1 DLC0 Dir Xtd 0 0
 *                      |   |+------------- 0: standard ID; 1: extended ID
 *                      +------------------ 0: receive    ; 1: transmit
*/
#define C_RX_DIR             0x00
#define C_TX_DIR             0x08

#define MK_TX_DLC(dlc)       ((vuint8)((dlc) & 0xF))
#define MK_TX_DLC_EXT(dlc)   ((vuint8)((dlc) & 0xF))

/* extract  DLC from register format to logical format */
#define XT_TX_DLC(dlc)       ((vuint8)((dlc) & 0xF))        /* return code has to be vuint8 */

#if defined( C_SINGLE_RECEIVE_CHANNEL )
/* Bus-Off functions */

# define CanResetBusOffStart(a)  (CanInit(a))
# define CanResetBusOffEnd(a)

/* Bus-Sleep functions */
# define CanResetBusSleep(a)     (CanInit(a))

#else
/* Bus-Off functions */
# define CanResetBusOffStart(ch, a)  (CanInit((ch), (a)))
# define CanResetBusOffEnd(ch, a)
  
/* Bus-Sleep functions */
# define CanResetBusSleep(ch, a)     (CanInit((ch), (a)))
#endif


/* The macros CanRxActualIdRawx() have to provide the register context of the ID registers.
   It is not necessary to mask any bits. These macros are for internal use only and masking
   will be done in can_hls.c
*/                                                 
# define CanRxActualIdRaw0(rxStruct)   ((vuint32)*((CanChipMsgPtr32)((rxStruct)->pChipMsgObj)))

/* Macros for CAN message access within ApplCanMsgReceived() or PreCopy() function */
#if defined( C_ENABLE_EXTENDED_ID )
# define CanRxActualIdExtHi(rxStruct)      ((vuint8) ( *((rxStruct)->pChipMsgObj) >> 24) & 0x1F )    /* return code has to be vuint8 */
# define CanRxActualIdExtMidHi(rxStruct)   ((vuint8) ( *((rxStruct)->pChipMsgObj) >> 16 ))           /* return code has to be vuint8 */
# define CanRxActualIdExtMidLo(rxStruct)   ((vuint8) ( *((rxStruct)->pChipMsgObj) >>  8 ))           /* return code has to be vuint8 */
# define CanRxActualIdExtLo(rxStruct)      ((vuint8) ( *((rxStruct)->pChipMsgObj) ))                 /* return code has to be vuint8 */
#endif
#define CanRxActualExtId(rxStruct)                  ( (vuint32)*((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT))((rxStruct)->pChipMsgObj)) & 0x1FFFFFFFUL)
#define CanRxActualStdId(rxStruct)      (Can_IdType)(((vuint32)*((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT))((rxStruct)->pChipMsgObj)) & 0x1FFC0000UL) >> 18)
#define CanRxActualDLC(rxStruct)        (vuint8)     ((volatile tRXMsg*)((rxStruct)->pChipMsgObj))->R1.DLC  /* PRQA S 0310, 488 */ /* MD_Can_0310, MD_Can_0488_LL */ /* return code has to be vuint8 */
#define CanRxActualFdType(rxStruct)     (vuint8)     ((volatile tRXMsg*)((rxStruct)->pChipMsgObj))->R1.FDF  /* PRQA S 0310, 488 */ /* MD_Can_0310, MD_Can_0488_LL */ /* return code has to be vuint8,
                                                                                                    R1 Bit 21 EDL: 1 = CAN FD frame format (new DLC-coding and CRC)
                                                                                                    R1 Bit 20 BRS: 1 = Frame received with bit rate switching    */
#define CanRxActualData(rxStruct,i)     (vuint8)     (*                     ((rxStruct)->pChipData+(i)) )               /* PRQA S 0310, 488 */ /* MD_Can_0310, MD_Can_0488_LL */ /* return code has to be vuint8 */
#define CanRxActualIdType(rxStruct)     (tCanIdType)((* (volatile vuint32*) ((rxStruct)->pChipMsgObj)) & kCanIdTypeExt) /* PRQA S 0310, 488 */ /* MD_Can_0310, MD_Can_0488_LL */ /* return code has to be tCanIdType */

#if defined (C_CPUTYPE_BITORDER_LSB2MSB) /* COV_CAN_CPUTYPE */
# define CanBswap32(x)                   (vuint32)(x)
#else /* endianess */
# define CanBswap32(x)                   (vuint32)  (( ((vuint32)((x) & 0xFF000000UL)) >> 24) | \
                                                    ( ((vuint32)((x) & 0x00FF0000UL)) >>  8) | \
                                                    ( ((vuint32)((x) & 0x0000FF00UL)) <<  8) | \
                                                    ( ((vuint32)((x) & 0x000000FFUL)) << 24))      /* swap b4-b3-b2-b1 to b1-b2-b3-b4 */
#endif /* endianess */

/* support reading the error counters */
#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CanTxActualErrorCounter()             (vuint8)(((( V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(0)))->ECR)        & 0x000000FFu)
# define CanRxActualErrorCounter()             (vuint8)(((((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(0)))->ECR) >> 8)  & 0x0000007Fu)
#else
# define CanTxActualErrorCounter(ch)           (vuint8)(((( V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(ch)))->ECR)       & 0x000000FFu)
# define CanRxActualErrorCounter(ch)           (vuint8)(((((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(ch)))->ECR) >> 8) & 0x0000007Fu)
#endif /* C_SINGLE_RECEIVE_CHANNEL */

/* Macros for CAN message access within GenericConfirmation() function */
/* *** Only Mirror Mode *** */
#define CanTxActualIdType(txConfStruct)       ((tCanIdType) ( *((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & kCanIdTypeExt))
#define CanTxActualStdId(txConfStruct)        ((Can_IdType) ((*((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & 0x1FFC0000UL) >> 18))
#define CanTxActualExtId(txConfStruct)        ((vuint32)    ( *((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & 0x1FFFFFFFUL))
#define CanTxActualFdType(txConfStruct)       ((vuint8)      ((volatile tTXMsg*)((txConfStruct)->pChipMsgObj))->T1.FDF)
#define CanTxActualDLC(txConfStruct)          ((vuint8)      ((volatile tTXMsg*)((txConfStruct)->pChipMsgObj))->T1.DLC)
#define CanTxActualData(txConfStruct,i)                       *((V_DEF_P2VAR(volatile, vuint8,  AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipData)  +(i))

/* Macros for CAN message access within PreTransmit() function */
#define CanTxWriteActId(txStruct,id)     { *((CanChipMsgPtr32) ((txStruct)->pChipMsgObj)) = MK_STDID0((id)); }            /* PRQA S 3458 */ /* MD_Can_3458 */
#define CanTxWriteActExtId(txStruct,id)  { *((CanChipMsgPtr32) ((txStruct)->pChipMsgObj)) = MK_EXTID0((id)); }            /* PRQA S 3458 */ /* MD_Can_3458 */

#define CanTxWriteActDLC(txStruct,dlc)   { (((volatile tTXMsg*)((txStruct)->pChipMsgObj))->T1.DLC) = ((dlc) & 0x0Fu); }          /* PRQA S 3458 */ /* MD_Can_3458 */



/* Macros for Message and CAN buffer access (mostly used by COM/IL but also available for usage by the application) */
/* Message buffers (for each message ID) */
# define StartRxReadSync()          (VStdSuspendAllInterrupts())
# define EndRxReadSync()            (VStdResumeAllInterrupts())

# define StartRxWriteSync()         (VStdSuspendAllInterrupts())
# define EndRxWriteSync()           (VStdResumeAllInterrupts())

# define StartTxReadSync()
# define EndTxReadSync()

# define StartTxWriteSync()         (VStdSuspendAllInterrupts())
# define EndTxWriteSync()           (VStdResumeAllInterrupts())

/* CAN buffers (for each CAN message object) */
# define StartRxWriteCANSync() 
# define EndRxWriteCANSync()   

# define StartRxReadCANSync()  
# define EndRxReadCANSync()    

# define StartRxFullCANReadSync(Obj)
# define EndRxFullCANReadSync(Obj)

# define StartRxFullCANWriteSync(obj)
# define EndRxFullCANWriteSync(obj)

/* Macros for flag access */
# define CanStartFlagWriteSync()    (VStdSuspendAllInterrupts())
# define CanEndFlagWriteSync()      (VStdResumeAllInterrupts())



#define CAN_HL_MIN(x,y) (((x)>(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */
#define CAN_HL_MAX(x,y) (((x)<(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */

/***************************************************************************************************/
/* Macros for dummy statements */
#if !defined(CAN_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT(x) (x) = (x)
# else
#  define CAN_DUMMY_STATEMENT(x)
# endif
#endif
#if !defined(CAN_DUMMY_STATEMENT_CONST) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT_CONST(x) (void)(x)
# else
#  define CAN_DUMMY_STATEMENT_CONST(x)
# endif
#endif

/***************************************************************************************************/
/* Macros for DET and assertions */
#if (CAN_DEV_ERROR_REPORT == STD_ON) /* \trace SPEC-1404, SPEC-1696, SPEC-3803, SPEC-3849 */
/* \trace SPEC-1725, SPEC-1403, SPEC-1568, SPEC-3781, SPEC-3819 */
# if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) /* COV_CAN_MICROSAR_VERSION */
#  define Can_CallDetReportError(api, err) ((void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, (api), (err)))
# else
#  define Can_CallDetReportError(api, err) (Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, (api), (err)))
# endif
# define assertHardware(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertInternal(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertUser(a, b, c)      if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertGen(a, b, c)       if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define C_ENABLE_HARDWARE_CHECK
# define C_ENABLE_INTERNAL_CHECK
# define C_ENABLE_USER_CHECK
# define C_ENABLE_GEN_CHECK
#else
# define Can_CallDetReportError(api, err)
# define assertHardware(a, b, c)
# define assertInternal(a, b, c)
# define assertUser(a, b, c)
# define assertGen(a, b, c)
#endif
# define CAN_IS_NO_ERROR(errorId)

/***************************************************************************************************/
/* Macros for Critical Area abstraction */
#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) /* COV_CAN_MICROSAR_VERSION */
# define Can_EnterCritical(area)     SchM_Enter_Can_##area() /* PRQA S 0342 */ /* MD_Can_0342 */
# define Can_LeaveCritical(area)     SchM_Exit_Can_##area() /* PRQA S 0342*/ /* MD_Can_0342 */
#else
# define Can_EnterCritical(area)     SchM_Enter_Can(area) /* do not use double brackets here ESCAN00060494 */
# define Can_LeaveCritical(area)     SchM_Exit_Can(area)
#endif

#define CanDeclareGlobalInterruptOldStatus
/* CAN_EXCLUSIVE_AREA_0 called only by LL code */
#define CanSingleGlobalInterruptDisable()     Can_EnterCritical(CAN_EXCLUSIVE_AREA_0)
#define CanSingleGlobalInterruptRestore()     Can_LeaveCritical(CAN_EXCLUSIVE_AREA_0)
#define CanGlobalInterruptDisable()           Can_EnterCritical(CAN_EXCLUSIVE_AREA_0)
#define CanGlobalInterruptRestore()           Can_LeaveCritical(CAN_EXCLUSIVE_AREA_0)
#define CanNestedGlobalInterruptDisable()     Can_EnterCritical(CAN_EXCLUSIVE_AREA_0)
#define CanNestedGlobalInterruptRestore()     Can_LeaveCritical(CAN_EXCLUSIVE_AREA_0)

/* For LL: parameter has to be 'channel' not CAN_CHANNEL_PARA_ONLY */
# define CAN_CAN_INTERRUPT_RESTORE(ch)  Can_EnableControllerInterrupts((uint8)(ch))
# define CAN_CAN_INTERRUPT_DISABLE(ch)  Can_DisableControllerInterrupts((uint8)(ch))

/***************************************************************************************************/
/* Macros for LL-HLL compatibility */


/***************************************************************************/
/* error codes                                                             */
/***************************************************************************/
/* error numbers for User Assertions 0x20-0x3f - hardware depended */

/* error numbers for Generation tool Assertions 0x60-0x7f - hardware depended */

/* error numbers for Hardware Assertions 0xA0-0xBF - hardware dependent */
# define kCanErrorWrongBaseAddress               ((vuint8)0xA0)
# define kCanErrorCanSleepFromReset              ((vuint8)0xA1)
# define kCanErrorMcanRevision                   ((vuint8)0xA2)
# define kCanErrorMcanMessageRAMOverflow         ((vuint8)0xA3)
# define kCanErrorChannelHdlTooLarge             ((vuint8)0xA4)

# define kCanErrorControllerId                   ((vuint8)0xE0)
# define kCanErrorConfirmationHandle             ((vuint8)0xE1)
# define kCanErrorSIDFCMax                       ((vuint8)0xE2)
# define kCanErrorXIDFCMax                       ((vuint8)0xE3)
# define kCanErrorDlcMax                         ((vuint8)0xE4)

/***************************************************************************/
/* Special switches need by CAN driver                                     */
/***************************************************************************/

/***************************************************************************/
/* Defines / data types / structures / unions                              */
/***************************************************************************/
/* Define CAN Chip hardware; segment must be located in locator file    */
/* register layout of the can chip                                      */
/* Structure describing CAN receive buffer. */
/* Note: When the M_CAN addresses the Message RAM it addresses 32-bit words, not single bytes. */

typedef struct sCanRxInfoStruct
{
  CanChipMsgPtr  pChipMsgObj;
  CanChipDataPtr pChipData;
  Can_IdType localId;
  Can_HwHandleType localHrh;
  uint8 localDlc;
  /* LL specific part */
} tCanRxInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxInfoStruct, VAR_NOINIT) CanRxInfoPtrType;

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
typedef struct sCanTxInfoStruct
{
  CanChipDataPtr pChipData;
  /* LL specific part */
  CanChipMsgPtr   pChipMsgObj;
} tCanTxInfoStruct;
#endif

typedef struct sCanInitInfoStruct
{
  CAN_CHANNEL_CANTYPE_LOCAL
  CanInitHandle  initObject;
  uint8 isMbCorrupt;
  uint8 isChCorrupt;
  /* LL specific part */
  vuint32 ie;     /* INT enable/disable control */
  vuint32 txbtie; /* TXBTIE, TXBCIE enable/disable control */
  #if defined( C_ENABLE_STD_ID )
  # if (kCanNumberOfStandardFilter > 0)  /* at least one std filter available */
  V_DEF_P2CONST(V_NONE, vuint32, AUTOMATIC, CONST_PBCFG) pFS;
  # endif
  vuint16 stdFeCount;
  #endif
  #if defined( C_ENABLE_EXTENDED_ID )
  vuint16 extFeCount;
  #endif
  vuint32 tmpVal;
  V_DEF_P2VAR(V_NONE, tTXBEType, AUTOMATIC, VAR_NOINIT) pTXB; /* pointer to TxBuffer */
} tCanInitInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanInitInfoStruct, VAR_NOINIT) CanInitInfoPtrType;
#define CAN_HL_INFO_INIT_PTR(member)(initInfo->member) /* PRQA S 3410 */ /* MD_Can_3410 */
#define CAN_HL_INFO_INIT(member)    (initInfo.member)  /* PRQA S 3410 */ /* MD_Can_3410 */

typedef struct sCanRxBasicInfoStruct
{
  tCanRxInfoStruct rxInfo;
  CanObjectHandle rxObjHandle;
  CAN_CHANNEL_CANTYPE_LOCAL
  /* LL specific part */
  tRxElmType fElm;
  vuint8 fGetIndex;
  V_DEF_P2VAR(V_NONE,   tRxElmType, AUTOMATIC, VAR_NOINIT) pShm;        /* shared message RAM   */
  V_DEF_P2VAR(volatile, vuint32,    AUTOMATIC, VAR_NOINIT) pFifoAck;    /* Fifo acknowledge register (RXFnA) */
  V_DEF_P2VAR(volatile, tRXFnS,     AUTOMATIC, VAR_NOINIT) pFifoStatus; /* Fifo status register (RXFnS) */
  # if defined (C_CPUTYPE_BITORDER_MSB2LSB) /* COV_CAN_CPUTYPE */
  vuint32 fElmTmp;
  # endif
  # if defined(C_ENABLE_CAN_FD_FULL)
  vuint8  fElmSize, indexL;
  # endif
} tCanRxBasicInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxBasicInfoStruct, VAR_NOINIT) CanRxBasicInfoPtrType;
#define CAN_HL_INFO_RXBASIC_PTR(member) ((*rxBasicInfo).member) /* PRQA S 3410 */ /* MD_Can_3410 */
#define CAN_HL_INFO_RXBASIC(member)     (rxBasicInfo.member)  /* PRQA S 3410 */ /* MD_Can_3410 */

typedef struct sCanRxFullInfoStruct
{
  tCanRxInfoStruct rxInfo;
  CanObjectHandle rxObjHandle;
  CAN_CHANNEL_CANTYPE_LOCAL
  /* LL specific part */
  tRxElmType bfElm;
  vuint16 objectNumber;
  V_DEF_P2VAR(V_NONE, tRxElmType, AUTOMATIC, VAR_NOINIT) pShm;        /* shared message RAM   */
  # if defined (C_CPUTYPE_BITORDER_MSB2LSB) /* COV_CAN_CPUTYPE */
  vuint32 fElmTmp;
  # endif
  # if defined(C_ENABLE_CAN_FD_FULL)
  vuint8  rElmSize, indexL;
  # endif
} tCanRxFullInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxFullInfoStruct, VAR_NOINIT) CanRxFullInfoPtrType;
#define CAN_HL_INFO_RXFULL_PTR(member) ((*rxFullInfo).member) /* PRQA S 3410 */ /* MD_Can_3410 */
#define CAN_HL_INFO_RXFULL(member)     (rxFullInfo.member)  /* PRQA S 3410 */ /* MD_Can_3410 */

V_DEF_P2VAR_TYPE(V_NONE, CanObjectHandle, VAR_NOINIT) CanHlObjectHandlePtrType;
    
/***************************************************************************/
/* module global variable declaration                                      */
/***************************************************************************/

/***************************************************************************/
/* External Declarations                                                   */
/***************************************************************************/
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED  /*---------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /*----------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***************************************************************************/
/* local function prototypes (only internal usage)                         */
/***************************************************************************/
#define CAN_START_SEC_STATIC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#if defined( C_ENABLE_CAN_RAM_CHECK )
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_IsMailboxCorrupt()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       check the current mailbox at index hwObjHandle by write and read back patterns.
 *  \param[in]     Controller          CAN controller
 *  \param[in]     hwObjHandle         Handle to hardware object
 *  \return        kCanTrue:    Mailbox is corrupt
 *  \return        kCanFalse:   Mailbox is not corrupt  
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle);
/* CODE CATEGORY 4 END */
#endif


#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_InitBeginIsRegisterCorrupt()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       check the channel register at the beginning of the initialization by write and read back patterns.
 *  \param[in]     Controller          CAN controller
 *  \return        kCanTrue:    Channel is corrupt
 *  \return        kCanFalse:   Channel is not corrupt  
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_InitEndIsRegisterCorrupt()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       check the channel register at the ending of the initialization by write and read back patterns.
 *  \param[in]     Controller          CAN controller
 *  \return        kCanTrue:    Channel is corrupt
 *  \return        kCanFalse:   Channel is not corrupt  
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndIsRegisterCorrupt(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanBoschErratum_010()
 ***********************************************************************************************************/
/*! \brief         Restart Tx FSM after erratum_010 appeared (When CCCR.CCE is set while a Tx scan is in progress the Tx Handler FSM stops.)
 *  \details       1) Cancel all pending transmission requests, 
 *                 2) Issue a clock stop request
 *                 3) Wait until Clock Stop Acknowledge
 *                 4) Go back to Normal Operation (First reset CCCR.CSR, then reset CCCR.INIT)
 *                 5) Issue a second clock stop request
 *                 6) Await Clock Stop Acknowledge
 *                 7) Set CCCR.CCE and reset CCCR.CSR
 *  \param[in]     Controller   CAN controller
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
#if ( CAN_BOSCH_ERRATUM_010 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanBoschErratum_010( CAN_HW_CHANNEL_CANTYPE_ONLY );
#endif
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanSetAllFilter()
 ***********************************************************************************************************/
/*! \brief         Write the hardware filters into the Message RAM
 *  \details       Write standard and extended filter information for each CAN channel into the Message RAM
 *  \param[in]     Controller   CAN controller
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanSetAllFilter( CAN_CHANNEL_CANTYPE_FIRST CanInitInfoPtrType initInfo );
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanSetAllRegister()
 ***********************************************************************************************************/
/*! \brief         Initialize MCAN configuration registers
 *  \details       Assure that MCAN is in configuration enable mode and fill in all configuration relevant registers
 *  \param[in]     Controller   CAN controller
 *  \param[in]     initInfo     CAN controller configuration data
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanSetAllRegister( CAN_CHANNEL_CANTYPE_FIRST CanInitInfoPtrType initInfo, CanInitHandle initObject );
/* CODE CATEGORY 4 END */


#if defined( C_ENABLE_REGEXT_MCANSS ) /* COV_CAN_HW_SPECIFIC */
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanSetExtraRegister()
 ***********************************************************************************************************/
/*! \brief         Initialize extra TDA MCAN registers
 *  \details       Assure that TDA MCAN is in configuration enable mode and fill in all configuration relevant registers
 *  \param[in]     
 *  \param[in]     
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanSetExtraRegister( void );
/* CODE CATEGORY 4 END */
#endif


#if ( (((CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH))) ) /* COV_CAN_LOCK_ISR_BY_APPL */
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_CanInterruptDisable()
 ***********************************************************************************************************/
/*! \brief         Disable interrupt
 *  \details       Disable CAN interrupt
 *  \param[in]     Controller       CAN controller
 *  \param[in]     pointer to local variable
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CanChannelHandle  Controller, tCanLLCanIntOld* localInterruptOldFlagPtr);
/* CODE CATEGORY 4 END */
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_CanInterruptRestore()
 ***********************************************************************************************************/
/*! \brief         Restore interrupt
 *  \details       Restore CAN interrupt to the state before disable interrupt
 *  \param[in]     Controller       CAN controller
 *  \param[in]     old state
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CanChannelHandle  Controller, tCanLLCanIntOld localInterruptOldFlag);
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StartRequest()
 ***********************************************************************************************************/
/*! \brief         Start mode transition from STOP to NORMAL
 *  \details       Check the current state and trigger the transition to Normal Operation mode if necessary
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Normal Mode already reached
 *  \return        kCanRequested:   Transition to Normal Mode requested 
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanLL_StartRequest(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StartProcessed()
 ***********************************************************************************************************/
/*! \brief         Observe mode transition from STOP to NORMAL
 *  \details       Check if the requested transition to Normal Mode is fulfilled
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Normal Mode reached
 *  \return        kCanFailed:      Normal Mode not reached yet
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanLL_StartProcessed(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StopRequest()
 ***********************************************************************************************************/
/*! \brief         Stop mode transition from NORMAL to STOP
 *  \details       Check the current state and trigger the transition to Stop mode if necessary
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Stop Mode already reached
 *  \return        kCanRequested:   Transition to Stop Mode requested 
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanLL_StopRequest(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StopProcessed()
 ***********************************************************************************************************/
/*! \brief         Observe mode transition from NORMAL to STOP
 *  \details       Check if the requested transition to Stop Mode is fulfilled
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Stop Mode reached
 *  \return        kCanFailed:      Stop Mode not reached yet
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanLL_StopProcessed(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_if_TxIsObjConfPending()
 ***********************************************************************************************************/
/*! \brief         Check for pending Tx confirmations
 *  \details       Check all Tx objects within the configuration for any pending confirmation or cancellation
 *  \param[in]     Controller   CAN controller
 *  \param[in]     txBuffer     Buffer requests pending
 *  \return        kCanTrue:    at least one request pending
 *  \return        kCanFalse:   no request is pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
#if defined(C_ENABLE_TX_POLLING)
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanLL_if_TxIsObjConfPending( CAN_CHANNEL_CANTYPE_FIRST vuint32 txBuffer );
#endif
/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanInterruptTimeoutCounter()
 ***********************************************************************************************************/
/*! \brief         Protocol exception handling
 *  \details       check for protocol error and try to proceed if an exception appeared
 *  \param[in]     Controller   CAN controller
 *  \return        void
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanErrorHandlingBusOff()
 ***********************************************************************************************************/
/*! \brief         BusOff detection and treatment 
 *  \details       check the MCAN BusOff state,Message RAM access error and failure handling
 *  \param[in]     Controller   CAN controller
 *  \return        kCanTrue:    Channel is in BusOff state
 *  \return        kCanFalse:   Channel is not in BusOff state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanErrorHandlingBusOff(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING ))  || \
      defined( C_ENABLE_INDIVIDUAL_POLLING ) )        /* ISR necessary; no pure polling configuration*/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInterruptRx(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif

#if !defined(C_ENABLE_ERROR_POLLING)
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanInterruptErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif
#if !defined(C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInterruptTx(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif

#if defined( C_ENABLE_CAN_ECC_INIT_SHM )
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) Can_EccInit(void); /* PRQA S 3408, 3447 */ /* MD_Can_3408_extLinkage, MD_Can_3447 */
#endif  /* C_ENABLE_CAN_ECC_INIT_SHM */

/************************************************************************************************************
 *  CanInit()
 ***********************************************************************************************************/
/*! \brief         Wrapper for Can_InitController()
 *  \details       Initialization of controller specific CAN hardware. \n
 *                 The CAN driver registers and variables are initialized. \n
 *                 The CAN controller is fully initialized and left back within the state "STOP mode", ready to change to "Running Mode".
 *                 Called from LowLevel driver code while bus off handling or in case of mode transition that requires a reinitialization.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \param[in]     initObject    Index of the initialization structure to be initialized (specifies the baud rate to be used.)
 *  \pre           initObject has to be valid
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInit(CAN_CHANNEL_CANTYPE_FIRST uint8 initObject);
/************************************************************************************************************
 *  Can_CleanUpSendState()
 ***********************************************************************************************************/
/*! \brief         Clean up send state
 *  \details       Reset active send state (semaphore blocking TX while send).
 *                 Called by Can_SetControllerMode(), Can_Mainfunction_Mode() (Can_InitController() do same but without this call).
 *  \param[in]     Controller    CAN controller \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) Can_CleanUpSendState(CAN_CHANNEL_CANTYPE_ONLY);

#if (defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) ) || defined(C_ENABLE_HW_LOOP_TIMER) /* always used for sync mode */ /* COV_CAN_MICROSAR_VERSION */
# if (CAN_HW_LOOP_SUPPORT_API == STD_OFF)
/************************************************************************************************************
 *  ApplCanTimerLoop()
 ***********************************************************************************************************/
/*! \brief         Time out monitoring
 *  \details       Service function to check (against generated maximum loop value) whether a hardware loop shall be continued or broken.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \return        CAN_NOT_OK  when loop shall be broken (observation stops) \n
 *                             CAN_NOT_OK should only be used in case of a time out occurs due to a hardware issue. \n
 *                             After this an appropriate error handling is needed (see chapter Hardware Loop Check / Time out Monitoring).
 *  \return        CAN_OK      when loop shall be continued (observation continues)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Please refer to chapter "Hardware Loop Check".
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop(CAN_CHANNEL_CANTYPE_FIRST uint8 source);
# endif
#endif

/************************************************************************************************************
 *  CanHL_StartTransition()
 ***********************************************************************************************************/
/*! \brief         Request START
 *  \details       Handle START transition and wait ASR3:synchronous, ASR4:asynchronous-short time and notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller    CAN controller (Controller must be in valid range). \n
 *                               (only if not using "Optimize for one controller")
 *  \return        CAN_NOT_OK    transition rejected
 *  \return        CAN_OK        transition finished successful or is ongoing asynchronous
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_StartTransition(CAN_CHANNEL_CANTYPE_ONLY);

/************************************************************************************************************
 *  CanHL_StopTransition()
 ***********************************************************************************************************/
/*! \brief         Request STOP
 *  \details       Handle STOP transition and wait ASR3:synchronous, ASR4:asynchronous-short time and notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller    CAN controller (Controller must be in valid range). \n
 *                               (only if not using "Optimize for one controller")
 *  \return        CAN_NOT_OK    transition rejected
 *  \return        CAN_OK        transition finished successful or is ongoing asynchronous
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_StopTransition(CAN_CHANNEL_CANTYPE_ONLY);

/************************************************************************************************************
 *  CanHL_WakeupTransition()
 ***********************************************************************************************************/
/*! \brief         Request WAKEUP
 *  \details       Handle WAKEUP transition and wait ASR3:synchronous, ASR4:asynchronous-short time and notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller    CAN controller (Controller must be in valid range). \n
 *                               (only if not using "Optimize for one controller")
 *  \return        CAN_NOT_OK    transition rejected
 *  \return        CAN_OK        transition finished successful or is ongoing asynchronous
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WakeupTransition(CAN_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_CAN_RAM_CHECK)
/************************************************************************************************************
 *  CanHL_DoRamCheck()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       Start RAM check by set request and start Can_InitController doing the check.
 *                 Called by CanHL_WakeupTransition(), Wakeup Processing, Can_RamCheckExecution().
 *  \param[in]     Controller    CAN controller (Controller must be in valid range). \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_DoRamCheck(CAN_CHANNEL_CANTYPE_ONLY);
#endif

/************************************************************************************************************
 *  CanHL_SleepTransition()
 ***********************************************************************************************************/
/*! \brief         Request SLEEP
 *  \details       Handle SLEEP transition and wait ASR3:synchronous, ASR4:asynchronous-short time and notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller    CAN controller (Controller must be in valid range). \n
 *                               (only if not using "Optimize for one controller")
 *  \return        CAN_NOT_OK    transition rejected
 *  \return        CAN_OK        transition finished successful or is ongoing asynchronous
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_SleepTransition(CAN_CHANNEL_CANTYPE_ONLY);



/************************************************************************************************************
 *  CanHL_WritePrepare()
 ***********************************************************************************************************/
/*! \brief         TX preparation
 *  \details       Search for BasicCAN object handle to transmit (Multiplexed TX) and backup data for cancel TX object if necessary
 *                 Called by Can_Write().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     Hth              hardware transmit handle from (CanMailboxId)
 *  \param[in]     PduInfo          PDU info include ID, DLC, data, PDU
 *  \return        logTxObjHandle   logical transmit handle to be send
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_WritePrepare(CAN_CHANNEL_CANTYPE_FIRST Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo);


/************************************************************************************************************
 *  CanHL_WriteStart()
 ***********************************************************************************************************/
/*! \brief         TX start
 *  \details       Write ID, DLC and Data to FullCAN or BasicCAN object and set transmit request
 *                 Called by Can_Write().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     Hth             hardware transmit handle from (CanMailboxId)
 *  \param[in]     logTxObjHandle  logical TX object handle
 *  \param[in]     PduInfo         PDU info include ID, DLC, data, PDU
 *  \return        CAN_NOT_OK      transmission failed.
 *  \return        CAN_OK          transmission successful.
 *  \return        CAN_BUSY        transition object busy - repeat it.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart(CAN_CHANNEL_CANTYPE_FIRST Can_HwHandleType Hth, CanObjectHandle logTxObjHandle, Can_PduInfoPtrType PduInfo);

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR40X) /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  CanHL_StartProcessed()
 ***********************************************************************************************************/
/*! \brief         Check START
 *  \details       Transition finished and notify to upper layer.
 *                 Called by Can_MainFunction_Mode().
 *  \param[in]     Controller      CAN controller. (Controller must be in valid range). \n
 *                                 (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_StartProcessed(CAN_CHANNEL_CANTYPE_ONLY);

/************************************************************************************************************
 *  CanHL_StopProcessed()
 ***********************************************************************************************************/
/*! \brief         Check STOP
 *  \details       Transition finished and notify to upper layer.
 *                 Called by Can_MainFunction_Mode().
 *  \param[in]     Controller      CAN controller. (Controller must be in valid range). \n
 *                                 (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_StopProcessed(CAN_CHANNEL_CANTYPE_ONLY);


#endif /* CAN_ENABLE_MICROSAR_VERSION_MSR40X */

/************************************************************************************************************
 *  CanHL_GetTxHwToLogHandle()
 ***********************************************************************************************************/
/*! \brief         Convert Handle
 *  \details       Hardware to logical Handle conversion.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     hwTxObjHandle   Handle to hardware mailbox
 *  \return        logical handle for the given hardware mailbox
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetTxHwToLogHandle(CAN_CHANNEL_CANTYPE_FIRST Can_HwHandleType hwTxObjHandle);

/************************************************************************************************************
 *  CanHL_GetTxLogToHwHandle()
 ***********************************************************************************************************/
/*! \brief         Convert Handle
 *  \details       Logical to hardware Handle conversion.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     logTxObjHandle  Logical handle of TX mailbox
 *  \return        hardware mailbox for the given logical handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_HwHandleType, STATIC_CODE) CanHL_GetTxLogToHwHandle(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle logTxObjHandle);

#if defined(C_ENABLE_CAN_RAM_CHECK)
/************************************************************************************************************
 *  CanHL_RamCheckMailboxNotification()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       Notify upper layer in case of an HW issue and deactivate controller.
 *                 Called by Can_InitController().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     hwObjHandle      Handle to hardware object
 *  \param[in]     htrh             Hrh or Hth of the hardware object
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANTYPE_FIRST Can_HwHandleType hwObjHandle, Can_HwHandleType htrh);
#endif



/************************************************************************************************************
 *  CanHL_SetValue32()
 ***********************************************************************************************************/
/*! \brief         Write value and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 Notify upper layer in case of an HW issue and deactivate controller.
 *                 Called by Can_InitController().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            value to be written.
 *  \param[in]     readMask         mask to check the read back value.
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_SetValue32(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, uint32 value, uint32 readMask);




/************************************************************************************************************
 *  CanHL_InitBegin()
 ***********************************************************************************************************/
/*! \brief         Start Initialization
 *  \details       LL implementation see token CanLL_InitBegin description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin(CanInitInfoPtrType initInfo);

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitTxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX FullCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN(CanInitInfoPtrType initInfo);
#endif

/************************************************************************************************************
 *  CanHL_InitTxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX BasicCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN(CanInitInfoPtrType initInfo);


#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitRxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX FullCAN
 *  \details       LL implementation see token CanLL_InitFullCANObj description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN(CanInitInfoPtrType initInfo);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitRxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX BasicCAN
 *  \details       LL implementation see token CanLL_InitBasicCANObj description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN(CanInitInfoPtrType initInfo);
#endif

/************************************************************************************************************
 *  CanHL_InitEnd_InitMode()
 ***********************************************************************************************************/
/*! \brief         End Initialization
 *  \details       LL implementation see token CanLL_InitEnd_InitMode description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode(CanInitInfoPtrType initInfo);

/************************************************************************************************************
 *  CanHL_InitEnd_StopMode()
 ***********************************************************************************************************/
/*! \brief         Transition to STOP
 *  \details       LL implementation see token CanLL_InitEnd_StopMode description.
 *                 Called by Can_InitController().
 *  \param[in]     initInfo          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_StopMode(CanInitInfoPtrType initInfo);

/************************************************************************************************************
 *  CanHL_StopReinit()
 ***********************************************************************************************************/
/*! \brief         Reinitialization after STOP
 *  \details       LL implementation see token CanLL_StopReinit description.
 *                 Called by Can_InitController().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_StopReinit(CAN_HW_CHANNEL_CANTYPE_ONLY);

/************************************************************************************************************
 *  CanHL_InitPowerOn()
 ***********************************************************************************************************/
/*! \brief         Power on initialization
 *  \details       LL implementation see token CanLL_InitPowerOn description.
 *                 Called by Can_InitController().
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_InitPowerOn(void);

/************************************************************************************************************
 *  CanHL_InitPowerOnChannelSpecific()
 ***********************************************************************************************************/
/*! \brief         Power on channel initialization
 *  \details       LL implementation see token CanLL_InitPowerOnChannelSpecific description.
 *                 Called by Can_Init().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_RxBasicMsgReceivedBegin()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN start
 *  \details       RX BasicCAN handling start.
 *                 Called by CanBasicCanMsgReceived().
 *  \param[in]     rxBasicInfo          include controller and all LL specific settings.
 *  \return        CAN_NOT_OK      reception failed.
 *  \return        CAN_OK          reception successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_RxBasicMsgReceivedBegin(CanRxBasicInfoPtrType rxBasicInfo);

/************************************************************************************************************
 *  CanHL_RxBasicMsgReceivedSearch()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN search
 *  \details       RX BasicCAN search logical HRH from hardware hwRxHandle.
 *                 Called by CanBasicCanMsgReceived().
 *  \param[out]    rxBasicInfo          include Hrh, controller and all LL specific settings.
 *  \return        CAN_NOT_OK      reception failed.
 *  \return        CAN_OK          reception successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_RxBasicMsgReceivedSearch(CanRxBasicInfoPtrType rxBasicInfo);

/************************************************************************************************************
 *  CanHL_RxBasicMsgReceivedEnd()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN end
 *  \details       RX BasicCAN handling end.
 *                 Called by CanBasicCanMsgReceived().
 *  \param[in]     rxBasicInfo          include controller and all LL specific settings.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicMsgReceivedEnd(CanRxBasicInfoPtrType rxBasicInfo);

# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxBasicMsgReceivePolling()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN polling
 *  \details       RX BasicCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicMsgReceivePolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_RxFullMsgReceivedBegin()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN start
 *  \details       RX FullCAN handling start.
 *                 Called by CanFullCanMsgReceived().
 *  \param[in]     rxFullInfo          include controller and all LL specific settings.
 *  \return        CAN_NOT_OK      reception failed.
 *  \return        CAN_OK          reception successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_RxFullMsgReceivedBegin(CanRxFullInfoPtrType rxFullInfo);

/************************************************************************************************************
 *  CanHL_RxFullMsgReceivedSearch()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN search
 *  \details       RX FullCAN search logical HRH from hardware hwTxHandle.
 *                 Called by CanFullCanMsgReceived().
 *  \param[out]    rxFullInfo          include HRH, controller and all LL specific settings.
 *  \return        CAN_NOT_OK      reception failed.
 *  \return        CAN_OK          reception successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_RxFullMsgReceivedSearch(CanRxFullInfoPtrType rxFullInfo);

/************************************************************************************************************
 *  CanHL_RxFullMsgReceivedEnd()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN end
 *  \details       RX FullCAN handling end.
 *                 Called by CanFullCanMsgReceived().
 *  \param[in]     rxFullInfo          include controller and all LL specific settings.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullMsgReceivedEnd(CanRxFullInfoPtrType rxFullInfo);

# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxFullMsgReceivePolling()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN polling
 *  \details       RX FullCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullMsgReceivePolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_RxMsgReceivedNotification()
 ***********************************************************************************************************/
/*! \brief         RX notification
 *  \details       RX queue and notification handling for BasicCAN and FullCAN reception.
 *                 Called by CanBasicCanMsgReceived(),CanFullCanMsgReceived().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxInfo          include controller and all LL specific settings.
 *  \return        errorId         error identifier reporting to DET
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANTYPE_FIRST CanRxInfoPtrType rxInfo);
#endif

#if defined(C_ENABLE_RX_QUEUE)
/************************************************************************************************************
 *  CanHL_RxQueueExecution()
 ***********************************************************************************************************/
/*! \brief         RX queue
 *  \details       RX queue execution and notification.
 *                 Called by Can_MainFunction_Read().
 *  \return        errorId         error identifier reporting to DET
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxQueueExecution(void);
#endif

/************************************************************************************************************
 *  CanHL_TxConfirmation()
 ***********************************************************************************************************/
/*! \brief         TX Confirmation handling
 *  \details       Called for a transmit or cancel event. Finish transmission by free send mailbox and call confirmation. \n
 *                 Called for FullCAN and BasicCAN handling.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \param[in]     txObjHandle   transmit hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/************************************************************************************************************
 *  CanBasicCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive BasicCAN data and call indication function.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \param[in]     rxObjHandle   received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanBasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanFullCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive FullCAN data and call indication function.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \param[in]     rxObjHandle   received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanFullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_ErrorHandling()
 ***********************************************************************************************************/
/*! \brief         BUSOFF handling
 *  \details       Handler for bus off situation.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);


#if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */
/************************************************************************************************************
 *  CanHL_TxTaskConfPendingHandling()
 ***********************************************************************************************************/
/*! \brief         Tx task confirmation
 *  \details       Tx task handle the pending mailboxes.
 *                 Called by Can_MainFunction_Write().
 *  \param[in]     Controller    CAN controller. \n
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxTaskConfPendingHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif


#define CAN_STOP_SEC_STATIC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CAN_START_SEC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if defined(CAN_ENABLE_MICROSAR_VERSION_MSR403) /* COV_CAN_MICROSAR_VERSION */
/************************************************************************************************************
 *  Can_InitController()
 ***********************************************************************************************************/
/*! \brief         Initialization of controller specific CAN hardware.
 *  \details       The CAN driver registers and variables are initialized. \n
 *                 The CAN controller is fully initialized and left back within the state "STOP Mode", ready to change to "Running Mode".
 *  \param[in]     Controller            CAN controller
 *  \param[in]     ControllerConfigPtr   Pointer to the configuration data structure.
 *  \pre           Disabled Interrupts.
 *  \pre           Can_Init() has to be called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Has to be called during the start up sequence before CAN communication takes place. \n
 *                 Must not be called while in "SLEEP Mode".
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitController( uint8 Controller, Can_ControllerConfigPtrType ControllerConfigPtr );
#endif

#define CAN_STOP_SEC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* CAN_LOCAL_H */

/* End of channel */



/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

