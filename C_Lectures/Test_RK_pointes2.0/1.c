#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[2][2] = {{12}, {14,16}};
	int (*ptr)[2] = arr;
	printf("%d,%d",**ptr,**(ptr+1));

}
