/*
Слайд 9
*/

#include <stdio.h>

int main(void)
{
    char str_arr[] = "June";
    char *str_ptr  = "June";

    printf("str_arr: %s\n", str_arr);
    printf("str_ptr: %s\n", str_ptr);

    str_arr[0] = 'j';
    printf("str_arr: %s\n", str_arr);

    str_ptr[0] = 'j';
    printf("str_ptr: %s\n", str_ptr);

    return 0;
}