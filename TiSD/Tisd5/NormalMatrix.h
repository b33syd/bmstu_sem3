//
// Created by alexey on 05.11.16.
//



#ifndef TISD5_NORMALMATRIX_H
#define TISD5_NORMALMATRIX_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class NormalMatrix {
private:
    int n;
    int m;
    int **matrix;
public:
    //Конструкторы
    NormalMatrix();

    NormalMatrix(int n, int m, int **matr);

    //свойства get
    int getN() const;

    int getM() const;

    int getMatr(int i, int j) const;



    //свойства set
    void setN(int n);

    void setM(int m);

    void setMatrix(int **matrix);



    //методы
    void show();

    void create(int n, int m, int **matr);

    void transposition(NormalMatrix matrA);

    void multiplication(NormalMatrix matrA, NormalMatrix matrB);

    int memory()
    {
        int res=0;
        res+=sizeof( matrix[0][0])*n*m;

        res+=sizeof( matrix[0])*n;
        res+=sizeof( matrix);
        res+=sizeof(n);
        res+=sizeof(m);
        //res+=16;
        return res;
    }

};


#endif //TISD5_NORMALMATRIX_H
