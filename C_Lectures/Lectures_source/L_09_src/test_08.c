/*
Слайд 13
*/

#include <stdio.h>


int read_line(char *s, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;

    s[i] = '\0';

    return i;
}


int main(void)
{
    char str[10];
    int n;

    puts("Input string:");

    n = read_line(str, sizeof(str));

    printf("Input string [%s] (n = %d)\n", str, n);

    return 0;
}