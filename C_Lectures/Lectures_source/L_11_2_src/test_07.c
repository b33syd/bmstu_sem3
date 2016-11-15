#include <stdio.h>


struct s_t
{
    int i;
    double d;
};


union u_t
{
    int i;
    double d;
};


int main(void)
{
    struct s_t s   = {1, 5.25};

    union u_t  u_1 = {1};
    union u_t  u_2 = { .d = 5.25 };     // c99 only

    /*
    // error: excess elements in union initializer
    union u_t  u_3 = {1, 5.25};
    */

    printf("%d %f\n", s.i, s.d);

    printf("%d\n", u_1.i);
    printf("%f\n", u_2.d);


    return 0;
}