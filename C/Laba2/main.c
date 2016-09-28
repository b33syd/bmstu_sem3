#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define ERROR_ARG -1
#define ERROR_OPEN_INPUT_FILE -2
#define ERROR_OPEN_OUTPUT_FILE -4
#define OK 0



int main(int argc, char **argv)
{
    //valueber of run-time errors
    int status_work = OK;

    if (argc < 4)
    {
        status_work = ERROR_ARG;
    }
    else
    {
        struct list *head = NULL, *even = NULL, *odd = NULL;

        FILE * file1 = fopen(argv[1], "r");
        if (file1 == 0)
        {
            status_work = ERROR_OPEN_INPUT_FILE;
        }
        else
        {
            status_work = read_list_from_file(&head, file1);

            fclose(file1);

            if (status_work == OK)
                status_work = distributor(head, &even, &odd);

            
            FILE * file2 = fopen(argv[2], "w");
            if ((file2 == 0) && (status_work == OK))
            {
                status_work = ERROR_OPEN_OUTPUT_FILE;
            }
            else
            {
                print_to_file(even, file2);
                fclose(file2);
            }

            FILE * file3 = fopen(argv[3], "w");
            if ((file3 == 0) && (status_work == OK))
            {
                status_work = ERROR_OPEN_OUTPUT_FILE;
            }
            else
            {
                print_to_file(odd, file3);
                fclose(file3);
            }            
        }

        free_all(head);
        free_all(even);
        free_all(odd);

        head = NULL;
        even = NULL;
        odd = NULL;
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

    return status_work;
}
