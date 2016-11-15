/*
Слайд 16
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello!";
    char str_long[] = "Very very long string...";
    char dst[10];

    strcpy(dst, src);

    printf("strcpy: src [%s], dst [%s]\n", src, dst);

    strncpy(dst, str_long, sizeof(dst) - 1);
    dst[sizeof(dst) - 1] = '\0';

    printf("strncpyt: str_long [%s], dst [%s]\n", str_long, dst);

    return 0;
}