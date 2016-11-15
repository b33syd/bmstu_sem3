/*
����� 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = NULL;
    int n = 5;

    // ��������� ������
    a = malloc(n * sizeof(int));

    printf("a %p\n", a);

    // �������� ���������� ���������
    if (a == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }

    // ������������� ������

    for (int i = 0; i < n; i++)
        a[i] = i;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    // ������������ ������
    free(a);

    return 0;
}