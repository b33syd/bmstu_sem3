/*
Слайд 10.
*/

#include <stdio.h>

int main(void)
{
    char arr_1[][9] = {"January", "February", "March"};

    /*const*/ char *arr_2[] = {"January", "February", "March"};

    for (int i = 0; i < 3; i++)
        printf("%s\n", arr_1[i]);

    for (int i = 0; i < 3; i++)
        printf("%s\n", arr_2[i]);

    return 0;
}
