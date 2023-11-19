/****************************************************************************
 **
 ** $HeadURL: https://subversion/svn/library-ES/branches/library-es/1.2.0-VectorInformatik/development/common/actCLib/local_include/actDataConversion.h $
 ** $Revision: 2593 $
 ** $Date: 2017-12-18 11:13:05 +0100 (Mo, 18 Dez 2017) $
 ** $Author: mneuhaus $
 **
 ** \copyright(cv cryptovision GmbH, 1999-2015)
 **
 ** \version(cv library/es 1.2)
 **
 ***************************************************************************/

/****************************************************************************
 **
 **     Part of the actCLibrary
 **
 **     Layer: Core Module
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** data (byte array <-> unsigned) conversion functions
 **
 **   In contrast to the actBigNum conversion functions, these functions
 **   just convert byte arrays into arrays of larger types WITHOUT
 **   converting them to little endian BNDigit order.
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **
 ** functions:
 **   actBEtoU8         //  convert BIG endian byte array to U8         //  NOT implemented
 **   actLEtoU8         //  convert little endian byte array to U8
 **   actU8toBE         //  convert U8 to BIG endian byte array         //  NOT implemented
 **   actU8toLE         //  convert U8 to little endian byte array
 **   actCpyBEtoU8      //  copy BIG endian byte array to U8 array      //  NOT implemented
 **   actCpyLEtoU8      //  copy little endian byte array to U8 array
 **   actCpyU8toBE      //  copy U8 array to BIG endian byte array      //  NOT implemented
 **   actCpyU8toLE      //  copy U8 array to little endian byte array
 **
 **   actBEtoU16        //  convert BIG endian byte array to U16        //  NOT implemented
 **   actLEtoU16        //  convert little endian byte array to U16
 **   actU16toBE        //  convert U16 to BIG endian byte array        //  NOT implemented
 **   actU16toLE        //  convert U16 to little endian byte array
 **   actCpyBEtoU16     //  copy BIG endian byte array to U16 array     //  NOT implemented
 **   actCpyLEtoU16     //  copy little endian byte array to U16 array
 **   actCpyU16toBE     //  copy U16 array to BIG endian byte array     //  NOT implemented
 **   actCpyU16toLE     //  copy U16 array to little endian byte array
 **
 **   actBEtoU32        //  convert BIG endian byte array to U32
 **   actLEtoU32        //  convert little endian byte array to U32
 **   actU32toBE        //  convert U32 to BIG endian byte array
 **   actU32toLE        //  convert U32 to little endian byte array
 **   actCpyBEtoU32     //  copy BIG endian byte array to U32 array
 **   actCpyLEtoU32     //  copy little endian byte array to U32 array
 **   actCpyU32toBE     //  copy U32 array to BIG endian byte array
 **   actCpyU32toLE     //  copy U32 array to little endian byte array
 **
 **   actBEtoU64        //  convert BIG endian byte array to U64
 **   actLEtoU64        //  convert little endian byte array to U64     //  NOT implemented
 **   actU64toBE        //  convert U64 to BIG endian byte array
 **   actU64toLE        //  convert U64 to little endian byte array     //  NOT implemented
 **   actCpyBEtoU64     //  copy BIG endian byte array to U64 array
 **   actCpyBEtoU64     //  copy little endian byte array to U64 array  //  NOT implemented
 **   actCpyU64toBE     //  copy U64 array to BIG endian byte array
 **   actCpyU64toBE     //  copy U64 array to little endian byte array  //  NOT implemented
 **
 **   actGetU8fromU16   //  get a single U8 out of a U16
 **   actGetU8fromU32   //  get a single U8 out of a U32
 **   actGetU8fromU64   //  get a single U8 out of a U64
 **
 **   parameters:
 **     tgt     target memory
 **     src     source memory or value
 **     length  length of source memory in units of source type
 **
 **   remarks:
 **     pointers are NOT checked for validity (NULL)
 **     target memory length is NOT validated
 **     source memory length is NOT evaluated to be an exact multiple of target memory sizeof(type) - NO padding will be done!
 **
 ***************************************************************************/

#ifndef     actDataConversion_h
#define actDataConversion_h


#include "actITypes.h"
#include "actConfig.h"


#ifdef  __cplusplus
  extern "C" {
#endif


CRYPTOCV_FUNC( actU8 ) actLEtoU8    (CRYPTOCV_P2CONST_PARA( actU8 ) src);

CRYPTOCV_FUNC( void ) actU8toLE     (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU8 src);


CRYPTOCV_FUNC( void ) actCpyLEtoU8  (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);

CRYPTOCV_FUNC( void ) actCpyU8toLE  (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);


CRYPTOCV_FUNC( actU16 ) actLEtoU16  (CRYPTOCV_P2CONST_PARA( actU8 ) src);

CRYPTOCV_FUNC( void ) actU16toLE    (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU16  src);


CRYPTOCV_FUNC( void ) actCpyLEtoU16 (CRYPTOCV_P2VAR_PARA( actU16 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);

CRYPTOCV_FUNC( void ) actCpyU16toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU16 ) src, const actU32 length);

CRYPTOCV_FUNC( actU32 ) actBEtoU32  (CRYPTOCV_P2CONST_PARA( actU8 ) src);
CRYPTOCV_FUNC( actU32 ) actLEtoU32  (CRYPTOCV_P2CONST_PARA( actU8 ) src);
CRYPTOCV_FUNC( void ) actU32toBE    (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU32  src);
CRYPTOCV_FUNC( void ) actU32toLE    (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU32  src);

CRYPTOCV_FUNC( void ) actCpyBEtoU32 (CRYPTOCV_P2VAR_PARA( actU32 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);
CRYPTOCV_FUNC( void ) actCpyLEtoU32 (CRYPTOCV_P2VAR_PARA( actU32 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);
CRYPTOCV_FUNC( void ) actCpyU32toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU32 ) src, const actU32 length);
CRYPTOCV_FUNC( void ) actCpyU32toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU32 ) src, const actU32 length);

#ifdef ACT_PLATFORM_UINT64_AVAILABLE
CRYPTOCV_FUNC( actU64 )  actBEtoU64 (CRYPTOCV_P2CONST_PARA( actU8 ) src);

CRYPTOCV_FUNC( void ) actU64toBE    (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU64  src);


CRYPTOCV_FUNC( void ) actCpyBEtoU64 (CRYPTOCV_P2VAR_PARA( actU64 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length);

CRYPTOCV_FUNC( void ) actCpyU64toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU64 ) src, const actU32 length);

#endif


/*  get a byte out of a larger type (U16, U32, U64) */
#ifndef OPTIMIZE_actGetU8
    #define actGetU8fromU16(x, n)   ((actU8) LOW_BYTE (((x) >> ((n) <<2))))
    #define actGetU8fromU32(x, n)   ((actU8) LOW_BYTE (((x) >> ((n) <<3))))
    #define actGetU8fromU64(x, n)   ((actU8) LOW_BYTE (((x) >> ((n) <<4))))
#else
    /* You may try this one also. The version may result in CODE size or
       performance benefits. CAUTION: With some compilers, this macro does
       not work correctly! */
    /* MUST use this version with TI's CCS ARM-7 compiler */
    #ifdef LITTLE_ENDIAN
        #define actGetU8fromU16(x, n)  (* (((actU8*) &(x))    +(n)))
        #define actGetU8fromU32(x, n)  (* (((actU8*) &(x))    +(n)))
        #define actGetU8fromU64(x, n)  (* (((actU8*) &(x))    +(n)))
    #else
        #define actGetU8fromU16(x, n)  (* (((actU8*) &(x)) +1 -(n)))
        #define actGetU8fromU32(x, n)  (* (((actU8*) &(x)) +3 -(n)))
        #define actGetU8fromU64(x, n)  (* (((actU8*) &(x)) +7 -(n)))
    #endif
#endif

#ifdef  __cplusplus
  } /* extern "C" */
#endif

#endif  /* actDataConversion_h */
