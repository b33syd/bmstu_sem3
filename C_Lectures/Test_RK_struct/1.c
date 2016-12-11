#include <stdio.h>
#include <string.h>

struct test
{
    char str[20];
};

int main(void)
{
    struct test st1, st2;

    strcpy(st1.str, "Programming");
    st2 = st1;
    st1.str[0] = 'S';
    printf("%s", st2.str);

    return 0;
}
