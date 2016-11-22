#include "func.h"
#include <string.h>

int main(int argc, char const *argv[])
{	
	struct matrix* A;
	struct matrix* B;
	struct matrix* C;
	int code_error=OK;
	if (argc < 5)
        code_error = ERROR_ARG;
    else
    {

    	FILE * file_inA = fopen(argv[1], "r");
	    if (file_inA == 0)
	    	code_error = ERROR_OPEN_INPUT_FILE;
	    else
	    {
	    	A=read_matrix(file_inA);
	    	fclose(file_inA);

	    	if(!A)
		    	code_error=ERROR_NULL;
		    else
		    	print(A);
	    }


	    if(code_error==OK)
	    {
		    FILE * file_inB = fopen(argv[2], "r");
		    if (file_inB == 0)
		    	code_error = ERROR_OPEN_INPUT_FILE;
		    else
		    {
		    	B=read_matrix(file_inB);
		    }
		    fclose(file_inB);
		    printf("\n");

		    if(!B)
		    	code_error=ERROR_NULL;
		    else
		    	print(B);
		}
		
		if(code_error==OK)
	    {
			int k=0;
			if(!strcmp(argv[4],"SUMM")) k=1;
			if(!strcmp(argv[4],"MULT")) k=2;
			if(!strcmp(argv[4],"INV")) k=3;

		    switch(k)
		    {
		    	case (1): printf("\nSUMM\n"); C=summ(A,B); break;
		    	case (2): printf("\nMULT\n"); C=multiplication(A,B); break;
				case (3): printf("\nINV\n");  C=invert(A); break;
				default: printf("ERROR KEY\n"); code_error=ERROR_KEY; break; 
		    }
		}
		if(!C)
			code_error=ERROR_NULL;

	    if(code_error==OK)
	    {
	    	
			//printf("\n");
			print(C);
		    FILE * file_out = fopen(argv[3], "w");
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
	            printf("NUll object.\n");
	            break;
	        case (ERROR_KEY):
	            printf("Error command.\n");
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
    }
}
