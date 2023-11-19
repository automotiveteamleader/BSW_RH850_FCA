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
 *  02.05.01   2017-01-23  HRf     ESCAN00093666    Change filter rule to support use-case with FIPS-186
 *  02.06.00   2017-07-25  JHg     ESCAN00096044    Added support for Ed25519 signatures
 *  02.07.00   2017-11-21  JHg     ESCAN00097510    Select available de-/encryption and verification workspaces at compile-time
 **********************************************************************************************************************/

#ifndef __SEC_WORKSPACE_H__
#define __SEC_WORKSPACE_H__

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_SecModHis CQComponent : Impl_Workspace */
#define SYSSERVICE_SECMODHIS_WORKSPACE_VERSION            0x0207u
#define SYSSERVICE_SECMODHIS_WORKSPACE_RELEASE_VERSION    0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/* PRQA S 0828 TAG_SecWorkspace_0828_1 */ /* MD_MSR_1.1_828 */ 

#define SECMWS_START_SEC_DATA_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if defined( SEC_ENABLE_SECURITY_CLASS_CCC )
#  if defined( SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 )
#   if defined( SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 )
V_MEMROM0 extern V_MEMROM1 SecM_WorkspacePtrType   V_MEMROM2 secWorkSpacePtrSigRsaV15Rmd160;
V_MEMROM0 extern V_MEMROM1 SecM_LengthType         V_MEMROM2 secWorkSpaceSizeSigRsaV15Rmd160;
#   endif /* SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 */
#  endif /* SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 */
# endif /* SEC_ENABLE_SECURITY_CLASS_CCC */

#define SECMWS_STOP_SEC_DATA_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA L:TAG_SecWorkspace_0828_1 */

#endif /* __SEC_WORKSPACE_H__ */

/***********************************************************************************************************************
 *  END OF FILE: SEC_WORKSPACE.H
 **********************************************************************************************************************/

