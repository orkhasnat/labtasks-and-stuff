/*
 * Courtesy of CMU ICS Course and CS:APP authors
 *
 * <Please put your name and studnet_id here>
 */
char __name__[] = "Tasnimul Hasnat";
char __studentID__[] = "190041113";
/* for teesting purpose
void binary(int n)
{
  int arr[32];
  int i = 0;
  while (n > 0)
  {
    arr[i++] = n & 1;
    n = n >> 1;
  }
  while (i < 32)
    arr[i++] = 0;
  for (int j = 31; j >= 0; j--)
    printf("%d", arr[j]);
  printf("\n");
}
*/
/*
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will submit.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Implement each function with one or more lines of C code. Your code 
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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif

// 1
/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
  return ~(~x & ~y);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
  return ~(0x00);
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
  return ~(0x01 << 31);
}
// 2
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */

int byteSwap(int x, int n, int m)
{
/*  
  // to extract the nth byte we need to strip n*8 bytes from the given x. so we do n>>3 to make it n*8 and then >> those amount of bits from x. Lastly we and with 0xff to get the same value of the last byte of x.
  int mth_byte = (x >> (m << 3)) & 0xff;
  int nth_byte = (x >> (n << 3)) & 0xff;

  // basically reversing the process to get the mask and swapping
  mth_byte = mth_byte << (n << 3);
  nth_byte = nth_byte << (m << 3);
  // printf("%x %x\n", mth_byte, nth_byte);

  // basically clearing out the mth and nth bytes
  x = x & ~(0xff << (m << 3)) & ~(0xff << (n << 3));

  // oring them to put them back and swapping
  return x | mth_byte | nth_byte;
*/
  // one-liner
  return (x & ~(0xff << (m << 3)) & ~(0xff << (n << 3))) | (((x >> (m << 3)) & 0xff) << (n << 3)) | (((x >> (n << 3)) & 0xff) << (m << 3));
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
// https://www.youtube.com/watch?v=waAlgFq9Xq
int copyLSB(int x)
{
  // basically else if conditional block
  // return (-1 + x&1) & 0x00 | ~(-1 + x&1) & ~0x00;

  // same as before just evaluating xy + x'y' as x xnor y
  // return ~((-1 + (x & 1)) ^ 0);

  // or use the conditional function
  // return conditional(x & 1, ~0, 0);

  // another short version
  // return ~(x & 1) + 1 ;

  // or shortest version
  // basically in signed int when the sign bit is 1 right shifting preserves the sign bit always thus appending a 1 at the front basically copying them all.
  return (x << 31) >> 31;
}
// 3
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38 = 0b00111000
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int bitMask(int highbit, int lowbit)
{
  // thanks stackovrflow!!
  // https://stackoverflow.com/questions/35109714/can-someone-explain-how-this-bitmask-code-works
  // ~0 or all ones shift them up to highbit+1 and the same for lowbit.
  // the highbit mask is negated and then and them with the lowbit mask part.
  // caution highbit+1 will not work here because it might overflow if highbit is passed 31 then
  // highbit+1 will become 32 which is a problem. thus use highbit << 1
  return ~(~0 << highbit << 1) & (~0 << lowbit);
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  return (~(~0x00 + !(!x)) & y) | ((~0x00 + !(!x)) & z);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  // // check if x - 0x30 or x- 0x39 is negtive or not .
  // int lower_bound_check = !((x + (~0x30 + 1)) >> 31 & 1);
  // int upper_bound_check = !((0x39 + (~x + 1)) >> 31 & 1);
  return !((x + (~0x30 + 1)) >> 31 & 1) & !((0x39 + (~x + 1)) >> 31 & 1);
}

// 4
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x)
{
  // if msb is 1 then return -x else return x
  // couldve use (x>>31) &1 to get the msb out but conditional func handles it bts.
  // one thing to notice x>>31 when x<0(-ve) will return all ones ie -1.
  // return conditional((x >> 31), ~x + 1, x);

  // easier method
  // x>>31 either returns 0 or -1 . A number whe xored with 0 returns itself ,
  // when xored with 1 it returns -(x+1) eg for x=-6 returns 5
  // thus adding the msb when negetive brings back the abs(x)
  // int msb = (1 & (x >> 31));
  return ((x >> 31) ^ x) + (1 & (x >> 31));
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x)
{
  // x and -x at 31st bit will always give 0 and 1 and oring them will give 1 always.
  // except for zero. thus we and with 1.
  return ((x | (~x + 1)) >> 31) & 1;
}
