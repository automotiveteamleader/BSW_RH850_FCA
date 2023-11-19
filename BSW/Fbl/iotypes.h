/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         HIS IO driver types
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
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Torben Stoessel               TnS           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2015-09-23  JHg     ESCAN00085431    No changes
 *                         JHg     ESCAN00085436    No changes
 *                         JHg     ESCAN00085438    No changes
 *                         JHg     ESCAN00085439    No changes
 *  02.01.00   2018-02-09  TnS     ESCAN00088473    No changes
 *                         Ach     ESCAN00098291    Wrong include sequence in configurations with FblHal module
 **********************************************************************************************************************/

#ifndef __IO_TYPES_H__
#define __IO_TYPES_H__

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "v_cfg.h"
#include "FblHal_Cfg.h"
#include "v_def.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define IO_E_OK         0x00u             /**< Memory driver action successful */
#define IO_E_NOT_OK     0x01u             /**< Memory driver action failed */
#define IO_E_ERASED     0xE5u             /**< Read failure (e.g. ECC), but memory is assumed to be erased */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef vuint8    IO_U8;
typedef vuint16   IO_U16;
typedef vuint32   IO_U32;
typedef vsint8    IO_S8;
typedef vsint16   IO_S16;
typedef vsint32   IO_S32;

#if ( !defined( C_CPUTYPE_8BIT ) || \
    defined( FBL_PROCESSOR_BANKED ))
typedef vuint32   IO_SizeType;
typedef vuint32   IO_PositionType;
#else
typedef vuint16   IO_SizeType;
typedef vuint16   IO_PositionType;
#endif

typedef vuint16   IO_ErrorType;
typedef vuint8*   IO_MemPtrType;

#endif /* __IO_TYPES_H__ */

/***********************************************************************************************************************
 *  END OF FILE: IOTYPES.H
 **********************************************************************************************************************/
