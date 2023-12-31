/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file         WrapNv.h
 *  \brief        Wrapper for NV-memory access
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
 *  02.00.00   2016-02-22  Rie     ESCAN00088726    Added support for Fee/NvM
 *                                                  Removed unused code
 *  02.01.00   2016-03-09  Rie     ESCAN00088817    Removed function call NvM_Errorhook
 *                                 ESCAN00088819    Abstraction of Fls interface
 *  02.02.00   2016-07-05  Rie     ESCAN00090830    Added support for no NV driver use-case
 *  02.02.01   2016-09-06  Rie     ESCAN00091757    Fixed MISRA findings
 *  02.02.02   2016-10-17  Rie     ESCAN00092351    Configure used FEE functions
 *  02.03.00   2017-09-19  Rie     ESCAN00094172    Fixed compiler warning undefined preprocessor define
 *                                 ESCAN00095574    Added support for EA
 *  02.04.00   2017-11-29  Rie     ESCAN00096851    Updated APIs for MSR-Release 18
 *                                 ESCAN00097590    Added error code for Record ID check
 *                                 ESCAN00097591    Added support for sequential queue handling of asynchronous access
 *  02.04.01   2018-01-11  Rie     ESCAN00097944    Fixed state handling
 *                                 ESCAN00097953    Fixed endless loop
 *  02.05.00   2018-02-08  Rie     ESCAN00097770    Consider main function call cycle
 *  02.06.00   2018-03-21  Rie     ESCAN00098860    Added support for EEL
 *  02.06.01   2018-04-06  Rie     ESCAN00099015    No changes
 *********************************************************************************************************************/

#ifndef __WRAPNV_H__
#define __WRAPNV_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_WrapperNv CQComponent : Implementation */
#define SYSSERVICE_WRAPPERNV_VERSION              0x0206u
#define SYSSERVICE_WRAPPERNV_RELEASE_VERSION      0x01u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "WrapNv_Cfg.h"
#if defined( WRAPNV_USECASE_FEE ) 
# include "Std_Types.h"
#endif /* WRAPNV_USECASE_* */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#if defined( WRAPNV_USECASE_FEE ) 
/* Vendor and module identification */
# define WRAPNV_VENDOR_ID           30u
# define WRAPNV_MODULE_ID           255u
# define WRAPNV_INSTANCE_ID         0u

/* Service IDs */
# define WRAPNV_APIID_INIT          0x00u
# define WRAPNV_APIID_READ          0x01u
# define WRAPNV_APIID_READPARTIAL   0x02u
# define WRAPNV_APIID_WRITE         0x03u
# define WRAPNV_APIID_DELETE        0x04u

/* Development errors */
# define WRAPNV_E_NO_ERROR          0x10u
# define WRAPNV_E_NOT_IDLE          0x11u
# define WRAPNV_E_PARAM_DATASET     0x12u
# define WRAPNV_E_PARAM_READ        0x13u
# define WRAPNV_E_PARAM_ID          0x14u
#endif /* WRAPNV_USECASE_* */

/* PRQA S 0883 TAG_WrapNv_0883 */ /* MD_WrapNv_0883 */
/** Positive return value of NV-Wrapper */
#if defined( kFblOk )
# define WRAPNV_E_OK                kFblOk
#elif defined( kEepMgrOk )
# define WRAPNV_E_OK                kEepMgrOk
#elif defined( E_OK )
# define WRAPNV_E_OK                E_OK
#else
# define WRAPNV_E_OK                0u
#endif

/** Negative return value of NV-Wrapper */
#if defined( kFblFailed )
# define WRAPNV_E_NOT_OK            kFblFailed
#elif defined( kEepMgrFailed )
# define WRAPNV_E_NOT_OK            kEepMgrFailed
#elif defined( E_NOT_OK )
# define WRAPNV_E_NOT_OK            E_NOT_OK
#else
# define WRAPNV_E_NOT_OK            1u
#endif

/** Pending return value of NV-Wrapper */
#if defined( kEepMgrBusy )
# define WRAPNV_E_PENDING           kEepMgrBusy
#elif defined( E_PENDING )
# define WRAPNV_E_PENDING           E_PENDING
#else
# define WRAPNV_E_PENDING           2u
#endif

/** Return type of NV-Wrapper */
#if defined( kFblOk )
# define WrapNv_ReturnType          tFblResult
#elif defined( kEepMgrOk )
# define WrapNv_ReturnType          vuint8
#elif defined( E_OK )
# define WrapNv_ReturnType          Std_ReturnType
#else
# define WrapNv_ReturnType          WrapNv_DefaultReturntype
#endif
/* PRQA L:TAG_WrapNv_0883 */

/**********************************************************************************************************************
 *  TYPEDEFS
 *********************************************************************************************************************/

/** Operation status for asynchronous access */
typedef enum
{
   WRAPNV_OPSTATUS_INIT = 0u,       /**< Operation has been initialized */
   WRAPNV_OPSTATUS_PENDING,         /**< Operation is currently pending */
   WRAPNV_OPSTATUS_CANCEL,          /**< Operation has been canceled */
   WRAPNV_OPSTATUS_IDLE             /**< Internal: Currently no operation is active */
} tWrapNvOpStatus;

#if defined( WRAPNV_USECASE_FEE ) 
typedef P2VAR(uint8, AUTOMATIC, WRAPNV_DATA) tWrapNvRamData;
typedef P2CONST(uint8, AUTOMATIC, WRAPNV_DATA) tWrapNvConstData;
#endif /* WRAPNV_USECASE_* */

typedef unsigned char WrapNv_DefaultReturntype;

#if defined( WRAPNV_USECASE_FEE ) 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, WRAPNV_CODE) WrapNv_Init( void );

FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadSync( uint16 id, uint16 idx, tWrapNvRamData buffer );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialSync( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteSync( uint16 id, uint16 idx, tWrapNvConstData buffer );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteSync( uint16 id, uint16 idx );

FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadAsync( uint16 id, uint16 idx, tWrapNvRamData buffer, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialAsync( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteAsync( uint16 id, uint16 idx, tWrapNvConstData buffer, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteAsync( uint16 id, uint16 idx, tWrapNvOpStatus opStatus );

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* WRAPNV_USECASE_* */

#endif /* __WRAPNV_H__ */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV.H
 **********************************************************************************************************************/
