/*
Слайд 4
*/

#include <stdio.h>

int main(void)
{
    int *p;

    {
        int b = 5;

        p = &b;

        printf("%d %d\n", *p, b);
    }

    /*
    printf("%d\n", b);
    // error: 'b' undeclared (first use in this function)
    */

    printf("%d\n", *p);

    return 0;
}
