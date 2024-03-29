#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
//Please complete the following 3 func before 2:30

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

//Please work on the following two funcs
//I will start 3:15

//Let user tell how many students first
//Ask user enter the info of each student
//Add each student into the classroom struct
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


//Try to write fwrite a classroom into file and load it back
// If a member of stuct is pointer, fwrite the stuct will not fwrite the mem of the pointer for you.
// Write the pointer addr into file does not have any value
// You should always write the mem pointer point to to the file

int main() {
    classroom  * c = PopulateClassroom();
    DisplayClassroom(c);
    FreeClassroom(c);
    return 0;
}
