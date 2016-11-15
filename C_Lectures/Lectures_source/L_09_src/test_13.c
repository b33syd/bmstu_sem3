/*
Слайд 22
*/

#include <stdio.h>

size_t str_len_1(const char *str)
{
    size_t n;

    for (n = 0; str[n] != '\0'; n++)
        ;

    return n;
}

size_t str_len_2(const char *str)
{
    const char *beg = str;

    while (*str)
        str++;

    return str - beg;
}

int main(void)
{
    char str_1[] = "abcde";
    char str_2[] = "";

    printf("str_len_1([%s]) = %d\n", str_1, str_len_1(str_1));
    printf("str_len_1([%s]) = %d\n", str_2, str_len_1(str_2));

    printf("str_len_2([%s]) = %d\n", str_1, str_len_1(str_1));
    printf("str_len_2([%s]) = %d\n", str_2, str_len_1(str_2));

    return 0;
}