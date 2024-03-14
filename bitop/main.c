#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
// Prints a value as a string of bits (up to 32 bits)
void showBits(const char * prompt, unsigned int value, int bytes)
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
 * unsigned char swapNibbles(unsigned char a) {}
 *
 * 2. Write a function blendNibbles that will take two unsigned chars and return
 * a result which contains the high-order nibble of the first unsigned char and then
 * (as the low-order nibble of the result) the high-order nibble of the second unsigned char.
 * So for instance, given 10001111 and 01101110, the return value would be 10000110.
 * unsigned char blendNibbles(unsigned char first, unsigned char second){}
 *
 * Hint: 1. Both one line code function
 * 2. Assume the number is unsigned char
 *
 *
 * Ask me to join your room if you need help
 * All rooms will be kept opened until 4pm
 */

//TODO Shift sign num, shfit alway return int, swapNibbles,blendNibbles
//TODO typedef,func point - assign 2
//Execise: reverseBits testPrecedence languageQuestions,encrypted
//Execise: sort, extent encrypted

void shiftSignedNumber()
{
    int i = -2;
    int j = 2;
    showBits("i=",i,sizeof(int));
    showBits("j=",j,sizeof(int));
//    showBits("i>>1",i>>1,sizeof(int));
//    showBits("j>>1",j>>1,sizeof(int));
//    showBits("i>>2",i>>2,sizeof(int));
//    showBits("j>>2",j>>2,sizeof(int));
//    showBits("i>>4",i>>4,sizeof(int));
//    showBits("j>>4",j>>4,sizeof(int));
    showBits("i<<1",i<<1,sizeof(int));
    showBits("j<<1",j<<1,sizeof(int));
    showBits("i<<2",i<<2,sizeof(int));
    showBits("j<<2",j<<2,sizeof(int));
    showBits("i<<4",i<<4,sizeof(int));
    showBits("j<<4",j<<4,sizeof(int));

}

void shiftReturnInt()
{
    unsigned char c = 60;
    showBits("c",c,sizeof(char));
    showBits("c>>1",c>>1,sizeof(int));
    showBits("c<<1",c<<1,sizeof(int));
    showBits("c<<10",c<<10,sizeof(int));
    showBits("c<<10",c<<10,sizeof(char));
}

unsigned char swapNibbles(unsigned char a)
{
    //a<<4 00000000
    //a>>4 00001111
    return (a<<4)|(a>>4);
}

unsigned char blendNibbles(unsigned char a,unsigned char b)
{
    //a & 0b11110000 ->11110000
    //b>>4           ->00001001
    return (a & 0b11110000) | (b>>4);
}
/*
 * 3.	Write a function called reverseBits.
 * Given an unsigned integer, return another unsigned integer
 * where the bits are reversed. So if 0x0000008D is passed in,
 * 0xB1000000 would be returned (0000000000000000000010001101 would
 * return 10110001000000000000000000000000). The signature would be:
unsigned int reverseBits(unsigned int data)

 - use & with mask to get each bit
 - use | to put the bit you get back to result
 - swap the pos when put
 */
unsigned int reverseBits(unsigned int data)
{
    unsigned int rs = 0;
    unsigned int cur_bit;//00000000000000000000000000000001 if the first bit is 1
    int totalBits = sizeof(int)*8;
    for(int i=0;i<totalBits;i++)
    {
        //1. get the ith bit. AND with a mask(1<<i)
        showBits("data:",data,4);
        cur_bit=data & (1<<i);
        showBits("mask:",1<<i,4);
        showBits("cur:",cur_bit,4);

        //2. put the bit into rs at totalBits-i. OR
        if(cur_bit)
        {
            rs |= 1 << (totalBits-i-1);
        }
        showBits("rs:",rs,4);
        printf("-----------------------------------\n");
    }
    return rs;
}

int main() {
//    bitAND();
//    bitInversion();
//    bitOR();
//    bitXOR();
//    shiftOp();
//    shiftSignedNumber();
//    shiftReturnInt();
//    unsigned char a = 0b11110001;
//    unsigned char b = 0b10010000;
//
//    showBits("a before:",a,sizeof(char));
//    showBits("b before:",b,sizeof(char));
//    a = blendNibbles(a,b);
//    showBits("a after:",a,sizeof(char));
    unsigned int i = 0b0000000000000000000010001101;
    showBits("i:",i,4);
    showBits("Rev:", reverseBits(i),4);

    return 0;
}
