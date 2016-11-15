/*
Слайды 17-19
*/

#include <stdlib.h>


double* get_array_1(int *n)
{
    *n = 0;      // ?

    //
    // определить количество элементов
    //

    int nmemb = 5;

    //
    // выделить память
    //

    double *p = NULL;


    if (nmemb)
    {
        p = malloc(nmemb * sizeof(double));

        if (p)
            *n = nmemb;
    }

    return p;

    // Возвращает NULL, если произошла ошибка
}


int get_array_2(double **data, int *n)
{
    int rc = 0;

    *n = 0;             // ?
    *data = NULL;       // ?

    //
    // определить количество элементов
    //

    int nmemb = 5;

    //
    // выделить память
    //

    if (!rc && nmemb)
    {
        *data = malloc(nmemb * sizeof(double));

        if (*data)
            *n = nmemb;
        else
            rc = -1;    // ошибка выделения памяти
    }

    return rc;
}


int main(void)
{
    double *p_1;
    double *p_2;
    int n_1;
    int n_2, rc;

    p_1 = get_array_1(&n_1);

    rc = get_array_2(&p_2, &n_2);

    (void) rc;

    free(p_1);
    free(p_2);

    return 0;
}