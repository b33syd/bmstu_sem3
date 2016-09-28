#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct list *create_node(int value)
{
    struct list *node = malloc(sizeof(struct list));
    if (node)
    {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

struct list *add_front(struct list *head, struct list *node)
{
    node->next = head;
    return node;
}

struct list *add_end(struct list *head, struct list *node)
{
    struct list *cur = head;

    if (!head)
        return node;

    for (; cur->next; cur = cur->next);

    cur->next = node;

    return head;
}

int search_position(struct list *head, int value)
{
    int i = 0;
    for (; head; head = head->next, i++)
    {
        if (head->value >= value)
            break;        
    }

    return i;
}

struct list *search_position_by_node(struct list *head, int value)
{
    struct list *current = head;
    struct list *prew = NULL;
    while (current != 0)
    {
        if (current->value >= value)
            return prew;
        prew = current;
        current = current->next;
    }    
    return prew;
}

struct list *insert_by_node(struct list *head, struct list *node_after, struct list *node_to_insert)
{
    struct list *pointer_start = head;
    if (node_after != NULL)
    {
        node_to_insert->next = node_after->next;
        node_after->next = node_to_insert;        
    }
    else
        pointer_start = add_front(head, node_to_insert);
   
    return pointer_start;
}

struct list *insert(struct list *head, unsigned n, struct list *node)
{
    unsigned i = 1;
    struct list *pointer_start = head;

    //Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
    //произойдёт вставка в конец
    if (n == 0)
    {
        pointer_start = add_front(head, node);
    }
    else
    {
        while (i < n && head->next)
        {
            head = head->next;
            i++;
        }

        //Если это не последний, то next на следующий узел
        if (head->next)
        {
            node->next = head->next;
        }
        else
        {
            node->next = NULL;
        }

        head->next = node;
        //printf("%d",head->next->value);
    }
    return pointer_start;
}

void print(struct list *head)
{    
    printf("List:\n");
    for (; head; head = head->next)
    {
        printf("%d ", head->value);
    }

    printf("\n");
}

void print_to_file(struct list *head, FILE *file)
{    
    for (; head; head = head->next)
    {
        fprintf(file, "%d ", head->value);
    }
    printf("\n");
}

void free_all(struct list *head)
{
    struct list *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

int distributor(struct list *head, struct list **even, struct list **odd)
{
    int status_work = OK;
    struct list *node;

    while ((head) && (status_work == OK))
    {
        if (head->value % 2 == 0)
        {
            //printf("EVEN\n");
            node = create_node(head->value);
            if (node)
                *even = add_end(*even, node);
            else
                status_work = ERROR_MALLOC;
        }
        else
        {
            //printf("ODD\n");
            node = create_node(head->value);
            if (node)
                *odd = add_end(*odd, node);
            else
                status_work = ERROR_MALLOC;
        }

        head = head->next;
    }

    return status_work;
}

int read_list_from_file(struct list **head, FILE *file)
{
    int status_work = OK;
    int temp;
    struct list *node;

    while ((fscanf(file, "%d", &temp) != EOF) && (status_work == OK))
    {
        node = create_node(temp);
        if (node == NULL)
            status_work = ERROR_MALLOC;
        *head = insert_by_node(*head, search_position_by_node(*head, node->value), node);
        //*head = insert(*head, search_position(*head, node->value), node);
    }
    if (*head == NULL)
        status_work = ERROR_LENGTH;

    return status_work;
}
