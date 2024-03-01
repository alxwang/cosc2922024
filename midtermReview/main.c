#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum BOOL {false,true};

void enumerations()
{
    int i = 1;
    enum BOOL done = false;
    do {
        printf("%d ",i);
        i++;
        done=(i>15);
    }while(!done);

}

void enter_name(char * cNamePtr, char * cPrompt)
{
//    printf("%s",cPrompt);
    printf(cPrompt);
    scanf("%s",cNamePtr);
}
#define MAX_NAME_SIZE 100
void test_enter_name()
{
    char cFirstName[MAX_NAME_SIZE];
    char cLastName[MAX_NAME_SIZE];
    enter_name(cFirstName,"Please enter first name:");
    enter_name(cLastName,"Please enter last name:");
    printf("Your full name is %s %s\n",cFirstName,cLastName);
}

void string_funcs()
{
    char string1[] = "Hello world";
    char string2[] = "C is great!";
    char string3[40];
    char string4[] = "Bob";

    string3[0]='\0';
    memset(string3,0,40);

    printf("String [%s] length is %d\n",string1,strlen(string1));
    printf("String 3 before copy:[%s]\n",string3);
    strcpy(string3,string1);
    printf("String 3 after copy:[%s]\n",string3);

    strcat(string3,"! ");
    strcat(string3,string2);
    printf("String 3 after concat:[%s]\n",string3);

    enum BOOL strcmp_rs = true;
    strcmp_rs = strcmp(string1,string2);
    printf("%d\n",strcmp_rs);
}

void string_cat(char * leftPtr, char * rightPtr)
{
    char * appendPtr = leftPtr+ strlen(leftPtr);
    int i =0;
    do{
        appendPtr[i]=rightPtr[i];
        i++;
//    } while (i< strlen(rightPtr));
    } while (rightPtr[i]!=0);
}
void string_cat_s(char ** leftPtr, char * rightPtr)
{
    //concat will never cause mem overwrite problem
}

void swap(int * p1, int * p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int * newInt()
{
//    int * i = (int*)malloc(sizeof(int));
//    *i = 1234;
//    return i;
    static int i =1234;
    return &i;
}
#define ARR_SIZE 4
void hideString(int * iArrPtr, char *cArrPtr)
{
    char * cPtr = NULL;
    for(int i=0;i<ARR_SIZE;i++)
    {
        cPtr = (char*)&iArrPtr[i];
        cPtr+=2;
        *cPtr = cArrPtr[i];
    }
}

void unHideString(int * iArrPtr)
{
    char * cPtr = NULL;
    for(int i=0;i<ARR_SIZE;i++)
    {
        cPtr = (char*)&iArrPtr[i];
        cPtr+=2;
        printf("%c ",*cPtr);
    }
}

void testHideUnhide() {
    int iArray[] = {32842938, 9329823, 8439339, 7943085};
    char cArray[] = "Bill";

    hideString(iArray, cArray);
    //You may want to print out iArray next with a for loop
    //to see how the int values have changed.

    //This should print out “Bill”
    unHideString(iArray);
}

#define MAXLENGTH 100
char * getName(int * length,char ** lastChar)
{
    char buf[MAXLENGTH];
    printf("Enter a name:");
    //We need to get space
    char * input = fgets(buf,MAXLENGTH,stdin);
    char * rs = NULL;
    if(input)
    {
        *length= strlen(input);
        //Choice 1:
        rs = strdup(input);
        rs[*length-1] = 0;
        *length= strlen(rs);
        //Chice 2:
//        rs = (char*) malloc(*length*sizeof(char));
//        strcpy(rs,input);
//        memcpy(rs,input,(*length)+1);
        *lastChar = rs+(*length)-1;
    }
    return rs;
}

int main() {
//    enumerations();
//    test_enter_name();
//    string_funcs();
//    char string1[] = "Hello world";
//    char string2[] = "C is great!";
//    char string3[40];
//    string3[0]='\0';
//    string_cat(string3,string1);
//    string_cat(string3,string2);
//    printf("String 3 after concat:[%s]\n",string3);
//    testHideUnhide();
    int len = 0;
    char * lastChar = NULL;
    char * name = getName(&len,&lastChar);
    printf("[%s] [%s]\n",name,lastChar);

    for(int i=len;i>0;i--)
    {
        printf("%c ",*lastChar--);
    }

    return 0;
}
