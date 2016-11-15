/*
Слайд 6
*/

#include <stdio.h>

int main(void)
{
    int a = 1;
    int *p = &a;    // p теперь указывает на a

    a = 3;

    // операция разыменования используется для чтения
    printf("%d %d\n", a, *p);

    // операция разыменования используется для записи
    *p = 5;

    printf("%d %d\n", a, *p);

    printf("%p\n", p);

    return 0;
}