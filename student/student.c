//
// Created by Alex Wang on 2024-03-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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

//Convert student struct to a mem block so we can easily write it to file
unsigned char * Student2Stream(student * s)
{

}

//Write classroom to file
void writeClassroom2File(classroom * c, FILE * f)
{

}

//read classroom from file
void readClassroomFromFile(classroom * c, FILE * f)
{

}

//Without touch/access classroom struct, add a new student into file directly
void addStudent2FileWithoutClassroom(student * s, FILE * f)
{

}