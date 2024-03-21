//
// Created by Alex Wang on 2024-03-21.
//

#ifndef STRUCTURE_STRUCT_H
#define STRUCTURE_STRUCT_H
#define NAME_SIZE 5

typedef struct
{
    char cName[NAME_SIZE];
    int day;
    int month;
    int year;
}BirthDate;

typedef struct
{
    float x;
    float y;
}Point;



#endif //STRUCTURE_STRUCT_H
