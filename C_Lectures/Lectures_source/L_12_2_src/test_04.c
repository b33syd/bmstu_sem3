/*
Слайд 23
*/


#include <stdio.h>


void f(int a)
{
    static int counter = 20;
    int b = 5;

    counter++;

    printf("a = %d, b = %d, counter = %d\n", a, b, counter);
}


int main(void)
{
    f(3);
    f(7);
    f(5);

    return 0;
}
