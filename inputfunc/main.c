#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
int readNumber()
{
    int i = 0;
    printf("Enter a number:");
    scanf("%d",&i);//pass in a pointer to the var
    return i;
}

void printNumber(int i)
{
    printf("%d\n",i);
}

void readNumbers(int * pNums,int count)
{
    printf("Please enter %d numbers:",count);
    for(int i=0;i<count;i++)
    {
        scanf("%d",pNums);//no & because pNums is a pointer
        pNums++;
    }
}

void printNumbers(int * pNums, int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%d ",*pNums);//no & because pNums is a pointer
        pNums++;
    }

}
char * itoa(int num, char *str)
{
    if(str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}

void readString(char * pStr, char * len)
{
    char sfmt[4];
    sfmt[0]='\0';
    strcat(sfmt,"%");
    strcat(sfmt,len);
    strcat(sfmt,"s");
    scanf(sfmt,pStr);
}


#define MAX_NAME_LEN 6
int main() {
//    int i=0;
//    i = readNumber();
//    printNumber(i);
//    int nums[3];
//    memset(nums,0,sizeof(int)*3);
//    readNumbers(nums,3);
//    printNumbers(nums,3);
    int age = 20;
    char name[MAX_NAME_LEN+1];
    memset(name,0,MAX_NAME_LEN+1);
    printf("Please enter a name:");
////    scanf("%s",name);//scanf does not check your input mem size
//    scanf("%6s",name);
//    readString(name, "6");
    fgets(name,MAX_NAME_LEN+1,stdin);//The 2nd arg is the size of name not len of str
    printf("Your name is %s and you are %d years old\n",name,age);

    return 0;
}
