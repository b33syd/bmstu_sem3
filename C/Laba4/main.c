#include "func.h"
#include <string.h>

int reader(struct matrix** Matr,const char* filename)
{
	int code_error=OK;
	FILE * file_in = fopen(filename, "r");
	if (file_in == 0)
	{
		code_error = ERROR_OPEN_INPUT_FILE;
	}
	else
	{	
		*Matr=read_matrix(file_in);
		fclose(file_in);
		
		if(!*Matr)
			code_error=ERROR_NULL;
		
	}
	return code_error;
}

int main(int argc, char const *argv[])
{	
	struct matrix* A=NULL;
	struct matrix* B=NULL;
	struct matrix* C=NULL;
	int code_error=OK;
	int type_of_work=0;

	
	switch(argc)
	{
		case(5):
			code_error=reader(&A,argv[1]);
			if(code_error==OK)
				code_error=reader(&B,argv[1]);
			if(code_error==OK)
				if(!strcmp(argv[4],"SUMM")) type_of_work=1;
				if(!strcmp(argv[4],"MULT")) type_of_work=2;
			break;

		case(4):

			code_error=reader(&A,argv[1]);
			if(code_error==OK)
				if(!strcmp(argv[3],"INV")) type_of_work=3;
			break;

		default:
			 code_error = ERROR_ARG;
			 break;
	}


	if(code_error==OK)
	{
		switch(type_of_work)
		{
			case (1): 
				printf("\nSUMM\n"); 
				C=summ(A,B); 
				break;
			case (2):
				printf("\nMULT\n");
				C=multiplication(A,B);
				break;
			case (3):
				printf("\nINV\n");
				C=invert(A);
				break;
			default:
				//printf("ERROR KEY\n");
				code_error=ERROR_KEY; break; 
		}
	}

	if((!C)&&(code_error==OK))
		code_error=ERROR_NULL;

	if(code_error==OK)
	{

		print(C);
		FILE * file_out=NULL;

		if (type_of_work==3)
			file_out = fopen(argv[2], "w");
		else
			file_out = fopen(argv[3], "w");

		if (file_out == 0)
			code_error = ERROR_OPEN_OUTPUT_FILE;
		else
			print_to_file(file_out,C);

		fclose(file_out);
	}

	switch(code_error)
	{
		case (ERROR_MALLOC):
			printf("Can`t malloc memory.\n");
			break;
		case (ERROR_ARG):
			printf("Not enough arguments.\n");
			break;
		case (ERROR_OPEN_INPUT_FILE):
			printf("Unable to open input file.\n");
			break;
		case (ERROR_OPEN_OUTPUT_FILE):
			printf("Unable to open output file.\n");
			break;
		case (ERROR_NULL):
			printf("NULL object.\n");
			break;
		case (ERROR_KEY):
			printf("Error params.\n");
			break;
	}
		
		
	erase(A);
	erase(B);
	erase(C);

	if(A)
		free(A);
	if(B)
		free(B);
	if(C)
		free(C);
		
	return code_error;
}

