#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ERROR_LENGTH -2

void count_file_length(int *array_length, FILE *file);

int readfromfile(int *array_st, int *array_end, FILE *file);

int seach_max_pair(int *p_start, int *p_end, int *max);

#endif // FUNCTIONS_H