#include <stdio.h>

/*static*/ int i;

void f1(void)
{
    i = 1;
}

void f5(void)
{
    i = 5;
}

int main(void)
{
    printf("1) i = %d\n", i);

    f1();

    printf("2) i = %d\n", i);

    f5();

    printf("3) i = %d\n", i);

    return 0;
}
