#include <stdio.h>

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void test(void)
{
    long double test = 0.0;

    for(unsigned long long i = 0; i < 10000; i++)
        test += 0.5;
}

#define N 5

int main(void)
{
    unsigned long long tb, te;

    tb = tick();
    for(int i = 0; i < N; i++)
        test();
    te = tick();

    printf("test 'time': %llu\n", (te - tb) / N);

    return 0;
}