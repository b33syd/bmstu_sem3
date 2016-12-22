/*
К слайду 30
*/

#include <stdio.h>

int main(void)
{
    unsigned char a = 0x01;
    unsigned char b = 0x02;

    if (a && b)
        printf("a && b true\n");
    else
        printf("a && b false\n");

    if ((b && 1) == 1)
        printf("odd\n");
    else
        printf("even\n");

    a = 0;
    if (a && b / a)
        printf("true\n");
    else
        printf("false\n");
                           
    return 0;
}
