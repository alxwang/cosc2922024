#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int openFile(const char * filename,const char * mode, FILE ** pFile)
{
    *pFile = NULL;
    int iErr = EXIT_SUCCESS;
    *pFile = fopen(filename, mode);
    if (*pFile != NULL)
    {
        printf("%s was successfully opened and closed.\n", filename);
        return iErr;
    }
    else
    {
        iErr = errno;
        printf("Error accessing file %s: %s\n", filename, strerror(iErr));
    }
    return iErr;
}
#define MAX_NAME_LEN 12

int writeRec(const char * filename,const char * mode)
{
    FILE * file = NULL;
    if (EXIT_SUCCESS==openFile(filename,mode,&file))
    {
        //Do something here
        char name[MAX_NAME_LEN+1];
        name[0]='\0';
        int sin = 0;
        int i=0;
        while(i<3) {
            printf("Please enter a name:");
            fgets(name, MAX_NAME_LEN, stdin);
            printf("Please enter a SIN #:");
            scanf("%d", &sin);
            getc(stdin);
            fwrite(&sin, sizeof(int), 1, file);
            fwrite(name, MAX_NAME_LEN, 1, file);
            i++;
        }
        fclose(file);
    }
    return 1;
}

int readRec(const char * filename,const char * mode)
{
    FILE * file = NULL;
    if (EXIT_SUCCESS==openFile(filename,mode,&file))
    {
        //Do something here
        int sin = 0;
        fread(&sin,sizeof(int),1,file);
        char name[MAX_NAME_LEN+1];
        name[0]='\0';
        fread(name,MAX_NAME_LEN,1,file);
        printf("%s:%d\n",name,sin);
        fclose(file);
    }
    return 1;
}

int searchRec(const char * filename,const char * mode)
{
    FILE * file = NULL;
    if (EXIT_SUCCESS==openFile(filename,mode,&file))
    {
        //Do something here
        char name[MAX_NAME_LEN+1];
        name[0]='\0';
        int sin = 0;
        int i=0;
        int sin2search=0;
        printf("Please enter a SIN to search:");
        scanf("%d",&sin2search);

        while(!feof(file))
        {
            fread(&sin,sizeof(int),1,file);
            if(sin==sin2search)
            {
                fread(name,MAX_NAME_LEN,1,file);
                printf("Found %d: %s\n",sin,name);
                break;
            }
            else
            {
                fseek(file,MAX_NAME_LEN,SEEK_CUR);
                //fread(name,MAX_NAME_LEN,1,file);
            }
        }

        fclose(file);
    }
    return 1;
}


int main() {
    printf("Hello, World!\n");
    char filename[]="test.bin";
//    writeRec(filename,"wb,");
//    readRec(filename,"rb");
    searchRec(filename,"rb");
    return 0;
}
