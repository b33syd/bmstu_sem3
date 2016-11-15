/*
Слайд 10
*/

#include <stdio.h>

int main(void)
{
    int a = 1;

    {
        int b = 2;

        printf("inner block, a = %d, b = %d\n", a, b);
    }

    printf("outer block, a = %d\n", a);

    /*
    printf("outer block, b = %d\n", b);
    */

    return 0;
}
