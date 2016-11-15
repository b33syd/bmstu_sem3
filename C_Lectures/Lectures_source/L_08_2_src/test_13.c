/*
Слайд 21
*/

#include <stdio.h>

int str_len(const char *str)
{
    const char *pbeg = str, *pend = str;

    while (*pend)
        pend++;

    return pend - pbeg;
}

int main(void)
{
    char *pa = "Test";
    char *pb = "T";
    char *pc = "";

    printf("\"%s\" %d\n", pa, str_len(pa));
    printf("\"%s\" %d\n", pb, str_len(pb));
    printf("\"%s\" %d\n", pc, str_len(pc));

    return 0;
}