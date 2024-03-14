#include <stdio.h>
//#define BYTE unsigned char
//#define WORD unsigned short
//#define DWORD unsigned int
typedef unsigned int DWORD;

typedef int (*MODIFIER)(int i);


int dec(int i)
{
    return --i;
}

typedef int (*COMPARETOR)(int a,int b);

int add(int a,int b)
{
    return a+b;
}

int compare(int a,int b)
{
    return a-b;
}

void iterateArray(int arr[],int size, MODIFIER m)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=m(arr[i]);
    }
}

//1. define new inc/dec which take one int* no return
//2. define MODIFIEREX can point to new func
void incex(int * a)
{
    ++(*a);
}

typedef void (*MODIFIEREX)(int * a);

void iterateArrayex(int arr[],int size, MODIFIEREX m)
{
    for(int i=0;i<size;i++)
    {
        m(&arr[i]);
    }
}


int inc(int i)
{
    return ++i;
}

int main() {
//    COMPARETOR comparetor = compare;
//    COMPARETOR adder = add;
//    printf("%d\n",comparetor(1,2));
//    printf("%d\n",adder(1,2));
    int a[]={1,2,3,4,5,6};
    iterateArray(a,6,inc);
    iterateArray(a,6,dec);

    return 0;
}
