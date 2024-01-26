//
// Created by Alex Wang on 2024-01-25.
//
#include <stdio.h>
#include "array_pointers.h"

void intArrayPrinter(int iArr[],int iSize)
{
    printf("The addr of array is %p\n",iArr);
    printf("The addr of the array var in stack is %p\n",&iArr);
    for(int i=0;i<iSize;i++)
    {
        printf("The %d element has value %d at addr %p\n",i,iArr[i],&iArr[i]);
    }
}

void intArrayAsPointerPrinter(int * iArr,int iSize)
{
    printf("The addr of array is %p\n",iArr);
    printf("The addr of the array var in stack is %p\n",&iArr);
    int * pInt = iArr;
    for(int i=0;i<iSize;i++)
    {
        printf("The %d element has value %d at addr %p\n",i,*pInt,pInt);
        pInt++;
    }
}


//Assume cArr is a str
void charArrayAsPointerPrinter(char * cArr)
{
    printf("The addr of array is %p\n",cArr);
    printf("The addr of the array var in stack is %p\n",&cArr);
    char * pCur = cArr;
    while(*pCur)
    {
        printf("%c",*pCur++);
    }
    printf("\n");
}

//cArr is an array
void charArrayPrinter(char cArr[],int len)
{
    printf("The addr of array is %p\n",cArr);
    printf("The addr of the array var in stack is %p\n",&cArr);
    for(int i=0;i<len;i++)
    {
        printf("%c",cArr[i]);
    }
    printf("\n");
}


//I want do implement %x without using it
void intBytePrinter(int iVal)
{
    char * pChar = (char*)&iVal;//Now I can use pChar to access the 4 bytes of iVal byte by byte
    for(int i=0;i<sizeof(int);i++)
    {
        printf("The byte value is %d(%x) and char equivalent is %c\n",*pChar,*pChar,*pChar);
        pChar++;
    }
}

double encode()
{
    double  x = 0.0;//x is hold 8 bytes of memory

    printf("Please enter 3 letters name:");


    printf("Please enter a age(<128)");


    printf("please enter the student loan(<65535)");


    return x;
}
void decode(double x)
{
    //print the name, age, load embeded in the 8 bytes mem of the x

}
