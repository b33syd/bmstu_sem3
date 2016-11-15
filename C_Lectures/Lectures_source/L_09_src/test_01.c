/*
Слайд 3
*/

#include <stdio.h>

int count_spaces(const char *s)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;

    return count;
}

int main(void)
{
    printf("%d\n", count_spaces("I am a string!"));
    printf("%d\n", count_spaces("    "));

    return 0;
}