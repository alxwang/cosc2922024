//
// Created by Alex Wang on 2024-03-22.
//

#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H
#define MAX_NAME_SIZE 128
/*
 * Define two structs
 * 1. student includes name(not limitation pls), student#, list of marks(no limitation)
 * 2. class include list of students(no limitation)
 *
 * Let's get into the break room and working on create 2 structs
 * I will start in 1:50
 *
 */
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

// Get student data from the user
student* GetStudent();

// Ask the user to populate the classroom. First ask how many students.
// Then ask for data for each student.
classroom * PopulateClassroom();

// Display each student in the classroom
void DisplayClassroom(classroom * c);

void FreeClassroom(classroom* classPtr);


#endif //STUDENT_STRUCT_H
