//
// Created by Alex Wang on 2024-03-21.
//

#ifndef STRUCTURE_STRUCT_H
#define STRUCTURE_STRUCT_H
#define NAME_SIZE 5

//20 bytes
//#pragma pack(push)
//#pragma pack(1)
typedef struct
{
//    char cName[NAME_SIZE];//8 bytes
    char * cName;
//    int day ; //4
//    int month;//4
//    int year;//4
    int * date;
}BirthDate;

typedef struct
{
    int day ; //4
    int month;//4
    int year;//4
}Date;



//#pragma pack(pop)

typedef union
{
    int i;
    float b;
    char c;
    char name[5];
}SOMETHING;

typedef struct
{
    float x;
    float y;
}Point;



#endif //STRUCTURE_STRUCT_H
