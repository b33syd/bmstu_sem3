#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstr1.h"

#define OK 0
#define FAIL -10
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"


int test_strcspn(const char *str, const char *sub)
{
    if(strcspn(str, sub) == mystrcspn(str, sub))
        return OK;
    else
        return FAIL;
}

int test_strndup(const char *str, const int maxlen)
{

    int result=OK;
    char *mydup = mystrndup(str,maxlen);
    char *standartdup = strndup(str,maxlen);

    //printf("                   %s\n",mydup);
    //printf("                   %s\n",standartdup );

    if (!strcmp(standartdup, mydup))
        result = OK;
    else
        result = FAIL;

    if(standartdup!=NULL)
        free(standartdup);
    if(mydup!=NULL)
        free(mydup);

    return result;
}


char *answer(int val)
{
    char *answer = "FAIL";
    if (val == OK)
    {
        printf("%s", KGRN);
        answer = "OK";
    }
    else
        printf("%s", KRED);
        
    return answer;

    
}

int main()
{
    //Null
    printf("test strcspn 1 %s\n", answer(test_strcspn("12345", "")));
    //only one for search
    printf("test strcspn 2 %s\n", answer(test_strcspn("12345", "1")));
    printf("test strcspn 3 %s\n", answer(test_strcspn("12345", "2")));
    printf("test strcspn 4 %s\n", answer(test_strcspn("12345", "3")));
    printf("test strcspn 5 %s\n", answer(test_strcspn("12345", "4")));
    printf("test strcspn 6 %s\n", answer(test_strcspn("12345", "5")));
    //Out of range
    printf("test strcspn 7 %s\n", answer(test_strcspn("12345", "6")));
    
    //full tests
    printf("test strcspn 8 %s\n", answer(test_strcspn("12345", "32")));
    printf("test strcspn 9 %s\n", answer(test_strcspn("num 7", "u7")));
    printf("test strcspn 10 %s\n", answer(test_strcspn("num 7 or 9", "1234567890")));

    

    printf("test strndup 1 %s\n", answer(test_strndup("",0)));
    //printf("test strndup 2 %s\n", answer(test_strndup(NULL,10)));
    printf("test strndup 3 %s\n", answer(test_strndup(NULL,NULL)));
    printf("test strndup 4 %s\n", answer(test_strndup("",1)));
    printf("test strndup 5 %s\n", answer(test_strndup("",10)));

    printf("test strndup 6 %s\n", answer(test_strndup("1",0)));
    printf("test strndup 7 %s\n", answer(test_strndup("1",1)));
    printf("test strndup 8 %s\n", answer(test_strndup("1",10)));

    printf("test strndup 9 %s\n", answer(test_strndup("No targets specified",19)));
    printf("test strndup 10 %s\n", answer(test_strndup("No targets specified",20)));
    printf("test strndup 11 %s\n", answer(test_strndup("No targets specified",21)));

    printf("test strndup 12 %s\n", answer(test_strndup("No targets specified",-1)));


    return 0;
}