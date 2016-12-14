#include <stdio.h>

int func_1(int a)
{
	int b = a + 10;

	printf("%d\n", b);

	return b;
}

int main(void)
{
	int a = 5, rc;

	rc = func_1(a);

	return 0;
}