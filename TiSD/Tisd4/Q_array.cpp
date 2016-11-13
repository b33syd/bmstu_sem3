//
// Created by alexey on 13.11.16.
//

#include "Q_array.h"
using namespace std;

Q_array::Q_array()
{
    //cout << "const" << endl;
    max_size = START_SIZE;
    info.count_request = info.sum_size = info.tmp_size = 0;
    info.sum_time = info.out_request = info.in_request = 0;
    back = front = 0;
    arr = new int[max_size];
}
Q_array::Q_array(const Q_array &obj)
{
    if(this != &obj) {
        *this = obj;
    }
}

Q_array& Q_array::operator=(const Q_array &obj)
{
    //cout << "=";
    if(this != &obj) {
        max_size = obj.max_size;
        front = obj.front;
        back = obj.back;
        info = obj.info;
        if(arr) delete[] arr;
        arr = new int[obj.max_size];  //Выделяю память для элемента объекта
        for (int i = 0; i < max_size; i++) {
            arr[i] = obj.arr[i]; //Поэлементное копирование
        }
        max_size=obj.max_size;
    }
    return *this;
}

Q_array::~Q_array() {

    if(arr) {
        delete[] arr;
    }
}

void Q_array::increase() {
    //cout << "in" << endl;
    int * arr_copy = new int[max_size * 2];
    int j = 0;
    int i = back;
    while(i != front) {
        arr_copy[j] = arr[i];
        j++;
        i++;
        i %= max_size;
    }
    back = 0;
    front = j;
    delete[] arr;
    arr = arr_copy;
    max_size *= 2;
}
void Q_array::PushBack(int x) {
    /*
     * if(front == (back - 1 + max_size) % max_size) {
        increase();
    }*/
    info.tmp_size++;
    info.sum_size += info.tmp_size;
    info.count_request++;
    info.in_request++;
    back--;
    back += max_size;
    back %= max_size;
    arr[back] = x;
}
int Q_array::PopFront() {
    int x;
    //assert(back != front);
    info.tmp_size--;
    info.sum_size += info.tmp_size;
    info.count_request++;
    info.out_request++;
    front--;
    front += max_size;
    front %= max_size;
    x = arr[front];
    //x.time_out = time_out;
    //info.sum_time += time_out - x.time_in;
    return x;
}
bool Q_array::Empty_Q()
{
    return back == front;
}
int * Q_array::get_arr()
{
    return arr;
}

bool Q_array::is_full() {
    return front == (back - 1 + max_size) % max_size;
}

/*
 * информацию о текущей и средней длине очереди,
 * количестве вошедших и вышедших заявок и о среднем времени пребывания заявок в очереди.
 */
void Q_array::show() {

    cout << "Текущая длина очереди: " << info.tmp_size << endl;
    cout << "Средняя длина очереди: " << (double) info.sum_size / (double) info.count_request << endl;
    //cout << "Кол-во вошедших заявок: " << info.in_request << endl;
    //cout << "Кол-во вышедших заявок: " << info.out_request << endl;
    //cout << "Средне время пребывания в очереди: " << (double) info.sum_time / (double) info.out_request << endl;
}