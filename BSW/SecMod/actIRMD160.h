/****************************************************************************
 ** Main author: Ubr                     Creation date: 10/17/03
 ** $Author:: mns                      $ $JustDate:: 03/18/05             $
 ** $Workfile:: actIRMD160.h              $ $Revision:: 1435                 $
 ** $NoKeywords::                                                         $
 **
 **
 ** \copyright(cv cryptovision GmbH, 1999 - 2005                          )
 **
 ** \version(1.0 (beta )                                                  )
 ***************************************************************************/

/****************************************************************************
 **
 **     Part of the actCLibrary
 **
 **     Layer: User Module - Interface
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: The interface for RMD160 hash algorithm.
 **
 ** constants:
 **  actHASH_SIZE_RMD160
 **
 ** types:
 **
 ** macros:
 **
 ** functions:
 **   actRMD160Init
 **   actRMD160Update
 **   actRMD160Finalize
 **
 ***************************************************************************/


#ifndef ACTIRMD160_H
#define ACTIRMD160_H


#include "actITypes.h"


/****************************************************************************
 ** Types and constants
 ***************************************************************************/


#define actHASH_SIZE_RMD160   20
#define actHASH_BLOCK_SIZE_RMD160   64

/* Workspace structure for RMD160 */
typedef struct
{
   actU32 H[5];                  /* message digest state buffer */
   actU32 low_count, hi_count;   /* 64 bit input count */
   int buffer_used;              /* number of bytes saved in buffer */
   actU8 buffer[actHASH_BLOCK_SIZE_RMD160];     /* remaining data buffer */
} actRMD160STRUCT;


/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

#ifdef  __cplusplus
extern "C" {
#endif

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRMD160Init(actRMD160STRUCT* info)
 **
 **  This function initializes the RMD160 algorithm.
 **
 ** input:
 ** - info:       pointer to hash context structure
 **
 ** output:
 ** - info:       initialized hash context structure
 ** - returns:    actOK allways
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( actRETURNCODE ) actRMD160Init( CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ) info );

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRMD160Update(actRMD160STRUCT* info,
 **                               const actU8* dataIN,
 **                               int length,
 **                               void (*watchdog) (void));
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the RMD160 algorithm.
 **  Uses any data already in the actRMD160STRUCT structure and leaves
 **  any partial data block there.
 **
 ** input:
 ** - info:       pointer to hash context structure
 ** - dataIN:     pointer to data to be hashed
 ** - length:     length of data in bytes
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       actualized hash context structure
 ** - returns:    actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 **               actOK                 else
 **
 ** assumes:
 ** - actRMD160Init() is called once before calling this function
 ** - dataIN != NULL is a valid pointer
 ** - length >= 0
 **
 ** uses:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( actRETURNCODE ) actRMD160Update(
   CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ) info,
   CRYPTOCV_P2CONST_PARA( actU8 ) dataIN, int length,
   CRYPTOCV_P2FUNC( CRYPTOCV_NONE, void, watchdog )( void ) );

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRMD160Finalize(actRMD160STRUCT* info,
 **                                 actU8 hash[actHASH_SIZE_RMD160],
 **                                 void (*watchdog) (void));
 **
 **  This function finalizes the RMD160 algorithm and delivers the hash value.
 **
 ** input:
 ** - info:       pointer to hash context structure
 ** - hash:       byte array to contain the hash value
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       finalized hash context structure
 ** - hash:       the final hash value,
 **                  (big endian of length actHASH_SIZE_RMD160)
 ** - returns:    actOK allways
 **
 ** assumes:
 ** - actRMD160Init() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_RMD160
 **
 ***************************************************************************/
CRYPTOCV_FUNC( actRETURNCODE ) actRMD160Finalize(
   CRYPTOCV_P2VAR_PARA( actRMD160STRUCT ) info, CRYPTOCV_P2VAR_PARA( actU8 ) hash,
   CRYPTOCV_P2FUNC( CRYPTOCV_NONE, void, watchdog )( void ) );

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif /* ACTIRMD160_H */

