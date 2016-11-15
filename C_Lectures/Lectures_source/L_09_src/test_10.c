/*
Слайд 14
*/

#include <string.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    FILE *f;
    char str[10];

    if (argc < 2)
        return -1;

    f = fopen(argv[1], "r");
    if (f)
    {
        while (fgets(str, sizeof(str), f))
            puts(str);
            /*
            printf("%s", str);
            */

        fclose(f);
    }

    return 0;
}