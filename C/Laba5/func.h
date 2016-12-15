#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

char *print(char *q, size_t *size,const char ch, int *global_counter);

char *printer3(char *q, size_t *size, const signed short toconvert,int *global_counter);

char *printer1(char *q, size_t *size, const char *line,int *global_counter);

int digit_len(int num);

char get_n_char(int num,int k);

char *printer2(char *q, size_t *size, const int toprint,int *global_counter);

size_t my_vsnprintf(char *buffer, size_t buff_size, const char *format, va_list ap);

int my_snprintf(char *buffer, size_t n, const char *format, ...);

#endif // FUNC_H