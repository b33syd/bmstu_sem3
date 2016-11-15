/*
Слайд 8, вторая часть
*/

#include <stdio.h>

int main(void)
{
    int *p;

    printf("%d\n", *p);     // ОШИБКА времени выполнения

    *p = 1;                 // ОШИБКА времени выполнения

    return 0;
}