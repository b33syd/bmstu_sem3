/*
Слайд 12
*/

#include <stdio.h>

int main(void)
{
    int n;

    printf("n: ");
    scanf("%d", &n);

    int a[n];

    printf("sizeof(a) = %d\n", sizeof(a));

    for (int i = 0; i < n; i++)
        a[i] = i;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
