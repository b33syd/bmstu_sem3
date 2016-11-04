#include "func.h"



struct matrix * read_matrix(FILE * file)
{	
	struct matrix * matr= malloc(sizeof(struct matrix));
	fscanf(file,"%d", &matr->n);
	fscanf(file,"%d", &matr->m);

	matr->matrix=(double **)malloc(matr->n*sizeof(double *));

	for (int i = 0; i < matr->n; ++i)
	{
		matr->matrix[i]=malloc(matr->m*sizeof(double));
		
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
	for (int i = 0; i < matrA->n; ++i)
	{
		if(matrA->matrix[i]!=NULL)
			free(matrA->matrix[i]);
	}
	if(matrA->matrix)
		free(matrA->matrix);
	matrA->matrix=NULL;
	return NULL;
}



struct matrix* summ(const struct matrix *matrA, const struct matrix *matrB)
{
	struct matrix* matrC= malloc(sizeof(struct matrix));
	if((matrA->n!=matrB->n) && (matrA->m!=matrB->m))
		return NULL;

	matrC->n=matrA->n;
	matrC->m=matrA->m;

	matrC->matrix=malloc(matrA->n*sizeof(double *));
	
	for (int i = 0; i < matrA->n; ++i)
	{
		matrC->matrix[i]=malloc(matrA->m*sizeof(double));

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

	matrC->matrix=malloc(matrA->n*sizeof(double *));

	for (int i = 0; i < matrA->n; ++i)
	{
		matrC->matrix[i]=malloc(matrB->m*sizeof(double));

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