#ifndef LIBSTR2_H
#define LIBSTR2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR_ARG -1
#define ERROR_OPEN_INPUT_FILE -2
#define ERROR_MALLOC -3
#define ERROR_BAD_LENGTH -4
#define ERROR_OPEN_OUTPUT_FILE -5
#define BUF_SIZE 5

#define DEBUG 2
#define LEVEL 0
#include "debug.h"

int readfromfile2(char **line,size_t *n, FILE *file);
char *replace( const char *line,  const char *replace_what, const char *replace_with);


#endif // LIBSTR2_H