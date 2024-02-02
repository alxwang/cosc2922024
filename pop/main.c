#include <stdio.h>
#include <stdlib.h>

int myIndexOf(char * str, char ch)
{
    int iLoc = 0;
    while(*str)
    {
        if(*str==ch)
        {
            return iLoc;
        }
        iLoc++;
        str++;
    }
    return -1;
}
//If ch exist, return the first loc and the count of ch existence
int myIndexOfwithCount(char * str, char ch,int  * pcount)
{
    int iLoc = 0;
    *pcount = 0;
    int bFirsttime = 1;//bFirsttime is true
    int iPos = -1;
    while(*str)
    {
        if(*str==ch)
        {
            if(bFirsttime)//Only update iPos when bFirsttime is true
            {
                iPos = iLoc;
                bFirsttime=0;//bFirsttime is false now
            }
            (*pcount)++;
        }
        iLoc++;
        str++;
    }
    return iPos;
}

int myIndexOfwithCountandPos(char * str, char ch,int  * pcount,char **lastPos)
{
    int iLoc = 0;
    *pcount = 0;
    int bFirsttime = 1;//bFirsttime is true
    int iPos = -1;
    while(*str)
    {
        if(*str==ch)
        {
            if(bFirsttime)//Only update iPos when bFirsttime is true
            {
                iPos = iLoc;
                bFirsttime=0;//bFirsttime is false now
            }
            *lastPos = str;
            (*pcount)++;
        }
        iLoc++;
        str++;
    }
    return iPos;
}

void review(){
    int iArr[]={1,2,3,4,5,6};
    char * cPtr=(char*)iArr;
    int * iPtr=iArr;

    printf("%p = %p = %p = %p\n",&iArr[0],iArr,cPtr,iPtr);

    for(int i=0;i<6;i++) printf("%d ",iArr[i]);
    printf("\n");

    for(int * pCur = iPtr;pCur-iPtr<6;pCur++)printf("%d ",*pCur);
    printf("\n");

    int * pCur = iPtr;
    while(pCur-iPtr<6)
    {
        printf("%d ",*pCur);
        pCur++;
    }
    printf("\n");

    pCur = iPtr;
//    for(int i=0;i<6;i++)
    for(;;)//a never ending loop
    {
        (*pCur)--;
        pCur++;
        if(pCur-iPtr>5) break;
    }
    for(int i=0;i<6;i++) printf("%d ",iArr[i]);
    printf("\n");
    printf("%p - %p = %d\n",pCur,iPtr,pCur-iPtr);
    pCur-=7;//Move pCur back to the 1st element of array
    printf("%p - %p = %d\n",pCur,iPtr,pCur-iPtr);

    printf("%p = %p = %p = %p\n",&iArr[0],iArr,cPtr,iPtr);
    *cPtr = 7;//Update the first lowest byte of first element of array ato 7

    cPtr++;
    *cPtr = 7;//0x00000707

    cPtr++;
    *cPtr = 7;//0x00070707

    cPtr++;
    *cPtr = 7;//0x07070707

    cPtr++;
    //Update the first lowest byte of second element of array ato 7
    *cPtr = 7;//0x07070707

    for(int i=0;i<6;i++) printf("%d ",iArr[i]);


}



int main() {
//    char cTestString[] = "It's a beautiful day, isn't it?";
//    int iLoc=0;
//
//    iLoc= myIndexOf(cTestString,'a');
//    printf("%c is in %s at %d\n",'a',cTestString,iLoc);
//
//    int count = 0;
//    iLoc= myIndexOfwithCount(cTestString,'a',&count);
//    printf("(%d) %c is in %s at %d\n",count,'a',cTestString,iLoc);
//
//    char * lastPos = NULL;
//    iLoc= myIndexOfwithCountandPos(cTestString,'a',&count,&lastPos);
//    printf("(%d) %c is in \"%s\" at (%d)\"%s\"\n",count,'a',cTestString,iLoc,lastPos);

    review();
}
