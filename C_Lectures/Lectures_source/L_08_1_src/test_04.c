#include <stdio.h>

#define N 10

int sum_array(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int main(void)
{
    int a[N];
    int n;

    do
    {
        printf("Input n (1 <= n <= %d): ", N);
        scanf("%d", &n);
    }
    while (n < 1 || n > N);

    printf("Imput elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Summa of {");
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n-1) ? '}' : ',');

    printf(" is %d\n", sum_array(a, n));

    return 0;
}