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