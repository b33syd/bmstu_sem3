/*
Слайд 12, пример 2.2
*/

#include <stdio.h>

int main(void)
{
    int si = -1;
    unsigned int ui = 1;

    // ui = 1 представимо в типе int
    printf("%d\n", si < (int)ui);
}