//
// Created by alexey on 13.11.16.
//

#include "Q_list.h"
using namespace std;


list *create_node(int x)
{
    list *a = new list;
    if (a)
    {
        a->value = x;
        a->next = NULL;
    }
    return a;
}
list *add_to_list(list *tmp, list *head)
{
    if (!head)
    {
        head = tmp;
        return head;
    }
    tmp->next = head;
    head = tmp;
    return head;
}

void free_all(list *head, list* memory[], int *m)
{
    list *next;
    for (; head; head = next)
    {
        next = head->next;
        memory[*m] = head;
        (*m)++;
        *m %= MAX_MEMORY;
        delete head;
    }
}

void print_adr(list *head) {
    if(head) {
        print_adr(head->next);
        cout <<  head << " ";
    }
}

Q_list::Q_list()
{
    head = NULL;
    tail = NULL;
    info = info_queue();
    m = 0;
}


Q_list::~Q_list()
{
    free_all(head, memory, &m);
    //cout << "~ " << endl;
}

void Q_list::PushBack(int x)
{
    list *tmp = create_node(x);
    if (tmp == NULL) {
        cout << "Cannot allocate memory";
        return;
    }
    if(head == NULL && tail == NULL) {
        tail = head = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
    int j = 0;
    for(int i = 0; i < m-j; i++) {
        if(memory[i] == tmp) {
            j++;
        }
        memory[i] = memory[i+j];
    }
    m -= j;
    info.in_request++;
    info.count_request++;
    info.tmp_size++;
    info.sum_size += info.tmp_size;
}
 int Q_list::PopFront() {
    int x;
    if(head == NULL) { return int(); }
    //assert(info.tmp_size > 0);
    x = head->value;
    list* tmp = head->next;
    memory[m] = head;
    m++;
    m %= MAX_MEMORY;
    delete head;
    head = tmp;
    info.tmp_size--;
    info.sum_size += info.tmp_size;
    info.count_request++;
    info.out_request++;
    //x.time_out = time_out;
    //info.sum_time += time_out - x.time_in;
    if(info.tmp_size == 0) { head = tail = NULL; }
    return x;
}

bool Q_list::Empty_Q()
{
    return head == NULL;
}
void Q_list::show_adr()
{
    if(m == 0) {
        cout << "No free memory" << endl;
        return;
    }
    for(int i = 0; i < m; i++) {
        cout << memory[i] << " ";
    }
    cout << endl;
}
/*
 * информацию о текущей и средней длине очереди,
 *
 */
void Q_list::show() {

    cout << "Текущая длина очереди: " << info.tmp_size << endl;
    cout << "Средняя длина очереди: " << (double) info.sum_size / (double) info.count_request << endl;
    //cout << "Кол-во вошедших заявок: " << info.in_request << endl;
    //cout << "Кол-во вышедших заявок: " << info.out_request << endl;
    //cout << "Средне время пребывания в очереди: " << (double) info.sum_time / (double) info.out_request << endl;
}
bool Q_list::is_full() {
    return info.tmp_size >= START_SIZE;
}
