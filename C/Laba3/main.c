#include <stdio.h>
#include <stdlib.h>

#include "libstr2.h"


/*
 *
 *1) прототип фукции readfromfile? pozix-getline  ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 *2) довыделяем память по одному эллементу или блоками? по блокам, но вернуть только нужную длинну
 *3) использовать ли size_t? %U
 *4) использовать ли memcpy mystrndup? да
 *5) что использовать признаком окончания строки? \0
 *6) как сравнивать с работой стандартных функций? strcmp
 *7) Добавлять ли поддержку русских строк? нет
 **/


int work(FILE * file_in,FILE * file_out,const char * replace_what, const char * replace_to)
{	
	char *string=NULL; 
	char *string1=NULL; 
	int code_error=0;
	size_t length=0;

	while((code_error=readfromfile2(&string,&length,file_in)!=-1))
	{
		string1=replace(string, replace_what,replace_to);
		
		fprintf(file_out,"%s",string1);
		if(string1!=NULL)
			free(string1);
		if(string!=NULL)
			free(string);

		length=0;
	}

}



int main(int argc, char const *argv[])
{	
	int code_error=OK;
	if (argc < 5)
        code_error = ERROR_ARG;
    else
    {
	    FILE * file_in = fopen(argv[1], "r");
	    if (file_in == 0)
	       code_error = ERROR_OPEN_INPUT_FILE;	   
	    else
	    {
 			FILE * file_out = fopen(argv[2], "w");
		    if (file_out == 0)
		        code_error = ERROR_OPEN_OUTPUT_FILE;
		    else
		    
		    	work(file_in,file_out,argv[3],argv[4]);	    	
	    	
	    	fclose(file_out);	    	
	    }

	    fclose(file_in);
	}
	switch(code_error)
	{
		case 0: printf("OK\n"); break;
		default : printf("BAD\n");
	}

	return 0;
}

