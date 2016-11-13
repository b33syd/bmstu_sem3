//
// Created by alexey on 13.11.16.
//

#ifndef TISD4_Q_LIST_H
#define TISD4_Q_LIST_H
#include "lib.h"
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} list;

list *create_node(int x);
list *add_to_list(list *tmp, list *head);
void free_all(list *head, list* memory, int m);
void print_adr(list *head);




class Q_list {
private:
    list *memory[MAX_MEMORY];
    int m;
    list *head;
    list *tail;
    info_queue info;
public:
    Q_list();
    ~Q_list();
    void show();
    void show_adr();
    int PopFront();
    void PushBack(int x);
    bool Empty_Q();
    bool is_full();
};


#endif //TISD4_Q_LIST_H
