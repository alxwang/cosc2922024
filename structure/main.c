#include <stdio.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>

//void printBirthDate(BirthDate b)
//{
//    b.day=31;
//    printf("%s %d-%d-%d\n",b.cName,b.year, b.month,b.day);
//}
//void printBirthDatePtr(BirthDate * b)
//{
//    b->day=31;//(*b).day=31
//    printf("%s %d-%d-%d\n",b->cName,b->year, b->month,b->day);
//}


int main() {
//    BirthDate birthDate;
//    strcpy(birthDate.cName,"alex");
//    birthDate.day=1;
//    birthDate.month=1;
//    birthDate.year = 2010;
//    printBirthDatePtr(&birthDate);//pointer passed
//    printBirthDate(birthDate);//Memcpy from main stack to func stack happens
//    printf("%d", birthDate.day);
//    int size_of_BirthDate = sizeof(BirthDate);
//    printf("Size of BirthDate stuct is %d\n",size_of_BirthDate);
//    BirthDate * pb = (BirthDate*)malloc(size_of_BirthDate);
//    strcpy(pb->cName,"Alex");
//    pb->day=1;
//    pb->month=1;
//    pb->year=2000;
////    printBirthDatePtr(pb);
//    printBirthDate(*pb);
//    free(pb);
    BirthDate b;
//    b.day =1;
//    b.month=1;
//    b.year=1;
//    b.date=(int*) malloc(sizeof(int)*3);
//    b.date[2]=2000;
//    b.date[1]=1;
//    b.date[0]=1;
////    b.cName=(char*) malloc(5);
////    strcpy(b.cName,"alex");
//    b.cName = strdup("alex");
//
//    printf("%s\n",(char*)b.cName);
//    Date * d = (Date*)(b.date);//b.date is a int arr of 3 ints
//    printf("%d %d %d\n",d->year,d->month,d->day);

//...
//    free(b.cName);
    SOMETHING u;
    u.b='a';
    u.i=10;
    strcpy(u.name,"alex");
    printf("%c\n",u.b);
    printf("%d\n",u.i);
    return 0;
}
