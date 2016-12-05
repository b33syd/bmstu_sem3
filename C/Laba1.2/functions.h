#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ERROR_LENGTH -2
#define ERROR_MALLOC -3
#define BAD_POINTERS -6

unsigned long long tick(void);

void count_file_length(int *array_length, FILE *file);

int readfromfile(int *array_st, int *array_end, FILE *file);

//которые больше суммы элементов расположенных за ним.
int filter(int *array, int *array_end,int **filtered,int **filtered_end);

//Модифицированная сортировка вставками. Для поиска места вставки нового элемента используется двоичный поиск.
//void mod_insertion_sort(int *array, int *array_end);
void mod_insertion_sort(void *base,const size_t nmemb,const size_t size, int (*compar)(const void*, const void*));

void printarray(int *array, int *array_end);
int compare_int_less(const void *val1, const void *val2);

#endif // FUNCTIONS_H