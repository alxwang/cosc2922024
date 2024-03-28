//
// Created by Alex Wang on 2024-03-27.
//
#include "fileio.h"
#include <errno.h>
#include <stdlib.h>

FILE* openFile(const char* fileName, const char* fileMode)
{
    FILE * f = NULL;
    if((f= fopen(fileName,fileMode))!=NULL)
    {
        printf("File opened\n");
    }
    else
    {
        printf("File open failed\n");
    }
    return f;
}

int readFile(FILE* filePtr, unsigned char * data, int bytesToRead)
{
    int nRead = fread(data,sizeof(char),bytesToRead,filePtr);
    if(nRead!=bytesToRead)
    {
        printf("Try to read %d bytes, got %d bytes\n",bytesToRead,nRead);
        return ferror(filePtr);
    }
    else
    {
        return 0;
    }
}

int writeFile(FILE* filePtr, unsigned char * data, int bytesToWrite)
{
    int numWrite = fwrite(data,sizeof(char),bytesToWrite,filePtr);
    if(numWrite!=bytesToWrite)
    {
        printf("Try to write %d bytes, write %d bytes\n",bytesToWrite,numWrite);
        return ferror(filePtr);
    }
    else
    {
        return 0;
    }
}