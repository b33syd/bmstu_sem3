#ifndef LIST_H
#define LIST_H


struct list
{
    int value;
    struct list *next;
};



struct list *create_node(int value);



void print(struct list *head);


struct list *add_end(struct list *head, struct list *node);



void free_all(struct list *head);


#endif // LIST_H
