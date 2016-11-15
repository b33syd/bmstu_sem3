/*
Слайды 17 - 19
*/

#include <stdio.h>

#define N 10

float sum_1(const float* a, int n)
{
    float sum = 0.0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

float sum_2(const float* pb, const float* pe)
{
    float sum = 0.0;

    for (const float* pcur = pb; pcur < pe; pcur++)
        sum += *pcur;

    return sum;
}

float sum_3(const float* pb, const float* pe)
{
    float sum = 0.0;
    const float* pcur = pb;

    while (pcur < pe)
        sum += *pcur++;

    return sum;
}

float sum_4(const float* pb, const float* pe)
{
    float sum = 0.0;

    while (pb < pe)
    {
        sum += *pb;
        pb++;
    }

    return sum;
}

int main(void)
{
    float a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    size_t n = sizeof(a) / sizeof(a[0]);

    printf("1. %4.2f\n", sum_1(a, n));
    printf("2. %4.2f\n", sum_2(a, a + n));
    printf("3. %4.2f\n", sum_3(a, a + n));
    printf("4. %4.2f\n", sum_4(a, a + n));

    return 0;
}


