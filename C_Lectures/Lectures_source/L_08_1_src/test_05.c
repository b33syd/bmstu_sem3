#include <stdio.h>

void zero_var(int a)
{
    a = 0;
}

void zero_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

void print_array(const int a[], int n)
{
    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(void)
{
    int a = 5;
    int b[] = {1, 2, 3, 4, 5};

    printf("a = %d\n", a);

    zero_var(a);

    printf("a = %d\n", a);

    print_array(b, sizeof(b) / sizeof(b[0]));

    zero_array(b, sizeof(b) / sizeof(b[0]));

    print_array(b, sizeof(b) / sizeof(b[0]));

    return 0;
}