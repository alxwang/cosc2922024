#include <stdio.h>
#include <string.h>
#include "bitmap.h"
int main() {
    FILE * f = GetFile("Please enter a bitmap file:","rb");
    IMAGE img;
    memset(&img,0,sizeof(IMAGE));
    ReadImage(&img,f);
    if(img.bmHDR!=NULL)
    {
        PrintHeader(img.bmHDR);
    }
    return 0;
}
