/*
Слайд 14
*/

#include <stdio.h>

int main(void)
{
    int a[10];
    int *pa = a;
    char c[10];
    char *pc = c;

    printf("%p %p\n", pa, pa + 1);
    printf("%p %p\n", pc, pc + 1);

    return 0;
}