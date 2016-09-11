#include <stdio.h>
#include "functions.h"

#define MAX_ARRAY_LENGTH 10
#define FILE_IS_NORMAL 0
#define FILE_IS_TOO_LARGE 1

#define OK 0
#define DIVISION_BY_ZERO -3

//Read data from file to array
int ReadDataFromFile(double array[], int *array_length, FILE *file)
{
	*array_length=0;
	int status_work=FILE_IS_NORMAL;
	
	while (((fscanf (file, "%lf", &array[*array_length])) != EOF) &&(status_work==OK)) {
		
		*array_length=*array_length+1;
		if(*array_length==MAX_ARRAY_LENGTH)
			status_work= FILE_IS_TOO_LARGE;
	}


	return status_work; 
}

//Calculation of the average value of a real array, output error code
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
//Copy elements higher then average value to a new array
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

//Print elements to file
void  PrintToFile(const double array_of_numbers_bigger_average[],
	int length_array_of_numbers_bigger_average,FILE *file)
{
	for (int i = 0; i < length_array_of_numbers_bigger_average; ++i)
	{
		fprintf(file,"%lf \n", array_of_numbers_bigger_average[i]);
	}
}