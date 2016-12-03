#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[2][2] = {12, 14,16};
	int *ptr = arr[0];
	printf("%d,%d",*ptr,*(ptr+2));

}
