/*
Слайд 11
*/

#include <stdio.h>

int main(void)
{
    char str_out[] = "Hello, world!";
    char str_in[5];

    printf("%s\n", str_out);

    puts(str_out);

    gets(str_in);
    printf("%s (%s)\n", str_in, str_out);

    scanf("%s", str_in);
    printf("%s (%s)\n", str_in, str_out);

    // "Безопасный" способ вызова функции scanf
    scanf("%4s", str_in);
    printf("%s\n", str_in);

    return 0;
}