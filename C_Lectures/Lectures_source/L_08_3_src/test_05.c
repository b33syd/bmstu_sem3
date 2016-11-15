/*
Слайд 14
*/

#include <stdlib.h>

void f(void)
{
    // каждый раз при вызове функции
    int *p = malloc(5 * sizeof(int));

    *p = 0;
}

int main(void)
{
    char *p;
    for (int i = 0; i < 10; i++)
    {
        // на каждой итерации цикла
        p = malloc(sizeof(char));
        *p = i;
    }

    f();

    return 0;
}
