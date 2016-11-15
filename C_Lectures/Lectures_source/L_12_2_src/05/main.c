#include <stdio.h>
#include "a.h"


int main(void)
{
    extern int a;


    printf("a = %d\n", a);

    f();

    printf("a = %d\n", a);

    return 0;
}
