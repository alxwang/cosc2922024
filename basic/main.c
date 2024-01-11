//Everything started with # is a pre-process directive
#include "stdio.h"
#include "stdlib.h"

//Macro
#define PI 3.1415926
const float CPI= 3.1415926f;

//int maxi(int a, int b)
//{
//    return a>b?a:b;
//}
//
//float maxf(float a, float b)
//{
//    return a>b?a:b;
//}

#define MAX(a,b) (((a)>(b))?(a):(b))

void primitiveTypes()
{
    char c = 'A'; //character literals are in single quotes
    int x = 234234;
    float f = PI;
    double d = PI;
    printf(" the value of c is %c\n",c);
    printf(" the value of c as int is %d\n",c);
    printf(" the value of x is %d \n",x);
    printf(" the value of x as a char is %c\n",x);//4 byes of int need to be converted to 1 byte c: the lowest byte of in t will be used
    printf(" the value of x as HEX is %x\n",x);

    printf("the value of f is %f\n",f);
    printf("the value of f is %10.2f\n",f);
    printf("the value of f is %10.2f\n",d);

    printf("the size of char is %d\n",sizeof(c));
    printf("the size of char is %zu\n",sizeof(c));
    printf("the size of double is %zu\n",sizeof(d));
}

void modifiers(){
    char c  = 'A';//-128-127 is range of a sign number in 1 byte
    unsigned char uc = 'A'; //0-255 is range of an unsigned number in 1 byte

//    signed char cc = 165; singed is default
    char cc = 165; // 165->bin->see as a signed number -91
    unsigned ucc = 165;
    printf("%d %d %d %d \n",c,uc,cc,ucc);

    short s = 100;
    short int si = 100;

    long l = 200;
    long int li = 200;

    cc++;
    cc+=1;
}

void castDemo(){
    int x = 0;
    float  y = 3.2f;

//    x = y;
    x = (int)y;//explicitly cast is not required in C but we should do it.
    printf("x = %d\n",x);

    float c;//You have to init the var otherwise c will contain random value
    float f = 115;
    c = ((float )5/9)*(f-32);
    printf("c = %f\n",c);
}

void stringDemo()
{
    char c = 'A';
    //There is no String object in C
    //in C, string is an array of char
    //in C, string is null-terminlated char array
    char s1[] = "Alex";
    char s2[4];
    s2[0]=s1[0];//'A'
    s2[1]=s1[1];//'l'
    s2[2]=s1[2];//'e'
    s2[3]=s1[3];//'x'
//    s2[3]=0;//'x'
    printf("s1=%s\n",s1);
    printf("s2=%s\n",s2);
    printf("size of s1 is %d\n",sizeof(s1));
    printf("size of s2 is %d\n",sizeof(s2));
}

void stringFuncs()
{
    char s1[]="Alex";
    //S1 is an memory address
    printf("s1 is at %x\n",s1);
    char * s2 = s1;//Pointer is datatype for memory address
//    char * s2 = &s1[0]//Same as line 99
//    printf("s2 is at %x\n",s2);
//    printf("s1 = %x\n",s1);
//    printf("s2 = %s\n",s2);

//    printf("[%x]%c\n",s1,s1[0]);
//    printf("[%x]%c\n",s1+1,s1[1]);
//    printf("[%x]%c\n",s1+2,s1[2]);
//    printf("[%x]%c\n",s1+3,s1[3]);
//    printf("[%x]%d\n",s1+4,s1[4]);


//    printf("[%x]%c\n",s1,s1[0]);
//    printf("[%x]%c\n",++s2,s1[1]);
//    printf("[%x]%c\n",++s2,s1[2]);
//    printf("[%x]%c\n",++s2,s1[3]);
//    printf("[%x]%d\n",++s2,s1[4]);


//    printf("[%x]%c\n",s2,*s2);
//    s2++;
//    printf("[%x]%c\n",s2,*s2);
//    s2++;
//    printf("[%x]%c\n",s2,*s2);
//    s2++;
//    printf("[%x]%c\n",s2,*s2);
//    s2++;
//    printf("[%x]%d\n",s2,*s2);


    int l = 0;
    int * p_l = &l;
    printf("%d = %x? %d\n",l,*p_l,l==*p_l);

//    int * p;//0

//    if (++(*p_l)){
//        printf("True\n");
//    }
//    else
//    {
//        printf("False\n");
//    }

}

void loopDemo()
{
//    for(int i =0;i<10;i++)
//    {
//        printf("%d ",i);
//    }
    char s1[]="Alex";
    //S1 is an memory address
    printf("s1 is at %x\n",s1);
    char * s2 = s1;//Pointer is datatype for memory address

    for(char * ps = s1;*ps;ps++)
    {
        printf("%c ",*ps);
    }

}


int main(int argc, char *argv[])
{
//
//    printf("Basic app. %f\n",PI);//--> printf("Basic app. %f\n",3.1415926)
//    printf("Basic app. %f\n",CPI);
//    printf("Max of 3,4 is %d\n",MAX(3,4));//->printf("Max of 3,4 is %d\n",(((3)>(4))?(3):(4)));
//    primitiveTypes();
//    modifiers();
//    castDemo();
//    stringDemo();
//    stringFuncs();
    loopDemo();
    return EXIT_SUCCESS;//Return 0;
}

