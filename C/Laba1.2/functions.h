#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ERROR_LENGTH -2
#define ERROR_MALLOC -3
#define BAD_POINTERS -6
#define N 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long tick(void);

void count_file_length(int *array_length, FILE *file);

int readfromfile(int *array_st, int *array_end, FILE *file);

//которые больше суммы элементов расположенных за ним.
int filter(const int *array, const int *array_end, int **filtered, int **filtered_end);

//Модифицированная сортировка вставками. Для поиска места вставки нового элемента используется двоичный поиск.
void mod_insertion_sort(void *base, const size_t nmemb, const size_t size, int (*compar)(const void *, const void *));

void printarray(const int *array, const int *array_end);
void printarrayd(const double *array, int n);


int compare_int_less(const void *val1, const void *val2);

int read_file(int **array, int *array_length, FILE *file);

int testing(const int *a_st, const int *a_end, const int sort_t);

void printarray_to_file(const int *array, const int *array_end, FILE *file);

void* bin_search(const void *arr, const void *arr_end, const void *value, const int size, int (*comparator)(const void *, const void *));

int compare_double_less(const void *val1, const void *val2);
#endif // FUNCTIONS_H