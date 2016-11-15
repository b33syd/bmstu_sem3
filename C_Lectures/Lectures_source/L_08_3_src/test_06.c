/*
Слайд 15
*/

#include <stdio.h>
#include <stdlib.h>

void f(int *n)
{
    if (*n == 10)
        free(n);
}

int main(void)
{
    int *p, *q;
    p = malloc(sizeof(int));
    // malloc может вернуть NULL
    *p = 10;
    f(p);
    // p может указывать на освобожденную память
    printf("*p = %d", *p);
    // q непроинициализированный указатель
    printf("*q = %d", *q);

    return 0;
}
