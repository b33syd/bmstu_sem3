#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


#define FAILED -1;

#define OK 0


int test_count_file_length(const char *patch, const int answer)
{
    int array_length = 0;
    FILE * file = fopen(patch, "r");

    count_file_length(&array_length, file);
    fclose(file);

    if (array_length == answer)
        return OK;
    else
        return FAILED;
}

int test_readfromfile(const char *patch, const int array_length, int *control_array)
{
    int status = OK;

    FILE * file = fopen(patch, "r");

    //create array
    int *array;
    array = malloc(array_length * sizeof(int));

    if (array != NULL)
    {
        int *p_end;
        //count end poiner
        p_end = array + array_length;
        status = readfromfile(array, p_end, file);

        for (int i = 0; i < array_length; i++)
        {
            if (array[i] != control_array[i])
            {
                status = FAILED;
                break;
            }
        }
    }
    else
    {
        status = FAILED;
    }

    fclose(file);
    free(array);

    return status;
}

int test_seach_max_pair(int *array, const int array_length, const int answer)
{
    int *p_end;
    p_end = array + array_length;

    int max = seach_max_pair(array, p_end);

    if (max == answer)
        return OK;
    else
        return FAILED;
}

char *answer(int val)
{
    char *answer = "FAILED";
    if (val == OK)
        answer = "OK";
    return answer;
}

int main()
{
    printf("test count_file_length 1 %s\n", answer(test_count_file_length("tests/empty_file", 0)));
    printf("test count_file_length 2 %s\n", answer(test_count_file_length("tests/normal", 15)));

    int control_array1[6] = { 1000, 1, 2, 3, 4, 5 };
    printf("test readfromfile 1 %s\n", answer(test_readfromfile("tests/first_max", 6, control_array1)));

    int array1[6] = { 1000, 1, 2, 3, 4, 5 };
    printf("test seach_max_pair 1 %s\n", answer(test_seach_max_pair(array1, 6, 1005)));

    int array2[6] = { 5, 1, 2, 3, 4, 1000 };
    printf("test seach_max_pair 2 %s\n", answer(test_seach_max_pair(array2, 6, 1005)));

    int array3[6] = { 1, 2, 3, 3, 2, 1 };
    printf("test seach_max_pair 3 %s\n", answer(test_seach_max_pair(array3, 6, 6)));

    int array4[5] = { 1, 2, 100, 2, 1 };
    printf("test seach_max_pair 4 %s\n", answer(test_seach_max_pair(array4, 5, 100)));

    int array5[15] = { 1, 2, 3, 4, 5, 6, 7, 4, 4, 4, 4, 4, 3, 2, 1 };
    printf("test seach_max_pair 5 %s\n", answer(test_seach_max_pair(array5, 15, 11)));

    return 0;
}