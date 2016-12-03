#include <stdio.h>

int main(void)
{
    int a[] = {0, 1, 2, 3, 4};

    int *p[] = {a, a+1, a+2, a+3, a+4};

    int **pp=p;

    printf("%d %d\n", a, *a);
    // Ответ


    printf("%d %d %d\n", p, *p, **p);
    // Ответ


    printf("%d %d %d\n", pp, *pp, **pp);
    // Ответ


    pp++;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    *pp++;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    *++pp;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    ++*pp;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    pp=p;

    **pp++;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    *++*pp;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    ++**pp;

    printf("%d %d %d\n", pp-p, *pp-a, **pp);
    // Ответ


    return 0;
}
