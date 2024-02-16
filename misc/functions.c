//
// Created by Alex Wang on 2024-02-16.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <float.h>

//Return a new string in cPtrPtr. It should contain the string in cPtrPtr and remove count of chars from right(end)
void trimRight(char ** cPtrPtr, int count)
{
    char * str = *cPtrPtr;
    printf("Address of Original Str is %p\n",str);
    printf("Address of Original Str Ptr ptr is %p\n",cPtrPtr);
    int diff = strlen(str)-count;
    *cPtrPtr = (char*) malloc(diff+1);
    memcpy(*cPtrPtr,str,diff);
    *(*cPtrPtr+diff) = 0;//Manually set the last char in the mem block as 0 to make it into a str
    free(str);//Free only can free mem alloced by malloc
    str=NULL;
}


int findChar(char * str, char tofind, char ** strptrptr)
{
    int loc = 0;
    while(*str)
    {
        if(*str==tofind)
        {
            *strptrptr = str;
            return loc;
        }
        str++;
        loc++;
    }
    *strptrptr=NULL;
    return -1;
}

char * allocRow(int size)
{
    char * str = (char*) malloc(size * sizeof(char));
    str[0]=0;
    return str;
}

char** createArray(int rowsize[],int numRows)
{
    //Alloc an array of char*
    char ** cPtrptr = (char**) malloc(numRows*sizeof(char*));
    for(int i=0;i< numRows;i++)
    {
        char * row = allocRow(rowsize[i]);
        *(cPtrptr+i) = row;
    }
    return cPtrptr;
}

void printArray(char ** cPtrPtr, int numRows)
{
    for(int i=0;i<numRows;i++)
    {
        printf("%s\n",cPtrPtr[i]);
    }
}

void testJaggedArray()
{
    int iRowVals[] = { 4, 6, 5 };
    // calculate the number of rows in iRowVals
    int iRows = sizeof(iRowVals) / sizeof(int);

    // Create the jagged array
    char** cPtrPtr = createArray(iRowVals, iRows);

    // Add some data to each row
    // Index into each location char by char using brackets
    cPtrPtr[0][0] = 'M';
    cPtrPtr[0][1] = 'e';
    cPtrPtr[0][2] = 'l';
    cPtrPtr[0][3] = '\0';

    // Index in using pointer math
    *(*(cPtrPtr + 1) + 0) = 'C';
    *(*(cPtrPtr + 1) + 1) = 'h';
    *(*(cPtrPtr + 1) + 2) = 'r';
    *(*(cPtrPtr + 1) + 3) = 'i';
    *(*(cPtrPtr + 1) + 4) = 's';
    *(*(cPtrPtr + 1) + 5) = '\0';

    // Use strcpy - only because this is a jagged array of chars
    strncpy(cPtrPtr[2],"Mark",iRowVals[2]);

    // Print the array
    printArray(cPtrPtr, iRows);

    // Free ALL the memory created for the jagged array
    // Free each row first
    for (int i = 0; i < iRows; i++)
    {
        free(cPtrPtr[i]);
        cPtrPtr[i] = NULL;
    }
    free(cPtrPtr);
    cPtrPtr = NULL;
}
double * read_doubles_in_java_style(int * size, double ** max)
{
    double dMax = -DBL_MAX;
    printf("Please enter the numbers of doubles:");
    scanf("%d",size);
    double * arr = (double *) malloc(*size*sizeof(double));
    for(int i=0;i<*size;i++)
    {
        printf("Please enter a double:");
        scanf("%lf",&arr[i]);
        if(arr[i]>dMax)
        {
            dMax=arr[i];
            *max=arr+i;
        }

    }
    return arr;
}

double * read_doubles(int * size, double ** max)
{
    printf("Please enter the numbers of doubles:");
    scanf("%d",size);
    double * arr = (double *) malloc(*size*sizeof(double));
    *max=arr;//Set the first value as the max value
    for(int i=0;i<*size;i++)
    {
        printf("Please enter a double:");
        scanf("%lf",&arr[i]);
        if(arr[i]>**max)//**max has the cur max val
        {
            *max=arr+i;
        }

    }
    return arr;
}
//Get some double from user and find the max value
void testDoubleArrayWithMax()
{
    // Create a function that ask the user for a number of doubles
    // and read in that number of doubles ("%lf" in scanf) into a dynamically allocated array
    // and return that array.
    // Also change an int so that it will contain the size of the array allocated.
    // Also change a pointer so that it will point to the largest element in that array.
    // In this function (calling function), print out the array and then print out the max value.
    int iArraySize;
    double* dMaxPointer = NULL;
    double* dArray = read_doubles(&iArraySize, &dMaxPointer);

    for (int i = 0; i < iArraySize; i++)
    {
        printf("Double #%d: %lf\n", i, dArray[i]);
    }
    printf("The max value at %p and was %lf\n", dMaxPointer, *dMaxPointer);

    free(dArray);
    dArray = NULL;
}

//swap byte from an int to a char *
void swapBytesWithPointer_in_java_style(int* iValuePtr, char** cBytePtrPtr)
{
    int i = *iValuePtr;
    char * BytePointerOld = (char*)&i;
    char * BytePointerNew = (char*)iValuePtr;
    BytePointerNew[3] = BytePointerOld[0];
    BytePointerNew[2] = BytePointerOld[1];
    BytePointerNew[1] = BytePointerOld[2];
    BytePointerNew[0] = BytePointerOld[3];
    *cBytePtrPtr = BytePointerNew+3;//Highest byte
}

void swapBytesWithPointer(int* iValuePtr, char** cBytePtrPtr)
{
    char * bytes = (char*) iValuePtr;
    char temp;
    temp = bytes[0];
    bytes[0]=bytes[3];
    bytes[3]=temp;
    temp = bytes[1];
    bytes[1]=bytes[2];
    bytes[2]=temp;
    *cBytePtrPtr=&bytes[3];
}

void testSwapBytesWithPointer()
{
    // Create a function that will take an int and swap its bytes (as if it was Big-Endian
    // instead of Little-Endian) and change a char pointer to the new high-order byte (formerly
    // the low-order byte). For instance, if 0x65666768 was passed in, the result would be
    // 0x68676665 and the pointer would point to the byte containing 0x68.
    int iValue = 0x65666768;
    char* cBytePointer = NULL;

    printf("Initial value: %x\t%d\n", iValue, iValue);
    swapBytesWithPointer(&iValue, &cBytePointer);
    printf("Changed value: %x\t%d\n", iValue, iValue);
    printf("New high-order byte: %x\n", *cBytePointer);
}

//But no one should use global var anymore
//int grade_count = 0;//global var

int getGrade(int * grade_count)
{
    //do some reading, figure out where is a global var sit in mem area
    //Where is a static var siting in mem area
    //Will the global var has an init value change the mem area?
//    static int grade_count = 0;//static local value
    *grade_count++;
    int grade;
    printf("Please enter a grade(0 to end):");
    scanf("%d",&grade);
    printf("\n%d grades have been entered\n",*grade_count);
    return grade;
}

//[ID:4 LEN:4 STR:LEN]
void writeData(FILE * f)
{
    char cont = 'y';
    unsigned int len = 0;
    char name[1024];
    int id = 0;
    while(cont=='y')
    {
        printf("Please enter an ID:");
        scanf("%d",&id);
        getchar();
        printf("Please enter a name:");
        fgets(name,1023,f);
        getchar();
        len = strlen(name);
        fwrite(&id,sizeof(unsigned int),1,f);
        fwrite(&len,sizeof(unsigned int),1,f);
        fwrite(name,sizeof(char),len,f);
        printf("Would you cont(y)?");
        cont=getchar();
    }
}

void readData(FILE * f)
{
    unsigned int len = 0;
    char * name=NULL;
    int id= 0;
    while(!feof(f)) {
        fread(&id,sizeof(unsigned int),1,f);
        fread(&len,sizeof(unsigned int),1,f);
        name = (char*) malloc((len+1)*sizeof(char));
        fread(name,sizeof(char),len,f);
        name[len] = 0;
        //Printf out the data you read
        free(name);
    }
}
//Search each rec in f from the beginning and print the rec
//if the record id filed ==id
void searchData(FILE * f, int id)
{

}
