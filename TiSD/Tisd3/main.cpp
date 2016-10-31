#include <iostream>
#include "Book.h"
using namespace std;


#include <time.h>
#include "Book.h"
#include <fstream>
#include <algorithm>
#include "Table_key.cpp.cpp"
#define MAX_RECORD 200


void read_dB(Book *arr,int *n)
{
    ifstream fin("/home/alexey/ClionProjects/Tisd3/database");

    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        int m;
        fin>>m;
        for (int i = 0; i < m; ++i) {
            arr[i].read_from_file(fin);
        }
        *n=m;
    }
    fin.close();
}
//+
bool isLess(Book book1, Book book2 )
{
    return book1.GetPages()>book2.GetPages();
}

bool isLess(Table_key book1, Table_key book2 )
{
    return  book1.pages>book2.pages;

}

bool isLess(Table_key *book1, Table_key *book2 )
{
    return  &(book1->pages)>&(book2->pages);

}

bool isLess(Book *book1, Book book2 )
{
    return book1->GetPages()>book2.GetPages();
}





template <class T>
void mySort(T* arr, int l, int r, bool (*isLess)( T,  T))
{
    for(int i=l; i<r;i++)
    {
        for(int j=i+1; j<r;j++)
        {
            if(isLess(arr[i], arr[j]))
                swap(arr[i],arr[j]);

        }
    }
}


template <class T>
void quick_sort(T *begin, T* end) {
    T *i = begin, *j = end, x = *(i + (j - i) / 2);

    do {
        while (isLess(x,*i)) i++;
        while (isLess(*j,x)) j--;

        if(i <= j) {
            if (isLess(*i,*j)) {
                T tmp = *j;
                *j = *i;
                *i = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < end)
        quick_sort(i, end);
    if (begin < j)
        quick_sort(begin, j);
}


void Search(Book *arr, int n)
{
    char industry[LEN_STRING];
    cout << "Введите отрасль: ";
    cin.getline( industry, sizeof industry );

    int year;
    {
        int flag = 0;
        char str[LEN_STRING];
        int x;
        do {
            flag = 0;
            cout << "Введите год издания: ";

            cin.getline(str,LEN_STRING,'\n');
            char **end = NULL;
            x = strtol(str, end, 10);
            if (x < 0 || x > 2017) {
                cout << "Ошибочный ввод" << endl;
                flag = 1;
            }
        } while (flag);

        year=x;
    }


    for (int i = 0; i < n; ++i)
    {
        if(arr[i].search(year,industry)==true)
        {
            arr[i].show();
        }

    }
}

int Remove(Book *arr, int *k)
{
    int n=*k;
    int z;
    cout << "Введите индекс удаляемой записи от 0 до " << n - 1;
    cin >> z;
    if(z < 0 && z >= n) {
        cout << "выход из дапазона" << endl;
        return 0;
    }

    for(int i = z; i < n; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n].~Book();
    arr[n] = Book();

    cout << "Элемент  был удален удален" << endl;
    n--;
    *k=n;
}


void Sort_to_time(Book *arr, int n,Table_key *keys) {
    time_t t1, t2, t3, t4;
    for(int i = 0; i < n; i++) {
        keys[i] = Table_key(i, arr[i]);
    }
    //Сортировка по ключам
    t1 = clock();
    //mySort(keys,0,n,isLess);
    quick_sort(keys,keys+n-1);
    t2 = clock();

    //Сортировка таблицы
    t3 = clock();
    //mySort(arr,0,n,isLess);
    quick_sort(arr,arr+n-1);
    t4 = clock();

    cout << "Время работы сортировки по ключам: " << t2 - t1 << " мс" << endl;
    cout << "Время работы сортировки таблицы: " << t4 - t3  << " мс" << endl;
}


void DifSort(Book *arr, int n,Table_key *keys) {

    time_t t1, t2, t3, t4;
    for(int i = 0; i < n; i++) {
        keys[i] = Table_key(i, arr[i]);
        cout << keys[i].id << " ";
    }
    cout <<endl;

    t1 = clock();
    quick_sort(keys, keys+n-1);
    t2 = clock();


    for(int i = 0; i < n; i++) {
        cout << keys[i].id << " ";
        keys[i] = Table_key(i, arr[i]);
    }
    cout <<endl;

    t3 = clock();
    mySort(keys,0,n,isLess);
    t4 = clock();

    for(int i = 0; i < n; i++) {
        cout << keys[i].id << " ";
    }
    cout <<endl;

    cout << "Время работы быстрой сортировки: " << t2 - t1 << " мс" << endl;
    cout << "Время работы сортировки пузырьком: " << t4 - t3 << " мс" << endl;

}


void Key_sort(Book *arr, int n,Table_key *keys) {
    for(int i = 0; i < n; i++) {
        keys[i] = Table_key(i, arr[i]);
        cout << keys[i].id << " ";
    }
    cout << endl;
    //mySort(keys,0,n,isLess);
    quick_sort(keys, keys+n-1);
    for(int i = 0; i < n; i++) {
        cout << keys[i].id << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        //arr[keys[i].id].show();
    }
    cout << endl;
}

int main() {


    int a;
    Book arr[MAX_RECORD];
    int n=0;

    time_t t1, t2, t3, t4;

    int z;
    read_dB(arr,&n);
    Table_key keys[MAX_RECORD];
    while(true) {
        cout << "**************************************************************" << endl;
        cout << "Выберите одно из следующих действий:" << endl;

        cout << "0: Показать таблицу" << endl;
        cout << "1: Отсортировать по ключам (не меняя исходную)" << endl;
        cout << "2: Отсортировать таблицу" << endl;
        cout << "3: Добавить запись" << endl;
        cout << "4: Удалить запись" << endl;
        cout << "5: Сравние времени сортировки таблицы и ключей" << endl;
        cout << "6: Сравнить эффективность сортировок (по ключам)" << endl;
        cout << "7: Поиск по году и отрасли" << endl;
        cout << "8: Выход" << endl;
        cout << sizeof(arr[10]) << endl;
        cout << sizeof(keys[1])<< endl;





        {
            int flag = 0;
            char str[LEN_STRING];
            int x;
            do {
                flag = 0;
                //cin >> str;
                cin.getline(str,LEN_STRING,'\n');
                char **end = NULL;
                x = strtol(str, end, 10);
                if (x < 0 || x > 2017) {
                    cout << "Ошибочный ввод" << endl;
                    flag = 1;
                }
            } while (flag);

            a=x;
        }


        switch(a)
        {
            case 0:
                for (int i = 0; i < n; i++) {
                    cout << i << endl;
                    arr[i].show();
                    cout << endl;
                }
                break;
///////////////////////////////////////////////////////////////////////////
            case 1:
                Key_sort(arr, n,keys);
                break;
///////////////////////////////////////////////////////////////////////////
            case 2:
               //mySort(arr,0,n,isLess);
                quick_sort(arr, arr+n-1);

                for(int i = 0; i < n; i++) {
                    arr[i].show();
                    cout << endl;
                }
                break;
///////////////////////////////////////////////////////////////////////////
            case 3:
                if(n >= MAX_RECORD - 1) {
                    cout << "Переполнение массива записей" << endl;
                    break;
                }
                arr[n].create_record();
                n++;
                break;
            case 4:
                Remove(arr, &n);
                break;
///////////////////////////////////////////////////////////////////////////
            case 5:
                Sort_to_time(arr, n,keys);
                break;
            case 6:
                DifSort(arr,n,keys);
                break;
            case 7:
                Search(arr,n);
                break;

            case 8:
                cout << "Выход" << endl;
                return 0;
            default:
                cout << "Ошибочный ввод";
                break;

        }
    }
}


