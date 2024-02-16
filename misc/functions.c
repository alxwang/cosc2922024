//
// Created by Alex Wang on 2024-02-16.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>

//Return a new string in cPtrPtr. It should contain the string in cPtrPtr and remove count of chars from right(end)
void trimRight(char ** cPtrPtr, int count)
{
    char * str = *cPtrPtr;
    printf("Address of Original Str is %p\n",str);
    printf("Address of Original Str Ptr ptr is %p\n",cPtrPtr);
    int diff = strlen(str)-count;
    *cPtrPtr = (char*) malloc(diff+1);
    memcpy(*cPtrPtr,str,diff);
    *(*cPtrPtr+diff) = 0;//Manually set the last char in the mem block as 0 to make it into a str
    free(str);//Free only can free mem alloced by malloc
    str=NULL;
}


int findChar(char * str, char tofind, char ** strptrptr)
{
    int loc = 0;
    while(*str)
    {
        if(*str==tofind)
        {
            *strptrptr = str;
            return loc;
        }
        str++;
        loc++;
    }
    *strptrptr=NULL;
    return -1;
}

char * allocRow(int size)
{
    char * str = (char*) malloc(size * sizeof(char));
    str[0]=0;
    return str;
}

char** createArray(int rowsize[],int numRows)
{
    //Alloc an array of char*
    char ** cPtrptr = (char**) malloc(numRows*sizeof(char*));
    for(int i=0;i< numRows;i++)
    {
        char * row = allocRow(rowsize[i]);
        *(cPtrptr+i) = row;
    }
    return cPtrptr;
}

void printArray(char ** cPtrPtr, int numRows)
{
    for(int i=0;i<numRows;i++)
    {
        printf("%s\n",cPtrPtr[i]);
    }
}

void testJaggedArray()
{
    int iRowVals[] = { 4, 6, 5 };
    // calculate the number of rows in iRowVals
    int iRows = sizeof(iRowVals) / sizeof(int);

    // Create the jagged array
    char** cPtrPtr = createArray(iRowVals, iRows);

    // Add some data to each row
    // Index into each location char by char using brackets
    cPtrPtr[0][0] = 'M';
    cPtrPtr[0][1] = 'e';
    cPtrPtr[0][2] = 'l';
    cPtrPtr[0][3] = '\0';

    // Index in using pointer math
    *(*(cPtrPtr + 1) + 0) = 'C';
    *(*(cPtrPtr + 1) + 1) = 'h';
    *(*(cPtrPtr + 1) + 2) = 'r';
    *(*(cPtrPtr + 1) + 3) = 'i';
    *(*(cPtrPtr + 1) + 4) = 's';
    *(*(cPtrPtr + 1) + 5) = '\0';

    // Use strcpy - only because this is a jagged array of chars
    strncpy(cPtrPtr[2],"Mark",iRowVals[2]);

    // Print the array
    printArray(cPtrPtr, iRows);

    // Free ALL the memory created for the jagged array
    // Free each row first
    for (int i = 0; i < iRows; i++)
    {
        free(cPtrPtr[i]);
        cPtrPtr[i] = NULL;
    }
    free(cPtrPtr);
    cPtrPtr = NULL;
}