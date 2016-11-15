/*
Слайд 6, 7
*/

#include <stdio.h>


#define N 3
#define M 3


int main(void)
{
    int a[N][M] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int *p;

    for (p = a[0]; p < a[0] + M; p++)
        *p = 0;


    int (*q)[M];

    for (q = a; q < a + N; q++)
        (*q)[1] = 0;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }

    return 0;
}