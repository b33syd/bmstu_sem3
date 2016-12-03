#include <stdio.h>
#include <string.h>

int main(void)
{
    char str_a[40] = "e is ";
    char str_b[40] = "My nam";
    const char *quote = "Yummy.";

    strcat(str_a, quote);
    strcat(str_b, str_a);

    puts(str_b);

    return 0;
}
