#include <stdio.h>

int main(void)
{
    int n = 10;

    printf("At the beginning, n = %d\n\n", n);

    for (int n = 0; n < 3; n++)
        printf("loop 1: index n = %d\n", n);

    printf("\nAfter loop 1, n = %d\n\n", n);

    for (int n = 0; n < 3; n++)
    {
        printf("loop 2: index n = %d, ", n);

        int n = 20;

        printf("variable n = %d\n", n);
        n++;        
    }

    printf("\nAfter loop 2, n = %d\n", n);

    return 0;
}