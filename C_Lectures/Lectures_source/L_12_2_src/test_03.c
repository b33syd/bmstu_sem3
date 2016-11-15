/*
Слайд 20
*/

#include <stdio.h>

/*
auto int d;

// error: file-scope declaration of 'd' specifies 'auto'
*/


void f(void)
{
    auto int c = 3;
    /*
    auto static int e;

    // error: multiple storage classes in declaration specifiers
    */

    printf("c = %d\n", c);
}


int main(void)
{
    int a = 1;
    auto int b = 2;

    printf("a = %d, b = %d\n", a, b);

    f();

    return 0;    
}