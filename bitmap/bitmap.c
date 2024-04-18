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

void ManipulateImage(IMAGE*imgPtr, BM_FUNC_PTR func)
{
    for(int row =0;row<imgPtr->bmHDR->dwHeight;row++)
    {
        for(int col=0;col<imgPtr->bmHDR->dwWidth;col++)
        {
            func(GetPixel(row,col,imgPtr));
        }
    }
}

PIXEL* GetPixel(int row, int col, IMAGE* imgPtr)
{
    unsigned int padding = imgPtr->bmHDR->dwWidth % 4;
    unsigned int offset =
            (imgPtr->bmHDR->dwWidth*sizeof(PIXEL)+padding)*row+
            col*sizeof(PIXEL);
    return (PIXEL*)(((BYTE*)imgPtr->bmData)+offset);
}

void ManipulateTwoImages(IMAGE* imgPtr1, IMAGE*imgPtr2, BM_TWO_PIXELS func)
{
    //Apply func to the area of the smaller image
    //Get work area size
    int height  = (imgPtr1->bmHDR->dwHeight<imgPtr2->bmHDR->dwHeight)?
                    imgPtr1->bmHDR->dwHeight:imgPtr2->bmHDR->dwHeight;
    int width = (imgPtr1->bmHDR->dwWidth<imgPtr2->bmHDR->dwWidth)?
                imgPtr1->bmHDR->dwWidth:imgPtr2->bmHDR->dwWidth;
    for(int row =0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            func(GetPixel(row,col,imgPtr1),GetPixel(row,col,imgPtr2));
        }
    }
}


IMAGE ResizeCanvas(IMAGE*imgPtr, int newWidth, int newHeight)
{
    IMAGE imgNew={NULL,NULL};
    unsigned int newImageSize = 0;
    unsigned int padding = 0;
    unsigned int width,height;
    PIXEL startPixel={255,255,255};
    imgNew.bmHDR=(BITMAPHDR*) malloc(sizeof(BITMAPHDR));
    if(imgNew.bmHDR)
    {
        memcpy(imgNew.bmHDR,imgPtr->bmHDR,sizeof(BITMAPHDR));
        imgNew.bmHDR->dwWidth=newWidth;
        imgNew.bmHDR->dwHeight=newHeight;
        padding = newWidth % 4;
        newImageSize = (newWidth*sizeof(PIXEL)+padding)*newHeight;
        imgNew.bmHDR->dwImageSize=newImageSize;
        imgNew.bmHDR->dwFileSize=newImageSize+ sizeof(BITMAPHDR);
        imgNew.bmData=(PIXEL*) malloc(newImageSize);
        if(imgNew.bmData)
        {
            InitializePixelData(&imgNew,startPixel);
            height=(newHeight<imgPtr->bmHDR->dwHeight)?newHeight:imgPtr->bmHDR->dwHeight;
            width=(newWidth<imgPtr->bmHDR->dwWidth)?newWidth:imgPtr->bmHDR->dwWidth;
            float xr = (float)imgPtr->bmHDR->dwWidth/(float)width;
            float yr = (float)imgPtr->bmHDR->dwHeight/(float)height;
            for(int row =0;row<height;row++)
                for(int col=0;col<width;col++)
                {
                    *GetPixel(row,col,&imgNew)=
                            *GetPixel((int)(row*yr),(int)(col*xr),imgPtr);
                }
        }
    }
    return imgNew;
}

void InitializePixelData(IMAGE* imgPtr, PIXEL desiredPixel)
{
    for(int row =0;row<imgPtr->bmHDR->dwHeight;row++)
    {
        for(int col=0;col<imgPtr->bmHDR->dwWidth;col++)
        {
            *(GetPixel(row,col,imgPtr))=desiredPixel;
        }
    }

}

IMAGE Crop(IMAGE* imgPtr, int newWidth, int newHeight, int top, int left)
{
    IMAGE imgNew={NULL,NULL};
    unsigned int newImageSize = 0;
    unsigned int padding = 0;
    unsigned int width,height;
    PIXEL startPixel={255,255,255};
    imgNew.bmHDR=(BITMAPHDR*) malloc(sizeof(BITMAPHDR));
    if(imgNew.bmHDR)
    {
        memcpy(imgNew.bmHDR,imgPtr->bmHDR,sizeof(BITMAPHDR));
        imgNew.bmHDR->dwWidth=newWidth;
        imgNew.bmHDR->dwHeight=newHeight;
        padding = newWidth % 4;
        newImageSize = (newWidth*sizeof(PIXEL)+padding)*newHeight;
        imgNew.bmHDR->dwImageSize=newImageSize;
        imgNew.bmHDR->dwFileSize=newImageSize+ sizeof(BITMAPHDR);
        imgNew.bmData=(PIXEL*) malloc(newImageSize);
        if(imgNew.bmData)
        {
            InitializePixelData(&imgNew,startPixel);
            height=(newHeight<imgPtr->bmHDR->dwHeight)?newHeight:imgPtr->bmHDR->dwHeight;
            width=(newWidth<imgPtr->bmHDR->dwWidth)?newWidth:imgPtr->bmHDR->dwWidth;
            for(int row =0;row<height;row++)
                for(int col=0;col<width;col++)
                {
                    *GetPixel(row,col,&imgNew)=*GetPixel(row+top,col+left,imgPtr);
                }
        }
    }
    return imgNew;
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

void WriteImage(IMAGE*imgPtr, FILE*f)
{
    unsigned int padding = imgPtr->bmHDR->dwWidth % 4;
    unsigned int imageSize = (imgPtr->bmHDR->dwWidth*sizeof(PIXEL)+padding)*imgPtr->bmHDR->dwHeight;
    if(fwrite(imgPtr->bmHDR, sizeof(BITMAPHDR),1,f)!=1)
    {
        printf("Failed to write image header\n");
    }
    else
    {
        if(fwrite(imgPtr->bmData,imageSize,1,f)!=1)
        {
            printf("Failed to write image data.\n");
        }
    }
}

void FreeImage(IMAGE*imgPtr)
{
    free(imgPtr->bmHDR);
    imgPtr->bmHDR=NULL;
    free(imgPtr->bmData);
    imgPtr->bmData=NULL;
}