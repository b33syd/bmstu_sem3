#include <stdio.h>
struct st
{
    int x;
    static int y;
};

int main(void)
{
    printf("%d", sizeof(struct st));
    return 0;
}
