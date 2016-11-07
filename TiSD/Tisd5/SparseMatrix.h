//
// Created by alexey on 05.11.16.
//

#ifndef TISD5_SPARSEMATRIX_H
#define TISD5_SPARSEMATRIX_H

#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include "NormalMatrix.h"

class SparseMatrix {

private:
    std::vector<int> A;  //не нулевые элементы
    std::vector<int> IA; // номера строк  для элементов вектора A
    std::list<int> JA; //
    int n;// количесво строк
    int m;// количестро столбцов

public:
    SparseMatrix();

    SparseMatrix(const SparseMatrix &obj);

    SparseMatrix(NormalMatrix matrA);

    ~SparseMatrix();

    //SparseMatrix operator* (SparseMatrix &obj);
    SparseMatrix &operator=(const SparseMatrix &obj);

    int getN() const;

    int getM() const;

    void show();

    // Преобразование из обычной матрицы в разряженную
    void convert(NormalMatrix &matrA);


    void transposition(const NormalMatrix &matrA);

    void mult(SparseMatrix &obj1, SparseMatrix &obj2);


    int **to_standart();

    void transposition(const SparseMatrix &obj);

    int smallmult(std::vector<int> &A1, std::vector<int> &IA1, int st1, int end1,
                  std::vector<int> &A2, std::vector<int> &IA2, int st2, int end2);

    int memory()
    {
        int res=0;
        res+=sizeof(A[0])*A.size()+sizeof(A);
        res+=sizeof(IA[0])*IA.size()+sizeof(IA);
        res+=sizeof(JA.begin())*JA.size()+sizeof(JA);
        res+=sizeof(n);
        res+=sizeof(m);
        //res+=16;
        return res;
    }



};

#endif //TISD5_SPARSEMATRIX_H
