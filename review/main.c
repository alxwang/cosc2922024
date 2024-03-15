
#include <stdio.h>

#define	ENGLISH_SIGNAL	0x01
#define	FRENCH_SIGNAL	0x02
#define	CREE_SIGNAL		0x04


unsigned char languageQuestions()
{
    unsigned char lang = 0;//All 8 bits are 0 so all false
    unsigned char choice[] = "YES";
    printf("Do you speak english(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= ENGLISH_SIGNAL;
    }
    printf("Do you speak French(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= FRENCH_SIGNAL;
    }

    printf("Do you speak Plains Cree(y/n)?");
    fgets(choice,3,stdin);
    if (choice[0]=='y')
    {
        //set first bit in lang to 1
        lang |= CREE_SIGNAL;
    }
    return  lang;
}


void printGreetings(unsigned  char lang)
{
    if(lang & ENGLISH_SIGNAL)
    {
        printf("Hello\n");
    }
    if(lang & FRENCH_SIGNAL)
    {
        printf("Bonjour\n");
    }
    if(lang & CREE_SIGNAL)
    {
        printf("Tan'si\n");
    }
}



int main() {
    unsigned  char lang = languageQuestions();
    printGreetings(lang);
    return 0;
}
