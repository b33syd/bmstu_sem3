/*
Слайд 14
*/

#include <string.h>
#include <stdio.h>


int main(void)
{
    char str[10];
    int n;

    puts("Input string:");

    fgets(str, sizeof(str), stdin);

    // "Удалим" символ перехода на новую строку
    n = strlen(str);
    if (str[n-1] == '\n')
        str[n-1] = '\0';

    printf("Input string [%s]\n", str);

    return 0;
}