#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int demoOpen(const char * filename,const char * mode, FILE ** f)
{
    //A file handler is FILE * NOT FILE
    int err = EXIT_SUCCESS;

    *f = fopen(filename,mode);
    if(*f!=NULL)
    {
        //Success
        printf("fopen %s %s successed\n",filename,mode);
    }
    else
    {
        //Failed
        err = errno;//errno is a global var define in errno.h
        //errno always contains the most recent error code
        printf("fopen %s %s failed: %d\n",filename,mode,err);
    }
    return err;
}

int demoWriteStr(FILE * f, const char * str)
{
    int rs = 0;
    //Write a char
//   rs = fputc(str[0],f);
    //Write the str
    rs = fputs(str,f);
    //Write the str with a fmt
//    rs = fprintf(f, "My name is: %s",str);
    //Write it as a binary stream
//    rs = fwrite((void *)str,sizeof(char), strlen(str),f);
    if(rs>0)
    {
        printf("Success. Rs: %d\n",rs);
    }
    else
    {
        //Failed
        int err= ferror(f);
        if(err!=0)
        {
            //I know why failed
            printf("Failed. Error: %d\n",err);
        } else
        {
            printf("Failed. Error unknown");
        }
    }
    return rs;
}

int demoRead(FILE * f, char * buf){
    int rs = 0;
    //fread - read as bin stream
//    rs = fread((void*)buf,sizeof(char),4,f);
    //fgetc read a char from file
//    char ch = fgetc(f);
//    if(ch==EOF){
//        printf("Filed to read a char");
//    }
//    else
//    {
//        buf[0]=ch;
//    }
//    rs = ch;
    //fgets
//    char * pStr = fgets(buf,99,f);
//    printf("%s %p=%p\n",pStr,pStr,buf);
    //fscanf
    rs = fscanf(f,"%4s",buf);
    printf("%d\n",rs);
    return rs;
}


int main() {
    char fn[] = "test.txt";
    FILE * f = NULL;
    demoOpen(fn,"a+",&f);//My mistake is using a instead of a+
    //a+ means append and read
    //a means append only no read
    demoWriteStr(f,"Alex");

    //Reset the file cursor to begining so we can read.
    fseek(f,0,SEEK_SET);
    //SEEK_SET mean based on begin
    //SEEK_CUR cur pos
    //SEEK_END end of file
    char buf[100];
    memset(buf,0,100);
    demoRead(f,buf);
    for(int i=0;i<100;i++) fputc(buf[i],stdout);
    fclose(f);
    f=NULL;
    return 0;
}
