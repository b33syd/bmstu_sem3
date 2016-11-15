/*
Слайд 5
*/


#include <stdio.h>
#include <assert.h>


int get_max(const int *a, int n)
{
    assert(n);

    int max = a[0];

    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];

    return max;
}


#define N 2
#define M 3


int main(void)
{
    int a[N][M] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("max = %d\n", get_max(&a[0][0], N * M));

    /*
    // warning: passing argument 1 of 'get_max' from incompatible pointer type
    printf("max = %d\n", get_max(a, N * M));
    */

    printf("max = %d\n", get_max(a[0], N * M));
             
    return 0;
}