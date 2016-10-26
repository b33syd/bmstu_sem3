#include <stdio.h>
#include "functions.h"

#define BAD_READ -10
#define OK 0

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

int seach_max_pair(const int *p_start, const int *p_end, int *max)
{
    if (p_end ==p_start)
        return  ERROR_LENGTH;

    //change pointer to last element
    p_end--;
    *max = *p_start + *p_end;

    while (p_start < p_end)
    {
        //even number of elements
        if (*max < (*p_start + *p_end))
        {
            *max = *p_start + *p_end;
        }

        //change pointers
        p_start++;
        p_end--;
    }
    //uneven number of elements
    if (*max < (*p_start) && (p_start == p_end))
    {
        *max = *p_start;
    }

    return OK;
}
