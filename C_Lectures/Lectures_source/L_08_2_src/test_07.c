#include <stdio.h>

int main(void)
{
    {
        int a[10];
        int *pa = a;

        printf("sizeof(a) = %d\n", sizeof(a));

        printf("sizeof(pa) = %d\n", sizeof(pa));
    }

    {
        int a[10];
        int *pa;

        printf("a = %p, &a = %p\n", a, &a);

        // warning: assignment from incompatible pointer type [enabled by default]
        pa = &a;
    }

    {
        char a[] = "abcdef";

        printf("sizeof(a) = %d\n", sizeof(a));
    }

    return 0;
}