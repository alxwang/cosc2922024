#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

typedef struct {
    char a;
    char b;
    int i;
} S1;

typedef struct {
    char a[5];
    short d;
    short e;
    int i;
    char b;
} S2;



int main() {
    printf("%d\n",sizeof(S1));
    printf("%d\n",sizeof(S2));
//    classroom  * c = PopulateClassroom();
//    DisplayClassroom(c);
//    FreeClassroom(c);
    return 0;
}
