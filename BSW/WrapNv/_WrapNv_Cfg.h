/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM-specific wrapper for FEE access
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
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2016-02-05  Rie     -                Initial version
 *  02.01.00   2016-03-11  Rie     -                Fixed macros/defines for EepM use-case
 *                                 -                Update to new interface
 *  02.02.00   2016-07-05  Rie     ESCAN00090830    Added support for no NV driver use-case
 *  02.02.01   2016-09-06  Rie     ESCAN00091757    Fixed MISRA findings
 *  02.02.02   2016-10-17  Rie     ESCAN00092351    Configure used FEE functions
 *  02.03.00   2017-09-19  Rie     ESCAN00094172    No changes
 *                                 ESCAN00095574    Added support for EA
 *  02.04.00   2017-11-29  Rie     ESCAN00096851    No changes
 *                                 ESCAN00097590    Added constants for Record ID check
 *                                 ESCAN00097591    No changes
 *  02.04.01   2018-01-11  Rie     ESCAN00097944    No changes
 *                                 ESCAN00097953    No changes
 *  02.05.00   2018-02-08  Rie     ESCAN00097770    Specify call cycle for main functions
 *  02.06.00   2018-03-21  Rie     ESCAN00098860    Added support for EEL
 *  02.06.01   2018-04-06  Rie     ESCAN00099015    No changes
 *********************************************************************************************************************/

#ifndef __WRAPNV_CFG_H__
#define __WRAPNV_CFG_H__

/***********************************************************************************************************************
 *  CONFIGURATION SWITCHES
 **********************************************************************************************************************/

#if defined( WRAPNV_USECASE_FEE )    
#else
#  define WRAPNV_USECASE_FEE
#endif

#if defined( WRAPNV_USECASE_FEE ) 
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "Std_Types.h"
# include "MemIf_Types.h"
# if defined( WRAPNV_USECASE_FEE )
#  include "Fls.h"
#  include "Fee.h"
# endif /* WRAPNV_USECASE_* */

/**********************************************************************************************************************
 *  CONFIGURATION DEFINES
 *********************************************************************************************************************/

# if defined( WRAPNV_USECASE_FEE ) 
/** Prefix of a NV block */
#  define WRAPNV_BLOCK_PREFIX(value)         FeeConf_FeeBlockConfiguration_Fee ## value /* PRQA S 0342 */ /* MD_WrapNv_0342 */
/** Function called in synchronous API while waiting for the job to be finished. Also used to get a millisecond cycle. */
#  define WRAPNV_TRIGGER_FCT()               ((FblRealTimeSupport() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
/** Configure whether the Fee/Fls should be initialized during WrapNv initialization */
#  define WRAPNV_ENABLE_MEM_INITIALIZATION
# endif /* WRAPNV_USECASE_* */

/** Maximum size of all NV blocks */
# define WRAPNV_MAX_BLOCK_LENGTH             0x100u

/** Main function call cycle
 *   0 = Polling
 *  >0 = Millisecond cycle call
 */
# if defined( WRAPNV_USECASE_FEE ) 
#  define WRAPNV_HWDRV_CYCLE_MAINFUNCTION    0u       /**< Call cylce for HWDRV (Fls/Eep) */
#  define WRAPNV_MEMDRV_CYCLE_MAINFUNCTION   0u       /**< Call cylce for MEMDRV (Fee/Ea) */
# endif

# if defined( WRAPNV_USECASE_FEE )
/** FLS function abstraction */
#  define WRAPNV_HWDRV_INIT                  Fls_Init
#  define WRAPNV_HWDRV_MAINFUNCTION          Fls_MainFunction
/** FLS configuration set used by NV-Wrapper */
#  define WRAPNV_HWDRV_INIT_PARAMETER        FlsConfigSet

/** FEE function abstraction */
#  define WRAPNV_MEMDRV_INIT                 Fee_Init
#  define WRAPNV_MEMDRV_GETSTATUS            Fee_GetStatus
#  define WRAPNV_MEMDRV_GETJOBRESULT         Fee_GetJobResult
#  define WRAPNV_MEMDRV_MAINFUNCTION         Fee_MainFunction
#  define WRAPNV_MEMDRV_READ                 Fee_Read
#  define WRAPNV_MEMDRV_WRITE                Fee_Write
#  define WRAPNV_MEMDRV_INVALIDATEBLOCK      Fee_InvalidateBlock
#  define WRAPNV_MEMDRV_CANCEL               Fee_Cancel

# endif /* WRAPNV_USECASE_* */
#endif

/***********************************************************************************************************************
 *  COMPATIBILITY DEFINES
 **********************************************************************************************************************/

#if defined( WRAPNV_USECASE_FEE ) 

/* TODO: add configuration for FEE/EA/NVM */
/* Below is an example */

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/*  Memory Layout
*   |
*   +-- ResetFlags
*       |
*       +-- ProgReqFlag                                           Reprogramming request flag
*       |
*       +-- ResetResponseFlag                                     Reset response flag
*/

/* Reset flags */
#define kEepSizeProgReqFlag                  0x01u
#define kEepSizeResetResponseFlag            0x01u
#define kEepSizeResetFlags                   (  kEepSizeProgReqFlag              \
                                              + kEepSizeResetResponseFlag)

/* Reset flags */
#define WRAPNV_DATASET_RESETFLAGS                  1u
#define WRAPNV_RECORD_ID_PROGREQFLAG               0u
#define WRAPNV_RECORD_ID_RESETRESPONSEFLAG         (WRAPNV_RECORD_ID_PROGREQFLAG + 1u)

#define WRAPNV_RECORD_ID_MAX                       (WRAPNV_RECORD_ID_RESETRESPONSEFLAG)

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Specifies how the NV block is configured */
typedef enum
{
   WRAPNV_RECORDACCESS_STRUCTURED = 0u,      /**< NV block consists of several elements */
   WRAPNV_RECORDACCESS_SINGLE                /**< NV block consists of a single element */
} tWrapNvRecordAccess;

/** NV block configuration strucutre */
typedef struct
{
   tWrapNvRecordAccess blockDataAccess;      /**< Access variat to the NV block */
   uint16 blockNumber;                       /**< Number of NV block */
   uint16 blockLength;                       /**< Length of NV block */
   uint16 blockMaxDatasets;                  /**< Maximum datasets alloweed for the NV block */
   P2CONST(uint8, AUTOMATIC, WRAPNV_CONST) blockDefaultValue;           /**< Default value for NV block */
} tWrapNvBlockTbl;

/** NV record configuration structure */
typedef struct
{
   uint16 recordDataOffset;                  /**< Offset in NV block to the data */
   uint16 recordDataLength;                  /**< Length of data inside the NV block */
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) recordBlockPtr;    /**< Pointer to the NV block */
} tWrapNvRecordTbl;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

extern CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[];
extern CONST(uint16, WRAPNV_CONST) kWrapNvNrOfBlock;
extern CONST(uint16, WRAPNV_CONST) kWrapNvNrOfRecord;

/***********************************************************************************************************************
 *  ACCESS MACROS
 **********************************************************************************************************************/

/* Reset flags */
#define ApplFblNvReadProgReqFlag(idx, buf)                        WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGREQFLAG, (idx), (buf))
#define ApplFblNvWriteProgReqFlag(idx, buf)                       WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGREQFLAG, (idx), (buf))
#define ApplFblNvReadAsyncProgReqFlag(idx, buf, op)               WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGREQFLAG, (idx), (buf), (op))
#define ApplFblNvWriteAsyncProgReqFlag(idx, buf, op)              WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGREQFLAG, (idx), (buf), (op))

#define ApplFblNvReadResetResponseFlag(idx, buf)                  WrapNv_ReadSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, (idx), (buf))
#define ApplFblNvWriteResetResponseFlag(idx, buf)                 WrapNv_WriteSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, (idx), (buf))
#define ApplFblNvReadAsyncResetResponseFlag(idx, buf, op)         WrapNv_ReadAsync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, (idx), (buf), (op))
#define ApplFblNvWriteAsyncResetResponseFlag(idx, buf, op)        WrapNv_WriteAsync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, (idx), (buf), (op))

#endif /* WRAPNV_USECASE_NONE */

#endif /* __WRAPNV_CFG_H__ */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV_CFG.H
 **********************************************************************************************************************/
