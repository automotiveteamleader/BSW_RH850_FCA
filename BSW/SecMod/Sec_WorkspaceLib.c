/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the verification component of the HIS security module - Default workspaces
 *
 *  \description  Defines the default workspaces used by the library parts for verification, seed/key and decryption
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Markus Schneider              Mss           Vector Informatik GmbH
 *  Ralf Haegenlaeuer             HRf           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2013-06-20  JHg     ESCAN00068213    Initial release based on FblSecMod_Vector 02.02.00
 *  02.00.00   2013-10-01  JHg     ESCAN00070691    Major refactoring
 *                                                   Moved to separate sub-package
 *                                                   Select available workspaces at integration-time
 *                                                   Export pointer and size of workspaces instead workspaces directly
 *  02.01.00   2013-11-08  JHg     ESCAN00071174    Added support for seed/key and verification (filter settings)
 *  02.02.00   2013-12-19  Mss     ESCAN00072741    Added support for AES encryption
 *  02.03.00   2014-02-12  Mss     ESCAN00073596    Added support for AES192 and AES256
 *  02.03.01   2014-05-26  JHg     ESCAN00075254    Fixed case of MemMap.h
 *  02.04.00   2015-10-12  JHg     ESCAN00085809    Added support for RSASSA-PSS signatures
 *  02.05.00   2016-06-29  JHg     ESCAN00089791    Added support for CMAC (AES-128)
 *                         JHg     ESCAN00090734    Added support for FIPS-186 PRNG
 *  02.05.01   2017-01-23  HRf     ESCAN00093666    No changes
 *  02.06.00   2017-07-25  JHg     ESCAN00096044    Added support for Ed25519 signatures
 *                                                  Added esl_getBytesRNG
 *  02.07.00   2017-11-21  JHg     ESCAN00097510    Select available de-/encryption and verification workspaces at compile-time
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* File has to be delivered as object code */
#define SEC_OBJECT_CODE_ONLY

/* Security module configuration settings */
#include "Sec_Inc.h"                /* PRQA S 0883 */ /* MD_SecInc_0883 */

/* Global definitions for security module */
#include "Sec_Types.h"

/* Required for configuration switches */
# include "Sec_Verification.h"      /* PRQA S 0883 */ /* MD_SecInc_0883 */

/* Workspace interface */
#include "Sec_Workspace.h"

/* Required for definitions of workspace types */
# include "Sec_VerificationLib.h"   /* PRQA S 0883 */ /* MD_SecInc_0883 */

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

#if ( SYSSERVICE_SECMODHIS_WORKSPACE_VERSION != 0x0207u ) || \
    ( SYSSERVICE_SECMODHIS_WORKSPACE_RELEASE_VERSION != 0x00u )
# error "Error in SEC_WORKSPACE.C: Source and header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#define SECMWS_START_SEC_DATA
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if defined( SEC_ENABLE_SECURITY_CLASS_CCC )
#  if defined( SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 )
#   if defined( SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 )
/** Default workspace for RIPEMD-160 RSA V1.5 signature primitive */
V_MEMRAM0 static V_MEMRAM1 SecM_WorkspaceSigRsaV15Rmd160Type      V_MEMRAM2 workSpaceSigRsaV15Rmd160;
#   endif /* SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 */
#  endif /* SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 */
# endif /* SEC_ENABLE_SECURITY_CLASS_CCC */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# if defined( SEC_ENABLE_SECURITY_CLASS_CCC )
#  if defined( SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 )
#   if defined( SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 )
/** Pointer to default workspace for RIPEMD-160 RSA V1.5 signature primitive */
V_MEMROM0 V_MEMROM1 SecM_WorkspacePtrType V_MEMROM2 secWorkSpacePtrSigRsaV15Rmd160     = (SecM_WorkspacePtrType)&workSpaceSigRsaV15Rmd160;   /* PRQA S 0310 */ /* MD_SecWorkspace_0310 */
/** Size of default workspace for RIPEMD-160 RSA V1.5 signature primitive */
V_MEMROM0 V_MEMROM1 SecM_LengthType       V_MEMROM2 secWorkSpaceSizeSigRsaV15Rmd160    = sizeof(workSpaceSigRsaV15Rmd160);
#   endif /* SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 */
#  endif /* SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 */
# endif /* SEC_ENABLE_SECURITY_CLASS_CCC */

#define SECMWS_STOP_SEC_DATA
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_getBytesRNG
 *********************************************************************************************************************/
/*! \brief         Provide random bytes
 *  \details       Dummy function to resolve dependency from SysService_CryptoCv
 *  \param[in]     targetLength Length of the data to be randomized in bytes
 *  \param[out]    target Pointer to the data to be randomized
 *  \return        ESL_ERC_NO_ERROR if operation successful
 *                 ESL_ERC_ERROR if error occured during operation
 *********************************************************************************************************************/
CRYPTOCV_FUNC(eslt_ErrorCode) esl_getBytesRNG( const eslt_Length targetLength, CRYPTOCV_P2VAR_PARA(eslt_Byte) target )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Avoid compiler warnings */
   /* PRQA S 3112 2 */ /* MD_Sec_3112 */
   (void)targetLength;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   if (targetLength > 0u)
   {
      target[0u] = 0x00u;
   }

   return ESL_ERC_ERROR;
}

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecWorkspace_0310:
      Reason: References to workspaces are passed as generic pointer which is casted back to the actual type on use.
      Risk: Passing of pointer with less strict alignment than required by workspace type.
      Prevention: Generic pointer type references basic structure to enforce alignment required by most workspace types.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_WORKSPACELIB.C
 **********************************************************************************************************************/
