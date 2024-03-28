//
// Created by Alex Wang on 2024-03-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "fileio.h"

student* CreateStudent(char* cNamePtr, int iStudentNum, int* iMarksPtr, int iMarkCount)
{
    student  * sPtr = (student*) malloc(sizeof(student));
    sPtr->cNamePtr = strdup(cNamePtr);
    sPtr->iStudentNum = iStudentNum;
    sPtr->iMarkCount = iMarkCount;
    sPtr->iMarkPtr =(int*) malloc(iMarkCount*sizeof(int));
    memcpy(sPtr->iMarkPtr,iMarksPtr,iMarkCount*sizeof(int));
    return sPtr;
}

void DisplayStudent(student * s)
{
    printf("Name: %s\nStudent#: %d\nMarks:\n",s->cNamePtr,s->iStudentNum);
    for(int i=0;i<s->iMarkCount;i++)
    {
        printf("%d ",s->iMarkPtr[i]);
    }
    printf("\n");
}

void FreeStudent(student* sPtr)
{
    free(sPtr->cNamePtr);
    free(sPtr->iMarkPtr);
    free(sPtr);
}


student* GetStudent()
{
    char cName[MAX_NAME_SIZE];
    int iMarks[2];
    int iStudentNum;

    // Get the name
    printf("Enter the student name: ");
    fgets(cName, MAX_NAME_SIZE,stdin);
    cName[strlen(cName)-1]=0; //Remove newline \n
    // Get the student number
    printf("Enter the student number: ");
    scanf("%d", &iStudentNum);

    printf("Enter two marks, separated by a space: ");
    scanf("%d %d", iMarks, iMarks + 1);
    getc(stdin); // Clear any newline characters for next time

    return CreateStudent(cName, iStudentNum, iMarks, 2);
}

classroom * PopulateClassroom(){
    classroom * c = (classroom*) malloc(sizeof(classroom));
    memset(c,0,sizeof(classroom));
    printf("Enter number of students: ");
    scanf("%hu", &c->sNumStudents);
    getc(stdin);
    //Your code
    c->sPtrPtr = (student**) malloc(c->sNumStudents*sizeof(student*));

    for(int i =0;i<c->sNumStudents;i++)
    {
        c->sPtrPtr[i] = GetStudent();
    }
    return c;
}

void FreeClassroom(classroom* classPtr)
{
    for(int i =0;i<classPtr->sNumStudents;i++)
    {
        free(classPtr->sPtrPtr[i]); //Free all students
    }
    free(classPtr->sPtrPtr); //free student array
    free(classPtr);
}


// Display each student in the classroom
void DisplayClassroom(classroom * c)
{
    for (int i = 0; i < c->sNumStudents; i++)
    {
        DisplayStudent(c->sPtrPtr[i]);
    }
}
/*
 * typedef struct
{
    //name
    char * cNamePtr;
    //student#
    int iStudentNum;
    //list of marks
    int * iMarkPtr;
    int iMarkCount;
}student;
 */


//Convert student struct to a mem block so we can easily write it to file
unsigned char * Student2Stream(student * s, int * nSize)
{
    *nSize =sizeof(int) //Overall size to read except this number
                +sizeof(int) //Space for iStudenNUm
                +sizeof(int)//Space for iMarkCount
                +strlen(s->cNamePtr)//space for name
                +sizeof(int)//Space of the length for name
                +sizeof(int)*s->iMarkCount;//Space of marks

    unsigned char * memblock = (unsigned char*) malloc(*nSize);
    unsigned char * pCur = memblock;
    *((int*)pCur)=*nSize-sizeof(int);
    pCur+=sizeof(int);//Move forward 4 bytes
    *((int*)pCur)= strlen(s->cNamePtr);//First 4 bytes is the len of name
    pCur+=sizeof(int);//Move forward 4 bytes
    strcpy(pCur,s->cNamePtr);//Copy name to the memblock
    pCur+= strlen(s->cNamePtr);//Move forward name-len bytes
    *((int*)pCur)=s->iStudentNum;
    pCur+=sizeof(int);
    *((int*)pCur)=s->iMarkCount;
    pCur+=sizeof(int);
    memcpy(pCur,s->iMarkPtr,sizeof(int)*s->iMarkCount);
    return memblock;
}

//Write classroom to file
void writeClassroom2File(classroom * c, FILE * f)
{
    //Write the num students
    fwrite(&c->sNumStudents,sizeof(int),1,f);
    for(int i=0;i<c->sNumStudents;i++)
    {
        int nSize = 0;
        unsigned char * memblk = Student2Stream(c->sPtrPtr[i],&nSize);
        writeFile(f,memblk,nSize);
        free(memblk);
        memblk=NULL;
    }
}

//read classroom from file
void readClassroomFromFile(classroom ** c, FILE * f)
{
    int numStudent = 0;
    fread(&numStudent,sizeof(int),1,f);
    *c = (classroom*) malloc(sizeof(classroom));
    (*c)->sNumStudents=numStudent;
    for(int i=0;i<numStudent;i++)
    {
        student * s = (student*) malloc(sizeof(student));
        (*c)->sPtrPtr[i]=s;
        int sizeofRec = 0;
        fread(&sizeofRec,sizeof(int),1,f);
        unsigned char * memblk = (unsigned char *) malloc(sizeofRec);
        readFile(f,memblk,sizeofRec);

        unsigned char * pCur = memblk;

        //Why we can not use strdup?
        //How to change our code to use it?
        //Can we use strcpy instead of memcpy?
        int namesize = *((int*)pCur);
        pCur+=sizeof(int);
        s->cNamePtr = (char*) malloc(namesize+1);//First 4 bytes is the len of name
        memset(s->cNamePtr,0,namesize+1);
        memcpy(pCur,s->cNamePtr,namesize);

        pCur+= strlen(s->cNamePtr);//Move forward name-len bytes

        s->iStudentNum = *((int*)pCur);
        pCur+=sizeof(int);

        s->iMarkCount = *((int*)pCur);
        pCur+=sizeof(int);

        s->iMarkPtr = (int*) malloc(sizeof(int)*s->iMarkCount);
        memcpy(pCur,s->iMarkPtr,sizeof(int)*s->iMarkCount);

    }
}

//Without touch/access classroom struct, add a new student into file directly
void addStudent2FileWithoutClassroom(student * s, FILE * f)
{

}