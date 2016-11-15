/*
����� 3
*/

#include <stdio.h>

int main(void)
{
    int a[2][3][5];

    // a - ������ �� 2-� ��������� ���� "int [3][5]"

    int (*p)[3][5] = a;

    printf("p = %p, p + 1 = %p (sizeof(*p) = %d)\n", p, p + 1, sizeof(int [3][5]) /*sizeof(*p)*/);

    printf("\n");

    // a[i] - ������ �� 3-� ��������� ���� "int [5]"

    int (*q)[5] = a[0];

    printf("q = %p, q + 1 = %p (sizeof(*q) = %d)\n", q, q + 1, sizeof(int [5]) /*sizeof(*q)*/);

    q = a[1];

    printf("q = %p, q + 1 = %p (sizeof(*q) = %d)\n", q, q + 1, sizeof(int [5]) /*sizeof(*q)*/);

    printf("\n");

    // a[i][j] - ������ �� 5-�� ��������� ���� "int"

    int *r = a[0][0];

    printf("r = %p, r + 1 = %p (sizeof(*r) = %d)\n", r, r + 1, sizeof(*r));

    r = a[0][1];

    printf("r = %p, r + 1 = %p (sizeof(*r) = %d)\n", r, r + 1, sizeof(*r));

    printf("\n");

    // a[i][j][k] - ������� ���� "int"

    int s = a[0][0][0];

    printf("s = %d\n", s);

    return 0;
}
