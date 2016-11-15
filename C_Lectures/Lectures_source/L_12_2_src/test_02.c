/*
Слайд 11
*/

#include <stdio.h>

int main(void)
{
    int a = 1;

    {
        double a = 2.0;

        printf("inner block, a = %e\n", a);
    }

    printf("outer block, a = %d\n", a);

    return 0;
}