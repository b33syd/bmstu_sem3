/*
Слайды 8, 9
*/


#include <stdio.h>


void print(const int *a, int n)
{
    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);

    printf("\n");
}


int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int b[5] = {1, 2, 3};

    /*
    // warning: excess elements in array initializer
    int f[3] = {1, 2, 3, 4};
    */

    int c[5] = {0};

    int d[] = {1, 2, 3, 4, 5};

    // C99 only
    int e[10] = {[2] = 5, [5] = 10, [8] = 15};


    print(a, sizeof(a) / sizeof(a[0]));

    print(b, sizeof(b) / sizeof(b[0]));

    print(c, sizeof(c) / sizeof(c[0]));
             
    print(d, sizeof(d) / sizeof(d[0]));

    print(e, sizeof(e) / sizeof(e[0]));


    return 0;
}