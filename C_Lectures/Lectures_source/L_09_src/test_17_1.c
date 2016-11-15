// Copyright stackoverflow "atol() v/s. strtol()"


#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int res_help = atol("help");
    int res_zero = atol("0");

    printf("Got from help: %d, from zero: %d\n", res_help, res_zero);

    return 0;
}