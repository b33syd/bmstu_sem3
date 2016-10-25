//
// Created by alexey on 24.10.16.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#define OK 0
#define NULL_STACK -1
#define ERROR_MALLOC -2

#define LIMIT 11


class StackList
{

private:

    struct stack
    {
        int value;
        struct stack *next;
    };

    struct stack *head;
    std::vector<struct stack *> VectorForFreeMem;
    long int maxlen;
    int pos;

    struct stack *create_node(int value)
    {
        struct stack *node;

        node = (stack*) malloc(sizeof(struct stack));
        if (node)
        {
            node->value = value;
            node->next = NULL;
        }
        return node;
    }

    //maxmem
    void memoryusing(int k)
    {
        pos+=k;
        if(maxlen<pos)
            maxlen=pos;
    }

//добавление элемента
    int push(int newval)
    {
        int status_work=OK;
        struct stack *node;
        node = create_node(newval);

        if (node == NULL)
        {
            status_work = ERROR_MALLOC;
            std::cout<< "[error]\n";
        }
        else
        {
            node->next = head;
            head = node;
        }
        memoryusing(1);
        return status_work;

    }

//удаление элемента
    int pop1()
    {
        int status_work=OK;
        struct stack *node;

        if (head!=NULL)
        {
            node = head;
            head = node->next;
            VectorForFreeMem.push_back(node);
            memoryusing(-1);
            free(node);
        }
        else
            status_work=NULL_STACK;

        return status_work;
    }

//чтение головного элемента
    int peak(int *result)
    {
        //printf("peak\n");

        int status_work=OK;

        if (head!=NULL)
        {
            *result=head->value;
        }
        else
        {
            status_work=NULL_STACK;
            std::cout<<"Error: Empty stack"<<std::endl;
        }

        return status_work;
    }

    void free_all()
    {
        struct stack *next;

        for (; head; head = next)
        {
            next = head->next;
            free(head);
        }
    }

public:

    StackList()
    {
        pos=0;
        maxlen=0;
        head=NULL;
    }
    ~StackList()
    {
        free_all();
    }

    int  Push(int val)
    {
        if(maxlen==LIMIT)
        {
            std::cout << "Error: Full stack" << std::endl;
            return 1;
        }
        else
            push(val);

        return 0;
    }

    int Pop() {

        int val;

        if(peak(&val)!=OK)
            val=-1;



        pop1();

        return val;

    }
    char reconverter(int k)
    {
        char id=0;
        switch(k)
        {
            case 1:
                id='(';
                break;
            case 2:
                id=')';
                break;

            case 3:
                id='[';
                break;
            case 4:
                id=']';
                break;

            case 5:
                id='{';
                break;
            case 6:
                id='}';
                break;
        }
        return id;
    }

    void Show()
    {
        struct stack *next;
        struct stack *head1=head;

        for (; head; head = next) {
            next = head->next;
            std::cout << reconverter(head->value) << " ";
        }
        head=head1;
        std::cout<<std::endl;

        ShowADD();
    }

    void ShowADD()
    {
        struct stack *next;
        struct stack *head1=head;
        std::cout<< "Используемые адреса: ";
        for (; head; head = next) {
            next = head->next;
            std::cout << &(head->value) << " ";
        }
        head=head1;
        std::cout<<std::endl;

        std::cout<< "Используемые ранее адреса: ";
        for (int i = 0; i <VectorForFreeMem.size() ; ++i) {

            std::cout << VectorForFreeMem[i] << " ";
        }
        std::cout<<std::endl;


    }

    int Size()
    {
        //std::cout<< "maxlen"<<maxlen;
        return maxlen * sizeof(struct stack);
    }

    int IsEmpty()
    {
        if(pos==0)
            return 0;
        else
            return -1;
    }

};

