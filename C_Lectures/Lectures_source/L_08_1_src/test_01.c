#include <stdio.h>

#define N 10

int main(void)
{
    int a[N];
    int n;
    int sum;

    do
    {
        printf("Input n (1 <= n <= %d): ", N);
        scanf("%d", &n);
    }
    while (n < 1 || n > N);

    printf("Input elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    printf("Summa of {");
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n-1) ? '}' : ',');

    printf(" is %d\n", sum);

    return 0;
}