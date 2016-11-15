#include <stdio.h>

void f(int a[])
{
    printf("f: number of elements %d\n", sizeof(a) / sizeof(a[0]));
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};

    printf("main: number of elements %d\n", sizeof(a) / sizeof(a[0]));

    f(a);

    return 0;
}