/*
К слайдам 27 - 29
*/

#include <stdio.h>

int main(void)
{
    {
        unsigned char a    = 0x46;  // 01000110b
        unsigned char b    = 0x44;  // 01000100b
        unsigned char mask = 0x06;  // 00000110b

        printf("a & mask %x, res %d\n", a & mask, (a & mask) == mask);
        printf("b & mask %x, res %d\n", b & mask, (b & mask) == mask);
    }

    {
        unsigned char a      = 0x46;  // 01000110b
        unsigned char mask_1 = 0xbf;  // 10111111b
        unsigned char mask_2 = 0xf9;  // 11111001b

        printf("a & mask_1 %x\n", a & mask_1);
        printf("a & mask_2 %x\n", a & mask_2);
    }

    {
        unsigned char a      = 0x40;  // 01000000b
        unsigned char mask_1 = 0x06;  // 00000110b
        unsigned char mask_2 = 0x44;  // 01000100b

        printf("a | mask_1 %x\n", a | mask_1);
        printf("a | mask_2 %x\n", a | mask_2);
    }

    {
        unsigned char a      = 0x46;  // 01000110b
        unsigned char mask_1 = 0x44;  // 01000100b
        unsigned char mask_2 = 0xFF;  // 11111111b

        printf("a ^ mask_1 %x\n", a ^ mask_1);
        printf("a ^ mask_2 %x\n", a ^ mask_2);
    }

    {
        unsigned char a = 0xFF;  // 11111111b

        printf("a >> 1 = %2x\n", a >> 1);
        printf("a >> 4 = %2x\n", a >> 4);
    }

    {
        unsigned char a = 0x01;  // 00000001b

        printf("a << 1 = %2x\n", a << 1);
        printf("a << 4 = %2x\n", a << 4);
    }
}