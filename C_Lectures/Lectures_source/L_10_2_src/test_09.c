/*
Слайды 9, 10
*/

#include <stdio.h>

#define N 3
#define M 5

void print(const int arr[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    printf("\n");
}

int main(void)
{
    int a[N][M] = {{1, 2, 3}, {4, 5, 6}};

    // warning: expected 'const int (*)[5]' but argument is of type 'int (*)[5]'
    print(a, 2, 3);

    print((const int (*)[M]) a, 2, 3);


    return 0;
}