/*
Слайд 10
*/

#include <stdio.h>

#define N 11

void f_1(int a[N])
{
    printf("sizeof(a[N]) = %d\n", sizeof(a));
}

void f_2(int a[])
{
    printf("sizeof(a[]) = %d\n", sizeof(a));
}

void f_3(int *a)
{
    printf("sizeof(*a) = %d\n", sizeof(a));
}

int main(void)
{
    int a[N];
    int b[25];

    f_1(a);
    f_1(b);

    f_2(a);
    f_2(b);

    f_3(a);
    f_3(b);

    return 0;
}