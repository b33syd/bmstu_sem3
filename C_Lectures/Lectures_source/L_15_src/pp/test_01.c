#include <stdio.h>


#define PRINT_INT(n) printf(#n " = %d\n", n)


// ������ � ������ ������ ������ ��������� �� �����!
#define WRONG(n) printf(#(n))


int main(void)
{
    int a = 5, b = 3;

    PRINT_INT(a);

    PRINT_INT(b);

    PRINT_INT(a + b);

    return 0;
}
