//VARIANT1

#include "func.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_INPUT_FILE -1
#define ERROR_LENGTH -2
#define ERROR_MALLOC -3
#define ERROR_ARG -4
#define ERROR_OPEN_OUTPUT_FILE -5
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

    int *original_array;
    int *copy_of_array;
    int size_of_array=0;
    int status_work=OK;


     FILE* file;
       //try to open file
       //
       if (argc < 3)
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
           status_work = read_file(&original_array, &size_of_array, file);
            fclose(file);
           if (status_work == OK)
           {
               copy_of_array=malloc(sizeof(int)*size_of_array);
               copyarray(original_array,copy_of_array,size_of_array);

               int new_len=worker( copy_of_array,size_of_array);

               printf("Original array: ");
               printarray(original_array,size_of_array);

               printf("Fixed array:  ");
               printarray(copy_of_array,new_len);

               file = fopen(*++argv, "w");
               if (file == 0)
               {
                   status_work = ERROR_OPEN_OUTPUT_FILE;
               }
               else
               {
                printarray_to_file(copy_of_array,new_len,file);

                fclose(file);

               }


           }







            free(copy_of_array);
            free(original_array);
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
            case (ERROR_OPEN_OUTPUT_FILE):
           printf("Unable to open output file.\n");
           break;
       }












    return 0;
}
