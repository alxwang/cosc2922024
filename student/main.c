#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "fileio.h"

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
}COLOR;

typedef struct{
    unsigned short h;
    unsigned short l;
}TWOSHORT;

typedef union {
    unsigned int nVal;
    COLOR c;
    TWOSHORT ts;
}COLOR_VAL;
/*
 * 1.Create a struct representing a computer.
 * The struct should contain space for a 9-digit
 * computer ID (plus a null terminator),
 * an int for the size of RAM,
 * a character for a unit of RAM (like ‘K’ for kilobyte or ‘G’ for gigabyte),
 * and a pointer to dynamically allocated memory for a computer description.
 */
typedef struct
{
    char ID[10];//12
    int ram; //4
    char ramUnit;//4
    char * desc; //4
}computer;
typedef struct
{
    char ID[10];
    char ramUnit; //12
    int ram;//4
    char * desc; //4
}computer1;

computer assignValues(char* id, int ram, char unit, char* description)
{
    computer c;
    memset(&c,0,sizeof(computer));
    strncpy(c.ID,id,9);
    c.ram = ram;
    c.ramUnit = unit;
    c.desc = strdup(description);
    return c;
}

void displayValues(computer  c)
{
    printf("%s: %d %c %s\n",c.ID,c.ram,c.ramUnit,c.desc);
}

computer  * assignValuesPtr(char* id, int ram, char unit, char* description)
{
    computer * c=(computer*) malloc(sizeof(computer));
    memset(c,0,sizeof(computer));
    strncpy(c->ID,id,9);
    c->ram = ram;
    c->ramUnit = unit;
    c->desc = strdup(description);
    return c;
}

void displayValuePtr(computer *  c)
{
    printf("%s: %d %c %s\n",c->ID,c->ram,c->ramUnit,c->desc);
}


int main(int argc, char ** argv) {
    computer  * com = assignValuesPtr("123456789",16,'A',"Not enough ram");
    displayValuePtr(com);
    free(com);
    return 0;



//  COLOR  c = {100,100,100,100};
    COLOR_VAL cv;
    cv.nVal= 0x2A3BFF1C;
    printf("%x\n",cv.nVal);
    printf("%x\n",cv.c.r);
    printf("%x\n",cv.c.g);
    printf("%x\n",cv.c.b);
    printf("%x\n",cv.c.a);
    cv.c.a =0x3a;
    printf("%x\n",cv.nVal);


    char * str = "alex";
    char str1[] = "alex";
    int arr[] = {1,2,3,4,6};
//    int * arr1 = {1,2,3}; Not works

    student s = {
            "Alex",
            123,
            NULL,
            0
    };


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
