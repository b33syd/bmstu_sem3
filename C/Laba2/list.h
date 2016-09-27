#ifndef LIST_H
#define LIST_H


#define ERROR_MALLOC -3
#define ERROR_LENGTH -5
#define OK 0

struct list
{
    int value;
    struct list *next;
};

struct list *create_node(int value);

struct list *add_front(struct list *head, struct list *node);

void print(struct list *head);

struct list *insert(struct list *head, unsigned n, struct list *node);

struct list *add_end(struct list *head, struct list *node);

int search_position(struct list *head, int value);

void print_to_file(struct list *head, FILE *file);

void free_all(struct list *head);

int read_list_from_file(struct list **head, FILE *file);

int distributor(struct list *head, struct list **even, struct list **odd);

#endif // LIST_H