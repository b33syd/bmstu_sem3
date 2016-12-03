#include <stdio.h>
char* pr(char *str)
{
    char *pe = str;
    while (*pe)
        putchar(*pe++);
    do
    {
        putchar(*--pe);
    }
    while (pe - str);
    return pe;
}
int main()
{
	char * x = pr("Xo Xo Xo!");
}
