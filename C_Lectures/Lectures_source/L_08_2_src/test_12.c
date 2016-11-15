/*
Слайд 20
*/

#include <stdio.h>

int main(void)
{
    int a[10];
    int *pa = &a[0], *pb = &a[2];

    printf("%d\n", pb - pa);
    printf("%d\n", pa - pb);

    return 0;
}