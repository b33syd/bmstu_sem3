//
// Created by alexey on 05.11.16.
//
#include "NormalMatrix.h"
#include "SparseMatrix.h"


SparseMatrix::SparseMatrix() {
    n = m = 0;
}

void SparseMatrix::convert(NormalMatrix &matr) {
    n = matr.getN();
    m = matr.getM();
    bool first = false;
    int id = 0;
    //по столбцам
    for (int i = 0; i < m; ++i) {
        //по строкам
        int z = 0;// узнаем пустой ли столбик
        for (int j = 0; j < n; ++j) {


            if (matr.getMatr(j, i) != 0) {
                if (first == false) {
                    first = true;
                    id = IA.size();
                }
                z++;
                A.push_back(matr.getMatr(j, i));
                IA.push_back(j);
            }
        }
        if (z != 0)
            JA.push_back(id);
        else
            JA.push_back(-1);
        first = false;
    }
}

SparseMatrix::SparseMatrix(const SparseMatrix &obj) {
    *this = obj;
}

SparseMatrix::~SparseMatrix() {
    A.erase(A.begin(),A.end());
    IA.erase(IA.begin(),IA.end());
    JA.erase(JA.begin(),JA.end());
    A.clear();
    IA.clear();
    JA.clear();
}

void SparseMatrix::show() {
    std::cout << "n = " << n << "      m = " << m << std::endl;

    std::cout << "A : ";
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }

    std::cout << std::endl << "IA: ";
    for (int i = 0; i < IA.size(); i++) {
        std::cout << IA[i] << " ";
    }

    std::cout << std::endl << "JA: ";
    copy(JA.begin(), JA.end(), std::ostream_iterator<int>(std::cout, " ")); // вывод на экран элементов списка

    std::cout << std::endl;
}

SparseMatrix &SparseMatrix::operator=(const SparseMatrix &obj) {
    //самоприсваивание
    if (this == &obj) {
        return *this;
    }

    n = obj.n;
    m = obj.m;
    //NA = obj.NA;

    if (!JA.empty()) JA.erase(JA.begin(), JA.end());
    if (!A.empty()) A.erase(A.begin(), A.end());
    if (!IA.empty()) IA.erase(IA.begin(), IA.end());


    for (int i = 0; i < obj.A.size(); i++) {
        A.push_back(obj.A[i]);
        IA.push_back(obj.IA[i]);
    }
//
    std::copy(obj.JA.begin(), obj.JA.end(), JA.begin());

    return *this;
}

// не верно работает при ширине 1
int **SparseMatrix::to_standart() {
    int **res = new int* [n];

    for(int i = 0; i < n; i++)
    {
        res[i] = new int [m];
        for (int j = 0; j < m; j++)
        {
            res[i][j] = 0;
        }
    }

    int i=0,mem=0;

    std::list<int>::iterator k = JA.begin();
    std::list<int>::iterator next;
    if (IA.size()==0)
        return res;
    for (; k!=JA.end(); ++k) {
        next=std::next(k,1);
        if(*k==-1)
        {    i++;
            continue;
        }

        while(-1==*next)
        {
            next=std::next(next,1);
        }

        if (*next<*k)
            mem=IA.size();
        else
            mem = *next;

        for (int j = *k; j <mem ; ++j)
        {
            res[IA[j]][i] = A[j];
        }
        ++i;

    }
    return res;


}

int SparseMatrix::getN() const {
    return n;
}

int SparseMatrix::getM() const {
    return m;
}

void SparseMatrix::transposition() {
    std::vector <std::vector<int>> A_new (n);  //не нулевые элементы
    std::vector <std::vector<int>> IA_new(n); // номера строк  для элементов вектора A

    int i=0,mem=0;
    std::list<int>::iterator k = JA.begin();
    std::list<int>::iterator next;


    for (int p=0; k != JA.end(); ++k,p++) {

        next=std::next(k,1);
        if(*k==-1)
        {    //p++;
            //k++
            continue;
        }

        while(-1==*next)
        {
            next=std::next(next,1);
        }

        if (*next<*k)
            mem=IA.size();
        else
            mem = *next;

        for (int j = *k; j <mem ; ++j)
        {
            A_new[IA[j]].push_back(A[j]);
            IA_new[IA[j]].push_back(p);
        }
        //++i;
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < A_new[i].size(); j++) {
            std::cout << A_new[i][j] << " ";
        }
        std::cout << std::endl;
        for(int j = 0; j < A_new[i].size(); j++) {
            std::cout << IA_new[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------\n\n\n";*/
    //A.erase(A.begin(), A.end());
    //IA.erase(IA.begin(), IA.end());
    //JA.erase(JA.begin(), JA.end());
    A.clear();
    IA.clear();
    JA.clear();
    //std::cout <<"qqqqqqqqqqqqqqqqqqqqqqqqq "<<A.size()<< "  "<<JA.size()<<std::endl;
    int flag = 0;

    int AAAA=0;
    for(int i = 0; i < n; i++) {
        flag = 0;
        JA.push_back(AAAA);
        //std::cout << "n: " << n << "  ";
        int e=A_new[i].size();
        for(int j = 0; j < e; j++) {
            A.push_back(A_new[i][j]);
            IA.push_back(IA_new[i][j]);
            //std::cout << IA_new[i][j] << " ";
            AAAA++;
            flag = 1;
        }
        //std::cout << "\n";
        if(flag == 0) {
             *JA.end()=-1;
        }
    }
    std::swap(n, m);
}

/*
void SparseMatrix::transposition(const NormalMatrix &matrA) {
    NormalMatrix transNormal;
    transNormal.transposition(matrA);
    //transNormal.show();
    convert(transNormal);
    //delete (transNormal);
}

*/

SparseMatrix::SparseMatrix(NormalMatrix matrA) {
    convert(matrA);
}


void SparseMatrix::mult(SparseMatrix &obj1, SparseMatrix &obj2) {
    n = obj1.m;
    m = obj2.m;
    JA.push_back(0);

    int mem = 0, f = 0;
    std::list<int>::iterator k = obj1.JA.begin();
    std::list<int>::iterator next;
    int s1 = obj1.IA.size();
    int s2 = obj2.IA.size();
    for (; k != obj1.JA.end(); ++k) {
        next = std::next(k, 1);
        if (*k == -1) {
            f++;
            continue;
        }

        while (-1 == *next) {
            next = std::next(next, 1);
        }

        if (*next < *k)
            mem = s1;
        else
            mem = *next;

        int res=smallmult(obj1.A,obj1.IA,*k,mem,
                         obj2.A,obj2.IA,0,s2);

        /*int res = 0;
        for (int i = *k, j = 0; i < mem && j <= s2;) {


            if (obj1.IA[i] == obj2.IA[j]) {
                res += obj1.A[i] * obj2.A[j];
                i++;
                j++;
                //break;
            } else if (obj1.IA[i] < obj2.IA[j]) {
                i++;
            } else {
                j++;
            }
        }
    */

        if (res != 0) {
            A.push_back(res);
            IA.push_back(f);
        }
        f++;


    }
    //JA.push_back(n);
}


int SparseMatrix::smallmult(std::vector<int> &A1, std::vector<int> &IA1, int st1, int end1,
                            std::vector<int> &A2, std::vector<int> &IA2, int st2, int end2) {
    int result = 0;
    int temppos = st2;
    if (end2==0)
        return 0;
    for (int i = st1, j = temppos; i <end1 && j <= end2;) {


        if (IA1[i] == IA2[j]) {
            temppos = j;
            result += A1[i] * A2[temppos];
            i++;
            j++;
            //break;
        } else if (IA1[i] < IA2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return result;


/* WORK SLOW
    int result=0;
    int temppos=st2;
    for (int i = st1; i <end1; ++i) {

        for (int j = temppos; j <=end2 ; ++j) {
            if (IA1[i]==IA2[j])
            {
                temppos=j;
                result+=A1[i]*A2[temppos];
                break;
            }
        }
    }
    return  result;
    */
}
