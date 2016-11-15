/*
Слайды 12, 13, 14
*/


#include <stdio.h>


void zero(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}


void print(const int *a, int n)
{
    const int *pend = a + n;

    printf("Array: ");

    for ( ; a < pend; a++)
        printf(" %d", *a);

    printf("\n");

    /*
    // error: assignment of read-only location '*a'
    a[0] = 0;
    */
}


int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(a, sizeof(a) / sizeof(a[0]));

    zero(a, sizeof(a) / sizeof(a[0]));

    print(a, sizeof(a) / sizeof(a[0]));

    zero(b, 2);
    print(b, 10);

    zero(b + 7, 3);
    print(b, 10);

    print(b + 2, 5);
             
    return 0;
}