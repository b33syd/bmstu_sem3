/*
����� 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));

    if (!p)
        return -1;

    *p = 5;   

    printf("%p %d\n", p, *p);	// ����� 5

    free(p);

    printf("%p\n", p);  	// ����� (!)
    printf("%d\n", *p); 	// ������ ������� ����������

    return  0;
}
