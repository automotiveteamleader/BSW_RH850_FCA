/****************************************************************************
 ** Main author: Ubr                     Creation date: 02/24/05
 ** $LastChangedBy: men $
 ** $Date: 2008-05-13 12:23:58 +0200 (Di, 13. Mai 2008) $
 ** $URL: https://scm/svn/library-ES/branches/library-es/1.2.0-VectorInformatik/development/common/lib_es/source/ESLib_RMD160.c $
 ** $Rev: 1620 $
 ** $NoKeywords$
 **
 **
 ** \copyright(cv cryptovision GmbH, 1999 - 2005)
 **
 ** \version(cvActLibES 1.0)
 ***************************************************************************/

/****************************************************************************
 **
 **     This file is part of the embedded systems library cvActLib/ES.
 **
 **     Layer: core level
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: RIPEMD-160 implementation file.
 **                     Currently the actClib version is used.
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **
 ** functions:
 **   esl_initRIPEMD160
 **   esl_updateRIPEMD160
 **   esl_finalizeRIPEMD160
 **
 ***************************************************************************/


#include "ESLib.h"
#include "ESLib_types.h"

/* actCLib includes */
#include "actIRMD160.h"
#include "actUtilities.h"


/****************************************************************************
 **
 ** FUNCTION: esl_initRIPEMD160
 **
 **  This function initializes the RIPEMD-160 hash calculation.
 **
 ** input:
 ** - workSpace:   algorithm context buffer, initialized by
 **                esl_initWorkSpaceHeader(..) function
 **
 ** output:
 ** - workSpace:   initialized algorithm context structure
 ** - returns:     ESL_ERC_PARAMETER_INVALID input parameter is NULL
 **                ESL_ERC_WS_TOO_SMALL      work space too small
 **                ESL_ERC_NO_ERROR          else
 **
 ** assumes:
 ** - workSpace is initialized by esl_initWorkSpaceHeader(..)
 **
 ** uses:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( eslt_ErrorCode ) esl_initRIPEMD160( CRYPTOCV_P2VAR_PARA( eslt_WorkSpaceRIPEMD160 ) workSpace )
{
   /* Any NULLs ? */
   if ( !workSpace )
   {
      return ESL_ERC_PARAMETER_INVALID;
   }

   /* Check workSpace */
   if ( workSpace->header.size < ESL_MINSIZEOF_WS_RIPEMD160 )
   {
      return ESL_ERC_WS_TOO_SMALL;
   }

   /* Init actCLib RIPEMD-160 */
   actRMD160Init( (CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ))workSpace->wsRIPEMD160 );

   /* Set workSpace state */
   workSpace->header.status = (ESL_WST_ALGO_RIPEMD160 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

   return ESL_ERC_NO_ERROR;
}

/****************************************************************************
 **
 ** FUNCTION: esl_updateRIPEMD160
 **
 **  This function updates the RIPEMD-160 calculation for the given
 **  input message (or parts of it). This function cann be called
 **  several times until all input to be hashed is handled.
 **
 ** input:
 ** - workSpace:   algorithm context buffer, initialized by
 **                esl_initRIPEMD160(..) function
 ** - workSpace: length of input data in bytes
 ** - input:       pointer to data to be handled
 **
 ** output:
 ** - workSpace:   actualized algorithm context structure
 ** - returns:     ESL_ERC_PARAMETER_INVALID input parameter is NULL
 **                ESL_ERC_WS_STATE_INVALID  work space state invalid
 **                ESL_ERC_WS_TOO_SMALL      work space too small
 **                ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW   total input length overflow
 **                ESL_ERC_NO_ERROR          else
 **
 ** assumes:
 ** - workSpace is initialized by esl_initRIPEMD160(..)
 **
 ** uses:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( eslt_ErrorCode ) esl_updateRIPEMD160(
   CRYPTOCV_P2VAR_PARA( eslt_WorkSpaceRIPEMD160 ) workSpace,
   const eslt_Length inputSize, CRYPTOCV_P2CONST_PARA( eslt_Byte ) input )
{
   /* Any NULLs ? */
   if ( (!workSpace) || (!input) )
   {
      return ESL_ERC_PARAMETER_INVALID;
   }

   /* Check workSpace */
   if ( (workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_RIPEMD160 )
   {
      return ESL_ERC_WS_STATE_INVALID;
   }
   if ( !(workSpace->header.status & ESL_WST_M_RUNNING) )
   {
      return ESL_ERC_WS_STATE_INVALID;
   }
   if ( inputSize % ESL_SIZEOF_RIPEMD160_BLOCK == 0 )
   {
      if ( workSpace->header.size < ESL_MINSIZEOF_WS_RIPEMD160 )
      {
         return ESL_ERC_WS_TOO_SMALL;
      }
   }
   else
   {
      if ( workSpace->header.size < ESL_MAXSIZEOF_WS_RIPEMD160 )
      {
         return ESL_ERC_WS_TOO_SMALL;
      }
   }

   /* Update actCLib RIPEMD-160 */
   {
      actRETURNCODE result = actRMD160Update( (CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ))workSpace->wsRIPEMD160,
                                              input, (int)inputSize, workSpace->header.watchdog );
      if ( result == actEXCEPTION_LENGTH )
      {
         return ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
      }
   }

   return ESL_ERC_NO_ERROR;
}


/****************************************************************************
 **
 ** FUNCTION: esl_finalizeRIPEMD160
 **
 **  This function finalizes the RIPEMD-160 calculation by doing the appropriate
 **  padding of the input value and returning the hash value.
 **
 ** input:
 ** - workSpace:   algorithm context buffer, initialized by
 **                esl_initRIPEMD160(..) function
 ** - messageDigest: pointer to buffer for the hash value (20 bytes)
 **
 ** output:
 ** - workSpace:   actualized algorithm context structure
 ** - messageDigest: pointer to computed hash value
 ** - returns:     ESL_ERC_PARAMETER_INVALID input parameter is NULL
 **                ESL_ERC_WS_STATE_INVALID  work space state invalid
 **                ESL_ERC_WS_TOO_SMALL      work space too small
 **                ESL_ERC_NO_ERROR          else
 **
 ** assumes:
 ** - workSpace is initialized by esl_initRIPEMD160(..)
 ** - esl_updateRIPEMD160 called before
 **
 ** uses:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( eslt_ErrorCode ) esl_finalizeRIPEMD160(
   CRYPTOCV_P2VAR_PARA( eslt_WorkSpaceRIPEMD160 ) workSpace, CRYPTOCV_P2VAR_PARA( eslt_Byte ) messageDigest )
{
   /* Any NULLs ? */
   if ( (!workSpace) || (!messageDigest) )
   {
      return ESL_ERC_PARAMETER_INVALID;
   }

   /* Check workSpace */
   if ( (workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_RIPEMD160 )
   {
      return ESL_ERC_WS_STATE_INVALID;
   }
   if ( !(workSpace->header.status & ESL_WST_M_RUNNING) )
   {
      return ESL_ERC_WS_STATE_INVALID;
   }
   if ( workSpace->header.size < ESL_MAXSIZEOF_WS_RIPEMD160 )
   {
      return ESL_ERC_WS_TOO_SMALL;
   }

   /* Finalize actCLib RIPEMD-160 */
   actRMD160Finalize( (CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ))workSpace->wsRIPEMD160,
                      messageDigest, workSpace->header.watchdog );

   /* Reset and clear workspace */
   workSpace->header.status = ESL_WST_ALLOCATED;
   actMemset( workSpace->wsRIPEMD160, 0, (unsigned int)(workSpace->header.size) );

   return ESL_ERC_NO_ERROR;
}

