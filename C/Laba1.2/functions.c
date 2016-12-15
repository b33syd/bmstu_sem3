#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


#define BAD_READ -10
#define OK 0


unsigned long long tick(void)
{
	unsigned long long d;
	__asm__ __volatile__ ("rdtsc" : "=A" (d));
	return d;
}

void count_file_length(int *array_length, FILE *file)
{
	*array_length = 0;
	int temp;
	while ((fscanf(file, "%d", &temp) != EOF))
		*array_length = *array_length + 1;
}

int readfromfile(int *array_st, int *array_end, FILE *file)
{
	for (; array_st < array_end; array_st++)
	{
		if (fscanf(file, "%d", array_st) != 1)
		{
			return BAD_READ;
		}
	}
	return OK;
}

//Checked
int filer_summ(const int *array, const int *array_end)
{
	int full_summ = 0;

	//printf("filer_summ-->\n");

	if ((array_end - array) < 0)
	{
		//printf("BAD POINTERS in filer_summ exit, %p  %p\n",array,array_end);
		return BAD_POINTERS;
	}

	while (array != array_end)
	{
		full_summ += *array;
		array++;
	}

	//printf("filer_summ exit with: %d\n",full_summ);
	return full_summ;
}

//Checked
int filter_counter(const int *array, const int *array_end, int full_summ)
{
	//printf("filter_counter-->\n");
	int k = 0;

	while (array != array_end)
	{
		full_summ -= *array;
		if (full_summ < *array)
			k++;
		array++;
	}

	//printf("filter_counter exit with: %d\n",k);
	return k;
}

//Checked
int filter_newarray(const int *array, const int *array_end, int *filtered, int *filtered_end, int full_summ)
{
	while ((array != array_end) && (filtered_end != filtered))
	{
		full_summ -= *array;
		if (full_summ < *array)
		{
			*filtered = *array;
			//printf("COPIED %d , %d\n",*filtered, *array );
			filtered++;
		}
		array++;
	}
	//printf("ex\n");
	if (filtered_end != filtered)
		return ERROR_LENGTH;
	else
		return OK;
}

//Checked
int filter(const int *array, const int *array_end, int **filtered, int **filtered_end)
{
	int status_work = OK;
	int full_summ = filer_summ(array, array_end);
	int k = filter_counter(array, array_end, full_summ);

	*filtered = (int *) malloc(k * sizeof(int));


	if (*filtered != NULL)
	{
		*filtered_end = *filtered + k;
		filter_newarray(array, array_end, *filtered, *filtered_end, full_summ);
	} 
    else
	{
		status_work = ERROR_MALLOC;
	}
	return status_work;

}

//Checked
void printarray(const int *array, const int *array_end)
{
	//debug("9",6);
	while (array != array_end)
	{
		printf("%d ", *array);
		array++;
	}
	printf("\n");
}

void printarrayd(const double *array, int n)
{
    while (n!=0)
    {
        printf("%lf ", *array);
        array++;
        n--;
    }
    printf("\n");
}


int compare_double_less(const void *val1, const void *val2)
{
    double *a = (double *) val1;
    double *b = (double *) val2;
    //printf("EEEEEEEEEEEEEE %lf  %lf\n", *b , *a);
    return *a - *b;
}



int compare_int_less(const void *val1, const void *val2)
{
    int *a = (int *) val1;
    int *b = (int *) val2;
    //printf("EEEEEEEEEEEEEE %d  %d\n", *b , *a);
	return *a - *b;
}

void *bin_search(const void *arr, const void *arr_end, const void *value, const int size,
                                 int (*comparator)(const void *, const void *))
{   char *array = (char*) arr;
    char *array_end = (char*) arr_end;
    char *val = (char*) value;


	int n = 0;
	char *med;

    
    while (array != array_end)
    {
        n = (array_end - array) / size;
        med = array + n / 2 * size;
		if ( comparator(med, val) < 0)
			array = med + size;
		else
			array_end = med;
	}
	return (void*)array;
}


void mod_insertion_sort(void *adr, const size_t nmemb, const size_t size_of_el,
						int (*comparator)(const void *, const void *))
{
	char *array = (char *) adr;
	char *tmp = malloc(size_of_el);
	char *pos;

	while (array != adr + size_of_el * nmemb)
	{
		memcpy(tmp, array, size_of_el);

        
		pos = bin_search(adr, array, tmp, size_of_el, comparator);
		memmove(pos + size_of_el, pos, array - pos);
		memcpy(pos, tmp, size_of_el);

		array = array + size_of_el;
		
	}

	free(tmp);
}

int testing(const int *a_st, const int *a_end, const int sort_t)
{

    unsigned long long t_st, t_end, full_time = 0;
    int size = a_end - a_st;

    if (sort_t == 0)
    {
        printf("\nМодифицированная сортировка вставками с бин. поиском\n\n");
    }
    else
    {
        printf("\nВстроенная быстрая сортировка сортировка\n\n");
    }

    for (int i = 0; i < N; ++i)
    {
        int *filtered = malloc(sizeof(int) * size);
        int *filtered_end = filtered + size;

        memcpy(filtered, a_st, size * sizeof(int));

        if (sort_t == 0)
        {
            t_st = tick();
            mod_insertion_sort(filtered, size, 4, compare_int_less);
            t_end = tick();
        } 
        else
        {
            t_st = tick();
            qsort(filtered, size, 4, &compare_int_less);
            t_end = tick();
        }


        printf("test  %d 'time': \t%llu\n", i, (t_end - t_st));
        full_time = full_time + (t_end - t_st);

        free(filtered);

    }

    printf("\nAverage  time : \t%llu\n", full_time / N);
}





int read_file(int **array, int *array_length, FILE *file)
{
    *array_length = 0;
    int status_work = OK;
    
    count_file_length(array_length, file);
    rewind(file);
    

    if (*array_length == 0)
    {
        status_work = ERROR_LENGTH;
    } 
    else
    {
        //create array
        *array = malloc(*array_length * sizeof(int));
        if (*array != NULL)
        {
            int *p_end;
            //count end poiner
            p_end = *array + *array_length;

            status_work = readfromfile(*array, p_end, file);
        } else
        {
            status_work = ERROR_MALLOC;
        }
    }

    return status_work;
}

void printarray_to_file(const int *array, const int *array_end, FILE *file)
{
    while (array != array_end)
    {
        fprintf(file, "%d ", *array);
        array++;
    }
}