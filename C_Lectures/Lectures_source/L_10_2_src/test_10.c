/*
Слайд 10
*/

#include <stdio.h>

int main(void)
{
    const char c = 'x';		/* 1 */
    char *p1;			/* 2 */
    // warning: initialization from incompatible pointer type
    const char **p2 = &p1;	/* 3 */
    *p2 = &c;			/* 4 */
    *p1 = 'X';			/* 5 */
}