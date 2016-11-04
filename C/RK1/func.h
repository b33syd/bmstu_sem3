#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>

int fibonachi(int one, int second);
int search_fib_pair(int value);
void move_part_array(int *array,int pos_for_remove,int n);
void copyarray(int *array_from_read,int *array_to_save, int array_len);
int worker(int *array_to_save, int array_len);
void printarray(int *array, int array_len);
int readfromfile(int *array_st, int *array_end, FILE *file);
void count_file_length(int *array_length, FILE *file);
void printarray_to_file(int *array, int array_len,FILE *file);

#endif // FUNC_H
