#include <stdio.h>
#include "functions.h"



//Read data from file to array
int ReadDataFromFile(double array[], int *array_length, FILE *file) {
    *array_length = 0;

    double temp = 0;

    while ((fscanf(file, "%lf", &temp) != EOF)) {
        if (*array_length < MAX_ARRAY_LENGTH) {
            array[*array_length] = temp;
        }
        else {
            return FILE_IS_TOO_LARGE;
        }
        *array_length = *array_length + 1;

    }

    return FILE_IS_NORMAL;
}

//Calculation of the average value of a real array, output error code
int Average(const double array[], int array_length, double *average) {
    double summ = 0;
    int status_work = OK;

    for (int i = 0; i < array_length; ++i) {
        summ += array[i];
    }

    if (array_length == 0) {
        status_work = DIVISION_BY_ZERO;
    }
    else {
        *average = summ / array_length;
        status_work = OK;
    }

    return status_work;
}

//Copy elements higher then average value to a new array
void CreateArrayBiggerAverage(const double array[], double new_array[],
                              double average, int array_length, int *Newarray_length) {
    int index = 0;

    for (int i = 0; i < array_length; ++i) {
        if (array[i] > average) {
            new_array[index] = array[i];
            index++;
        }
    }

    *Newarray_length = index;
}

//Print elements to file
void PrintToFile(const double array_of_numbers_bigger_average[],
                 int length_array_of_numbers_bigger_average, FILE *file) {
    for (int i = 0; i < length_array_of_numbers_bigger_average; ++i) {
        fprintf(file, "%lf \n", array_of_numbers_bigger_average[i]);
    }
}