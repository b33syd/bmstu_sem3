/*
Слайд, 12 пример 2.3
*/

#include <stdio.h>

int main(void)
{
    int si;
    unsigned int ui;

    printf("Input si: ");
    scanf("%d", &si);

    printf("Input ui: ");
    scanf("%u", &ui);

    printf("si %d, ui %u, result of (is < ui) is %d\n", si, ui, (si < 0 || (unsigned) si < ui));
}