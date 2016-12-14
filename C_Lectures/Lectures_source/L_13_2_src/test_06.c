/*
К слайдам 21, 22
*/

#include <stdio.h>

int main(void)
{
    struct
    {
        int i;
        double d;
    } s;

    union
    {
        int i;
        double d;
    } u;

    printf("sizeof(s) %d\n", sizeof(s));
    printf("sizeof(u) %d\n", sizeof(u));

    printf("u.i %d, u.d %g\n", u.i, u.d);

    u.i = 5;

    printf("u.i %d, u.d %g\n", u.i, u.d);

    u.d = 5.25;

    printf("u.i %d, u.d %g\n", u.i, u.d);

    return 0;
}