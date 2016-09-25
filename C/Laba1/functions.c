#include <stdio.h>
#include "functions.h"

void count_file_length(int *array_length, FILE *file)
{
    int temp;
    while ((fscanf(file, "%d", &temp) != eof))
        *array_length = *array_length + 1;
}

void readfromfile(int *array_st, int *array_end, FILE *file)
{
    for (; array_st < array_end; array_st++)
    {
        fscanf(file, "%d", array_st);
    }
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