#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
// Prints a value as a string of bits (up to 32 bits)
void showBits(const char * prompt, int value, int bytes)
{
    unsigned int filter = 1;
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
//    int maskFindBit = 0b11110000;
    showBits("x",x,sizeof(int));
    showBits("mask",maskFindBit,sizeof(int));
    showBits("rs",x & maskFindBit,sizeof(int));

    int masksetBittoZero = 0xFFFFFFFE;
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

int main() {
//    bitAND();
    bitInversion();
    return 0;
}
