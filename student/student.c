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
 * Memory block layout:
 * int 4 overall size of the memblk - 4(the current int)
 * int 4 len of name(not include null ending)
 * char ? name(not include null ending)
 * int 4 student num
 * int 4 iMarkCount
 * int ? marks
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
    *((int*)pCur)=s->iStudentNum; //copy student #
    pCur+=sizeof(int);//Move forward 4 bytes
    *((int*)pCur)=s->iMarkCount;//Copy marks count
    pCur+=sizeof(int);//Move forward 4 bytes
    memcpy(pCur,s->iMarkPtr,sizeof(int)*s->iMarkCount); //Copy all marks
    return memblock;
}

//Write classroom to file
void writeClassroom2File(classroom * c, FILE * f)
{
    //Write the num students
    fwrite(&c->sNumStudents,sizeof(int),1,f);
    for(int i=0;i<c->sNumStudents;i++)
    {
        //For each student struct
        int nSize = 0;
        //Get the memblk(cont.) for the student
        unsigned char * memblk = Student2Stream(c->sPtrPtr[i],&nSize);
        //Write it to file
        writeFile(f,memblk,nSize);
        free(memblk);
        memblk=NULL;
    }
}

/*
 * Memory block layout:
 * int 4 overall size of the memblk - 4(the current int)
 * int 4 len of name(not include null ending)
 * char ? name(not include null ending)
 * int 4 student num
 * int 4 iMarkCount
 * int ? marks
 */

student * Stream2Student(unsigned char * memblk)
{
    student * s = (student*) malloc(sizeof(student));
    unsigned char * pCur = memblk;
    //Read size of name in bytes(not including null ending)
    int namesize = *((int*)pCur);
    pCur+=sizeof(int);//Move forward 4 bytes
    //Alloc string for name
    s->cNamePtr = (char*) malloc(namesize+1);//First 4 bytes is the len of name
    //Set string to ""
    memset(s->cNamePtr,0,namesize+1);
    //Copy all chars to name(not include null ending)
    memcpy(s->cNamePtr,pCur,namesize);
    //Move forward name len bytes
    pCur+= strlen(s->cNamePtr);//Move forward name-len bytes
    //Copy student #
    s->iStudentNum = *((int*)pCur);
    pCur+=sizeof(int);//Move forward 4 bytes
    //Copy mark count
    s->iMarkCount = *((int*)pCur);
    pCur+=sizeof(int);//Move forward 4 bytes
    //Alloc int array for marks
    s->iMarkPtr = (int*) malloc(sizeof(int)*s->iMarkCount);
    //Copy all marks
    memcpy(s->iMarkPtr,pCur,sizeof(int)*s->iMarkCount);
    return s;
}

//read classroom from file
void readClassroomFromFile(classroom ** c, FILE * f)
{
    int numStudent = 0;
    //read student count
    fread(&numStudent,sizeof(int),1,f);
    *c = (classroom*) malloc(sizeof(classroom));
    (*c)->sNumStudents=numStudent;
    (*c)->sPtrPtr = (student**) malloc((*c)->sNumStudents*sizeof(student*));
    for(int i=0;i<numStudent;i++)
    {
        //for each student
        int sizeofRec = 0;
        //Read the num of bytes for the student
        fread(&sizeofRec,sizeof(int),1,f);
        //read those bytes
        unsigned char * memblk = (unsigned char *) malloc(sizeofRec);
        readFile(f,memblk,sizeofRec);
        (*c)->sPtrPtr[i]= Stream2Student(memblk);
    }
}

//Without touch/access classroom struct, add a new student into file directly
void addStudent2FileWithoutClassroom(student * s, FILE * f)
{
    //Assume f is opened as append and
    // has at only one classroom
    //Seek to the beginning
    fseek(f,0,SEEK_SET);
    //Read 4 byte as int and keep it as the student count
    int nCount = 0;
    if (sizeof(int)!=fread(&nCount,sizeof(int),1,f))
    {
        printf("Failed to read student count\n");
        return;
    }
    //Seek to the end because we only APPEND
    fseek(f,0,SEEK_END);
    //Call Student2Steam to get the memblok
    int nSize = 0;
    unsigned char * memblk = Student2Stream(s,&nSize);
    //Write the memblok to the end of file
    writeFile(f,memblk,nSize);
    //Seek to the beginning
    fseek(f,0,SEEK_SET);
    //Write/update the student count
    //Write 4 byte int as count+1
    nCount++;
    if (sizeof(int)!=fwrite(&nCount,sizeof(int),1,f))
    {
        printf("Failed to update student count\n");
    }
}