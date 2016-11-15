/*
Слайд 7
*/

#include <stdio.h>

int main(void)
{
    int d = 5;

    // *&d = = = d
    printf("%d %d\n", *&d, d);

    int *pi = &d;

    // &*pi = = = pi
    printf("%p %p\n", &*pi, pi);

    return 0;    
}