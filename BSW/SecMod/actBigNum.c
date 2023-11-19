/****************************************************************************
 ** Main author: UBR                     Creation date: 10/17/03
 ** $Author:: mneuhaus                 $ $JustDate:: 10/17/03             $
 ** $Workfile:: actBigNum.c            $ $Revision:: 2677                 $
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
 **     Layer: Core Module
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** data (BIG endian byte array) to BNDigit conversion functions
 **
 **   In contrast to the actDataConversion functions, these functions
 **   convert BIG endian byte arrays into arrays of BNDIgits and at
 **   the same time CONVERT them to little endian BNDigit order.
 **
 **
 ** functions:
 **
 **   actBNSetOctetString       - convert     data to actBigNum
 **   actBNSetOctetStringROM    - convert ROM data to actBigNum
 **   actBNOctetString          - convert actBigNum to data
 **
 **   actBNCopy                 - actBigNum =  actBigNum
 **   actBNAssign               - (same as above)
 **   actBNSet                  - actBigNum =  value
 **   actBNIsZero               - constant run-time "== 0"
 **   actBNCompare              - actBigNum == actBigNum
 **   actBNAreEqual             - constant run-time "equals"
 **
 ***************************************************************************/


#include "actBigNum.h"
#include "actUtilities.h"
#include "actDataConversion.h"


/****************************************************************************
 ** Global Functions
 ***************************************************************************/


/****************************************************************************
 **
 ** FUNCTION:
 **  void actBNSetOctetString(actBNDIGIT *a,
 **                           const actBNLENGTH length,
 **                           const actU8 *in,
 **                           const int in_len)
 **
 **   Big Endian Byte array to BigNum conversion according to IEEE 1363
 **   OS2FEP (octet string to field element presentation).
 **
 ** input:                                              (length in digits)
 ** - a:       the destination number                        length
 ** - length:  length of a
 ** - in:      the source octet string
 ** - in_len:  the length in bytes of the octet string
 **
 ** output:
 ** - a:       the number representing the octet string      length
 **
 ** assumes:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( void ) actBNSetOctetString(
   CRYPTOCV_P2VAR_PARA( actBNDIGIT ) a, actBNLENGTH length,
   CRYPTOCV_P2CONST_PARA( actU8 ) in, const int in_len )
{
   int i, digits = in_len / actBN_BYTES_PER_DIGIT;
   CRYPTOCV_P2CONST_PARA( actU8 ) iter = in + in_len - 1;
#if ( actBN_BYTES_PER_DIGIT!=1 )
   actBNDIGIT tmp;
#endif

   actBNSetZero(a, length);
   digits = actMin(length, digits);

   /* copy bytes to digits */
   for (i=0; i<digits; ++i)
   {
   #if ( actBN_BYTES_PER_DIGIT==1 )
      *a++ = LOW_BYTE (*iter--);

   #elif ( actBN_BYTES_PER_DIGIT==2 )
      tmp =  LOW_BYTE (*(iter-1));
      tmp <<= 8;
      tmp |= LOW_BYTE (*iter);
      *a++ = tmp;
      iter -= 2;

   #elif ( actBN_BYTES_PER_DIGIT==4 )
      tmp =  LOW_BYTE (*(iter-3));
      tmp <<= 8;
      tmp |= LOW_BYTE (*(iter-2));
      tmp <<= 8;
      tmp |= LOW_BYTE (*(iter-1));
      tmp <<= 8;
      tmp |= LOW_BYTE (*iter);
      *a++ = tmp;
      iter -= 4;
   #endif
   }

   /* handle (in_len%actBN_BYTES_PER_DIGIT) remaining bytes */
#if ( actBN_BYTES_PER_DIGIT!=1 )
   if ( in_len<length*actBN_BYTES_PER_DIGIT )
   {
      for ( i=in_len%actBN_BYTES_PER_DIGIT-1; i>=0; --i)
      {
         *a <<= 8;
         *a |= LOW_BYTE (*(iter-i));
      }
   }
#endif
}

CRYPTOCV_FUNC( void ) actBNSetOctetStringROM(
   CRYPTOCV_P2VAR_PARA( actBNDIGIT ) a, actBNLENGTH length,
   actPKey in, const int in_len )
{
   int i, digits = in_len / actBN_BYTES_PER_DIGIT;
   actPKey iter = in + in_len - 1;
#if ( actBN_BYTES_PER_DIGIT!=1 )
   actBNDIGIT tmp;
#endif

   actBNSetZero(a, length);
   digits = actMin(length, digits);

   /* copy bytes to digits */
   for (i=0; i<digits; ++i)
   {
   #if ( actBN_BYTES_PER_DIGIT==1 )
      *a++ = LOW_BYTE (ACT_ROM_BYT(iter--));

   #elif ( actBN_BYTES_PER_DIGIT==2 )

      tmp =  LOW_BYTE (ACT_ROM_BYT(iter-1));
      tmp <<= 8;
      tmp |= LOW_BYTE (ACT_ROM_BYT(iter));
      *a++ = tmp;
      iter -= 2;

   #elif ( actBN_BYTES_PER_DIGIT==4 )

      tmp =  LOW_BYTE (ACT_ROM_BYT(iter-3));
      tmp <<= 8;
      tmp |= LOW_BYTE (ACT_ROM_BYT(iter-2));
      tmp <<= 8;
      tmp |= LOW_BYTE (ACT_ROM_BYT(iter-1));
      tmp <<= 8;
      tmp |= LOW_BYTE (ACT_ROM_BYT(iter));
      *a++ = tmp;
      iter -= 4;
   #endif
   }

   /* handle (in_len%actBN_BYTES_PER_DIGIT) remaining bytes */
#if ( actBN_BYTES_PER_DIGIT!=1 )
   if ( in_len<length*actBN_BYTES_PER_DIGIT )
   {
      for ( i=in_len%actBN_BYTES_PER_DIGIT-1; i>=0; --i)
      {
         *a <<= 8;
         *a |= LOW_BYTE (ACT_ROM_BYT(iter-i));
      }
   }
#endif
}


/****************************************************************************
 **
 ** FUNCTION:
 ** void actBNOctetString(actU8 *out,
 **                       int out_len,
 **                       const actBNDIGIT *a,
 **                       const actBNLENGTH length)
 **
 **   BigNum to Big Endian Byte array conversion according to IEEE 1363
 **   FE2OSP (field element to octet string presentation).
 **
 ** input:                                              (length in digits)
 ** - out:     the destination byte array
 ** - out_len: byte length of the destination byte array
 ** - a:       the source number                             length
 ** - length:  length of a
 **
 ** output:
 ** - out:     the octet string representing the out_len
 **            lowest bytes of the number a
 **
 ** assumes:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( void ) actBNOctetString(
   CRYPTOCV_P2VAR_PARA( actU8 ) out, int out_len,
   CRYPTOCV_P2CONST_PARA( actBNDIGIT ) a, const actBNLENGTH length )
{
   int i, digits = out_len / actBN_BYTES_PER_DIGIT;
#if ( actBN_BYTES_PER_DIGIT!=1 )
   actBNDIGIT tmp;
#endif

   actMemset(out, 0, (unsigned int)out_len);
   out += (out_len - 1);
   digits = actMin(length, digits);

   /* copy digits to bytes */
   for (i=0; i<digits; ++i)
   {
   #if ( actBN_BYTES_PER_DIGIT==1 )
      *(out--) = LOW_BYTE (*a++);

   #elif ( actBN_BYTES_PER_DIGIT==2 )
      tmp = *a++;
      *(out--) = ((actU8) LOW_BYTE (tmp));
      tmp >>= 8;
      *(out--) = ((actU8) LOW_BYTE (tmp));

   #elif ( actBN_BYTES_PER_DIGIT==4 )
      tmp = *a++;
      *(out--) = ((actU8) LOW_BYTE (tmp));
      tmp >>= 8;
      *(out--) = ((actU8) LOW_BYTE (tmp));
      tmp >>= 8;
      *(out--) = ((actU8) LOW_BYTE (tmp));
      tmp >>= 8;
      *(out--) = ((actU8) LOW_BYTE (tmp));
   #endif
   }

   /* handle (out_len%actBN_BYTES_PER_DIGIT) remaining bytes */
#if ( actBN_BYTES_PER_DIGIT!=1 )
   if ( out_len<=length*actBN_BYTES_PER_DIGIT )
   {
      i = out_len % actBN_BYTES_PER_DIGIT;
      if ( i > 0 )
      {
         tmp = *a;
         for (--i; i>=0; --i) {
            *(out--) = ((actU8) LOW_BYTE (tmp));
            tmp >>= 8;
         }
      }
   }
#endif
}


/****************************************************************************
 **
 ** FUNCTION:
 **  void actBNCopy(actBNDIGIT* a,
 **                 const actBNDIGIT* b,
 **                 const actBNLENGTH length)
 **
 **   Copies the BigNum b into a ( a = b ).
 **
 ** input:                                              (length in digits)
 ** - a:       the destination number                        length
 ** - b:       the source number                             length
 ** - length:  length of a and b
 **
 ** output:
 ** - a:       a == b                                        length
 **
 ** assumes:
 ** - a_length == b_length == length
 **
 ***************************************************************************/
CRYPTOCV_FUNC( void ) actBNCopy(
   CRYPTOCV_P2VAR_PARA( actBNDIGIT ) a, CRYPTOCV_P2CONST_PARA( actBNDIGIT ) b, const actBNLENGTH length )
{
   actBNLENGTH i;

   for(i=0; i<length; ++i)
   {
      *a++ = *b++;  /* a[i] = b[i] */
   }
}


/****************************************************************************
 **
 ** FUNCTION:
 **   actBNGetBitLength
 **
 **   Calculate exact length in bits of a BigNum.
 **
 ** input:                                              (length in digits)
 ** - a:       the number to be evaluated                    length
 ** - length:  length of a
 **
 ** output:
 ** - returns:   bit_length(a)
 **
 ***************************************************************************/
CRYPTOCV_FUNC( int ) actBNGetBitLength( CRYPTOCV_P2CONST_PARA( actBNDIGIT ) a, const int length )
{
   int bits = 0;

   if ( length>0 )
   {
      actBNDIGIT high_digit;
      int i = length-1;
      while ( (a[i]==0) && (i>0) ) { --i;} /* skipp leading zero digits */
      high_digit = a[i];
      bits = i*actBN_BITS_PER_DIGIT;
      while ( high_digit>0 )
      {
        ++bits;
        high_digit>>=1;
      }
   }

   return bits;
}


/****************************************************************************
 **
 ** FUNCTION:
 **  actBNSetBit
 **
 **   Sets a bit of a BigNum.
 **
 ** input:                                              (length in digits)
 ** - a:       the input number                              length
 ** - length:  length of a
 ** - bit_pos: position of the bit to be set
 **
 ** output:
 ** - a:       a | 2^bit_pos                                 length
 ** - returns:   -1      if bit_pos >= length*BITS_PER_DIGIT
 **               0      else (success)
 **
 ** assumes:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( int ) actBNSetBit( CRYPTOCV_P2VAR_PARA( actBNDIGIT ) a, const actBNLENGTH length, const int bit_pos )
{
   if ( (bit_pos<0) || (bit_pos>=length*actBN_BITS_PER_DIGIT) ) { return -1; }
   a[bit_pos/actBN_BITS_PER_DIGIT] |= ( ((actBNDIGIT)1) << (bit_pos%actBN_BITS_PER_DIGIT) );
   return 0;
}


/****************************************************************************
 **
 ** FUNCTION:
 **  void actBNSet (actBNDIGIT* a,
 **           const actBNLENGTH length
 **           const actBNDIGIT  value)
 **
 **   Set BigNum (a) from single digit (value).
 **
 ** input:                                              (length in digits)
 ** - a:       the number to be initialized                  length
 ** - length:  length of a
 ** - value:   value to store in BigNum a
 **
 ** output:
 ** - a:       a == value                                    length
 **
 ** assumes:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( void ) actBNSet( CRYPTOCV_P2VAR_PARA( actBNDIGIT ) a, 
                                const actBNLENGTH length,
                                const actBNDIGIT  value)
{
   actBNLENGTH i;

   *a++ = value;                /* a [0] = value */
   for (i = 1; i<length; ++i)
   {
      *a++ = (actBNDIGIT) 0;    /* a [i] = 0 */
   }
}


/****************************************************************************
 **
 ** FUNCTION:
 **  int actBNIsZero(const actBNDIGIT* a,
 **                  const actBNLENGTH length)
 **
 **   Compares a BigNum against zero.
 **
 ** input:                                              (length in digits)
 ** - a:       the number to be checked                      length
 ** - length:  length of a
 **
 ** output:
 ** - returns:    1   if a == 0
 **               0   if a != 0
 **
 ** assumes:
 **
 ***************************************************************************/
CRYPTOCV_FUNC( int ) actBNIsZero( CRYPTOCV_P2CONST_PARA( actBNDIGIT ) a,
                                  const actBNLENGTH length )
{
   actBNDIGIT  x;
   actBNLENGTH i;

   for (x = 0, i = 0; i < length; i++) {
      x |= *a++;
   }

   return x == 0;
}


/****************************************************************************
 **
 ** FUNCTION:
 **  int actBNCompare(const actBNDIGIT* a,
 **                   const actBNDIGIT* b,
 **                   const actBNLENGTH length)
 **
 **   Compares two BigNums.
 **
 ** input:                                              (length in digits)
 ** - a:       first number                                  length
 ** - b:       second number                                 length
 ** - length:  length of a and b
 **
 ** output:
 ** - returns:    1   if a > b
 **               0   if a == b
 **              -1   if a < b
 **
 ** assumes:
 ** - a_length == b_length == length
 **
 ***************************************************************************/
CRYPTOCV_FUNC( int ) actBNCompare(CRYPTOCV_P2CONST_PARA( actBNDIGIT ) a,
                                  CRYPTOCV_P2CONST_PARA( actBNDIGIT ) b,
                                   const actBNLENGTH length )
{
   actBNLENGTH i = length-1;

   for( ; i>=0; --i)
   {
      if( a[i]<b[i] )
      {
         return -1;
      }
      if( a[i]>b[i] )
      {
         return 1;
      }
   }

   return 0;
}


/****************************************************************************
 **
 ** FUNCTION:
 **  int actBNAreEqual (const actBNDIGIT* a,
 **                     const actBNDIGIT* b,
 **                     const actBNLENGTH length)
 **
 **   Compares two actBigNums for equality.
 **   CONSTANT RUN-TIME version. To be used for secure data!
 **
 ** input:
 ** - a:       first number
 ** - b:       second number
 ** - length:  length of a and b
 **
 ** output:
 ** - returns:    1   if a == b
 **               0   otherwise
 **
 ** assumes:
 ** - a_length == b_length == length
 **
 ***************************************************************************/
CRYPTOCV_FUNC( int ) actBNAreEqual (CRYPTOCV_P2CONST_PARA( actBNDIGIT ) a,
                                    CRYPTOCV_P2CONST_PARA( actBNDIGIT ) b,
                                    const actBNLENGTH length )
{
   actBNDIGIT  x;
   actBNLENGTH i;

   for (x = 0, i = 0; i < length; i++) {
      x |= *a++ ^ *b++;
   }

   return x == 0;
}

