#include "func.h"

#include <stdio.h>
#include <stdlib.h>

#define BAD_READ -1
#define OK 0
int fibonachi(int one, int second)
{
    return one+second;
}

int search_fib_pair(int value)
{
    int one=1;
    int second=1;
    int temp=0;
    while(second<value)
    {
        temp=one;
        one=second;
        second=fibonachi(temp,second);
    }

    if(second==value)
        return 0;
    else
        return 1;

}

void move_part_array(int *array,int pos_for_remove,int n)
{
    for(int i=pos_for_remove; i<n-1;i++)
    {
        array[i]=array[i+1];
    }
    array[n-1]=0;
}

void copyarray(int *array_from_read,int *array_to_save, int array_len)
{
    for(int i=0; i<array_len;i++)
        array_to_save[i]=array_from_read[i];
}


void printarray(int *array, int array_len)
{

    for(int i=0; i<array_len;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printarray_to_file(int *array, int array_len,FILE *file)
{

    for(int i=0; i<array_len;i++)
    {

        fprintf(file,"%d ", array[i]);

    }
    printf("\n");
}


int worker(int *array_to_save, int array_len)
{
    for(int i=0; i<array_len;i++)
    {
        if(search_fib_pair(array_to_save[i])==0)
        {
            move_part_array(array_to_save, i,array_len);
            array_len--;
            i--;
        }
    }
    return array_len;
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




