#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ARRAY_LENGTH 10
#define FILE_IS_NORMAL 0
#define FILE_IS_TOO_LARGE 1
#define OK 0
#define DIVISION_BY_ZERO -3

//Read data from file to array
int ReadDataFromFile(double array[], int *array_length, FILE *file);

//Calculation of the average value of a real array, output error code
int Average(const double array[], int array_length, double *average);

//Copy elements higher then average value to a new array
void CreateArrayBiggerAverage(const double array[],double new_array[],
								 	double average, int array_length, int *Newarray_length);

//Print elements to file
void  PrintToFile(const double array_of_numbers_bigger_average[],
						int length_array_of_numbers_bigger_average,FILE *file);

#endif // FUNCTIONS_H