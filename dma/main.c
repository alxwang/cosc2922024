#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
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
    int * prs = (int*)malloc((size1+size2)* sizeof(int));
    memcpy(prs,pInt1,size1* sizeof(int));
    memcpy(prs+size1* sizeof(int),pInt2,size2* sizeof(int));
    return prs;
}

int main() {
    int size = 0;
    printf("How many ints?");
    scanf("%d", &size);
    int * parr = getInts(size);
    inputInts(parr,size);
    printInts(parr,size);
    int newarr[]={100,200,3000};
    int * rs = ints_cat(parr,size,newarr,3);
    printInts(rs,size+3);
    free(parr);
}
