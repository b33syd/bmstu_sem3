/*
Слайд 8
*/

#include <stdio.h>


#define N 3
#define M 3


int sum_1(int a[N][M], int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += a[i][j];

    return sum;
}


int sum_2(int a[][M], int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += a[i][j];

    return sum;
}


/*
// error: array type has incomplete element type
// ошибка, компилятор не знает второй размерности массива, из-за этого не сможет
// выполнить обращение по индексу
int sum_3(int a[][],int n, int m)
{
    return 0;
}
*/


int sum_4(int (*a)[M],int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += a[i][j];

    return sum;
}


/*
// warning: passing argument 1 of 'sum_5' from incompatible pointer type
// ошибка, это не двумерный массив, а одномерный массив указателей 
int sum_5(int *a[M],int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += a[i][j];

    return sum;
}
*/


int main(void)
{
    int a[N][M] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    printf("sum_1 = %d\n", sum_1(a, N, M));
    printf("sum_2 = %d\n", sum_2(a, N, M));
    /*
    printf("sum_3 = %d\n", sum_3(a, N, M));
    */
    printf("sum_4 = %d\n", sum_4(a, N, M));
    /*
    printf("sum_5 = %d\n", sum_5(a, N, M));
    */

    return 0;
}
