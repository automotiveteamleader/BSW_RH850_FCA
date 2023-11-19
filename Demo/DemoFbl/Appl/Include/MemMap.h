/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        MemMap section definition to locate (link) data or code in memory
 *  \details      This file contains compiler specific section definition for every segment that can be mapped
 *                within the Flash Bootloader to a specific location.
 *
 *  \note
 *                Please note, that this file contains a collection of definitions to be used with the Flash Bootloader.
 *                This code may influence the behavior of the Bootloader in principle. Therefore, great care
 *                must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these definitions are meant for demonstration purposes only,
 *                Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the
 *                extent admissible by law or statute.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  THIS IS A GENERATED FILE
 *  Generator version : 01.08.02
 *  Generation date :   2018-07-26
 *********************************************************************************************************************/

/* PRQA S 0841 EOF */ /* MD_MSR_19.6 */
/* PRQA S 0883 EOF */ /* MD_MemMap_0883 */
/* PRQA S 3116 EOF */ /* MD_MSR_3.4 */

#define FBL_MEMMAP_ERROR

#if defined( ADC_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_DBTOC_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_NOINIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_NOINIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_NOINIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_NOINIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( APPL_FBL_INFO_HEADER_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".APPLHEADER"
# undef APPL_FBL_INFO_HEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( APPL_FBL_INFO_HEADER_STOP_SEC_CONST )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef APPL_FBL_INFO_HEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BSWM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_APPL_CODE )
# pragma ghs section text=".RAMCODE"
# undef CANIF_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_APPL_CODE )
# pragma ghs section text=default
# undef CANIF_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef CANIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CODE )
# pragma ghs section text=default
# undef CANIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_16BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_16BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_32BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_32BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_16BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_16BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_32BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_32BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef CANTP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CODE )
# pragma ghs section text=default
# undef CANTP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANTP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANTP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANTP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANTP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef CAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CODE )
# pragma ghs section text=default
# undef CAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CODE_APPL )
# pragma ghs section text=".RAMCODE"
# undef CAN_START_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CODE_APPL )
# pragma ghs section text=default
# undef CAN_STOP_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_16BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_16BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_32BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_32BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_STATIC_CODE )
# pragma ghs section text=".RAMCODE"
# undef CAN_START_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_STATIC_CODE )
# pragma ghs section text=default
# undef CAN_STOP_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_INIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_INIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef COMM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CODE )
# pragma ghs section text=default
# undef COMM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_64 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_64
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_64 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_64
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_CONST_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_CONST_1BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_CONST_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_CONST_1BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_1BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_1BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_FAST_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_FAST_1BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_FAST_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_FAST_1BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_NOINIT_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_NOINIT_1BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_NOINIT_1BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEFAULT_START_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_START_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEFAULT_STOP_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEFAULT_STOP_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef DET_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CODE )
# pragma ghs section text=default
# undef DET_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef DET_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_59_RENESAS_START_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_START_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_59_RENESAS_STOP_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FAL_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".R_FAL_CONST"
# undef FAL_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FAL_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section
# pragma ghs enddata
# undef FAL_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FAL_START_SEC_PUBLIC_CODE )
# pragma ghs section text=".R_FAL_CODE_RAM"
# undef FAL_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FAL_STOP_SEC_PUBLIC_CODE )
# pragma ghs section
# undef FAL_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FAL_START_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FAL_START_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FAL_STOP_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FAL_STOP_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLAP_FBLCOMMONDATA_START_SEC_CONST )
# pragma ghs section rodata=".OTP"
# undef FBLAP_FBLCOMMONDATA_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLAP_FBLCOMMONDATA_STOP_SEC_CONST )
   # pragma ghs section
# undef FBLAP_FBLCOMMONDATA_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLAP_RAMCODE_START_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_START_SEC_CODE_EXPORT )
# pragma ghs section text=".RAMCODE"
# undef FBLAP_RAMCODE_START_SEC_CODE
# undef FBLAP_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLAP_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT )
# pragma ghs section
# undef FBLAP_RAMCODE_STOP_SEC_CODE
# undef FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCOMMONDATA_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCOMMONDATA_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCOMMONDATA_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCOMMONDATA_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_APPL_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBLCW_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_APPL_CODE )
# pragma ghs section text=default
# undef FBLCW_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBLCW_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBLCW_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef FBLCW_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef FBLCW_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef FBLCW_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_8BIT )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_RAMCODE_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBLDIAG_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_RAMCODE_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBLDIAG_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHEADER_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".FBLHEADER"
# undef FBLHEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHEADER_STOP_SEC_CONST )
# pragma ghs section
# pragma ghs enddata
# undef FBLHEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHW_RAMCODE_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBLHW_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHW_RAMCODE_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBLHW_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT )
# pragma ghs section text=".R_FAL_CODE_RAM"
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT )
# pragma ghs section
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".R_FAL_CONST"
# undef FBLLIB_MEM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_CONST )
# pragma ghs section
# pragma ghs enddata
# undef FBLLIB_MEM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_VAR ) || \
    defined( FBLLIB_MEM_START_SEC_VAR_EXPORT )
# pragma ghs startdata
# pragma ghs section data=".R_FAL_DATA" 
# undef FBLLIB_MEM_START_SEC_VAR
# undef FBLLIB_MEM_START_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_VAR ) || \
    defined( FBLLIB_MEM_STOP_SEC_VAR_EXPORT )
# pragma ghs section 
# pragma ghs enddata
# undef FBLLIB_MEM_STOP_SEC_VAR
# undef FBLLIB_MEM_STOP_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLMIO_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLMIO_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLUPDATE_START_SEC_CONST ) || \
    defined( FBLUPDATE_START_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDATE_START_SEC_CONST
# undef FBLUPDATE_START_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLUPDATE_STOP_SEC_CONST ) || \
    defined( FBLUPDATE_STOP_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDATE_STOP_SEC_CONST
# undef FBLUPDATE_STOP_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_INIT_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_INIT_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_RAMCODE_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBLWD_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_RAMCODE_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBLWD_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_APPLVECT_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".APPLVECT"
# undef FBL_APPLVECT_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_APPLVECT_STOP_SEC_CONST )
# pragma ghs section
# pragma ghs enddata
# undef FBL_APPLVECT_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_BM_START_SEC_CODE )

# undef FBL_BM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BM_STOP_SEC_CODE )

# undef FBL_BM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_BM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_BM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_BM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BMPRESPAT_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_BMPRESPAT_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BMPRESPAT_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_BMPRESPAT_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BMINFO_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".BOOTM"
# undef FBL_BMINFO_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_BMINFO_STOP_SEC_CONST )
# pragma ghs section
# pragma ghs enddata
# undef FBL_BMINFO_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_CW_FULL_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBL_CW_FULL_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_CW_FULL_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBL_CW_FULL_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MAIN_FBLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MAIN_FBLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_MAIN_FBLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MAIN_FBLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MAIN_MAGICFLAG_START_SEC_VAR )
# pragma ghs startdata
# pragma ghs section bss=".MAGICFLAG"
# undef FBL_MAIN_MAGICFLAG_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_MAIN_MAGICFLAG_STOP_SEC_VAR )
# pragma ghs section
# pragma ghs enddata
# undef FBL_MAIN_MAGICFLAG_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_SHUTDOWNSTATUS_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_SHUTDOWNSTATUS_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_SHUTDOWNSTATUS_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_SHUTDOWNSTATUS_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_AP_RAMCODE_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBL_UPD_AP_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_AP_RAMCODE_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_MAIN_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_MAIN_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_MAIN_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_MAIN_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_RAMCODE_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef FBL_UPD_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_RAMCODE_STOP_SEC_CODE )
# pragma ghs section text=default
# undef FBL_UPD_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_START_SEC_BUFFER_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_START_SEC_BUFFER_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_STOP_SEC_BUFFER_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_STOP_SEC_BUFFER_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLASHCODE_START_SEC_VAR ) || \
    defined( FLASHCODE_START_SEC_VAR_EXPORT )
# pragma ghs startdata
# pragma ghs section bss=".FLASHDRV"
# undef FLASHCODE_START_SEC_VAR
# undef FLASHCODE_START_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLASHCODE_STOP_SEC_VAR ) || \
    defined( FLASHCODE_STOP_SEC_VAR_EXPORT )
# pragma ghs section
# pragma ghs enddata
# undef FLASHCODE_STOP_SEC_VAR
# undef FLASHCODE_STOP_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_PRIVATERAM_CODE )
# pragma ghs section text=".RAMCODE"
# undef FLS_59_RENESAS_START_SEC_PRIVATERAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_PRIVATERAM_CODE )
# pragma ghs section text=default

# undef FLS_59_RENESAS_STOP_SEC_PRIVATERAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_PRIVATERAM_CODE )
# pragma ghs section text=".RAMCODE"
# undef FLS_START_SEC_PRIVATERAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_PRIVATERAM_CODE )
# pragma ghs section text=default
# undef FLS_STOP_SEC_PRIVATERAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_NOINIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_NOINIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_NOINIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_NOINIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_APPL_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_APPL_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_APPL_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_APPL_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_DBTOC_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MEMCPY_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef MEMCPY_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMCPY_STOP_SEC_CODE )
# pragma ghs section text=default
# undef MEMCPY_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MEMIF_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMIF_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MEMIF_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMIF_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MEMIF_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMIF_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CONST_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CONST_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CONST_DESCRIPTOR_TABLE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_VAR_FAST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_VAR_FAST_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_VAR_FAST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_VAR_FAST_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_VAR_NOINIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_VAR_NOINIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_VAR_NOINIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_VAR_NOINIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef PDUR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CODE )
# pragma ghs section text=default
# undef PDUR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CONST_UNSPECIFIED )
# pragma ghs startdata
# pragma ghs section rodata=".RAMCONST"
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CONST_UNSPECIFIED )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_VAR_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( R_FAL_START_SEC_CONST )
# pragma ghs startdata
# pragma ghs section rodata=".R_FAL_CONST"
# undef R_FAL_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( R_FAL_STOP_SEC_CONST )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef R_FAL_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( R_FAL_START_SEC_DATA )
# pragma ghs startdata
# pragma ghs section rodata=".R_FAL_DATA"
# undef R_FAL_START_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( R_FAL_STOP_SEC_DATA )
# pragma ghs section rodata=default
# pragma ghs enddata
# undef R_FAL_STOP_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( R_FAL_START_SEC_RAM_CODE )
# pragma ghs section text=".R_FAL_CODE_RAM"
# undef R_FAL_START_SEC_RAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( R_FAL_STOP_SEC_RAM_CODE )
# pragma ghs section text=default
# undef R_FAL_STOP_SEC_RAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( R_FAL_START_SEC_ROM_CODE )
# pragma ghs section text=".R_FAL_CODE_ROM"
# undef R_FAL_START_SEC_ROM_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( R_FAL_STOP_SEC_ROM_CODE )
# pragma ghs section text=default
# undef R_FAL_STOP_SEC_ROM_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMWS_START_SEC_DATA ) || \
    defined( SECMWS_START_SEC_DATA_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMWS_START_SEC_DATA
# undef SECMWS_START_SEC_DATA_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMWS_STOP_SEC_DATA ) || \
    defined( SECMWS_STOP_SEC_DATA_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMWS_STOP_SEC_DATA
# undef SECMWS_STOP_SEC_DATA_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_59_RENESAS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_NO_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSTDLIB_START_SEC_CODE )
# pragma ghs section text=".RAMCODE"
# undef VSTDLIB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSTDLIB_STOP_SEC_CODE )
# pragma ghs section text=default
# undef VSTDLIB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_DRIVERB_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_DRIVERB_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_DRIVERB_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_PRIVATE_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_PRIVATE_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_PUBLIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_PUBLIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_59_RENESAS_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDTRIGGER_START_SEC_CODE ) || \
    defined( WDTRIGGER_START_SEC_CODE_EXPORT )
# pragma ghs section text=".RAMCODE"
# undef WDTRIGGER_START_SEC_CODE
# undef WDTRIGGER_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDTRIGGER_STOP_SEC_CODE ) || \
    defined( WDTRIGGER_STOP_SEC_CODE_EXPORT )
# pragma ghs section
# undef WDTRIGGER_STOP_SEC_CODE
# undef WDTRIGGER_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MEMMAP_ERROR )
# error "Error in MemMap.h: MemMap section is not included!"
#endif

/* Module specific MISRA deviations:

   MD_MemMap_0883:
      Reason:     This file has to be included multiple times explicitly, due to the memory mapping mechanism.
      Risk:       No risk due to the undef pragmas and error pragma.
      Prevention: No prevention.

*/

/**********************************************************************************************************************
 *  END OF FILE: MEMMAP.H
 *********************************************************************************************************************/
