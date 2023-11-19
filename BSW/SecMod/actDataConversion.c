/****************************************************************************
 **
 ** $HeadURL: https://subversion/svn/library-ES/branches/library-es/1.2.0-VectorInformatik/development/common/actCLib/source/actDataConversion.c $
 ** $Revision: 2590 $
 ** $Date: 2017-12-15 16:15:49 +0100 (Fr, 15 Dez 2017) $
 ** $Author: mneuhaus $
 **
 ** \copyright(cv cryptovision GmbH, 2017)
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
 ***************************************************************************/

#include "actDataConversion.h"


/****************************************************************************
 ** Global Functions
 ***************************************************************************/


/* convert little endian byte array to U8 */
CRYPTOCV_FUNC( actU8 )  actLEtoU8 (CRYPTOCV_P2CONST_PARA( actU8 ) src) {
    return LOW_BYTE (*src);
}

/* convert U8 to little endian byte array */
CRYPTOCV_FUNC( void ) actU8toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU8 in) {
    *tgt = (actU8) LOW_BYTE (in);
}


/* copy little endian byte array to U32 array */
CRYPTOCV_FUNC( void ) actCpyLEtoU8 (actU8 *tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        *tgt++ = LOW_BYTE (*src++);
    }
}

/* copy U8 array to little endian byte array */
CRYPTOCV_FUNC( void )  actCpyU8toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        *tgt++ = LOW_BYTE (*src++);
    }
}




/* convert little endian byte array to U16 */
CRYPTOCV_FUNC( actU16 ) actLEtoU16 (CRYPTOCV_P2CONST_PARA( actU8 ) src) {
    REGISTER actU16  u16;

    u16  = ((actU16) LOW_BYTE (*src++))     ;
    u16 |= ((actU16) LOW_BYTE (*src  )) << 8;

    return u16;
}

/* convert U16 to little endian byte array */
CRYPTOCV_FUNC( void )  actU16toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU16 in) {
    *tgt++ = (actU8) LOW_BYTE (in);
    *tgt   = (actU8) LOW_BYTE (in >> 8);
}


/* copy little endian byte array to U32 array */
CRYPTOCV_FUNC( void )  actCpyLEtoU16 (CRYPTOCV_P2VAR_PARA( actU16 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i += 2) {
        *tgt = actLEtoU16 (src);

        src += 2;
        tgt++;
    }
}

/* copy U16 array to little endian byte array */
CRYPTOCV_FUNC( void )  actCpyU16toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU16 )src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        actU16toLE (tgt, *src);

        src++;
        tgt += 2;
    }
}


/* convert BIG endian byte array to U32 */
CRYPTOCV_FUNC( actU32 )  actBEtoU32 (CRYPTOCV_P2CONST_PARA( actU8 ) src) {
    REGISTER actU32  u32;

    u32  = ((actU32) LOW_BYTE (*src++)) <<24;
    u32 |= ((actU32) LOW_BYTE (*src++)) <<16;
    u32 |= ((actU32) LOW_BYTE (*src++)) << 8;
    u32 |= ((actU32) LOW_BYTE (*src  ))     ;

    return u32;
}

/* convert little endian byte array to U32 */
CRYPTOCV_FUNC( actU32 )  actLEtoU32 (CRYPTOCV_P2CONST_PARA( actU8 ) src) {
    REGISTER actU32  u32;

    u32  = ((actU32) LOW_BYTE (*src++))     ;
    u32 |= ((actU32) LOW_BYTE (*src++)) << 8;
    u32 |= ((actU32) LOW_BYTE (*src++)) <<16;
    u32 |= ((actU32) LOW_BYTE (*src  )) <<24;

    return u32;
}

/* convert U32 to BIG endian byte array */
CRYPTOCV_FUNC( void )  actU32toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU32 in) {
    *tgt++ = (actU8) LOW_BYTE (in >>24);
    *tgt++ = (actU8) LOW_BYTE (in >>16);
    *tgt++ = (actU8) LOW_BYTE (in >> 8);
    *tgt   = (actU8) LOW_BYTE (in);
}

/* convert U32 to little endian byte array */
CRYPTOCV_FUNC( void )  actU32toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU32 in) {
    *tgt++ = (actU8) LOW_BYTE (in);
    *tgt++ = (actU8) LOW_BYTE (in >> 8);
    *tgt++ = (actU8) LOW_BYTE (in >>16);
    *tgt   = (actU8) LOW_BYTE (in >>24);
}


/* copy BIG endian byte array to U32 array */
CRYPTOCV_FUNC( void )  actCpyBEtoU32 (CRYPTOCV_P2VAR_PARA( actU32 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i += 4) {
        *tgt = actBEtoU32 (src);

        src += 4;
        tgt++;
    }
}

/* copy little endian byte array to U32 array */
CRYPTOCV_FUNC( void )  actCpyLEtoU32 (CRYPTOCV_P2VAR_PARA( actU32 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i += 4) {
        *tgt = actLEtoU32 (src);

        src += 4;
        tgt++;
    }
}

/* copy U32 array to BIG endian byte array */
CRYPTOCV_FUNC( void )  actCpyU32toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU32 )src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        actU32toBE (tgt, *src);

        src++;
        tgt += 4;
    }
}

/* copy U32 array to little endian byte array */
CRYPTOCV_FUNC( void )  actCpyU32toLE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU32 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        actU32toLE (tgt, *src);

        src++;
        tgt += 4;
    }
}


#ifdef ACT_PLATFORM_UINT64_AVAILABLE

/* convert BIG endian byte array to U64 */
CRYPTOCV_FUNC( actU64 )  actBEtoU64 (CRYPTOCV_P2CONST_PARA( actU8 ) src) {
    REGISTER actU64  u64;

    u64  = ((actU64) LOW_BYTE (*src++)) <<56;
    u64 |= ((actU64) LOW_BYTE (*src++)) <<48;
    u64 |= ((actU64) LOW_BYTE (*src++)) <<40;
    u64 |= ((actU64) LOW_BYTE (*src++)) <<32;
    u64 |= ((actU64) LOW_BYTE (*src++)) <<24;
    u64 |= ((actU64) LOW_BYTE (*src++)) <<16;
    u64 |= ((actU64) LOW_BYTE (*src++)) << 8;
    u64 |= ((actU64) LOW_BYTE (*src  ))     ;

    return u64;
}

/* convert U64 to BIG endian byte array */
CRYPTOCV_FUNC( void )  actU64toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, const actU64 in) {
    *tgt++ = (actU8) LOW_BYTE (in >>56);
    *tgt++ = (actU8) LOW_BYTE (in >>48);
    *tgt++ = (actU8) LOW_BYTE (in >>40);
    *tgt++ = (actU8) LOW_BYTE (in >>32);
    *tgt++ = (actU8) LOW_BYTE (in >>24);
    *tgt++ = (actU8) LOW_BYTE (in >>16);
    *tgt++ = (actU8) LOW_BYTE (in >> 8);
    *tgt   = (actU8) LOW_BYTE (in);
}

/* copy BIG endian byte array to U64 array */
CRYPTOCV_FUNC( void )  actCpyBEtoU64 (CRYPTOCV_P2VAR_PARA( actU64 ) tgt, CRYPTOCV_P2CONST_PARA( actU8 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i += 8) {
        *tgt = actBEtoU64 (src);

        src += 8;
        tgt++;
    }
}

/* copy U64 array to BIG endian byte array */
CRYPTOCV_FUNC( void )  actCpyU64toBE (CRYPTOCV_P2VAR_PARA( actU8 ) tgt, CRYPTOCV_P2CONST_PARA( actU64 ) src, const actU32 length) {
    actU32  i;

    for (i = 0; i < length; i++) {
        actU64toBE (tgt, *src);

        src++;
        tgt += 8;
    }
}

#endif
