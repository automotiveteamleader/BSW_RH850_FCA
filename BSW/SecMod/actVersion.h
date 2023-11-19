/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Crypto library
 *
 *  \description  Main header file of actCLibrary by cryptovision GmbH.
 *                Additional header used to document changes implemented by Vector Informatik GmbH.
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
 *  Thorsten Albers               Al            Vector Informatik GmbH
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Markus Schneider              Mss           Vector Informatik GmbH
 *  Tobias Finke                  Tof           Vector Informatik GmbH
 *  Philipp Ritter                Rpp           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2013-06-20  Al      -                Include Vector platform definitions
 *                         JHg     ESCAN00068214    Initial release based on original actCLibrary and
 *                                                   SysService_Crypto 01.04.01
 *                                                  File renamed from platform_t.h to actPlatformTypes.h
 *                                                  Moved from cv act library/ES
 *                                                  Declare base types defined by Vector platform definitions
 *                                                  Added ACT prefix to configuration settings
 *                                                  Use ULLONG_MAX from limits.h to detect availability of 64 bit type
 *                                                  Use compiler abstraction for ROM pointers from Vector platform definitions
 *                                                  Added additional watchdog triggers
 *  01.01.00   2013-09-26  JHg     ESCAN00070712    Added version information
 *                                                  Additional compiler abstraction
 *                                                  Added option to locate cryptographic keys in RAM instead of ROM
 *                                                  Include primitives for DES, T-DES and RC2
 *  01.02.00   2014-01-14  JHg     ESCAN00072933    Corrected ROM pointer cast in actECInit (actECTools.c)
 *  01.03.00   2014-01-20  JHg     ESCAN00073066    Corrected output length for symmetric stream decryption
 *  01.04.00   2014-02-11  JHg     ESCAN00073602    No changes
 *  01.04.01   2014-03-21  JHg     ESCAN00074421    Renamed certain single letter upper-case variables and members
 *  01.05.00   2014-04-23  JHg     ESCAN00074879    Added memcpy and memcmp variants for ROM to/with RAM
 *  01.06.00   2014-04-28  JHg     ESCAN00075252    Added dedicated file for version information
 *  02.00.00   2014-05-16  Mss     ESCAN00075464    Added memory qualifier abstraction for ASR/CBD
 *  02.00.01   2014-07-22  Mss     ESCAN00076891    Added an abstraction layer for usage within ASR context
 *                         JHg     ESCAN00075506    Replaced down-cast in actGetByte by bit-mask
 *  02.00.02   2014-11-28  Mss     ESCAN00079873    Remapping of error code in actGetExternRandom
 *  02.01.00   2014-01-22  Mss     ESCAN00080924    Rework of compiler abstraction for RSA and SHA256
 *  02.01.01   2015-02-03  Mss     ESCAN00081006    No changes
 *  02.02.00   2015-06-16  Mss     ESCAN00083455    Rework of compiler abstraction for remaining services
 *  02.03.00   2015-10-12  JHg     ESCAN00085787    Compiler abstraction: Differentiate pointers to constants in RAM and ROM
 *                         JHg     ESCAN00085791    Added functions to evaluate length in bits of RSA modulus
 *  02.04.00   2016-05-03  JHg     ESCAN00089871    Added support for CMAC (AES-128) generation/verification
 *                         JHg     ESCAN00089872    Added support for additional padding and block operation modes
 *             2016-06-15  Tof     ESCAN00090486    Added support for EdDSA, ECDH, GCM, GMAC, SHA-512
 *  02.04.01   2016-07-06  Tof     ESCAN00090852    Compiler error fix
 *  02.04.02   2016-08-04  Tof     ESCAN00091318    Fixed missing Optimization defines in actConfig.h
 *  02.04.03   2016-10-24  Tof     ESCAN00092483    Fixed wrong return value when AES decryption with padding failed
 *                                 ESCAN00092634    Fixed wrong file encoding of act25519util.c and act25519util.h
 *  02.05.00   2017-02-16  Mss     ESCAN00094050    Added support for SipHash
 *                                                  Renaming of actISHA2-32/64 due to potential compiler issues
 *                                                  Support of variant Ed25519ctx
 *  02.05.01   2017-06-21  Tof     ESCAN00095582    Signature fails when RAM variables are not initialized correctly
 *  02.06.00   2017-10-06  Mss     ESCAN00096934    Support for 16 bit platforms: SHA-384 and SHA-512
 *  02.09.00   2018-02-21  Rpp     ESCAN00095776    64 bit compiler support
 *                                 ESCAN00098553    Added support for EC-B/D key agreement
 *                                 ESCAN00098221    Fixed compiler error: actSHA2_64.c
 *                                 ESCAN00087210    Fixed Crypto routines fail on word-addressed platforms
 *                                                  for Signature Verification RSA2048-SHA256
 *                                 ESCAN00087210    Crypto routines fail on word-addressed platforms
 *                                 ESCAN00096521    Include actEd25519.h instead of actED25519.h
 *                                 ESCAN00090114    Removed compiler warning due to assignment in condition for big nums
 *  02.09.01   2018-03-27  Rpp     ESCAN00098933    ECBD exits with actEXCEPTION_POINT and could violate memory
 *                                 ESCAN00097093    Improved watchdog triggering for Curve25519 and its pre hashing
 *  02.09.02   2018-04-17          ESCAN00099166    Ensure backward compatibility:
 *                                                  - Standard Wdg Level was set back to 3
 *                                                  - Moved actRSACRTSTRUCT from actIRSAExp.h to actIRSA.h
 *                                 ESCAN00099167    Removed some C++ comments
 *                                 ESCAN00099169    Unreferenced formal parameter watchdog in actX25519.c
 *  02.10.00   2018-05-08  Rpp     STORYC-5007      Support ChaCha20 and Poly1305
 *                                 ESCAN00099420    Fixed compiler error for SHA2 without uint64 support
 **********************************************************************************************************************/

#ifndef ACTVERSION_H
#define ACTVERSION_H

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_CryptoCv CQComponent : Impl_actCLib */
#define SYSSERVICE_CRYPTOCV_ACTLIB_VERSION            0x020Au
#define SYSSERVICE_CRYPTOCV_ACTLIB_RELEASE_VERSION    0x00u

/*********************************************************************************************************************/

#endif /* ACTVERSION_H */

