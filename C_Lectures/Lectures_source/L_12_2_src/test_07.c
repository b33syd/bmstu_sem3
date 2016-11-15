/*
Слайд 28
*/

#include <stdio.h>

/*
register int c = 6;

// error: register name not specified for 'c'
*/


void print(const int *a, int n)
{
    printf("Array: ");

    for (register int i = 0; i < n; i++)
        printf(" %d", a[i]);

    printf("\n");
}

int main(void)
{
    int a[] = {2, 5, 1, 3, 4};

    print(a, sizeof(a) / sizeof(a[0]));

    {
        register int b = 5;

        printf("Address of b %p\n", &b);

        // error: address of register variable 'b' requested
    }


    return 0;
}
