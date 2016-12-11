#include <stdio.h>

int main(void)
{
    struct site
    {
        char name[] = "Programming";
        int no_of_pages = 200;
    };
    struct site *ptr;
    printf("%d ", ptr->no_of_pages);
    printf("%s", ptr->name);

    return 0;
}
