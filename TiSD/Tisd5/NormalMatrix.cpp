#include "NormalMatrix.h"
//
// Created by alexey on 05.11.16.
//



//Умножение матриц
void NormalMatrix::multiplication(NormalMatrix matrA,NormalMatrix matrB) {
    n = matrA.getN();
    m = matrB.getM();

    matrix = new int*[matrA.getN()];

    for (int i = 0; i < matrA.getN(); ++i) {

        matrix[i]=new int[matrB.getM() ];

        for (int j = 0; j < matrB.getM(); ++j) {
            matrix[i][j]=0;
            for (int l = 0; l < matrA.getM(); l++) {

                matrix[i][j] += matrA.getMatr(i,l) * matrB.getMatr(l,j);
            }
        }
    }
}


void  NormalMatrix::show()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m-1; ++j)
        {
           std::cout<<matrix[i][j]<<" ";

        }
        std::cout<<matrix[i][m-1]<<std::endl;
    }

}

NormalMatrix::NormalMatrix() {
    n=0;
    m=0;
}

NormalMatrix::NormalMatrix(int n,int m,int **matr) {
    create(n,m,matr);
}


NormalMatrix::~NormalMatrix() {

}

int NormalMatrix::getN() const {
    return n;
}

int NormalMatrix::getM() const {
    return m;
}

int NormalMatrix::getMatr(int i, int j) const {
    return matrix[i][j];
}

void NormalMatrix::setN(int n) {
    NormalMatrix::n = n;
}

void NormalMatrix::setM(int m) {
    NormalMatrix::m = m;
}

void NormalMatrix::setMatrix(int **matr)
{
    //NormalMatrix::matrix = matrix;
    NormalMatrix::matrix = new int*[getN()];
    for (int i = 0; i < getN(); ++i)
    {
        NormalMatrix::matrix[i]=new int[getM()];
        for (int j = 0; j < getM(); ++j)
        {
            NormalMatrix::matrix[i][j]=matr[i][j];
        }

    }
}

void NormalMatrix::transposition(NormalMatrix matrA)
{
    NormalMatrix::n=matrA.getM();
    NormalMatrix::m=matrA.getN();

    NormalMatrix::matrix = new int*[matrA.getM()];
    for (int i = 0; i < matrA.getM(); ++i)
    {
        NormalMatrix::matrix[i]=new int[matrA.getN()];
        for (int j = 0; j <matrA.getN(); ++j)
        {
            NormalMatrix::matrix[i][j]=matrA.matrix[j][i];
        }
    }

}

void NormalMatrix::create(int n,int m,int **matr)
{
    setN(n);
    setM(m);
    setMatrix(matr);
}
