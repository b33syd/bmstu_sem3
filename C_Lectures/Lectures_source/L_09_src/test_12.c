/*
Слайд 18 - 20
*/

#include <stdio.h>

int str_cmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

int main(void)
{
    char str_1[] = "abcde";
    char str_2[] = "abc";

    printf("str_cmp([%s], [%s]) = %d\n", str_1, str_2, str_cmp(str_1, str_2));

    return 0;
}