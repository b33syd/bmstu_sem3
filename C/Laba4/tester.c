#include "func.h"
#include <math.h>
#define GOOD 0
#define BAD 11
#define EPS 0.001
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"


int compare(const struct matrix *A, const struct matrix *B)
{
	double a,b;
	
	//printf("%d %d  %d  %d\n",A->n,A->m,B->n,B->m);
	if((((B->n)!=(A->n))||((B->m)!=(A->m))))
		return BAD;	

	for (int i = 0; i < A->n; ++i)
	{
		for (int j = 0; j < A->m; ++j)
		{
			a=A->matrix[i][j];
			b=B->matrix[i][j];			
			//printf("%lf 	%lf\n",a,b );
			if (fabs(a - b) > EPS*fmax(fabs(a), fabs(b)))
			{
				return BAD;
			}
		}
	}
	return GOOD;
}

int reader(struct matrix** Matr,const char* filename)
{
	int code_error=GOOD;
	FILE * file_in = fopen(filename, "r");
	if (file_in == 0)
	{
		code_error = BAD;
	}
	else
	{	
		*Matr=read_matrix(file_in);
		fclose(file_in);
		
		if(!*Matr)
			code_error=BAD;
		
	}
	return code_error;
}

int check(char * file1, char* file2, char* answer, int type)
{
	
	struct matrix* A=NULL;
	struct matrix* B=NULL;
	struct matrix* C=NULL;
	struct matrix* Control=NULL;

	if(reader(&A,file1)) return BAD;
	if (type!=INV)
	{
		if(reader(&B,file2)) return BAD;
	}

	if(reader(&Control,answer)) return BAD;

	switch(type)
	{
		case (SUMM): C=summ(A,B); break;
		case (MULT): C=multiplication(A,B); break;
		case (INV): C=invert(A); break;
	}


	if(C==NULL) return BAD;

	int Ans=compare(C,Control);


	erase(A);
	erase(B);
	erase(C);
	erase(Control);

	if(A)
		free(A);
	if(B)
		free(B);
	if(C)
		free(C);
	if(C)
		free(Control);
	return Ans;
}

char *answer(int val)
{
    char *answer = "FAIL";
    if (val == GOOD)
    {
        printf("%s", KGRN);
        answer = "OK";
    }
    else
        printf("%s", KRED);
    return answer;   
}

int main(int argc, char const *argv[])
{
	printf("test_sum_1 \t%s\n", answer(check("tests/square1","tests/square2","tests/answer2",SUMM)));
	printf("test_sum_2 \t%s\n", answer(check("tests/square2","tests/square1","tests/answer2",SUMM)));
	printf("test_sum_2 \t%s\n", answer(check("tests/col1","tests/col2","tests/answer6",SUMM)));
	printf("test_sum_2 \t%s\n", answer(check("tests/col2","tests/col1","tests/answer6",SUMM)));
	printf("test_sum_2 \t%s\n", answer(check("tests/row1","tests/row2","tests/answer7",SUMM)));
	printf("test_sum_2 \t%s\n", answer(check("tests/row2","tests/row1","tests/answer7",SUMM)));

	printf("test_mult_1 \t%s\n", answer(check("tests/square1","tests/square2","tests/answer1",MULT)));
	printf("test_mult_2 \t%s\n", answer(check("tests/square2","tests/square1","tests/answer5",MULT)));
	printf("test_mult_3 \t%s\n", answer(check("tests/col1","tests/row1","tests/answer8",MULT)));
	printf("test_mult_4 \t%s\n", answer(check("tests/col2","tests/row1","tests/answer9",MULT)));
	printf("test_mult_5 \t%s\n", answer(check("tests/col1","tests/row2","tests/answer10",MULT)));
	printf("test_mult_6 \t%s\n", answer(check("tests/col2","tests/row2","tests/answer11",MULT)));

	printf("test_inv_1 \t%s\n", answer(check("tests/square1","","tests/answer3",INV)));
	printf("test_inv_2 \t%s\n", answer(check("tests/square2","","tests/answer4",INV)));
	printf("test_inv_3 \t%s\n", answer(check("tests/test3","","tests/answer12",INV)));
	printf("test_inv_4 \t%s\n", answer(check("tests/test2","","tests/answer13",INV)));
	
	return 0;
}