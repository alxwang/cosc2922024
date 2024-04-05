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

//7.	How would you define a union that would contain options for memory to be stored
//        in bytes (as a long long int, in MB (as an int),
//                  in GB (as a short), or in TB (as an unsigned char)?

typedef union{
    long long int bytes; //8 bytes
    int mb;
    short gb;
    unsigned char tb;
}MemorySize;
#define BYTE unsigned char
BYTE mixByte(BYTE byte)
{
//    return byte>>6 | byte<<2;//Simple one
    BYTE rs = byte>>6 | byte<<2;
    BYTE bit3= (rs & 0x40) >> 1;
    BYTE bit2=(rs & 0x20) << 1;
    rs = (rs & 0x9F) | bit2 | bit2;
    return rs;
}

BYTE unmixByte(BYTE byte)
{
//    return byte >> 2 | byte <<6; //Simple one
    BYTE rs = byte >> 2 | byte <<6;
    BYTE bit5 = (rs & 0x10) >>1;
    BYTE bit4 = (rs & 0x08) <<1;
    rs = (rs & 0xE7) | bit4 | bit5;
    return rs;
}

int main(int argc, char ** argv) {
    //8.	What would the size of the union given above be? 8 bytes
    printf("%d\n",sizeof(MemorySize));

    MemorySize m;

    m.tb = 16; //0x10
    printf("%x\n", m.bytes); //00000000000000010
    m.bytes = 1234567890;//0x00000000499602D2
    printf("%x\n", m.tb);//tb is the lowest byte of the union
    printf("%x\n", m.gb);//tb is the lowest 2 bytes of the union
    printf("%x\n", m.mb);//tb is the lowest 4 byte of the union


//    computer  * com = assignValuesPtr("123456789",16,'A',"Not enough ram");
//    displayValuePtr(com);
//    free(com);
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
