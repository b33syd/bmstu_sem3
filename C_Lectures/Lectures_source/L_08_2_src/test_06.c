/*
Слайды 10, 11
*/

#include <stdio.h>

int main(void)
{
    {
        // Указатель на константу

        int a = 5;
        int b = 7;
        const int *p = &a;

        printf("%d\n", *p);
        /*
        // error: assignment of read-only location '*p'
        *p = 4;
        */
        p = &b;
    }

    {
        // Константный указатель

        int a = 5;
        int b = 7;
        int *const p = &a;

        printf("%d\n", *p);
        *p = 4;
        printf("%d\n", *p);
        /*
        // error: assignment of read-only variable 'p'
        p = &b;
        */
    }

    {
        // Константный указатель на константу

        int a = 5;
        int b = 7;
        const int *const p = &a;

        printf("%d\n", *p);
        /*
        // error: assignment of read-only location '*p'
        *p = 4;
        */
        printf("%d\n", *p);
        /*
        // error: assignment of read-only variable 'p'
        p = &b;
        */
    }

    return 0;    
}