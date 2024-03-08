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

    printf("%s: The value %d in binary is \t%s\n", prompt,value, &bitString[32 - bytes * 8]);

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
}

int main() {
    bitAND();
    return 0;
}
