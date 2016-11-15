/*
Слайд 8, первая часть
*/

#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int *p = &a;    // p теперь указывает на a
    int *q = p;     // q теперь указывает туда же куда и p, т.е. на a

    printf("Address of a = %p, p = %p, q = %p\n", &a, p, q);

    // а можно присвоить новое значение используя и *p, и *q

    *p = 1;
    printf("a = %d\n", a);

    *q = 3;
    printf("a = %d\n", a);

    // не путайте q = p и *q = *p

    p  = &a;
    q  = &b;
    *q = *p;

    printf("p = %p, *p = %d; q = %p, *q = %d\n", p, *p, q, *q);

    return 0;
}