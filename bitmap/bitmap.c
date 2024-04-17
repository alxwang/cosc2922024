#include "bitmap.h"
#include <memory.h>
#include <math.h>
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

void ReadImage(IMAGE*, FILE*)
{

}

void ReadHeader(IMAGE*, FILE*)
{

}

void ReadData(IMAGE*, FILE*)
{

}

void PrintHeader(BITMAPHDR*)
{

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