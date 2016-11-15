/*
Слайд 26-28
*/

#include <stdio.h>
#include <stdlib.h>


void free_matrix(double **data, int n);


double** allocate_matrix(int n, int m)
{
    double **data;

    data = calloc(n, sizeof(double*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = (double*) malloc(m * sizeof(double));
        if (!data[i])
        {
            free_matrix(data, n);

            return NULL;
        }
    }

    return data;
}


void free_matrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
        if (data[i])
            free(data[i]);

    free(data);
}


int main(void)
{
    int n = 2, m = 3;
    double **mtr = allocate_matrix(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mtr[i][j] = i + j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf(" %4.2f", mtr[i][j]);

        printf("\n");
    }

    free_matrix(mtr, n);

    return 0;
}