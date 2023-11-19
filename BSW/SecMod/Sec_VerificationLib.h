/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the verification component of the HIS security module - Signature verification
 *
 *  \description  Offers signature/checksum verification primitives based on hash, MAC and RSA
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

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Alexander Starke              ASe           Vector Informatik GmbH
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Thomas Mueller                ThM           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2013-06-20  JHg     ESCAN00068213    Initial release based on FblSecMod_Vector 02.02.00
 *  02.00.00   2013-11-08  JHg     ESCAN00071179    Major refactoring
 *                                                   Moved to separate sub-package
 *                                                   Split into source and library parts
 *                                                   Select available verification primitives at integration-time
 *  02.00.01   2013-12-19  JHg     ESCAN00072260    No changes
 *                         JHg     ESCAN00072561    No changes
 *  02.00.02   2014-01-20  JHg     ESCAN00073088    No changes
 *  02.01.00   2014-01-28  ASe     ESCAN00073047    No changes
 *  02.02.00   2014-02-10  JHg     ESCAN00073560    No changes
 *                         JHg     ESCAN00073355    No changes
 *  02.02.01   2014-05-28  JHg     ESCAN00074792    No changes
 *                         JHg     ESCAN00073918    No changes
 *  02.02.02   2015-02-09  CB      ESCAN00078641    No changes
 *  02.02.03   2015-07-29  AWh     ESCAN00084130    No changes
 *  02.03.00   2015-10-12  JHg     ESCAN00085807    Added support for RSASSA-PSS signatures
 *                         JHg     ESCAN00085808    No changes
 *  02.04.00   2015-11-03  JHg     ESCAN00086240    No changes
 *                         JHg     ESCAN00086241    No changes
 *  02.04.01   2015-12-18  JHg     ESCAN00087162    No changes
 *  02.04.02   2016-04-25  ThM     ESCAN00083969    No changes
 *  02.05.00   2016-06-29  JHg     ESCAN00089793    Added support for CMAC (AES-128)
 *                         JHg     ESCAN00090735    No changes
 *  02.05.01   2016-07-08  JHg     ESCAN00090837    No changes
 *  02.06.00   2017-01-18  JHg     ESCAN00093624    Added support for CRC-64
 *  02.07.00   2017-07-25  JHg     ESCAN00096043    Added support for Ed25519 signatures
 *                         JHg     ESCAN00096047    Added support for SHA-512 hashes
 *  02.07.01   2017-09-05  Ach     ESCAN00096544    No changes
 *  02.08.00   2017-11-21  JHg     ESCAN00097509    Select available verification primitives at compile-time
 *  02.08.01   2018-01-23  JHg     ESCAN00097060    No changes
 *                         JHg     ESCAN00098081    No changes
 **********************************************************************************************************************/

#ifndef __SEC_VERIFICATIONLIB_H__
#define __SEC_VERIFICATIONLIB_H__

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

#define SYSSERVICE_SECMODHIS_VERIFICATIONLIB_VERSION            0x0208u
#define SYSSERVICE_SECMODHIS_VERIFICATIONLIB_RELEASE_VERSION    0x01u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

#include "Sec_Verification.h"

/* ES library access */
#include "ESLib.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if defined( SEC_ENABLE_SECURITY_CLASS_CCC )
# if defined( SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 )
#  if defined( SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 )
/** Workspace for RIPEMD-160 RSA V1.5 signature primitive */
typedef struct
{
   SecM_BasicWkspSigRsaV15Rmd160Type      basic;   /**< Basic information (message digest, keys) */
   eslt_WorkSpaceRSAver                   esLib;   /**< ESLib workspace */
} SecM_WorkspaceSigRsaV15Rmd160Type;
#  endif /* SEC_ENABLE_HASH_ALGORITHM_RIPEMD160 */
# endif /* SEC_ENABLE_SIGNATURE_SCHEME_RSA_V15 */

#endif /* SEC_ENABLE_SECURITY_CLASS_CCC */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

/* Inclusion only allowed in modules which are delivered as object code, e.g. Sec_VerificationLib.c and Sec_Workspace.c! */
#if defined( SEC_OBJECT_CODE_ONLY )
#else
# error "Error in SEC_VERIFICATIONLIB.H: Included in file which isn't marked as object code delivery!"
#endif

#endif /* __SEC_VERIFICATIONLIB_H__ */

/***********************************************************************************************************************
 *  END OF FILE: SEC_VERIFICATIONLIB.H
 **********************************************************************************************************************/

