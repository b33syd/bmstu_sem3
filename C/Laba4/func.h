#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>


#define OK 0
#define ERROR_ARG -1
#define ERROR_OPEN_INPUT_FILE -2
#define ERROR_MALLOC -3
#define ERROR_OPEN_OUTPUT_FILE -4
#define ERROR_NULL -5
#define ERROR_KEY -10



struct matrix
{
	int n;
	int m;
	double **matrix;
};

struct matrix* read_matrix(FILE * file);

int  print_to_file(FILE * file,const struct matrix *matrA);

struct matrix * erase(struct matrix *matrA);

struct matrix*  invert(const struct matrix *matrA);

struct matrix* summ(const struct matrix *matrA, const struct matrix *matrB);

struct matrix* multiplication(const struct matrix *matrA,const struct matrix *matrB);

int print(const struct matrix *matrA);


#endif // FUNC_H