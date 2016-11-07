//
// Created by alexey on 07.11.16.
//
#include <iostream>
#include "func.h"
#include "NormalMatrix.h"
#include "SparseMatrix.h"
using namespace std;

int rand_int(int n) {
    return (int) ((rand() / (double) RAND_MAX) * (double) n);
}

int badmessage()
{
    cout << "error, попытайтесь еще раз:  ";
}

int **generate(int n, int m, double percent, int l, int r) {
    srand(time(0));
    int colv = n * m * percent / 100;
    int ** matr = new int* [n];
    for(int i = 0; i < n; i++) {
        matr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            matr[i][j] = 0;
        }
    }

    for(int i = 0; i < colv; i++) {
        int k=rand_int(n);
        int f=rand_int(m);
        //if(matr[k][f]!=0)
            matr[k][f] = rand_int(r - l) + l;
        //else
        //    --i;
    }
    return matr;
}

void free_matr(int **a, int n) {
    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete a;
}

int ** hand_input(int n, int m) {

    int **a = new int* [n];
    for(int i = 0; i < n; i++) {
        a[i] = new int [m];
        for(int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    cout << "Введите по 3 числа для каждого ненулевого эл-та (индексация с нуля)\n (строка  столбц  значение)\n";
    while(1) {
        while (1) {
            int i = n + 1, j = m + 1, k = 0;
            if (scanf("%d %d %d", &i, &j, &k)) {
                if ((i >= 0) && (i < n) && (j >= 0) && (j < m) && (k!=0)) {
                    a[i][j] = k;
                    break;
                }
            }
            badmessage();
        }
        cout << "Продолжить (1-нет)? ";
        char ch;
        cin >> ch;
        if (ch == '1') {
            break;
        }
    }
    return a;
}

void input_range(int *n){
    while(!(scanf("%d", n) && (*n >= -R_MAX) && (*n <= R_MAX))) {
        badmessage();
        *n = R_MAX + 1;
    }

}

void input_percent(double *p){
    double percent = -1;
    cout << "Введите процент заполнения [0, 100]: ";
    while(!(scanf("%lf", &percent) && (percent >= 0) && (percent <= 100))) {
        badmessage();
        percent = -1;
    }
    *p=percent;
}

int ** auto_input(int n, int m) {
    double percent = -1;
    input_percent(&percent);

    cout << "Диапазон значений [" << -R_MAX << ", " << R_MAX << "]: " << endl;
    int l, r;
    l = r = R_MAX + 1;
    cout << "Начало диапазона: " << endl;
    input_range(&l);

    cout << "Конец диапазона: " << endl;
    input_range(&r);

    return generate(n, m, percent, l, r);
}

int ** input_matr(int *n, int *m) {
    int tmp;
    *m = 0;
    cout << "Ввод матрицы\n";
    cout << "Введите кол-во строк [1, " << MAX_SIZE << "]: ";
    while(!(scanf("%d", n) && (*n >= 1) && (*n <= MAX_SIZE))) {
        badmessage();
        *n = 0;
    }
    cout << "Введите кол-во столбцов [1, " << MAX_SIZE << "]: ";
    *m = 0;
    while(!(scanf("%d", m) && (*m >= 1) && (*m <= MAX_SIZE))) {
        badmessage();
        *m = 0;
    }

    cout << "Выберите ввод: \n\t 1- ручной \n\t 2- автоматический" << endl;
    cin >> tmp;
    while(tmp != 1 && tmp != 2) { cout << "error, попытайтесь еще раз: "; cin >> tmp; }
    if(tmp == 1) {
        return hand_input(*n, *m);
    }
    else {
        return auto_input(*n, *m);
    }
}

int ** input_string(int n, int m) {
    int tmp;
    cout << "Ввод вектора-стобца\n";


    cout << "Выберите ввод: \n\t 1- ручной \n\t 2- автоматический" << endl;
    cin >> tmp;
    while(tmp != 1 && tmp != 2) { badmessage(); cin >> tmp; }
    if(tmp == 1) {
        return hand_input(n, m);
    }
    else {
        return auto_input(n, m);
    }
}

void work_hand() {
    cout << "Умножение матрицы на вектор-столбец:" << endl;

    int ** a;
    int na, ma;
    int ** b;
    int tmp;
    a = input_matr(&na, &ma);
    int nb=ma, mb=1;
    b = input_string(nb, mb);
    NormalMatrix normal1 = NormalMatrix(na, ma, a);
    NormalMatrix normal2 = NormalMatrix(nb, mb, b);

    SparseMatrix sm1 = SparseMatrix(normal1);
    SparseMatrix sm2 = SparseMatrix(normal2);
    SparseMatrix sm3 = SparseMatrix(normal1);

    //cout <<" MATRIX1"<<endl;
    //normal1.show();
    //sm1.show();
    //cout <<" MATRIX2"<<endl;
    //normal2.show();
    //sm2.show();

    //NormalMatrix normalres_from_spres,test1,test2,test3;
    NormalMatrix normalres;
    SparseMatrix spres;
    SparseMatrix sm1_tran;
    /*
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ before trans"<<endl;
    test1.create(sm1.getN(),sm1.getM(),sm1.to_standart());
    test1.show();
     */
    sm1.transposition();
    /*
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++after trans"<<endl;
    test2.create(sm1.getN(),sm1.getM(),sm1.to_standart());
    test2.show();
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++not normal ans"<<endl;
     */
    spres.mult(sm1,sm2);

    //normalres_from_spres.create(spres.getN(),spres.getM(),spres.to_standart());
    //spres.mult(sm1,sm2);

    //cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ normal ans"<<endl;
    normalres.multiplication(normal1,normal2);
    //normalres.show();
    //cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ end"<<endl;


    //cout <<" MATRIX3"<<endl;
    //normalres_from_spres.show();
    //spres.show();
    //normalres.show();


    //normalres_from_spres.show();
    //cout<<"55555555555555555555555555555555555555555555555555555555555555"<<endl;
    //normalres.show();
    char ch;
    int flag = 1;
    while(flag) {
        cout << "0: Вывести первую матрицу в разреженном формате" << endl;
        cout << "1: Вывести вектор-столбец в разреженном формате" << endl;
        cout << "2: Вывести результат умножения в разреженном формате" << endl;
        cout << "3: Вывести первую матрицу в стандартном формате" << endl;
        cout << "4: Вывести вектор-столбец в стандартном формате" << endl;
        cout << "5: Вывести результат работы стандартного алгоритма" << endl;
        cout << "6: Закончить работу" << endl;
        cin >> ch;
        //cout << ch << endl;
        switch(ch) {
            case '0':   sm1.show(); break;
            case '1':   sm2.show(); break;
            case '2':   spres.show(); break;
            case '3':   normal1.show(); break;
            case '4':   normal2.show(); break;
            case '5':   normalres.show(); break;
            case '6':
                flag = 0;
                break;
            default: cout << "Error"; break;
        }
    }
    free_matr(a, na);
    free_matr(b, nb);
}

void compare() {

    int n, m, k;
    n = m = k = 0;

    cout << "Введите кол-во строк [1, " << MAX_SIZE << "]: ";
    while(!(scanf("%d", &n) && (n >= 1) && (n <= MAX_SIZE))) {
        badmessage();
        n = 0;
    }

    cout << "Введите кол-во столбцов [1, " << MAX_SIZE << "]: ";
    m = 0;
    while(!(scanf("%d", &m) && (m >= 1) && (m <= MAX_SIZE))) {
        badmessage();
        m = 0;
    }


    double percent = -1;
    input_percent(&percent);

    int **a = generate(n, m, percent, -R_MAX, R_MAX);
    int **b = generate(m, 1, percent, -R_MAX, R_MAX);


    NormalMatrix m1 = NormalMatrix(n, m, a);
    SparseMatrix m2 = SparseMatrix(m1);
    NormalMatrix m3 = NormalMatrix(m, 1, b);
    SparseMatrix m4 = SparseMatrix(m3);
    NormalMatrix res1;
    time_t t1 = clock();
    res1.multiplication(m1, m3);
    time_t t2 = clock();
    //res1.show();

    SparseMatrix res2;
    /*SparseMatrix m5;
    time_t t3 = clock();
    m5.transposition(m1);
    time_t t4 = clock();
    res2.mult(m5, m4);
    time_t t5 = clock();
    //res2.show();
    */

    time_t t3 = clock();
    m2.transposition();
    res2.mult(m2, m4);
    time_t t5 = clock();

    cout << "Время умножения в стандартном виде: "  << t2 - t1 << endl;
    cout << "Время умножения в разреженном виде: "  << (t5 - t3) << endl;

    cout << "Память, для  стандартной матрицы " << m1.memory() << endl;
    cout << "Память, для  разряженной матрицы " << m2.memory()<< endl;

    free_matr(a, n);
    free_matr(b, m);
}