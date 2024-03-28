//
// Created by Alex Wang on 2024-03-22.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#define MAX_NAME_SIZE 128
#include <stdio.h>
#pragma push(pack)
#pragma pack(1)
typedef struct
{
    //name
    char * cNamePtr;
    //student#
    int iStudentNum;
    //list of marks
    int * iMarkPtr;
    int iMarkCount;
}student;

typedef struct
{
    //list of students
    student ** sPtrPtr; //-->student * sPtr[] without limitation
    int sNumStudents;
}classroom;
#pragma pop(pack)
/*
 * Define func for two structs
 */

// A function that creates a student and initializes the attributes. This is similar to the
// keyword new in C# or Java. It allocates the instance AND it is also like a constructor
// that sets all the attributes.
student* CreateStudent(char* cNamePtr, int iStudentNum, int* iMarksPtr, int iMarkCount);

// A function to display the date stored in a student instance.
// Takes a student instance, not a pointer. Sometimes this is done as a copy of the student
// is made. If this function messes up the struct somehow, it will not mess up the struct
// passed in.
void DisplayStudent(student * s);

// This function will free the memory allocated for a student instance.
// In C++, there is a function called a destructor where the programmer is
// supposed to release memory and clean up any other resources - this is similar.
void FreeStudent(student* sPtr);

//Convert student struct to a mem block so we can easily write it to file
unsigned char * Student2Stream(student * s, int * nSize);
//Write classroom to file
void writeClassroom2File(classroom * c, FILE * f);
//read classroom from file
void readClassroomFromFile(classroom ** c, FILE * f);
//Without touch/access classroom struct, add a new student into file directly
void addStudent2FileWithoutClassroom(student * s, FILE * f);

// Get student data from the user
student* GetStudent();

// Ask the user to populate the classroom. First ask how many students.
// Then ask for data for each student.
classroom * PopulateClassroom();

// Display each student in the classroom
void DisplayClassroom(classroom * c);

void FreeClassroom(classroom* classPtr);


#endif //STUDENT_STUDENT_H
