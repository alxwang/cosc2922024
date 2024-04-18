#include <stdio.h>
#include <string.h>
#include "bitmap.h"
int main() {
    FILE * f = GetFile("Please enter a bitmap file:","rb");
    IMAGE img;
    memset(&img,0,sizeof(IMAGE));
    ReadImage(&img,f);
    fclose(f);
    if(img.bmHDR!=NULL)
    {
        PrintHeader(img.bmHDR);
    }
//    img = Crop(&img,300,200,700,600);
    img = ResizeCanvas(&img, 400,300);
    f = fopen("new.bmp","w");
    WriteImage(&img,f);
    fclose(f);
    return 0;
}
