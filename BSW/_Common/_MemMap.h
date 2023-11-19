/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2017 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */


# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (1u)
# define MEMMAP_SW_MINOR_VERSION     (11u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION 
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION 
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION 
  
#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */



/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START  DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

#if defined (CAN_REMAP_PB_SECTIONS)        /* PRQA S 0883 */ /* Appears only while testing */
/* for none PB variants the code will be mapped to standard sections, so the generated and static code can ignore the variant handling */
# if defined (CAN_START_SEC_PBCFG)
#  undef CAN_START_SEC_PBCFG                /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_CONST_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_PBCFG)
#  undef CAN_STOP_SEC_PBCFG                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_CONST_UNSPECIFIED
# endif

# if defined (CAN_START_SEC_VAR_PBCFG)
#  undef CAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_VAR_PBCFG)
#  undef CAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# endif
#endif

/*******  CODE sections **********************************************************************************************/

#ifdef CAN_START_SEC_CODE                             /* CAN code */
# undef CAN_START_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE
# undef CAN_STOP_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_STATIC_CODE                      /* CAN static code */
# undef CAN_START_SEC_STATIC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_STATIC_CODE
# undef CAN_STOP_SEC_STATIC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_CODE_APPL                        /* Appl code (generic precopy)*/
# undef CAN_START_SEC_CODE_APPL                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE_APPL
# undef CAN_STOP_SEC_CODE_APPL                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CAN_START_SEC_CONST_8BIT                       /* Const 8bit */
# undef CAN_START_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_8BIT
# undef CAN_STOP_SEC_CONST_8BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_16BIT                      /* Const 16bit */
# undef CAN_START_SEC_CONST_16BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_16BIT
# undef CAN_STOP_SEC_CONST_16BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_32BIT                      /* Const 32bit */
# undef CAN_START_SEC_CONST_32BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                        /* mapped to default const 32bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_32BIT
# undef CAN_STOP_SEC_CONST_32BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_UNSPECIFIED                /* Const unspecified */
# undef CAN_START_SEC_CONST_UNSPECIFIED                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspec section */
#endif
#ifdef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_STOP_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
/* unused */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data (not relevant for CFG5 AutoSar4.0.3) */
#ifdef CAN_START_SEC_PBCFG_ROOT                       /* Generated Postbuild Root Table */
# undef CAN_START_SEC_PBCFG_ROOT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG_ROOT
# undef CAN_STOP_SEC_PBCFG_ROOT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_PBCFG                            /* Generated Postbuild */
# undef CAN_START_SEC_PBCFG                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG
# undef CAN_STOP_SEC_PBCFG                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CAN_START_SEC_VAR_INIT_UNSPECIFIED             /* init RAM*/
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED               /* mapped to default init var section */
#endif
#ifdef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED           /* uninit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_8BIT                  /* uninit 8bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_8BIT
# undef CAN_STOP_SEC_VAR_NOINIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_16BIT                  /* uninit 16bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_16BIT
# undef CAN_STOP_SEC_VAR_NOINIT_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_32BIT                  /* uninit 32bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_32BIT
# undef CAN_STOP_SEC_VAR_NOINIT_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif



/* VAR PBCFG sections */

#ifdef CAN_START_SEC_VAR_PBCFG           /* Generated Postbuild RAM*/
# undef CAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_PBCFG
# undef CAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
/* unused */


/* VAR FAST INIT sections */
/* unused */


/* VAR FAST NOINIT sections */
/* unused */

/* VAR FAST ZERO INIT sections */
/* unused */



/**********************************************************************************************************************
 *  Can END    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_Rh850McanAsr Erzeugungsgangnummer: 375 */


/**********************************************************************************************************************
 *  FblCw START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FBLCW_START_SEC_CODE
# undef FBLCW_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_STOP_SEC_CODE
# undef FBLCW_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* FBCW application callback code section */
#ifdef FBLCW_START_SEC_APPL_CODE
# undef FBLCW_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_STOP_SEC_APPL_CODE
# undef FBLCW_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif
#ifdef FBL_CW_FULL_START_SEC_CODE
# undef FBL_CW_FULL_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBL_CW_FULL_STOP_SEC_CODE
# undef FBL_CW_FULL_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FBLCW_START_SEC_CONST_8BIT
# undef FBLCW_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_8BIT
# undef FBLCW_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_16BIT
# undef FBLCW_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_16BIT
# undef FBLCW_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_32BIT
# undef FBLCW_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_32BIT
# undef FBLCW_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_64BIT
# undef FBLCW_START_SEC_CONST_64BIT
# define START_SEC_CONST_64BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_64BIT
# undef FBLCW_STOP_SEC_CONST_64BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_UNSPECIFIED
# undef FBLCW_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# undef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_PBCFG
# undef FBLCW_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FBLCW_STOP_SEC_PBCFG
# undef FBLCW_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_VAR_PBCFG
# undef FBLCW_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef FBLCW_STOP_SEC_VAR_PBCFG
# undef FBLCW_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_8BIT
# undef FBLCW_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_16BIT
# undef FBLCW_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_32BIT
# undef FBLCW_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_64BIT
# undef FBLCW_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FblCw END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_16BIT
# undef PDUR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_16BIT
# undef PDUR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */


/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_16BIT
# undef PDUR_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_32BIT
# undef PDUR_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif


#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

/* Postbuild CFG VAR sections */

#ifdef PDUR_START_SEC_VAR_PBCFG
# undef PDUR_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef PDUR_STOP_SEC_VAR_PBCFG
# undef PDUR_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CANIF_START_SEC_CODE
# undef CANIF_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CANIF_STOP_SEC_CODE
# undef CANIF_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef CANIF_START_SEC_APPL_CODE
# undef CANIF_START_SEC_APPL_CODE                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANIF_STOP_SEC_APPL_CODE
# undef CANIF_STOP_SEC_APPL_CODE                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANIF_START_SEC_CONST_8BIT
# undef CANIF_START_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif
#ifdef CANIF_STOP_SEC_CONST_8BIT
# undef CANIF_STOP_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef CANIF_START_SEC_CONST_16BIT
# undef CANIF_START_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_16BIT
# undef CANIF_STOP_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                             /* default const stop section */
#endif


/* Const 32bit */

#ifdef CANIF_START_SEC_CONST_32BIT
# undef CANIF_START_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                      /* mapped to const 32 bit section */
#endif
#ifdef CANIF_STOP_SEC_CONST_32BIT
# undef CANIF_STOP_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Const unspecified */

#ifdef CANIF_START_SEC_CONST_UNSPECIFIED
# undef CANIF_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified section */
#endif
#ifdef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* FAST CONST sections */

#ifdef CANIF_START_SEC_CONST_FAST_8BIT
# undef CANIF_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_8BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_8BIT
# undef CANIF_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_16BIT
# undef CANIF_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_16BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_16BIT
# undef CANIF_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_32BIT
# undef CANIF_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_32BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_32BIT
# undef CANIF_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef CANIF_START_SEC_PBCFG
# undef CANIF_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif
#ifdef CANIF_STOP_SEC_PBCFG
# undef CANIF_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CANIF_START_SEC_VAR_INIT_8BIT
# undef CANIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_16BIT
# undef CANIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_INIT_32BIT
# undef CANIF_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef CANIF_START_SEC_VAR_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef CANIF_START_SEC_VAR_PBCFG
# undef CANIF_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef CANIF_STOP_SEC_VAR_PBCFG
# undef CANIF_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_30_SMALLSECTOR_START_SEC_CODE
    #undef FEE_30_SMALLSECTOR_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector END
 *********************************************************************************************************************/

#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
    #undef MEMIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CODE_FAST
  #undef ADC_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ADC_STOP_SEC_CODE_FAST
  #undef ADC_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_CONST_32
  #undef ADC_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32
  #undef ADC_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
  #undef ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
  #undef ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_PRIVATE_CODE
  #undef ADC_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PRIVATE_CODE
  #undef ADC_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_PUBLIC_CODE
  #undef ADC_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PUBLIC_CODE
  #undef ADC_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_VAR_INIT_8
  #undef ADC_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_8
  #undef ADC_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_8
  #undef ADC_START_SEC_VAR_NOINIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_8
  #undef ADC_STOP_SEC_VAR_NOINIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_59_RENESAS_START_SEC_CODE_FAST
  #undef ADC_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_CODE_FAST
  #undef ADC_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ADC_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_59_RENESAS_START_SEC_CONST_32
  #undef ADC_59_RENESAS_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_CONST_32
  #undef ADC_59_RENESAS_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef ADC_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef ADC_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef ADC_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef ADC_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef ADC_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_59_RENESAS_START_SEC_VAR_INIT_8
  #undef ADC_59_RENESAS_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_VAR_INIT_8
  #undef ADC_59_RENESAS_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #undef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #undef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_CONST_16BIT
  #undef DEFAULT_START_SEC_CONST_16BIT
  #define START_SEC_CONST_16BIT
#endif

#ifdef DEFAULT_STOP_SEC_CONST_16BIT
  #undef DEFAULT_STOP_SEC_CONST_16BIT
  #define STOP_SEC_CONST
#endif

#ifdef DEFAULT_START_SEC_CONST_1BIT
  #undef DEFAULT_START_SEC_CONST_1BIT
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_CONST_1BIT
  #undef DEFAULT_STOP_SEC_CONST_1BIT
  #define STOP_SEC_CONST
#endif

#ifdef DEFAULT_START_SEC_CONST_32BIT
  #undef DEFAULT_START_SEC_CONST_32BIT
  #define START_SEC_CONST_32BIT
#endif

#ifdef DEFAULT_STOP_SEC_CONST_32BIT
  #undef DEFAULT_STOP_SEC_CONST_32BIT
  #define STOP_SEC_CONST
#endif

#ifdef DEFAULT_START_SEC_CONST_8BIT
  #undef DEFAULT_START_SEC_CONST_8BIT
  #define START_SEC_CONST_8BIT
#endif

#ifdef DEFAULT_STOP_SEC_CONST_8BIT
  #undef DEFAULT_STOP_SEC_CONST_8BIT
  #define STOP_SEC_CONST
#endif

#ifdef DEFAULT_START_SEC_CONST_UNSPECIFIED
  #undef DEFAULT_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_CONST_UNSPECIFIED
  #undef DEFAULT_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DEFAULT_START_SEC_VAR_16BIT
  #undef DEFAULT_START_SEC_VAR_16BIT
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_16BIT
  #undef DEFAULT_STOP_SEC_VAR_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_1BIT
  #undef DEFAULT_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_1BIT
  #undef DEFAULT_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_32BIT
  #undef DEFAULT_START_SEC_VAR_32BIT
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_32BIT
  #undef DEFAULT_STOP_SEC_VAR_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_8BIT
  #undef DEFAULT_START_SEC_VAR_8BIT
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_8BIT
  #undef DEFAULT_STOP_SEC_VAR_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_16BIT
  #undef DEFAULT_START_SEC_VAR_FAST_16BIT
  #define START_SEC_VAR_FAST_INIT_16BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_FAST_16BIT
  #undef DEFAULT_STOP_SEC_VAR_FAST_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_1BIT
  #undef DEFAULT_START_SEC_VAR_FAST_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_FAST_1BIT
  #undef DEFAULT_STOP_SEC_VAR_FAST_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_32BIT
  #undef DEFAULT_START_SEC_VAR_FAST_32BIT
  #define START_SEC_VAR_FAST_INIT_32BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_FAST_32BIT
  #undef DEFAULT_STOP_SEC_VAR_FAST_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_8BIT
  #undef DEFAULT_START_SEC_VAR_FAST_8BIT
  #define START_SEC_VAR_FAST_INIT_8BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_FAST_8BIT
  #undef DEFAULT_STOP_SEC_VAR_FAST_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
  #undef DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
  #define START_SEC_VAR_FAST_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
  #undef DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_NOINIT_16BIT
  #undef DEFAULT_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_NOINIT_1BIT
  #undef DEFAULT_START_SEC_VAR_NOINIT_1BIT
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_NOINIT_32BIT
  #undef DEFAULT_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_NOINIT_8BIT
  #undef DEFAULT_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DEFAULT_START_SEC_VAR_UNSPECIFIED
  #undef DEFAULT_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DEFAULT_STOP_SEC_VAR_UNSPECIFIED
  #undef DEFAULT_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #undef DIO_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef DIO_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef DIO_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef DIO_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef DIO_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef DIO_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef DIO_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef DIO_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_59_RENESAS_START_SEC_VAR_NO_INIT_16
  #undef DIO_59_RENESAS_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
  #undef DIO_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_APPL_CODE
  #undef FLS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_APPL_CODE
  #undef FLS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CODE
  #undef FLS_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
  #undef FLS_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_PRIVATE_CODE
  #undef FLS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_PRIVATE_CODE
  #undef FLS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_PRIVATERAM_CODE
  #undef FLS_START_SEC_PRIVATERAM_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_PRIVATERAM_CODE
  #undef FLS_STOP_SEC_PRIVATERAM_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_PUBLIC_CODE
  #undef FLS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_PUBLIC_CODE
  #undef FLS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_VAR_INIT_BOOLEAN
  #undef FLS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_32
  #undef FLS_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_32
  #undef FLS_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_BOOLEAN
  #undef FLS_START_SEC_VAR_NOINIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_59_RENESAS_START_SEC_APPL_CODE
  #undef FLS_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_APPL_CODE
  #undef FLS_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef FLS_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef FLS_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_START_SEC_PRIVATERAM_CODE
  #undef FLS_59_RENESAS_START_SEC_PRIVATERAM_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_PRIVATERAM_CODE
  #undef FLS_59_RENESAS_STOP_SEC_PRIVATERAM_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef FLS_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef FLS_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef FLS_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef FLS_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif



#ifdef GPT_59_RENESAS_START_SEC_APPL_CODE
  #undef GPT_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_APPL_CODE
  #undef GPT_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_START_SEC_APPL_DATA_UNSPECIFIED
  #undef GPT_59_RENESAS_START_SEC_APPL_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_APPL_DATA_UNSPECIFIED
  #undef GPT_59_RENESAS_STOP_SEC_APPL_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_59_RENESAS_START_SEC_CODE_FAST
  #undef GPT_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_CODE_FAST
  #undef GPT_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #undef GPT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #undef GPT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef GPT_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef GPT_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef GPT_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef GPT_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_59_RENESAS_START_SEC_VAR_INIT_32
  #undef GPT_59_RENESAS_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_VAR_INIT_32
  #undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_59_RENESAS_START_SEC_VAR_INIT_8
  #undef GPT_59_RENESAS_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_VAR_INIT_8
  #undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef GPT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef GPT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef GPT_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GPT_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_59_RENESAS_START_SEC_APPL_CODE
  #undef ICU_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_APPL_CODE
  #undef ICU_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_START_SEC_CODE_FAST
  #undef ICU_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_CODE_FAST
  #undef ICU_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #undef ICU_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #undef ICU_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef ICU_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef ICU_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef ICU_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef ICU_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef ICU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef ICU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_APPL_CODE
  #undef MCU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_APPL_CODE
  #undef MCU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CODE_FAST
  #undef MCU_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef MCU_STOP_SEC_CODE_FAST
  #undef MCU_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_CONST_32
  #undef MCU_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef MCU_STOP_SEC_CONST_32
  #undef MCU_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
  #undef MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
  #undef MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PRIVATE_CODE
  #undef MCU_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PRIVATE_CODE
  #undef MCU_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_PUBLIC_CODE
  #undef MCU_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PUBLIC_CODE
  #undef MCU_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_VAR_32
  #undef MCU_START_SEC_VAR_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_32
  #undef MCU_STOP_SEC_VAR_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_16
  #undef MCU_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_16
  #undef MCU_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_32
  #undef MCU_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_32
  #undef MCU_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_8
  #undef MCU_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_8
  #undef MCU_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_BOOLEAN
  #undef MCU_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif


#ifdef MCU_59_RENESAS_START_SEC_APPL_CODE
  #undef MCU_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_APPL_CODE
  #undef MCU_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_START_SEC_CODE_FAST
  #undef MCU_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_CODE_FAST
  #undef MCU_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_59_RENESAS_START_SEC_CONST_32
  #undef MCU_59_RENESAS_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_CONST_32
  #undef MCU_59_RENESAS_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef MCU_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef MCU_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef MCU_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef MCU_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef MCU_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_59_RENESAS_START_SEC_VAR_INIT_16
  #undef MCU_59_RENESAS_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_VAR_INIT_16
  #undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef MCU_59_RENESAS_START_SEC_VAR_INIT_32
  #undef MCU_59_RENESAS_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_VAR_INIT_32
  #undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_59_RENESAS_START_SEC_VAR_INIT_8
  #undef MCU_59_RENESAS_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_VAR_INIT_8
  #undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef MCU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef MCU_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MCU_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PORT_59_RENESAS_START_SEC_APPL_CODE
  #undef PORT_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_APPL_CODE
  #undef PORT_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #undef PORT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #undef PORT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef PORT_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef PORT_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef PORT_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef PORT_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef PORT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef PORT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PORT_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef PORT_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef PORT_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_59_RENESAS_START_SEC_APPL_CODE
  #undef PWM_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_APPL_CODE
  #undef PWM_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_START_SEC_CODE_FAST
  #undef PWM_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_CODE_FAST
  #undef PWM_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_START_SEC_CONST_32
  #undef PWM_59_RENESAS_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_CONST_32
  #undef PWM_59_RENESAS_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef PWM_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef PWM_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef PWM_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef PWM_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef PWM_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #undef PWM_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef PWM_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_APPL_CODE
  #undef SPI_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE
  #undef SPI_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
  #undef SPI_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_APPL_CODE
  #undef SPI_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE_FAST
  #undef SPI_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef SPI_STOP_SEC_CODE_FAST
  #undef SPI_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_32
  #undef SPI_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONST_32
  #undef SPI_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
  #undef SPI_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
  #undef SPI_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_PRIVATE_CODE
  #undef SPI_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PRIVATE_CODE
  #undef SPI_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_PUBLIC_CODE
  #undef SPI_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PUBLIC_CODE
  #undef SPI_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_VAR_INIT_16
  #undef SPI_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_16
  #undef SPI_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_8
  #undef SPI_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_8
  #undef SPI_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_16
  #undef SPI_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_16
  #undef SPI_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_8
  #undef SPI_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_8
  #undef SPI_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_UNSPECIFIED
  #undef SPI_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_APPL_CODE
  #undef SPI_59_RENESAS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_APPL_CODE
  #undef SPI_59_RENESAS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_START_SEC_CODE_FAST
  #undef SPI_59_RENESAS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_CODE_FAST
  #undef SPI_59_RENESAS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #undef SPI_59_RENESAS_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #undef SPI_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_59_RENESAS_START_SEC_PRIVATE_CODE
  #undef SPI_59_RENESAS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #undef SPI_59_RENESAS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_START_SEC_PUBLIC_CODE
  #undef SPI_59_RENESAS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #undef SPI_59_RENESAS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_INIT_16
  #undef SPI_59_RENESAS_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_INIT_16
  #undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_INIT_8
  #undef SPI_59_RENESAS_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_INIT_8
  #undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_16
  #undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
  #undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CONST_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
  #undef WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_INIT_32
  #undef WDG_59_DRIVERA_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_32
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_INIT_8
  #undef WDG_59_DRIVERA_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_CODE_FAST
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_CODE_FAST
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_CONST_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_PRIVATE_CODE
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_PRIVATE_CODE
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_PUBLIC_CODE
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_PUBLIC_CODE
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_32
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_32
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_8
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_8
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #define START_SEC_CODE                /* mapped to default code section */
#endif
#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #define STOP_SEC_CODE                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef NVM_START_SEC_CONST_8
    #undef NVM_START_SEC_CONST_8
    #define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8
    #undef NVM_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16
    #undef NVM_START_SEC_CONST_16
    #define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16
    #undef NVM_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
    #undef NVM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
    #undef NVM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NVM_START_SEC_VAR_NOINIT_8
    #undef NVM_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8
    #undef NVM_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* If Development Error Detection is ON (as well as INIT check),    *
 *   it SHALL be mapped to an initialized section (zeor is ok)      *
 * if Development Error Detection (or at least INIT check) is OFF,  *
 *   it MAY also be mapped to a NOINIT section.                     */
#ifdef NVM_START_SEC_VAR_UNSPECIFIED
    #undef NVM_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */
#ifdef NVM_START_SEC_VAR_FAST_8
    #undef NVM_START_SEC_VAR_FAST_8
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8
    #undef NVM_STOP_SEC_VAR_FAST_8
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* SHALL be mapped to a section that is guaranteed to be ZEROed out after Power-On Reset       *
 * (therefore it MAY be a "normal" ZERO_INIT section, being ZEROed out after ANY reset         *
 * Make shure this helds true for all kinds of variable data (esp. "uninitialized).            *
 * If necessary, create a special section (don't map to a common one)                          */    
#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef BSWM_START_SEC_CODE
# undef BSWM_START_SEC_CODE
# define START_SEC_CODE                                 /* mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_CODE
# undef BSWM_STOP_SEC_CODE
# define STOP_SEC_CODE                                  /* default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef BSWM_START_SEC_CONST_8BIT
# undef BSWM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                           /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_8BIT
# undef BSWM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_16BIT
# undef BSWM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_16BIT
# undef BSWM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_32BIT
# undef BSWM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_32BIT
# undef BSWM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
# undef BSWM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
# undef BSWM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_PBCFG
# undef BSWM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_PBCFG
# undef BSWM_STOP_SEC_PBCFG
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef BSWM_START_SEC_VAR_NOINIT_8BIT
# undef BSWM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT                      /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_16BIT
# undef  BSWM_START_SEC_VAR_NOINIT_16BIT                /* mapped to default var section */
# define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_32BIT
# undef  BSWM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT                     /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED               /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_PBCFG
# undef BSWM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG                            /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_PBCFG
# undef BSWM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef CRC_START_SEC_CONST_8
    #undef CRC_START_SEC_CONST_8
    #define START_SEC_CONST_8
#endif
#ifdef CRC_STOP_SEC_CONST_8
    #undef CRC_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_16
    #undef CRC_START_SEC_CONST_16
    #define START_SEC_CONST_16
#endif
#ifdef CRC_STOP_SEC_CONST_16
    #undef CRC_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_32
    #undef CRC_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef CRC_STOP_SEC_CONST_32
    #undef CRC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_64
    #undef CRC_START_SEC_CONST_64
    #define START_SEC_CONST_64
#endif
#ifdef CRC_STOP_SEC_CONST_64
    #undef CRC_STOP_SEC_CONST_64
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
 *********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/**********************************************************************************************************************
 *  WRAPNV START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef WRAPNV_START_SEC_CODE
 #undef WRAPNV_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef WRAPNV_STOP_SEC_CODE
 #undef WRAPNV_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef WRAPNV_START_SEC_CONST_UNSPECIFIED
 #undef WRAPNV_START_SEC_CONST_UNSPECIFIED
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
 #undef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
 #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
 #undef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 #undef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WRAPNV END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef   CANTP_START_SEC_CODE
# undef  CANTP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef   CANTP_STOP_SEC_CODE
# undef  CANTP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE      /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef   CANTP_START_SEC_CONST_UNSPECIFIED
# undef  CANTP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef  CANTP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTP_START_SEC_CONST_16BIT)
# undef CANTP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTP_STOP_SEC_CONST_16BIT)
# undef CANTP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_8BIT
# undef  CANTP_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_8BIT
# undef  CANTP_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef   CANTP_START_SEC_PBCFG
# undef  CANTP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_PBCFG
# undef  CANTP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef   CANTP_START_SEC_VAR_INIT_8BIT
# undef  CANTP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_8BIT
# undef  CANTP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef   CANTP_START_SEC_VAR_NOINIT_8BIT
# undef  CANTP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_PBCFG
# undef  CANTP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_VAR_PBCFG
# undef  CANTP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/


/* PRQA L:MEMMAP_0841_TAG */

#include "MemMap_Common.h"

/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

