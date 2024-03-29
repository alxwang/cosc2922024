#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "fileio.h"



int main(int argc, char ** argv) {
    classroom  * c = PopulateClassroom();
    printf("You entered:\n---------------------\n");
    DisplayClassroom(c);
    FILE * f = openFile("cls.dat","w");
    writeClassroom2File(c,f);
    FreeClassroom(c);
    c=NULL;
    fclose(f);
    f = openFile("cls.dat","r");
    readClassroomFromFile(&c, f);
    printf("Read from file:\n---------------------\n");
    DisplayClassroom(c);
    return 0;
}
