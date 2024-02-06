#include <stdio.h>
#include <string.h>
#include "array_pointers.h"
#include "printmem.h"
int main() {
//    int iArr[3]={1,2,3};
//    int iSize = sizeof(iArr) / sizeof(int);
//    printf("In Main, Array addr is %p\n",iArr);
//    intArrayPrinter(iArr,iSize);
//    intArrayAsPointerPrinter(iArr,iSize);
//    char str[]="Hello World";
//    charArrayAsPointerPrinter(str);
//    charArrayPrinter(str,strlen(str));
//    intBytePrinter(0x2f2e2d2c);
//    double x = encode();
//    decode(x);
//    return 0;
//    char pStr[10];
//    int i = readString(pStr,10);
//    printf("%d: %s\n",i,pStr);
//    char * pStr = "Alex Wang";
//    printStrAsInt(pStr);


    int tab[10] = {0, 23, 150, 255,
                   12, 16,  21, 42};
    print_memory(tab, sizeof(tab));
    return (0);
}


