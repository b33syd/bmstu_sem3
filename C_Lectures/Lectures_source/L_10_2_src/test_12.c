/*
Слайд 13
*/

#include <stdio.h>

int main(void)
{
    int n = 4, m = 3;
    int a[n][m];
    int (*p)[m] = a; // p == &a[0]

    // p === &a[0]
    printf("p %p, a %p\n", p, a);

    p += 1;

    // p === &a[1]
    printf("p %p, a %p\n", p, &a[1]);

    (*p)[2] = 99; 

    // a[1][2] === 99
    printf("a[1][2] %d\n", a[1][2]);

    n = p - a;

    // n === 1
    printf("n %d\n", n);

    return 0;
}