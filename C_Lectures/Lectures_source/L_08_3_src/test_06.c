/*
����� 15
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
    // malloc ����� ������� NULL
    *p = 10;
    f(p);
    // p ����� ��������� �� ������������� ������
    printf("*p = %d", *p);
    // q ����������������������� ���������
    printf("*q = %d", *q);

    return 0;
}
