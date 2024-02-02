#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int demoOpen(const char * filename,const char * mode, FILE * f)
{
    //A file handler is FILE * NOT FILE
    int err = EXIT_SUCCESS;

    f = fopen(filename,mode);
    if(f!=NULL)
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
    rs = fputc(str[0],f);
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

int main() {
    char fn[] = "test.txt";
    FILE * f = NULL;
    demoOpen(fn,"a",f);
    demoWriteStr(f,"Alex");
    fclose(f);
    return 0;
}
