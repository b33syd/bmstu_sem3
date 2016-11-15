/*
Слайд 13
*/

#include <stdio.h>


void test_1d(int n, int a[n])
{
    printf("test_1d\n\n");

    printf("sizeof(a) = %d\n\n", sizeof(a));

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


void test_2d(int n, int m, int a[/*n*/][m])
{
    printf("test_2d\n\n");

    printf("sizeof(a) = %d\n\n", sizeof(a));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}


int main(void)
{
    int n = 5;
    int a[n];
    int b[7] = {0};
    int c[1] = {100};
    int a_m[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int b_m[1][1] = {{0}};
    int c_m[2][2] = {{0, 1}, {2, 3}};

    for (int i = 0; i < n; i++)
        a[i] = i;

    test_1d(n, a);

    test_1d(7, b);

    test_1d(1, c);

    test_2d(2, 3, a_m);

    test_2d(1, 1, b_m);

    test_2d(2, 2, c_m);

    // "Ощибка" времени выполнения (переданные размер матрицы не соответсвуют фактическим)
    test_2d(2, 2, a_m);

    return 0;
}
