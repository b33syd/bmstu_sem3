
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define ERROR_OPEN_INPUT_FILE -1
#define ERROR_OPEN_OUTPUT_FILE -20
#define ERROR_LENGTH -2

#define ERROR_ARG -4
#define OK 0

#define DEBUG 10

#define YES 1
#define NO 2







int main(int argc, char **argv)
{
	
	int array_length = 0;
	int *array=NULL;
    int *filtered=NULL;
    int *filtered_end=NULL;
    int *array_end=NULL;
    int filter_flag=NO;

	int status_work = OK;

	FILE *file;

	if (argc < 4)
	{

		status_work = ERROR_ARG;
	} 
    else
	{
		file = fopen(argv[1], "r");

		if (file == 0)
		{
			status_work = ERROR_OPEN_INPUT_FILE;
		} 
        if(!strcmp(argv[2],"YES")) filter_flag=YES;
       


	}
	
	if (status_work == OK)
	{		
		status_work = read_file(&array, &array_length, file);
	    fclose(file);	
		if (status_work == OK)
		{
			//count end poiner
			array_end = array + array_length;	
			printf("Orinal array:\n");
            printarray(array, array_end);
			
            if(filter_flag==YES)
            {
                status_work = filter(array, array_end, &filtered, &filtered_end);;
			    printf("Filtered array:\n");
		        printarray(filtered, filtered_end);
            }
            else
            {
                filtered=array;
                filtered_end=array_end;
            }

			testing(filtered, filtered_end, 0);
			testing(filtered, filtered_end, 1);
        
            mod_insertion_sort(filtered, filtered_end - filtered, sizeof(int), compare_int_less);
            printf("Sorted array:\n");

            printarray(filtered, filtered_end);

            
            file = fopen(argv[3], "w");
            if (file == 0)
                status_work = ERROR_OPEN_OUTPUT_FILE;
            else
            {
                printarray_to_file(filtered, filtered_end, file);
                fclose(file);
            }
		}

	}
    if(array!=NULL)
        free(array);
    
    if(filter_flag==YES)
    {
        if(filtered!=NULL)
            free(filtered);
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
            printf("Unable to open input file.\n");
            break;

	}
    


	return status_work;

}