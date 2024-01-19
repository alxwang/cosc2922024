#include <stdio.h>
#include <string.h>


int main() {

    char str[] = "Hello!";
    printf("str is at %x\n",str);
    //Get length of a str
    printf("len is %d\n", strlen(str));
    char str1[7];//Alloc a char array
    //Copy n char from str to str1
    strncpy(str1,str, strlen(str));
    printf("str1 is at %x\n",str1);
    str1[0]='h';
    printf("str: %s\n", str);
    printf("str1: %s\n", str1);

    char str2[20];
    //Without init the str2, str2 is an array of char
    //It is not a string
    //With the init, str2 become a string.
//    for(int i=0;i<20;i++)str2[i]=0;
    //memset set the elements in str2 to 0 from begin(0) to 20 times
    memset(str2,0,20);
    //Concat str to the end of str2 with n chars
    strncat(str2,str,strlen(str));
    strncat(str2,str1,strlen(str1));
    printf("str2: %s\n", str2);
    printf("str: %s\n", str);
    printf("str1: %s\n", str1);

    //strncmp compare two string
    printf("str is %s str1\n",
           strncmp(str,str1,6)<0?"less than":"greater than or equal to");

    //Find a char in a string, return the point to substr form the char NOT INDEX
    printf("h in str2 is at %s\n",strchr(str2,'h'));
    printf("e in str2 is at %s\n",strchr(str2,'e'));
    printf("(Rev search)e in str2 is at %s\n",strrchr(str2,'e'));

    //Find a substring,return the point to substr form the char NOT INDEX
    printf("ello in str2 is at %s\n",strstr(str2,"ello"));

    //Work to complete before next class:
    //1. write code to find the second ello in str2 --> "ello!" instead of ello!hello!
    //2. Learn strtok function - powerful func in c
    //3. Complete the mem map exercise.
}
