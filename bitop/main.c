#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
// Prints a value as a string of bits (up to 32 bits)
void showBits(const char * prompt, int value, int bytes)
{
    unsigned int filter = 1; //0b00000001
    int bit;

    char* bitString = (char*)malloc(33);
    // Null terminator
    bitString[32] = '\0';

    for (bit = 0; bit < bytes * 8; bit++)
    {
        // Determine the value of the current bit
        if (value & filter)
        {
            bitString[31 - bit] = '1';
        }
        else
        {
            bitString[31 - bit] = '0';
        }
        filter *= 2; // Move to the next bit to the left
        /*
         * 0b00000001   1
         * 0b00000010   2
         * 0b00000100   4
         * 0b00001000   8
         * 0b00010000   16
         * 0b00100000   32
         * 0b01000000   64
         * 0b10000000   128
         */
    }

    printf("%s\t: The value %d in binary is \t%s\n", prompt,value, &bitString[32 - bytes * 8]);

    free(bitString);
    bitString = NULL;
}

void bitAND()
{
    // only 1 & 1 = 1 otherwise return 0
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a & b;
    showBits("a",a,sizeof(char));
    showBits("b",b,sizeof(char));
    showBits("rs",rs, sizeof(char));

    /*With a carefully constructed mask (a bit pattern that controls which bits will be displayed),
     * we can use bitwise AND to preserve bits as they are or turn some bits off.
     * Any bit combined with & will have the same value if the bit in the mask is 1,
     * and will be turned off (set to 0) if the bit in the mask is 0
    */

    int x = 0x30B1A0F;
    int maskFindBit = 0x00000004;
//    int maskFindBit = 0b00000000000000000000000000000100;
    showBits("x",x,sizeof(int));
    showBits("mask",maskFindBit,sizeof(int));
    showBits("rs",x & maskFindBit,sizeof(int));

    int masksetBittoZero = 0xFFFFFFFE;
//    int masksetBittoZero = 0b11111111111111111111111111111110;
    showBits("x",x,sizeof(int));
    showBits("mask",masksetBittoZero,sizeof(int));
    showBits("rs",x & masksetBittoZero,sizeof(int));

    /* Join the breakout room and do the following until 2:30:
     * 1. What is find bit, what is set bit in your way.
     * 2. How and why it works?
     * 3. How to build a mask?
     * 4. Try to change the mask and do something new.U cam define mask in bin as 0b....
     */
}

void bitInversion()
{
    unsigned char a = 0x48;
    unsigned char rs = ~a;
    showBits("a",a,sizeof(char));
    showBits("rs",rs, sizeof(char));

}

void bitOR()
{
    //only 0 or 0 = 0, otherwise return 1
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a | b;
    showBits("a",a,sizeof(char));
    showBits("b",b,sizeof(char));
    showBits("rs",rs, sizeof(char));

    /*
     * With a carefully constructed mask, we can use bitwise OR to preserve bits as they are or turn some bits on.
     * Any bit combined with | will have the same value if the bit in the mask is 0,
     * and will be turned on (set to 1) if the bit in the mask is 1.
     */
    int x = 0x030B1A0F;
    int mask = 0xFFFF0000; // set first 2 bytes to 1's and preserve other bits
    //mask  = 11111111111111110000000000000000
    showBits("x",x,sizeof(int));
    showBits("mask",mask,sizeof(int));
    showBits("rs",x | mask,sizeof(int));
    //The higher 16 bits are turned on (set to 1) because the higher 16 bits of mask is 1
    //The lower 16 bit are kept as the original values because the lower 16 bit of mask is 0;
}

void bitXOR()
{
    //return 1 if two operands are different.
    //Otherwise, return 0
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a ^ b;
    showBits("a",a,sizeof(char));
    showBits("b",b,sizeof(char));
    showBits("rs",rs, sizeof(char));

    /*
     * If XOR with a full complement mask (FF or all 1’s) will flip the bits in the other operand.
     * XOR with a mask of 0’s will preserve the bits in the other operand.
     */
    showBits("b",b, sizeof(char));
    showBits("Flip",0xFF ^ b, sizeof(char));//0b11111111 flip every bit with 1 in the mask
    showBits("Preserve", 0x00 ^ b, sizeof(char));//0b00000000 preserve bit with 0 in the mask

}

void shiftOp()
{
    short x = 37;
    showBits("No shift",x,sizeof(short));
    //Shift every bit to left, the bit on left will be shift out(dropped) if needed. Right side will be paded zeros.
    showBits("Shift 1 bit to the left", x<<1, sizeof(short));
    showBits("Shift 2 bit to the right", x>>2, sizeof(short));

}
/*
 * Next week we will work on 1. Shift sign/unsigned numbers
 * 2. Shift op and data type.
 *
 */

/*
 * 1. Work on shift more and try to understand it
 * 2. Review OR and XOR with your group
 * 3. Review Showbits
 * Question:
 * 1. Write a function swapNibbles that will take an unsigned char and make
 * the low-order 4 bits into the high-order 4 bits and also make the high-order 4 bits into the low-order 4 bits.
 * So for instance, passing in 11010011 would return 00111101.
 * 2. Write a function blendNibbles that will take two unsigned chars and return
 * a result which contains the high-order nibble of the first unsigned char and then
 * (as the low-order nibble of the result) the high-order nibble of the second unsigned char.
 * So for instance, given 10001111 and 01101110, the return value would be 10000110.
 *
 * Hint: 1. Both one line code function
 * 2. Assume the number is unsigned char
 *
 *
 * Ask me to join your room if you need help
 * All rooms will be kept opened until 4pm
 */
int main() {
//    bitAND();
//    bitInversion();
//    bitOR();
//    bitXOR();
    shiftOp();
    return 0;
}
