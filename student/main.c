#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
//Please complete the following 3 func before 2:30

student* CreateStudent(char* cNamePtr, int iStudentNum, int* iMarksPtr, int iMarkCount)
{

}

void DisplayStudent(student * s)
{

}

void FreeStudent(student* sPtr)
{

}


student* GetStudent()
{
    char cName[MAX_NAME_SIZE];
    int iMarks[2];
    int iStudentNum;

    // Get the name
    printf("Enter the student name: ");
    fgets(cName, MAX_NAME_SIZE,stdin);

    // Get the student number
    printf("Enter the student number: ");
    scanf("%d", &iStudentNum);

    printf("Enter two marks, separated by a space: ");
    scanf("%d %d", iMarks, iMarks + 1);
    getc(stdin); // Clear any newline characters for next time

    return CreateStudent(cName, iStudentNum, iMarks, 2);
}



int main() {

    return 0;
}
