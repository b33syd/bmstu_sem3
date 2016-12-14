/*
Слайд 19
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[16];

    if (argc < 2)
        return 1;

    sprintf(str, "Hello, %s!", argv[1]);

    printf("%s (%d)\n", str, strlen(str));

    return 0;
}
