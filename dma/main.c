#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "printmem.h"
void printInts(int * pInts,int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",pInts[i]);
    printf("\n");
}

int * getInts(int size)
{
    int * parr = (int*)malloc(size*sizeof(int));
    memset(parr,0,size*sizeof(int));
    return parr;
}

void inputInts(int * pInt,int size)
{
    int * pCur = pInt;
    while(pCur-pInt<size)
    {
        printf("Please enter a number:");
        scanf("%d", pCur);
        pCur++;
    }
}

int * ints_cat(int * pInt1, int size1,
               int * pInt2, int size2)
{
    int * prs = (int*)malloc((size1+size2)*sizeof(int));
    memcpy(prs,pInt1,size1*sizeof(int));
//  memcpy(prs+size1*sizeof(int),pInt2,size2*sizeof(int));
//  pre is an int*, so if we want to find the pos of 2nd array,we add size1(how many ints) not bytes
    memcpy(prs+size1,pInt2,size2*sizeof(int));
    return prs;
}

int * ints_cat_r(int * pInt1, int size1,
               int * pInt2, int size2)
{
    int * prs = (int*)realloc(pInt1,(size1+size2)*sizeof(int));
    /*
     * if there are enough bytes(size2) after pInt1, then a new pointer will be return at the same pos as pint1
     * With the size of size1+size2(extent the memory block size from size1 to size1+2
     * Otherwise, a new block mem will be allocated somewhere as size1+2, and
     * mem in pint1 will be copied to the new loc and old pint1 will be freed
     */
    memcpy(prs+size1,pInt2,size2*sizeof(int));
    return prs;
}

//Return a new int list which is newSize and contains the values in pInt
int * inc_ints(int * pInt, int size, int newSize)
{
    int * pre = (int*) malloc((newSize)* sizeof(int));
    memcpy(pre,pInt,size* sizeof(int));
    return pre;
}

char * getStringDynamic(const char * prompt)
{
    char buf[200];
    buf[0]='\0';
    printf(prompt);
    fgets(buf,199,stdin);
    //How to return the string in buf?
    //Stack will be free after the current function exits
    char * rs = (char*) malloc((strlen(buf)+1)* sizeof(char));
    strcpy(rs,buf);
    /*
     * memset,memcpy
     */
    return rs;
}

char * getSinAndName()
{
    char buf[200];
    buf[0]='\0';
    int sin = 0;
    printf("Please enter a sin#:");
    scanf("%d",&sin);
    getc(stdin);
    printf("Please enter your name:");
    fgets(buf,199,stdin);
    //Remove the 0a from buf
    buf[strlen(buf)-1] = 0;

    char * rs = (char *) malloc(strlen(buf)+1+sizeof(int));
    strcpy(rs,buf);
    *((int*)(rs+ strlen(buf)+1)) = sin;
//    memcpy(rs+ strlen(buf)+1,&sin, sizeof(4));
    return rs;
}

void printSinAndName(char * buf)
{
    char * name = buf;
    int * pSin = buf+ strlen(name)+1;
    printf("%s %d",name,*pSin);
}

//Remove the space or newline from the beginning and end of the string
char * trim(char * str)
{
    char * pCur = str;
    //Loop each char from begin to end
    while(*pCur==10 || * pCur==32) pCur++;
    char * rs = pCur;
    //Loop each char from end to begin
    pCur = str+(strlen(str)-1);
    while(*pCur==10 || *pCur==32)
    {
        *pCur = 0;
        pCur--;
    }
    return rs;
}
char* concatenateString(const char* cFirstPtr, const char* cSecondPtr)
{
    int iLengthFirst = strlen(cFirstPtr);
    int iLengthSecond = strlen(cSecondPtr);

    // Note that we must include space for the null terminator
    char* cReturnString = (char*)malloc(iLengthFirst + iLengthSecond + 1);

    if (cReturnString)
    {
        // Just to be safe, initialize our string to empty
        cReturnString[0] = '\0';

        // Copy the first string to destination
        strcpy(cReturnString, cFirstPtr);

        // Copy the second string to the end of the first string
        //strcat(cReturnString, cSecondPtr);
        strcpy(cReturnString + iLengthFirst, cSecondPtr);
    }

    return cReturnString;
}

int main() {
//    int size = 0;
//    printf("How many ints?");
//    scanf("%d", &size);
//    int * parr = getInts(size);
//    inputInts(parr,size);
//    printInts(parr,size);
//    int newarr[]={100,200,3000};
//    int * rs = ints_cat_r(parr,size,newarr,3);
//    printInts(rs,size+3);
//    free(rs);
//    char * str = getStringDynamic("Please enter a string:");
//    printf("%s",str);
//    free(str);
//    char * buf = getSinAndName();
//    print_memory(buf,strlen(buf)+1+ sizeof(int));
//    printSinAndName(buf);
//    free(buf);
//    char str[]="    alex  ";
    char str[]="           ";
    str[2] = 10;
    str[strlen(str)-2] = 10;
    printf("[%s]\n",str);
    char * rs = trim(str);
    printf("[%s]\n",rs);
}
