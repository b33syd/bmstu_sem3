#include <stdio.h>
#include "a.h"

extern double a;


int main(void)
{
    printf("a = %e\n", a);

    f();    

    printf("a = %e\n", a);

    return 0;
}
