/*
Слайд 21
*/

#include <stdlib.h>

int main(void)
{
    double *data;
    int n = 3, m = 2;

    data = malloc(n * m * sizeof(double));
    if (data)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                // Обращение к элементу i, j
                data[i*m +j] = 0.0;

        free(data);
    }

    return 0;
}