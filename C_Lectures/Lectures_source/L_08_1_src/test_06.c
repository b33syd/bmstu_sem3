#include <stdio.h>

void print_array(const int a[], int n)
{
    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    a[0] = 0;

    printf("\n");
}
