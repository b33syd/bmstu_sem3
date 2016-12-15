#include "functions.h"
#define GOOD 0
#define BAD 11
#define EPS 0.001
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define STR_LEN 50
#define N 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void test_speed(const int *a_st, const int *a_end)
{

 	unsigned long long t_st, t_end, full_timemod = 0,full_timeqsort = 0;
    int size = a_end - a_st;
  
    for (int i = 0; i < N; ++i)
    {
        int *filtered = malloc(sizeof(int) * size);
        int *filtered_end = filtered + size;

        memcpy(filtered, a_st, size * sizeof(int));  
        t_st = tick();
        mod_insertion_sort(filtered, size, 4, compare_int_less);
        t_end = tick(); 
       
        full_timemod = full_timemod +  (t_end - t_st);
       
        free(filtered);

    }
    for (int i = 0; i < N; ++i)
    {
        int *filtered = malloc(sizeof(int) * size);
        int *filtered_end = filtered + size;

        memcpy(filtered, a_st, size * sizeof(int));       
        t_st = tick();
        qsort(filtered, size, 4, compare_int_less);
        t_end = tick(); 
      
        full_timeqsort = full_timeqsort+ (t_end - t_st);

        free(filtered);

    }

    //if((full_timeqsort/N<846138100000)&&(full_timemod/N<846138100000))
    	printf("%d \t%llu  \t%llu\n", a_end-a_st, full_timemod / N,full_timeqsort/N );
}    


int main(int argc, char const *argv[])
{

	int* arr=malloc(10000*sizeof(4));
	
	printf("5000\n");
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=5000;
	}

	for (int i = 10000; i >1; i-=i/2)
	{
		test_speed(arr,arr+i);
	}

	printf("1-4\n");
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=i;
	}

	for (int i = 10000; i >1; i-=i/2)
	{
		test_speed(arr,arr+i);
	}


	printf("4-1\n");
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=10000-i;
	}

	for (int i = 10000; i >1; i-=i/2)
	{
		test_speed(arr,arr+i);
	}


	printf("rand\n");
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=rand();;
	}

	for (int i = 10000; i >1; i-=i/2)
	{
		test_speed(arr,arr+i);
	}


	/*//test_speed(arr,arr+10000);



	printf("4-3-2-1\n");
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=10000-i;
	}



	printf("50000\n");
	for (int i = 0; i < 10000; ++i)
	{
		arr[i]=5000;
	}	
*/

	
	return 0;
}