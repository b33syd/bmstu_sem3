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
	struct matrix * matr= malloc(sizeof(struct matrix));
	fscanf(file,"%d", &matr->n);
	fscanf(file,"%d", &matr->m);

	matr->matrix=allocate_matrix_solid(matr->n, matr->m);

	for (int i = 0; i < matr->n; ++i)
	{
		
		for (int j = 0; j < matr->m; ++j)
		{
			fscanf(file,"%lf", &matr->matrix[i][j]);
		}
	}

	return matr;
}

void print_to_file(FILE * file,const struct matrix *matrA)
{
	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrA->m-1; ++j)
		{
			fprintf(file, "%lf ",matrA->matrix[i][j] );			
		}
		fprintf(file, "%lf\n",matrA->matrix[i][matrA->m-1]);
	}
}

void print(const struct matrix *matrA)
{
	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrA->m-1; ++j)
		{
			printf("%lf ",matrA->matrix[i][j] );			
		}
		printf( "%lf\n",matrA->matrix[i][matrA->m-1]);
	}
}

struct matrix * erase(struct matrix *matrA)
{
	/*for (int i = 0; i < matrA->n; ++i)
	{
		if(matrA->matrix[i]!=NULL)
			free(matrA->matrix[i]);
	}
	*/
	if(matrA->matrix)
		free(matrA->matrix);
	matrA->matrix=NULL;
	return NULL;
}




void inversion(double **A, int N)
{
    double temp;

 	//create E with 0
    double **E = allocate_matrix_solid(N, N);
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
 	
    free(E);
}

struct matrix*  invert(const struct matrix *matrA)
{
	if (matrA->n==matrA->m)
	{
		struct matrix* matrC= malloc(sizeof(struct matrix));

		matrC->matrix=allocate_matrix_solid(matrA->n, matrA->m);
		matrC->n=matrA->n;
		matrC->m=matrA->m;
		for (int i = 0; i < matrA->n; ++i)
			for (int j = 0; j < matrA->m; ++j)
				matrC->matrix[i][j]=matrA->matrix[i][j];		

		inversion(matrC->matrix,matrC->n);
		return matrC;
	}
	else
		return NULL;
}


struct matrix* summ(const struct matrix *matrA, const struct matrix *matrB)
{
	struct matrix* matrC= malloc(sizeof(struct matrix));
	if((matrA->n!=matrB->n) && (matrA->m!=matrB->m))
		return NULL;

	matrC->n=matrA->n;
	matrC->m=matrA->m;

	matrC->matrix=allocate_matrix_solid(matrC->n, matrC->m);

	for (int i = 0; i < matrA->n; ++i)
	{
		for (int j = 0; j < matrA->m; ++j)
		{
			matrC->matrix[i][j]=matrA->matrix[i][j]+matrB->matrix[i][j];
		}
	}

	return  matrC;
}


struct matrix* multiplication(const struct matrix *matrA,const struct matrix *matrB)
{
	struct matrix* matrC= malloc(sizeof(struct matrix));
	if(matrA->m!=matrB->n) 
		return NULL;

	matrC->n=matrA->n;
	matrC->m=matrB->m;
	matrC->matrix=allocate_matrix_solid(matrC->n, matrC->m);

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