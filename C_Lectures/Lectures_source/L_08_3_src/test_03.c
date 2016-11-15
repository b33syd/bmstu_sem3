/*
Слайд 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = NULL;
    int n = 5;

    // Выделение памяти
    a = calloc(n, sizeof(int));

    printf("a %p\n", a);

    // Проверка успешности выделения
    if (a == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }

    // Использование памяти
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Освобождение памяти
    free(a);

    return 0;
}