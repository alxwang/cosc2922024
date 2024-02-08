#include <stdio.h>
void addArray1(int * arr,int size)
{
    //Add 1 to each element in arr
    for(int i =0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}


void addArray(int arr[],int size)
{
    //Add 1 to each element in arr
    for(int i =0;i<size;i++)
    {
        printf("%f ",arr[i]);
    }
}


void testArrayAdd()
{
    int arr[] = {1,2,3,4,5,6};
    for(int i =0;i<sizeof(arr);i++)
    {
        printf("%d ",arr[i]);
    }
}


int str_count(char * str);
void str_print(char * str) {
   char *pcur = str;
   //This works but not nice
//    while (*(pcur++)) {
//        printf("%c",*(pcur-1));
//    }

    char ch = 0;
//    while((ch = *pcur++)!=0)
//      while((ch = *pcur++))
    while(ch = *pcur++)
    {
        printf("%c",ch);
    }

    //(ch = *pcur++)!=0
    //1. get *pur and save the val into ch
    //2. pur++
    //3. ch!=0

    for(int i=0;i<str_count(str);i++) printf("%c",str[i]);

    pcur = str;
    for(char ch=*pcur;ch;ch=*(++pcur))
    {
        printf("%c",ch);
    }

}

int str_count(char * str)
{
    int nCount=0;
    char * pcur=str;
    while(*pcur++)
    {
        nCount++;
    }
    return nCount;
}

void inc(int * i)
{
    (*i)++;
}


char* getName()
{
    //You cannot return a pointer(mem addr) in a stack of a function
    //becuase the stack will be freed after the func is end
    //Therefore, the pointer is point to an invalid addr
    char name[] = "alex";
    return name;
}

int main() {

      printf("%s",getName());
//    int i=0;
//    while(i<10)
//    {
//        printf("%d",i);
//        //i++
//        inc(&i);
//    }

//    for(int i=0;i<10;i++)
//    {
//        printf("%d ",i);
//    }
//
//    int i = 0;
//    while(++i<10)
//    {
//        printf("%d ",i);
////        i++;
//    }
//
//    char str[] = "Alex";
//    printf("\n%d\n", str_count(str));
//    str_print(str);

    return 0;
}
