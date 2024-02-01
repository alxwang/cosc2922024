//
// Created by Alex Wang on 2024-01-25.
//
#include <stdio.h>
#include <strings.h>
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
//Complete encode and decode as a group. The starter code is in github already
double encode()
{
    double  x = 0.0;//x is hold 8 bytes of memory
    char * pStr = (char*)&x;

    printf("Please enter 3 letters name:");
//    char name[4];
//    name[0]='\0';
//    scanf("%3s",name);
//    strcpy(pStr,name);
    scanf("%3s",pStr);

//    pStr+= (strlen(pStr)+1);//pStr is point to 5th bytes of the string

    printf("Please enter a age(<128)");
//    unsigned char age = 0;
//    scanf("%d",&age);
//    *pStr = age;
//    pStr++; //pStr is point to 6th bytes
    scanf("%d",(int*)(pStr+4));//4 bytes are writen into buf,but only lowest byte will be kept because line 95 will overwrite top 3 bytes


    printf("please enter the student loan(<65535)");
//    unsigned short loan = 0;
//    scanf("%d",&loan);
//    unsigned short * pShort = (unsigned short *)pStr;
//    *pShort = loan;
    scanf("%hu",(unsigned short *)(pStr+5));
    return x;
}
void decode(double x)
{
    //print the name, age, load embeded in the 8 bytes mem of the x
    char * pStr = (char*)&x;
    printf("Name is %s\n",pStr);
//    pStr += strlen(pStr)+1;//Point to 5th byte
//    printf("Age is %d\n",*pStr);
//    pStr++;
//    printf("Loan is %d\n",  *((unsigned short *)pStr));
    printf("Age is %d\n",*(pStr+4));
    printf("Loan is %d\n",  *((unsigned short *)(pStr+5)));

}

//Read a string in one func call with space
int readString(char * str, int len)
{
    char ch = 0;
    char * pCur = str;
    //When user enter "enter" key the input is completed
    //Make sure I do not use more than len bytes
    while(ch != '\n' && pCur-str<len-1)
    {
        ch = getchar();//Get a char from user
        *pCur = ch;
        pCur++;
    }
    *pCur=0;
    return pCur-str-1;
}

void printStrAsInt(char * str)
{
    //Have a loop to point an int pointer
    // to each 4 bytes in the str
    int * pCur =(int*)str;
    int numofInts = (strlen(str)+1) / 4;//(9+1)/4=2
    for(int i=0;i<numofInts;i++)
    {
        printf("%x ",*(pCur+i));
    }

    //Have an int value and copy left over bytes to
    //the int's memory
    //Left over is <4 bytes
    //Use the mem of newInt as the buffer to build the last int
    int newInt = 0;
    //Use pIntChar to access the mem of newInt in bytes
    char * pIntChar = (char*)&newInt;
    //pCurChar is point to the first byte of the left over
    char * pCurChar = str+((numofInts)*sizeof(int));
    //Copy each byte from str to newint
    while(*pCurChar)
    {
        //Copy a byte from str to int
        *pIntChar = *pCurChar;
        pIntChar++;
        pCurChar++;
    }
    printf("%x ",newInt);
}
