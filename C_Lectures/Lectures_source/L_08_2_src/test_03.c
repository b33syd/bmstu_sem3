/*
����� 8, ������ �����
*/

#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int *p = &a;    // p ������ ��������� �� a
    int *q = p;     // q ������ ��������� ���� �� ���� � p, �.�. �� a

    printf("Address of a = %p, p = %p, q = %p\n", &a, p, q);

    // � ����� ��������� ����� �������� ��������� � *p, � *q

    *p = 1;
    printf("a = %d\n", a);

    *q = 3;
    printf("a = %d\n", a);

    // �� ������� q = p � *q = *p

    p  = &a;
    q  = &b;
    *q = *p;

    printf("p = %p, *p = %d; q = %p, *q = %d\n", p, *p, q, *q);

    return 0;
}