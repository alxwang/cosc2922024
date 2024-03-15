
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define	ENGLISH_SIGNAL	0x01
#define	FRENCH_SIGNAL	0x02
#define	CREE_SIGNAL		0x04

void showBits(const char * prompt, unsigned int value, int bytes)
{
    unsigned int filter = 1; //0b00000001
    int bit;

    char* bitString = (char*)malloc(33);
    // Null terminator
    bitString[32] = '\0';

    for (bit = 0; bit < bytes * 8; bit++)
    {
        // Determine the value of the current bit
        if (value & filter)
        {
            bitString[31 - bit] = '1';
        }
        else
        {
            bitString[31 - bit] = '0';
        }
        filter *= 2; // Move to the next bit to the left
        /*
         * 0b00000001   1
         * 0b00000010   2
         * 0b00000100   4
         * 0b00001000   8
         * 0b00010000   16
         * 0b00100000   32
         * 0b01000000   64
         * 0b10000000   128
         */
    }

    printf("%s\t: The value %d in binary is \t%s\n", prompt,value, &bitString[32 - bytes * 8]);

    free(bitString);
    bitString = NULL;
}


unsigned char languageQuestions()
{
    unsigned char lang = 0;//All 8 bits are 0 so all false
    showBits("lang",lang,1);
    unsigned char choice[] = "YES";
    printf("Do you speak english(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= ENGLISH_SIGNAL;
    }
    showBits("lang",lang,1);
    printf("Do you speak French(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= FRENCH_SIGNAL;
    }
    showBits("lang",lang,1);
    printf("Do you speak Plains Cree(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= CREE_SIGNAL;
    }
    showBits("lang",lang,1);
    return  lang;
}


void printGreetings(unsigned  char lang)
{
    if(lang & ENGLISH_SIGNAL)
    {
        printf("Hello\n");
    }
    if(lang & FRENCH_SIGNAL)
    {
        printf("Bonjour\n");
    }
    if(lang & CREE_SIGNAL)
    {
        printf("Tan'si\n");
    }
}

typedef unsigned char (*ENCRYPTOR)(unsigned char c, unsigned char p);

unsigned char encryptor(unsigned char c, unsigned char p)
{
    return c ^ p;
}

unsigned char encryptor1(unsigned char c, unsigned char p)
{
    return c ^ p+p;
}


// a ^ p = b
// b ^ p = a
void encryptMessage(FILE * in, FILE * out, FILE * pad,ENCRYPTOR e)
{
    int i,o,p;
    i = fgetc(in);
    while(!feof(in))
    {
        p = fgetc(pad);
        o = e(i,p);
        fputc(o,out);
        i = fgetc(in);
    }
}

int comp_a(int a, int b)
{
    return a-b;
}

int comp_d(int a, int b)
{
    return b-a;
}

typedef int (*COMPARER)(int a, int b);

void sortInts(int arr[], int size, COMPARER c)
{
    int i,j,key;
    for(int i=1;i<size;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && c(arr[j],key)>0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//Create a new row using malloc.
//Return the pointer to the row.
int* createRows(int* iPtr, int iRowSize){
    return (int *) malloc(iRowSize*sizeof(int));
}

//Print the values of the current row.
int* printRows(int* iPtr, int iRowSize)
{
    for(int i=0;i<iRowSize;i++)
    {
        printf("%d ",iPtr[i]);
    }
    printf("\n");
    return NULL;
}

int* enterRows(int* iPtr, int iRowSize)
{
    //Fill the value of each numbers in a row
}

int* doubleRows(int* iPtr, int iRowSize)
{
    //Double the value of each row
}
//Free the row and return null
int* freeRows(int* iPtr, int iRowSize){
    free(iPtr);
    return NULL;
}


typedef int* (*ROW_FUNC)(int* iPtr, int iRowSize);

void twoDArrayRowModifier(int** iArray, int iNumRows, ROW_FUNC rf, int iRowSize)
{
    for(int i =0;i<iNumRows;i++)
    {
        iArray[i] = rf(iArray[i],iRowSize);
    }
}

void testTwoDArray()
{
    int** iArray;
    int iNumRows = 3;
    int iRowSize = 3;

    iArray = (int**)malloc(iNumRows * sizeof(int*));

    //Create each row
    twoDArrayRowModifier(iArray, iNumRows, createRows, iRowSize);

    // Can call enterRows and doubleRows here...

    //Print each row
    twoDArrayRowModifier(iArray, iNumRows, printRows, iRowSize);

    //Free each row
    twoDArrayRowModifier(iArray, iNumRows, freeRows, iRowSize);

    free(iArray);
    iArray = NULL;
}




int main() {
//    unsigned  char lang = languageQuestions();
//    printGreetings(lang);
//    FILE * out = fopen("plaintext_message_new.txt","w");
//    FILE * in = fopen("encrypted.txt","r");
//    FILE * pad = fopen("random.pad","r");
//    encryptMessage(in,out,pad);
//    fclose(in);
//    fclose(out);
//    fclose(pad);
//    int a[]={5,3,6,3,6,2,7,1};
//    sortInts(a,sizeof(a)/4,comp_a);
//    for(int i=0;i<sizeof(a)/4;i++)printf("%d ",a[i]);
//    printf("\n");
//    sortInts(a,sizeof(a)/4,comp_d);
//    for(int i=0;i<sizeof(a)/4;i++)printf("%d ",a[i]);
    testTwoDArray();
    return 0;
}
