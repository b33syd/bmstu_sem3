/*
Слайд 18
*/

#include <stdio.h>

char* make_greeting(const char *name)
{
    char str[64];

    snprintf(str, sizeof(str), "Hello, %s!", name);

    return str;
}

int main(void)
{
    char *msg = make_greeting("Petya");

    printf("%s\n", msg);

    return 0;
}
