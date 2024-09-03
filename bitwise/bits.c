/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this part of the project by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc program (described in the spec) to check the legality of
     your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the spec and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *
 *      YOU WILL RECEIVE NO CREDIT IF YOUR CODE DOES NOT PASS THIS CHECK.
 *
 *   2. Use the btest checker to verify that your solutions produce the
 *      correct answers.
 */

#endif

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~, &, |
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
    int one = x & y;
    int two = ~x & ~y;
    return one | two;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int result = 85;
    result = result << 8;
    result |= 0x55;
    result = result << 8;
    result |= 0x55;
    result = result << 8;
    result |= 0x55;
    return result;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    int result = 170;
    result = result << 8;
    result |= 0xAA;
    result = result << 8;
    result |= 0xAA;
    result = result << 8;
    result |= 0xAA;
    return !((x & result) ^ result);
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned ints, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
    unsigned result;
    if (((uf >> 23) & 0xFF) == 0xFF) {
        if((uf & 0x7FFFFF) != 0) {
            return uf;
        }
    }
    result = uf & 0x7FFFFFFF;
    return result;
}

/*
 * implication - return x -> y in propositional logic - 0 for false, 1 for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    int result = (!x) | y;
    return result;
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    int result = (x >> 31) & 1;
    return result;
}

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    int sign_bit = x >> 31;
    int is_zero = !x;
    int is_positive = !sign_bit & !is_zero;
    int is_negative = sign_bit & !is_zero;
    return is_positive + (~is_negative + 1);
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int difference = x + (~y + 1);
    int sign_x = (x >> 31) & 1;
    int sign_y = (y >> 31) & 1;
    int sign_different = (difference >> 31) & 1;
    int sameValue = !!(x ^ y);
    int sameSign = (sign_x ^ sign_y); // Check if x and y have the same sign

    int y_is_greater = sameSign & sign_x;
    int x_is_greater = sameSign & sign_y;

    return (!y_is_greater) & (x_is_greater | (sameValue & ((sameSign ^ sign_different) ^ (!sameSign & 1))));
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int shifted_num = x >> n;
    int shifted_mask = ~(1 << 31 >> n << 1);
    return shifted_num & shifted_mask;
}

/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
    int mask = ~(1 << 31 >> n << 1);
    int shift_left = x << (32 + (~n + 1));
    int shift_right = (x >> n) & mask;
    int result = shift_left | shift_right;
    return result;
}

/*
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned ints, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
    unsigned sign = uf >> 31;
    unsigned exp = uf >> 23 & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0) {
        frac = frac << 2;
        if (frac > 0x7FFFFF) {
            exp = 1;
            while (frac & ~0xFFFFFF) {
                frac >>= 1;
                exp++;
            }
            frac &= 0x7FFFFF;
        }
    } else if (exp < 0xFF) {
        exp += 2;
        if (exp >= 0xFF) {
            exp = 0xFF;
            frac = 0;
        }
    }

    return (sign << 31) | (exp << 23) | frac;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {
    int negative = x >> 31;
    int neg_result = negative & x;
    int pos_result;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x &= ~(x >> 1);
    pos_result = x & (~x >> 1);
    return (negative & neg_result) | (~negative & pos_result);

//     int negative = x >> 31;
//    int neg_result = negative & 1;
//    x = (negative & (~x + 1)) | (~negative & x);
//    x |= x >> 1;
//    x |= x >> 2;
//    x |= x >> 4;
//    x |= x >> 8;
//    x |= x >> 16;
//    x &= ~(x >> 1);
//    return ((x << 1) + neg_result) & x;


}
