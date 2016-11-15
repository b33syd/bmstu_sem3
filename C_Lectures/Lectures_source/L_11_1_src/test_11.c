/*
Слайд 32
*/

#include <stdio.h>
#include <stdlib.h>


double** allocate_matrix(int n, int m)
{
    double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));
    if (!data)
        return NULL;

    for(int i = 0; i < n; i++)
        data[i] = (double*)
                 ((char*) data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
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

    free(mtr);

    return 0;
}