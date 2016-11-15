/*
Слайд 8
*/

#include <stdio.h>

int main(void)
{
    char str_1[] = {'J', 'u', 'n', 'e', '\0'};
    char str_2[] = "June";

    char str_3[5] = "June";
    /*
    // error: initializer-string for array of chars is too long
    char str_4[3] = "June";
    */
    char str_5[4] = "June";

    printf("str_1: %s\n", str_1);
    printf("str_2: %s (sizeof(str_2) = %d)\n", str_2, sizeof(str_2));
    printf("str_3: %s\n", str_3);
    printf("str_5: %s\n", str_5);

    return 0;
}