#include <stdio.h>
#include "other.h"
#include "test.h"
int main() {
    FOO f;
    printf("Hello, World!\n");
    printf("in Main, %f\n",PI);
    test();
    othertest();
    return 0;
}
