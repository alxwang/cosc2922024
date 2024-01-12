//
// Created by Alex Wang on 2024-01-12.
//
#include "strfuncs.h"
const float CPI= 3.1415926f;
//Work on the following function
//Return the length of pstr without the \0
int stringlen(char * pstr)
{
    int count = 0;
    for(char * ps = pstr;*ps;ps++)
    {
        count++;
    }
//    for(char ch=pstr[count];ch;ch = pstr[count])
//    {
//        count++;
//    }
    return count;
}