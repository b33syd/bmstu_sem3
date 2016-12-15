
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


#define N 15
#define MAX_BUF_LEN 100
#define K -199
#define OK 0
#define FAIL 1


int main()
{
	{
		char *buf = (char *) malloc(MAX_BUF_LEN);
		char *buf2 = (char *) malloc(MAX_BUF_LEN);
		char text[]="Buga ga";
		int n=5;
		int r1=my_snprintf(buf,MAX_BUF_LEN,"%s olo %d %hX", text, -70, n);
		int r2=snprintf(buf,MAX_BUF_LEN,"%s olo %d %hX",text, -70, n);
		int flag=OK;

		if(r1!=r2)
			flag=FAIL;

		if(memcmp(buf,buf2,strlen(buf2))!=0)
			flag=FAIL;

		free(buf);
		free(buf2);
		
		return flag;
	}

		

	return 0;
}