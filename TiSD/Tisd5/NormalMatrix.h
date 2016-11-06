//
// Created by alexey on 05.11.16.
//



#ifndef TISD5_NORMALMATRIX_H
#define TISD5_NORMALMATRIX_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class NormalMatrix
{
private:
    int n;
    int m;
    int  **matrix;
public:

    NormalMatrix();
    NormalMatrix(int n,int m,int **matr);
    ~NormalMatrix();

    int getN() const;
    int getM() const;
    int getMatr(int i, int j)const;

    void multiplication(NormalMatrix matrA,NormalMatrix matrB);

    void show();
    void create(int n,int m,int **matr);
    void transposition(NormalMatrix matrA);

    void setN(int n);
    void setM(int m);
    void setMatrix(int **matrix);


};


#endif //TISD5_NORMALMATRIX_H
