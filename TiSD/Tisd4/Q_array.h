//
// Created by alexey on 13.11.16.
//

#ifndef TISD4_Q_ARRAY_H
#define TISD4_Q_ARRAY_H

#include "lib.h"


class Q_array {
private:
    int * arr = NULL;
    int back;
    int front;
    int max_size;
    info_queue info;
    void increase();

public:
    Q_array();
    Q_array(const Q_array &);
    ~Q_array();
    int PopFront();
    void PushBack(int x);
    bool Empty_Q();
    Q_array& operator= (const Q_array &obj);
    int * get_arr();
    void show();
    void show_adr() {}
    bool is_full();
};


#endif //TISD4_Q_ARRAY_H
