#include <stdio.h>
#include "array_pointers.h"
int main() {
    int iArr[3]={1,2,3};
    int iSize = sizeof(iArr) / sizeof(int);
    printf("In Main, Array addr is %p\n",iArr);
    intArrayPrinter(iArr,iSize);
    intArrayAsPointerPrinter(iArr,iSize);
    return 0;
}
