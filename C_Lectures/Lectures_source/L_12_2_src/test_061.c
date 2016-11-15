#include <stdio.h>

extern int i;

static int i;

int main(void)
{
    printf("%d\n", i);

    return 0;
}
