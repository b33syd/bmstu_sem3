#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstr2.h"


#define OK 0
#define FAIL -10
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

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

int test_readfromfile2(const char *file_name)
{
	FILE * file_in1 = fopen(file_name, "r");
	FILE * file_in2 = fopen(file_name, "r");
	int result=OK;
	int code_error=0;
	char *answer_to_check;

	char* string=NULL;
	char str[256];
	size_t len=0;
	size_t length=0;
	//printf("WORK1\n");

	while((code_error=readfromfile2(&string,&length,file_in1)!=-1)&&(string!=NULL))
	{		
		fgets(str, sizeof(str), file_in2);
		//printf("%s",str );
		//printf("%s",string );
		//printf("answer_to_check  %s\n",string );
		if (!strcmp(string, str))
        	result = OK;
    	else    		
        	result = FAIL;
    	if (strlen(string)!=strlen(str))
        	result=FAIL;
    	
    	if(string!=NULL)
        	free(string);
        string=NULL;
	    
	    if(result==FAIL)
	    	return result;		
	}


	
	fclose(file_in2);
	fclose(file_in1);
    return result;

}

int test_replace(const char *line,  const char *replace_what, const char *replace_with, char* answer)
{
	int result=OK;
	char *answer_to_check=replace(line,replace_what,replace_with);

	//printf("answer_to_check  %s\n",answer_to_check );
	//printf("%s\n",answer_to_check );
	if (!strcmp(answer_to_check, answer))
        result = OK;
    else
        result = FAIL;

    if(answer_to_check!=NULL)
        free(answer_to_check);
    return result;

}

int main()
{
	printf("test replace 1 %s\n", answer(test_replace("caac","aa","cc","cccc")));
	printf("test replace 2 %s\n", answer(test_replace("aacc","aa","cc","cccc")));
	printf("test replace 3 %s\n", answer(test_replace("ccaa","aa","cc","cccc")));

	printf("test replace 4 %s\n", answer(test_replace("ccaaaa","aa","cc","cccccc")));
	printf("test replace 5 %s\n", answer(test_replace("aaccaa","aa","cc","cccccc")));
	printf("test replace 6 %s\n", answer(test_replace("aaaacc","aa","cc","cccccc")));

	printf("test replace 7 %s\n", answer(test_replace("aaaaaa","aa","cc","cccccc")));

	printf("test replace 8 %s\n", answer(test_replace("aaaaaa","aaa","cc","cccc")));

	printf("test replace 9 %s\n", answer(test_replace("aaaaaa","aaa","cccc","cccccccc")));
	printf("test replace 10 %s\n", answer(test_replace("aaaaaa","aaa","","")));
	printf("test replace 11 %s\n", answer(test_replace("aaaa","aa","aaaa","aaaaaaaa")));
	printf("test replace 12 %s\n", answer(test_replace("aaaaa","aa","aaaa","aaaaaaaaa")));
	printf("test replace 13 %s\n", answer(test_replace("аааа аа","аа","аааа","аааааааа аааа")));
	printf("test replace 14 %s\n", answer(test_replace("ааааа  аа","аа","аааа","ааааааааа  аааа")));
	printf("test replace 14 %s\n", answer(test_replace("","а","б","")));
	

	printf("test test_readfromfile 1 %s\n", answer(test_readfromfile2("tests/empty_file")));
	printf("test test_readfromfile 2 %s\n", answer(test_readfromfile2("tests/oneline")));
	printf("test test_readfromfile 3 %s\n", answer(test_readfromfile2("tests/twoline")));
	printf("test test_readfromfile 4 %s\n", answer(test_readfromfile2("tests/someline")));
	printf("test test_readfromfile 5 %s\n", answer(test_readfromfile2("tests/someline_with_one_empty")));
	printf("test test_readfromfile 5 %s\n", answer(test_readfromfile2("tests/bigtest")));

	/*#кратные буферу
	#vtymit ,eathf
	#больше буфера
	#str str свою
	# искать не с самого начала.
	*/
	
	//aaaa aaaa a
    return 0;
}

