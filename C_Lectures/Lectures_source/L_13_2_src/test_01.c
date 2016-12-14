/*
К слайду 8
*/

#include <stdio.h>

int main(void)
{
    struct
    {
        char a;
        int b;
    } c1;

    #pragma pack(push, 1)
    struct
    {
        char a;
        int b;
    } c2;
    #pragma pack(pop)

    printf("sizeof(c1) = %d\n", sizeof(c1));
    printf("&c1 %p, &c1.a %p\n", &c1, &c1.a);

    printf("sizeof(c2) = %d\n", sizeof(c2));
    printf("&c2 %p, &c2.a %p\n", &c2, &c2.a);

    return 0;
}