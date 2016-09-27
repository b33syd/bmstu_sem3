#include <stdio.h>
#include "functions.h"

#define BAD_READ -10
#define OK 0

void count_file_length(int *array_length, FILE *file)
{
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

int seach_max_pair(int *p_start, int *p_end)
{
    //change pointer to last element
    p_end--;
    int max = *p_start + *p_end;

    while (p_start <= p_end)
    {
        //even number of elements
        if (max < (*p_start + *p_end) && (p_start != p_end))
        {
            max = *p_start + *p_end;
        }

        //uneven number of elements
        if (max < (*p_start) && (p_start == p_end))
        {
            max = *p_start;
        }

        //change pointers
        p_start++;
        p_end--;
    }

    return max;
}
