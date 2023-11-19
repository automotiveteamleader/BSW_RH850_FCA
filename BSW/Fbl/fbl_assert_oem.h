/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM specific assertion defines
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
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.01.00   2018-01-11  CB      -                Initial implementation 
 *  00.95.00   2018-07-11  CB      -                Pre Release
 **********************************************************************************************************************/

#ifndef __FBL_ASSERT_OEM_H__
#define __FBL_ASSERT_OEM_H__

/***********************************************************************************************************************
 *  DEFINITION OF ASSERTION CODES (OEM)
 **********************************************************************************************************************/

/* 0x80-0xFF: OEM specific */
/* Diagnostic module errors */
#define kFblOemAssertMainHandlerIdxInvalid   0x80u
#define kFblOemAssertWrongServiceHandler     0x81u
#define kFblOemAssertInvalidError            0x82u
#define kFblOemAssertNoNrcSet                0x83u

/***********************************************************************************************************************
 *  END OF FILE: FBL_ASSERT_OEM.H
 **********************************************************************************************************************/

#endif /* __FBL_ASSERT_OEM_H__ */