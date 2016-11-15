// Copyright stackoverflow "atol() v/s. strtol()"


#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *end;
    int  res_help = strtol("help", &end, 10);

    if (!*end)
        printf("Converted successfully, result %d\n", res_help);
    else
        printf("Conversion error, non-convertible part: %s\n", end);

    int  res_zero = strtol("0", &end, 10);

    if (!*end)
        printf("Converted successfully, result %d\n", res_zero);
    else
        printf("Conversion error, non-convertible part: %s\n", end);

    return 0;
}