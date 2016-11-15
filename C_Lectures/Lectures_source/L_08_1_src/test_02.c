#include <stdio.h>

#define N 5

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5};

    for (int i = 0; i <= N; i++)
        printf("%d ", a[i]);

    return 0;
}
