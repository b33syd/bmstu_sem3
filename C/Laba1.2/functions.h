#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ERROR_LENGTH -2
#define ERROR_MALLOC -3
#define BAD_POINTERS -6

void count_file_length(int *array_length, FILE *file);

int readfromfile(int *array_st, int *array_end, FILE *file);

int filter(int *array, int *array_end,int **filtered,int **filtered_end);

void mod_insertion_sort(int *array, int *array_end);
void printarray(int *array, int *array_end);

#endif // FUNCTIONS_H