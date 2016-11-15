#include <stdio.h>
#include "a.h"


void g(void)
{
    printf("Another g\n");
}


int main(void)
{
    printf("f return %d\n", f(5));    

    printf("h return %d\n", h(5));

    g();

    return 0;
}
