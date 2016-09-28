#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define ERROR_OPEN_INPUT_FILE -1
#define ERROR_LENGTH -2
#define ERROR_MALLOC -3
#define ERROR_ARG -4
#define OK 0

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
        }
        else 
        {
            status_work = ERROR_MALLOC;
        }
    }
    return status_work;
}


int main(int argc, char **argv)
{
    int array_length = 0;
    int *array;
    int max = 0;

    int status_work = OK;
    
    FILE * file;
    //try to open file
    //
    if (argc < 2) 
    {
        status_work = ERROR_ARG;
    }
    else
    {
        file = fopen(*++argv, "r");

        if (file == 0)
        {
            status_work = ERROR_OPEN_INPUT_FILE;
        }
    }

    if (status_work == OK) 
    {            
        status_work = read_file(&array, &array_length, file);          
        
        if (status_work == OK)
        {       
            int *p_end;
            //count end poiner
            p_end = array + array_length;
            status_work = seach_max_pair(array, p_end, &max);
        }

        fclose(file);
        if (status_work != ERROR_LENGTH)
            free(array);    
    }

    switch (status_work) 
    {
        case (ERROR_MALLOC):
            printf("Can`t malloc memory.\n");
            break;
        case (ERROR_LENGTH):
            printf("Empty file or zero length of the array.\n");
            break;
        case (ERROR_ARG):
            printf("Not enough arguments.\n");
            break;
        case (ERROR_OPEN_INPUT_FILE):
            printf("Unable to open input file.\n");
            break;
        case (OK):
            printf("max %d\n", max);
    }

    return status_work;
}