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
 *  02.01.00   2016-03-11  Rie     -                Update to new interface
 *  02.02.00   2016-07-05  Rie     ESCAN00090830    No changes
 *  02.02.01   2016-09-06  Rie     ESCAN00091757    No changes
 *  02.02.02   2016-10-17  Rie     ESCAN00092351    No changes
 *  02.03.00   2017-09-19  Rie     ESCAN00094172    No changes
 *                                 ESCAN00095574    No changes
 *  02.04.00   2017-11-29  Rie     ESCAN00096851    No changes
 *                                 ESCAN00097590    Added constants for Record ID check
 *                                 ESCAN00097591    No changes
 *  02.04.01   2018-01-11  Rie     ESCAN00097944    No changes
 *                                 ESCAN00097953    No changes
 *  02.05.00   2018-02-08  Rie     ESCAN00097770    No changes
 *  02.06.00   2018-03-21  Rie     ESCAN00098860    No changes
 *  02.06.01   2018-04-06  Rie     ESCAN00099015    No changes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "WrapNv.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValueResetFlags[kEepSizeResetFlags] = {0x00, 0x00};

CONST(tWrapNvBlockTbl, WRAPNV_CONST) kWrapNvBlockTbl[] =
{
   /* Reset flags */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      WRAPNV_BLOCK_PREFIX(FblResetFlags),
      kEepSizeResetFlags,
      WRAPNV_DATASET_RESETFLAGS,
      kWrapNvDefaultValueResetFlags
   }
};

CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[] =
{
   /* Reset flags */
   {  /* Reprogramming flag */
      0u,
      kEepSizeProgReqFlag,
      &kWrapNvBlockTbl[0]
   },

   {  /* Reset response flag */
      1u,
      kEepSizeResetResponseFlag,
      &kWrapNvBlockTbl[0]
   }
};

CONST(uint16, WRAPNV_CONST) kWrapNvNrOfBlock = sizeof(kWrapNvBlockTbl) / sizeof(kWrapNvBlockTbl[0]);
CONST(uint16, WRAPNV_CONST) kWrapNvNrOfRecord = sizeof(kWrapNvRecordTbl) / sizeof(kWrapNvRecordTbl[0]);

# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV_CFG.C
 **********************************************************************************************************************/
