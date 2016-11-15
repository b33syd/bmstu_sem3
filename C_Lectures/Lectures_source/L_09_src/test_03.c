/*
Слайд 3 (зачем может понадобиться выражение "abc"[1])
*/

#include <stdio.h>
#include <assert.h>

char digit_to_hex_char(int digit)
{
    assert(digit >= 0 && digit < 16);

    return "0123456789abcdef"[digit];
}

int main(void)
{
    for (int i = 0; i < 16; i++)
        printf("dec %2d, hex %c\n", i, digit_to_hex_char(i));

    return 0;
}
