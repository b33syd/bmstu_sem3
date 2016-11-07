#include <iostream>
#include "func.h"

using namespace std;

int main(){
    while(true) {
        cout << "Умножение матрицы на вектор-столбец:" << endl;
        cout << "Выберите одно из следующих действий:" << endl;
        cout << "0: Работа с матрицей и вектором" << endl;
        cout << "1: Сравнение скорости работы стандартного алгоритма и работы с разряженными матрицами" << endl;
        cout << "2: Exit" << endl;
        int ch;
        cin >> ch;
        switch(ch) {
            case 0:
                work_hand();
                break;
            case 1:
                compare();
                break;
            case 2:
                return 0;
            default:
                cout << "Error code" << endl;
                break;
        }
    }
}

/*
int oldmain() {

    int m = 0;
    int n = 0;
    cin >> n >> m;

    int **res = new int *[n];

    int z = 1;
    for (int i = 0; i < n; i++) {
        res[i] = new int[m];
        for (int j = 0; j < m; j++) {
            res[i][j] = z;
            if (j == 2)
                res[i][j] = 0;
            if (j == 0)
                res[i][j] = 0;
            if (z == 2)
                res[i][j] = 0;
            if (z == 12)
                res[i][j] = 0;
            if (z == 17)
                res[i][j] = 0;

            z++;
        }
    }

    cout << "=============NORMAL=============" << endl;
    NormalMatrix m1 = NormalMatrix(n, m, res);
    m1.show();

    cout << "=============NOT    NORMAL=============" << endl;
    SparseMatrix m2 = SparseMatrix(m1);
    m2.show();


    for (int i = 0; i < n; i++) {
        delete[] res[i];
    }
    delete[] res;


    cout << "=============NEXT=============" << endl;
    n = m;
    m = 1;
    res = new int *[n];
    z = 1;

    for (int i = 0; i < n; i++) {
        res[i] = new int[m];
        for (int j = 0; j < m; j++) {
            res[i][j] = z;
            if (j == 2)
                res[i][j] = 0;
            //if(j==0)
            //  res[i][j]=0;
            if (z == 2)
                res[i][j] = 0;
            if (z == 12)
                res[i][j] = 0;
            if (z == 17)
                res[i][j] = 0;

            z++;
        }
    }

    cout << "=============NORMAL 2=============" << endl;
    NormalMatrix m3 = NormalMatrix(n, m, res);
    m3.show();

    cout << "=============NOT    NORMAL 2=============" << endl;
    SparseMatrix m4 = SparseMatrix(m3);
    m4.show();

    for (int i = 0; i < n; i++) {
        delete[] res[i];
    }
    delete[] res;

    cout << "=============NORMAL res=============" << endl;
    NormalMatrix res1;
    time_t t1 = clock();
    res1.multiplication(m1, m3);
    time_t t2 = clock();
    res1.show();

    cout << "=============NOT    NORMAL res=============" << endl;
    SparseMatrix res2;
    SparseMatrix m5;
    time_t t3 = clock();
    m5.transposition(m1);
    time_t t4 = clock();
    res2.mult(m5, m4);
    time_t t5 = clock();
    res2.show();

    cout << "Время умножения в стандартном виде: "  << t2 - t1 << endl;
    cout << "Время умножения в разреженном виде: "  << t5 - t4 << endl;
    cout << "Время транспонирования: "  << t4 - t3 << endl;




    cout<<"=============NORMAL from NOT NORMAl============="<<endl;
    //NormalMatrix m3;
    //m3.create(n,m,m2.to_standart());
    //m3.show();

    cout<<"=============NOT    NORMAL TRANSPOS============="<<endl;
    SparseMatrix m4;
    m4.transposition(m1);
    //m4.show();




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/