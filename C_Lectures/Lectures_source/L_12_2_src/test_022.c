#include <stdio.h>

int main(void)
{
    int x = 30;

    printf("1) x = %d\n", x);

    {
        int x = 77;

        printf("2) x = %d\n", x);
    }

    while (x++ < 33)
    {
        int x = 100;

        x++;

        printf("3) x = %d\n", x);
    }

    printf("4) x = %d\n", x);

    return 0;
}