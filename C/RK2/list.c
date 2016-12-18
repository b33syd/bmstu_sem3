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

struct list *add_end(struct list *head, struct list *node)
{
    // printf("TEST2");
    struct list *cur = head;

    if (!head)
        return node;
     //printf("TEST3");

    for (; cur->next; cur = cur->next);

    cur->next = node;
    // printf("TEST4");
    return head;


}

void print(struct list *head)
{    
    for (; head; head = head->next)
    {
        printf("%d->", head->value);
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



