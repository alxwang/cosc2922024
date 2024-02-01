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


int main() {
    char cTestString[] = "It's a beautiful day, isn't it?";
    int iLoc=0;

    iLoc= myIndexOf(cTestString,'a');
    printf("%c is in %s at %d\n",'a',cTestString,iLoc);

    int count = 0;
    iLoc= myIndexOfwithCount(cTestString,'a',&count);
    printf("(%d) %c is in %s at %d\n",count,'a',cTestString,iLoc);

    char * lastPos = NULL;
    iLoc= myIndexOfwithCountandPos(cTestString,'a',&count,&lastPos);
    printf("(%d) %c is in \"%s\" at (%d)\"%s\"\n",count,'a',cTestString,iLoc,lastPos);


}
