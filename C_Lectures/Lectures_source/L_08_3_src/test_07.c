/*
����� 16
*/

#include <stdlib.h>

void f(int *n)
{
    if (*n == 10)
        free(n);
}

int main(void)
{
    int *p;
    p = malloc(sizeof(int));
    *p = 10;
    f(p);
    // p ����� ��������� �� ������������� ������
    free(p);

    return 0;
}
