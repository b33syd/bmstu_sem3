#include "func.h"
#include <math.h>
//Добавить функцию освоюождания памяти

double** allocate_matrix_solid(int n, int m)
{
    double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data +  n * sizeof(double*) + i * m * sizeof(double));

   
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < m; j++)
    		data[i][j]=0;
    }

    return data;
}



struct matrix * read_matrix(FILE * file,int *codeerror)
{	

	*codeerror =OK;
	if (!file)
		return NULL;

	struct matrix * matr= malloc(sizeof(struct matrix));
	if (!matr)
		return NULL;

	//Контроль чтения
	if(fscanf(file,"%d %d", &matr->n,&matr->m)!=2)
	{
		*codeerror=ERROR_INPUT;
		free(matr);
		//printf("Error Input\n");
		return NULL;		
	}

	if((matr->n==0)||(matr->m==0))
	{	
		
		free(matr);
		return NULL;
	}

	matr->matrix=allocate_matrix_solid(matr->n, matr->m);
	if (!matr->matrix)
	{
		free(matr);
		return NULL;
	}

	for (int i = 0; i < matr->n; ++i)
	{
		
		for (int j = 0; j < matr->m; ++j)
		{
			//Контроль чтения
			if(fscanf(file,"%lf", &matr->matrix[i][j])!=1)
			{
				*codeerror=ERROR_INPUT;
				erase(matr);
				//printf("Error Input\n");
				return NULL;		
			}
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
	fprintf(file, "%d %d\n",matrA->n,matrA->m);

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
		free(matrA);
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

struct matrix*  invert(const struct matrix *matrA, int *codeerror)
{
	*codeerror=OK;
	double k=opredel(matrA->matrix,matrA->n);
	if (fabs(k)<0.0001)
	{
		*codeerror=NULL_OPR;
		//printf("Нулевой определитель\n");
		return NULL;
	}

	
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
		*codeerror=ERROR_SIZE;
		//printf("Неверная размерность\n");
		return NULL;
	}
}


struct matrix* summ(const struct matrix *matrA, const struct matrix *matrB,int *codeerror)
{
	*codeerror=OK;
	if((matrA->n!=matrB->n) || (matrA->m!=matrB->m))
	{	
		*codeerror=ERROR_SIZE;
		//printf("Неверная размерность\n");
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


struct matrix* multiplication(const struct matrix *matrA,const struct matrix *matrB,int *codeerror)
{
	*codeerror=OK;

	struct matrix* matrC= malloc(sizeof(struct matrix));
	if(!matrC)
		return NULL;

	if(matrA->m!=matrB->n)
	{
		*codeerror=ERROR_SIZE;
		//printf("Неверная размерность\n");
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



double ** minor(double** mas2,int mas2_size,int not_i, int not_j)
{
    double** mas=allocate_matrix_solid(mas2_size-1,mas2_size-1);
    int i2=0;
    for (int i = 0; i < mas2_size; i++)
    {
    	if(i==not_i) continue;
        int j2 = 0;
        for (int j = 0; j < mas2_size; j++)
        {
            if (j == not_j) continue;
            mas[i2][j2] = mas2[i][j];
            j2++;
        }

        i2++;
    }
    return mas;
}

double opredel(double** mas, int n)
{
    double A = 0;
    int k=1; //(-1) в степени i
    if (n == 1)
    {
        return mas[0][0];
    }
    else
    {
        if (n == 2)
        {
            return mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                double **test_minor = minor(mas, n, i,0);
                double opr = opredel(test_minor, n - 1);
                A += k * mas[i][0] * opr;
                k=-k;
                free(test_minor);
            }
            return A;
        }
    }
}
