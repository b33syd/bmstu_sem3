
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define ERROR_OPEN_INPUT_FILE -1
#define ERROR_LENGTH -2

#define ERROR_ARG -4
#define OK 0

#define DEBUG 5

void debug(char* str,int lev)
{
    if(lev>DEBUG)
        printf("DEBUG MESS %s\n",str);
}



int read_file(int **array, int *array_length, FILE *file)
{	

    debug("1",6);
    *array_length = 0;
    int status_work = OK;
    debug("2",6);
    count_file_length(array_length, file);
    debug("3",6);

    rewind(file);
    debug("4",6);

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
            debug("5",6);
            status_work = readfromfile(*array, p_end, file);
        }
        else 
        {
            status_work = ERROR_MALLOC;
        }
    }
    return status_work;
    debug("6",6);
}

void printarray_to_file(int *array, int *array_end,FILE *file)
{
    debug("7",6);
    while(array!=array_end)
    {
        fprintf(file,"%d ", *array);
        array++;
    }

}











int main(int argc, char **argv)
{	
	debug("10",6);
    int array_length = 0;
    int *array;

    int status_work = OK;
    
    FILE * file;
    
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
    debug("11",6);

    if (status_work == OK) 
    {            
    	debug("12",6);
        status_work = read_file(&array, &array_length, file);     
        debug("13",6);

        if (status_work == OK)
        {
            int *array_end;
            //count end poiner
            array_end = array + array_length;
            debug("14",6);
            printarray(array,array_end);
            /*debug("15",6);
            
            int *filtered;
            int *filtered_end;
            
            debug("16",6);
            status_work=filter(array, array_end,&filtered,&filtered_end);;
            debug("17",6);
            printarray(filtered,filtered_end);
            debug("18",6);
            */
            mod_insertion_sort(array, array_end);

            debug("17",6);
            printarray(array, array_end);
            debug("18",6);


        }    

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
        
    }

    return status_work;

}