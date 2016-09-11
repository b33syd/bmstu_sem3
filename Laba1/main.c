#include <stdio.h>
#define MAX_ARRAY_LENGTH 20
#define FILE_IS_TOO_LARGE 1
#define FILE_IS_NORMAL 0
#define ERROR_ARG -1
#define ERROR_OPEN_INPUT_FILE -2
#define DIVISION_BY_ZERO -3
#define ERROR_OPEN_OUTPUT_FILE -4
#define OK 0

int ReadDataFromFile(double array[], int *array_length, FILE *file)
{
	*array_length=0;
	int status_work=OK;
	printf("01\n");
	while (((fscanf (file, "%lf", &array[*array_length])) != EOF) &&(status_work==OK)) {
		printf("02\n");
		*array_length=*array_length+1;
		if(*array_length>=MAX_ARRAY_LENGTH-1)
			status_work= FILE_IS_TOO_LARGE;
	}
	return status_work; 
}

//calculation of the average value of a real array, output error code
int Average(const double array[], int array_length, double *average)
{
	double summ=0;
	int status_work=OK;

	for (int i =0; i < array_length; ++i)
	{
	 	summ+=array[i];
	}

	if(array_length==0)
	{
		status_work=DIVISION_BY_ZERO;
	}
	else
	{
		*average=summ/array_length;
		status_work= OK;
	}

	return status_work;
}

void CreateArrayBiggerAverage(const double array[],double new_array[],
								 double average, int array_length, int *Newarray_length)
{
	int index=0;

	for (int i=0; i < array_length; ++i)
	{
		if(array[i]>average)
		{
			new_array[index]=array[i];
			index++;
		}	 	
	}
	
	*Newarray_length=index;
}

void  PrintToFile(const double array_of_numbers_bigger_average[],
	int length_array_of_numbers_bigger_average,FILE *file)
{
	for (int i = 0; i < length_array_of_numbers_bigger_average; ++i)
	{
		fprintf(file,"%lf \n", array_of_numbers_bigger_average[i]);
	}
}


/*this_is_variable
 *ThisIsFunction()*/

int main(int argc, char **argv)
{	
	//File size label
	int status_read_from_file=FILE_IS_NORMAL;
	//number of run-time errors 
	int status_work= OK;

	double array_of_all_numbers[MAX_ARRAY_LENGTH];
	int length_array_of_all_numbers=0;
	
	double array_of_numbers_bigger_average[MAX_ARRAY_LENGTH];
	int length_array_of_numbers_bigger_average=0;

	double average=0;


	/*check the number of arguments
	 *	1) program name
	 *	2) input file
	 *	3) output file*/
	
	printf("-1\n");

	if (argc < 3)
    {
       status_work = ERROR_ARG;

    }
	else
    {
        //Verifying existence of the input data file
        FILE *file1 = fopen(argv[1], "r+");
        if (file1 == 0)
        {
            status_work = ERROR_OPEN_INPUT_FILE;
        }
        else
        {	printf("0\n");
        	switch (ReadDataFromFile(array_of_all_numbers,&length_array_of_all_numbers,file1))
            {
                case FILE_IS_TOO_LARGE:
                    status_read_from_file = FILE_IS_TOO_LARGE;
                    break;
                case FILE_IS_NORMAL:
                    status_read_from_file = FILE_IS_NORMAL;
                    break;
            }
        }
        printf("1\n");
       	if (file1)
            fclose(file1);    

	   	if(status_read_from_file==FILE_IS_TOO_LARGE)
	   		printf("The number of entries in the file exceeds the size limit of the array");

	   	printf("2\n");
	    switch (Average(array_of_all_numbers, length_array_of_all_numbers, &average))
	    {
	    	case DIVISION_BY_ZERO:
	    		status_work= DIVISION_BY_ZERO;
	    		break;
	    	case OK:
	    		status_work=OK;
	    		break;
	    }
	    printf("3\n");
	    printf("%lf %d",average,length_array_of_all_numbers);
	    CreateArrayBiggerAverage(array_of_all_numbers,array_of_numbers_bigger_average,
	    	average,length_array_of_all_numbers, &length_array_of_numbers_bigger_average);

	    FILE *file2 = fopen(argv[2], "w");
	    if (file2 == 0)
	    {
	        status_work = ERROR_OPEN_OUTPUT_FILE;
	    }
	    printf("4\n");
	    PrintToFile(array_of_numbers_bigger_average,length_array_of_numbers_bigger_average,file2);

		if (file2)
	         fclose(file2);
	}
	printf("5\n");
    switch(status_work)
    {
     	case ERROR_ARG:
     		printf("Not enough arguments");
     		break;
     	case ERROR_OPEN_INPUT_FILE:
     		printf("Unable to open input file");
     		break;
     	case DIVISION_BY_ZERO:
     		printf("Zero length of the array. Division by zero."); 
     		break;
     	case ERROR_OPEN_OUTPUT_FILE:
     		printf("Unable to open output file"); 
     		break;
     	
    }
    return status_work;

	
}