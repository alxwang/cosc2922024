#include <stdio.h>
#include "functions.h"
#include <string.h>
int main() {
    char str[]="Hello, World!";
    char * pstr = strdup(str);//strdup will call malloc to alloc mem in heap
//    printf("Before trim: %s\n",str);
//    printf("Address of Original Str in main is %p\n",pstr);
//    printf("Address of Original Str ptr ptr in main is %p\n",&pstr);
//    trimRight(&pstr,7);
//    printf("After trim: %s\n",pstr);
//    int loc = findChar(str,'o',&pstr);
//    printf("Find W in str:[%d],[%s]\n",loc,pstr);
    testJaggedArray();
    return 0;
}
