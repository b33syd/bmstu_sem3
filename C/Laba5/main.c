
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#include <limits.h>
#define N 15
#define MAX_BUF_LEN 100
#define K -199
#define OK 0
#define FAIL 1
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define RESET  "\033[0m"

int compare(char *buf1, char *buf2, int r1, int r2)
{
	int flag=OK;
	if(r1!=r2)
		flag=FAIL;

	if(memcmp(buf1,buf2,strlen(buf2))!=0)
		flag=FAIL;


	if(flag==FAIL)
	{
		printf("%s\n",buf1 );
		printf("%s\n",buf2);
	}

	return flag;
}

void answer(int val, int id)
{
    
    if (val == OK)
    {
       printf("%s%s%d %s%s\n", GREEN,"test",id, "PASSED", RESET);
    }
    else
        printf("%s%s%d %s%s\n", RED, "test",id, "FAILED", RESET);
    
}

int test1()
{
	char *buf = (char *) malloc(MAX_BUF_LEN);
	char *buf2 = (char *) malloc(MAX_BUF_LEN);
	char text[]="Buga ga";

	int r1=my_snprintf(buf,MAX_BUF_LEN,"%s olo %d %hX", text, -70, -170);
	int r2=snprintf(buf2,MAX_BUF_LEN,"%s olo %d %hX",text, -70,-170);
	printf("%s\n",buf);
	int flag=compare(buf,buf2, r1, r2);

	free(buf);
	free(buf2);
	
	return flag;
}

int test2()
{
	char *buf = (char *) malloc(MAX_BUF_LEN);
	char *buf2 = (char *) malloc(MAX_BUF_LEN);
	//char text[]="Buga ga";

	int r1=my_snprintf(buf,MAX_BUF_LEN,"My %s is %s. I live in %s. I \tam %d (%hX) years old.\n", "name", "Alexey", "", 197,197);
	int r2=snprintf(buf2,MAX_BUF_LEN,"My %s is %s. I live in %s. I \tam %d (%hX) years old.\n", "name", "Alexey", "", 197,197);
	printf("%s\n",buf);
	printf("%s\n",buf2);
	printf("%d %d \n",r1, r2);
	int flag=compare(buf,buf2, r1, r2);

	free(buf);
	free(buf2);
	
	return flag;
}


int main()
{
	int test_counter=1;
	
	
	//answer(test2(),"test2");
	//answer(test3(),"test3");
	char string[25], string1[25];
	{
		//Check convertion
		const char* command="hex %hX";
		int buff_s=25;
		int data_array[]={-65431,-32769,-32768,100,32766,32768, 654321,-100,0,32767};
		for (int i = 0; i < 7; ++i)
		{

			int n=data_array[i];
			int r1=snprintf(string, buff_s, command, n);
			int r2=my_snprintf(string1, buff_s, command, n);
			answer(compare(string, string1, r1,r2),test_counter);
			
			test_counter++;
		}
	}

	{

		//Check convertion dif buff
		const char* command="hex %hX";
		int buff_s=5;
		int data_array[]={-32767,USHRT_MAX,SHRT_MAX,SHRT_MIN};
		for (int k = 0; k < buff_s; k=k+2)
		{
			/* code */
			for (int i = 0; i < 4; ++i)
			{

				int n=data_array[i];
				int r1=snprintf(string, k, command, n);
				int r2=my_snprintf(string1, k, command, n);
				answer(compare(string, string1, r1,r2),test_counter);

				test_counter++;
			}
		}
	}


	{

		//Check print int with dif buffer
		const char* command="normal %d";
		int buff_s=5;
		int data_array[]={-327,327};
		for (int k = 0; k < buff_s; k=k+2)
		{
			/* code */
			for (int i = 0; i < 2; ++i)
			{

				int n=data_array[i];
				int r1=snprintf(string, k, command, n);
				int r2=my_snprintf(string1, k, command, n);
				answer(compare(string, string1, r1,r2),test_counter);

				test_counter++;
			}
		}
	}


	{

		//Check print string with dif buffer
		const char* command="line %s";
		int buff_s=20;
		char* data_array[]={"Too many test"};
		for (int k = 0; k < buff_s; k=k+2)
		{
			/* code */
			for (int i = 0; i < 1; ++i)
			{

				char* n=data_array[i];
				int r1=snprintf(string, k, command, n);
				int r2=my_snprintf(string1, k, command, n);
				answer(compare(string, string1, r1,r2),test_counter);

				test_counter++;
			}
		}
	}
	//combo test and dinamic mememory
	answer(test1(),test_counter);

	answer(test2(),test_counter);

	return 0;
}