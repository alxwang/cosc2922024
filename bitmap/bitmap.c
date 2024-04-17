#include "bitmap.h"
#include <memory.h>
#include <math.h>
#include <stdlib.h>

#define MAX_FILENAME_SIZE	256
//
// Created by Alex Wang on 2024-04-10.
//
FILE* GetFile(char* cPrompt, char* cMode)
{
    FILE* aFile = NULL;
    char cFileName[MAX_FILENAME_SIZE];
    // Get the name from the user
    printf("%s", cPrompt);
    fgets(cFileName, MAX_FILENAME_SIZE,stdin);
    cFileName[strlen(cFileName)-1]=0;
    // Open the file with the given name and mode passed in
    aFile = fopen(cFileName, cMode);

    return aFile;
}

void ReadImage(IMAGE*imgPtr, FILE*f)
{
    ReadHeader(imgPtr,f);
    if(imgPtr->bmHDR!=NULL)
    {
        ReadData(imgPtr,f);
    }
}

void ReadHeader(IMAGE*imgPtr, FILE*f)
{
    imgPtr->bmHDR=(BITMAPHDR*)malloc(sizeof(BITMAPHDR));
    if(imgPtr->bmHDR!=NULL)
    {
        if(fread(imgPtr->bmHDR, sizeof(BITMAPHDR),1,f)!=1)
        {
            free(imgPtr->bmHDR);
            imgPtr->bmHDR=NULL;
            printf("Failed to read header");
        }
    }
}

void ReadData(IMAGE* imgPtr, FILE*f)
{
    unsigned int padding = imgPtr->bmHDR->dwWidth % 4;
    unsigned int imageSize =
            (imgPtr->bmHDR->dwWidth*sizeof(PIXEL)+padding)
            *imgPtr->bmHDR->dwHeight;
    imgPtr->bmData=(PIXEL*) malloc(imageSize);
    if(imgPtr->bmData!=NULL)
    {
        if(fread(imgPtr->bmData,imageSize,1,f)!=1)
        {
            free(imgPtr->bmData);
            imgPtr->bmData=NULL;
            free(imgPtr->bmHDR);
            imgPtr->bmHDR=NULL;
        }
    }
    else
    {
        free(imgPtr->bmHDR);
        imgPtr->bmHDR=NULL;
    }
}

void PrintHeader(BITMAPHDR*headerPtr)
{
    printf("First two characters: %x\n", headerPtr->wType);
    printf("File size: %d\n", headerPtr->dwFileSize);
    printf("Data offset: %d\n", headerPtr->dwDataOffset);
    printf("Header size: %d\n", headerPtr->dwHeaderSize);
    printf("Dimensions: %d by %d\n", headerPtr->dwWidth, headerPtr->dwHeight);
    printf("Planes: %d\n", headerPtr->wPlanes);
    printf("Color depth: %d\n", headerPtr->wBitCount);
    printf("Compression: %d\n", headerPtr->dwCompression);
    printf("Image size: %d\n", headerPtr->dwImageSize);
    printf("Colors used: %d\n", headerPtr->dwClrUsed);

}

void ManipulateImage(IMAGE*, BM_FUNC_PTR)
{

}

PIXEL* GetPixel(int row, int col, IMAGE* imgPtr)
{

}

void ManipulateTwoImages(IMAGE*, IMAGE*, BM_TWO_PIXELS)
{

}


IMAGE ResizeCanvas(IMAGE*, int, int)
{

}

void InitializePixelData(IMAGE* imgPtr, PIXEL desiredPixel)
{

}

IMAGE Crop(IMAGE*, int, int, int, int)
{

}

IMAGE RotateImage(IMAGE* imgPtr, double theta)
{

}

void AntiAlias(IMAGE*)
{

}

IMAGE FancyRotateImage(IMAGE* imgPtr, double theta)
{

}

void WriteImage(IMAGE*, FILE*)
{

}

void FreeImage(IMAGE*)
{

}