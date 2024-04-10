#include <stdio.h>
#include "bitmap.h"
int main() {
    FILE * f = GetFile("Please enter a bitmap file:","rb");
    printf("%x",f);
    return 0;
}
