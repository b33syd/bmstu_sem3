#include "func.h"

double** allocate_matrix_solid(int n, int m)
{
    double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data +  n * sizeof(double*) + i * m * sizeof(double));

    //is need?
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < m; j++)
    		data[i][j]=0;
    }

    return data;
}

struct matrix * read_matrix(FILE * file)
{	
	if (!file)
		return NULL;

	struct matrix * matr= malloc(sizeof(struct matrix));
	if (!matr)
		return NULL;

	fscanf(file,"%d", &matr->n);
	fscanf(file,"%d", &matr->m);

	if((matr->n==0)||(matr->m==0))
	{	
		
		free(matr);
		return NULL;
	}

	matr->matrix=allocate_matrix_solid(matr->n, matr->m);
	if (!matr->matrix)
		return NULL;

	for (int i = 0; i < matr->n; ++i)
	{
		
		for (int j = 0; j < matr->m; ++j)
		{
			fscanf(file,"%lf", &matr->matrix[i][j]);
		}
	}

	return matr;
}

int print_to_file(FILE * file,const struct matrix *matrA)
{
	if (!matrA)
		return ERROR_NULL;
	if (!matrA->matrix)
		return ERROR_NULL;
	if (!file)
		return ERROR_NULL;

	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrA->m-1; ++j)
		{
			fprintf(file, "%lf ",matrA->matrix[i][j] );			
		}
		fprintf(file, "%lf\n",matrA->matrix[i][matrA->m-1]);
	}
	return OK;
}

int print(const struct matrix *matrA)
{
	if (!matrA)
		return ERROR_NULL;
	if (!matrA->matrix)
		return ERROR_NULL;

	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrA->m-1; ++j)
		{
			printf("%lf ",matrA->matrix[i][j] );			
		}
		printf( "%lf\n",matrA->matrix[i][matrA->m-1]);
	}
	return OK;
}

struct matrix * erase(struct matrix *matrA)
{
	if(matrA)
	{

		if(matrA->matrix)
			free(matrA->matrix);
		matrA->matrix=NULL;
	}
	return NULL;
}

int inversion(double **A, int N)
{
    double temp;

 	//create E with 0
    double **E = allocate_matrix_solid(N, N);

    if (!E)
    	return ERROR_MALLOC;
    

    for (int i = 0; i < N; i++)
        E[i][i] = 1.0;
 
    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];
 
        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }
 
        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
 
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
 
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];
 
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

 	//matrix swap
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];
 	if(E)
    	free(E);
    return 0;
}

struct matrix*  invert(const struct matrix *matrA)
{
	if (matrA->n==matrA->m)
	{
		struct matrix* matrC= malloc(sizeof(struct matrix));
		if(!matrC)
			return NULL;

		matrC->matrix=allocate_matrix_solid(matrA->n, matrA->m);

		
		if(!matrC->matrix)
			return NULL;
		//printf("work\n");

		matrC->n=matrA->n;
		matrC->m=matrA->m;
		for (int i = 0; i < matrA->n; ++i)
			for (int j = 0; j < matrA->m; ++j)
				matrC->matrix[i][j]=matrA->matrix[i][j];		

		inversion(matrC->matrix,matrC->n);
		return matrC;
	}
	else
	{
		printf("Неверная размерность\n");
		return NULL;
	}
}


struct matrix* summ(const struct matrix *matrA, const struct matrix *matrB)
{
	if((matrA->n!=matrB->n) || (matrA->m!=matrB->m))
	{	printf("Неверная размерность\n");
		return NULL;
	}

	struct matrix* matrC= malloc(sizeof(struct matrix));
	if(!matrC)
		return NULL;

	matrC->n=matrA->n;
	matrC->m=matrA->m;

	matrC->matrix=allocate_matrix_solid(matrC->n, matrC->m);
	if(!matrC->matrix)
		return NULL;

	for (int i = 0; i < matrA->n; ++i)
		for (int j = 0; j < matrA->m; ++j)		
			matrC->matrix[i][j]=matrA->matrix[i][j]+matrB->matrix[i][j];

	return  matrC;
}


struct matrix* multiplication(const struct matrix *matrA,const struct matrix *matrB)
{
	struct matrix* matrC= malloc(sizeof(struct matrix));
	if(!matrC)
		return NULL;

	if(matrA->m!=matrB->n)
	{
		printf("Неверная размерность\n");
		return NULL;
	}

	matrC->n=matrA->n;
	matrC->m=matrB->m;
	matrC->matrix=allocate_matrix_solid(matrC->n, matrC->m);
	if(!matrC->matrix)
		return NULL;

	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrB->m; ++j)
		{
			for (int l = 0; l < matrA->m; l++)
            {
				matrC->matrix[i][j]+=matrA->matrix[i][l]*matrB->matrix[l][j];
			}
		}
	}
	return  matrC;
}