/*
����� 23
*/

#include <stdio.h>
#include <string.h>

char*  str_cat(char *s1, const char *s2)
{
    char *cur = s1;

    while (*cur)
        cur++;

    // ��� ������ ����� warning, ������� ������������ � ������
    while ((*cur++ = *s2++))
        ;

    return s1;
}

int main(void)
{
    char dst[32];
    char str_1[] = "Hello";
    char str_2[] = ", world!";

    strcpy(dst, str_1);

    str_cat(dst, str_2);

    printf("dst [%s]\n", dst);

    return 0;
}