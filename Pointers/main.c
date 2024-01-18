#include <stdio.h>

int main() {
    char cExample[] = "Example";
    char * pStr = cExample;
    int * pInt = (int*)&cExample[0];
    printf("pStr pointer: %x\n",pStr);
    printf("pInt pointer value: %x\n",*pInt);//'m''a''x''E' -->6D617845
    printf("pInt pointer: %x\n",pInt);//'m''a''x''E' -->6D617845
    short * pShort = (short*)&cExample[1];
    printf("pShort pointer value: %x\n",*pShort);//'a''x'-->6178
    printf("pShort pointer: %x\n",pShort);//'a''x'-->6178

    printf("pStr+1 pointer: %x\n",pStr+1);//0012FDA5
    printf("pInt+1 pointer: %x\n",pInt+1);//0012FDA8
    printf("pShort pointer: %x\n",pShort+1);//0012FDA6
    printf("pStr+1 pointer value: %x\n",*(pStr+1));//78
    printf("pInt+1 pointer value: %x\n",*(pInt+1));//0'e''l'p'->00656c70
    printf("pShort+1 pointer value: %x\n",*(pShort+1));//'p''m'--> 706d

    //Add 3 to a char pointer will add 3 to addr
    printf("pStr+3 pointer: %x\n",pStr+3);//0012FDA7
    //Add 3 to an int pointer will add 3*sizeof(int)=12 to addr
    printf("pInt+3 pointer: %x\n",pInt+3);//0012FDA4+C
    //Add 3 to a short pointer will add 3*sizeof(short)=6 to addr
    printf("pShort+3 pointer: %x\n",pShort+3);//0012FDA5+6
    printf("pStr+3 pointer value: %x\n",*(pStr+3));//6D
    //Deref always work based on pinter type not printf fmt str
    printf("pInt+3 pointer value: %x\n",*(pInt+3));//0012FDA4 Should be the mem addr of pInt
    printf("pShort+3 pointer value: %x\n",(short)(*(pShort+3)));//A400

    pStr+=7; //0012FDAB
    printf("pStr pointer after +7 : %x\n",pStr);
    printf("pStr is [%s]\n",pStr);
    printf("pStr-4 as a string is %s\n",(pStr-4)); //"mple" No * in front of (
    printf("pStr-4 as a char: %c\n",*(pStr-4)); //'m'
    printf("pInt+1 as a char: %c\n",*(pInt+1)); //'p'
    printf("pInt+1 as a int: %x\n",*(pInt+1)); //0'e'l''p'->00656C70

}
