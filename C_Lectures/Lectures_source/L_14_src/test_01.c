#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SEARCH_NAME "Sidorov"


struct person
{
    char *name;
    int born_year;

    struct person *next;
};


struct person* create_person(char *name, int born_year)
{
    struct person *pers = malloc(sizeof(struct person));

    if (pers)
    {
        pers->name = name;
        pers->born_year = born_year;
        pers->next = NULL;        
    }
        
    return pers;
}


struct person* add_front(struct person *head,
                                   struct person *pers)
{
    pers->next = head;
    return pers;
}


struct person* add_end(struct person *head, 
                                   struct person *pers)
{
    struct person *cur = head;

    if (!head)
        return pers;
    for ( ; cur->next; cur = cur->next)
        ;
    cur->next = pers;
    return head;
}


struct person* lookup(struct person *head,
                                     const char *name)
{
    for ( ; head; head = head->next)
        if (strcmp(head->name, name) == 0)
            return head;

    return NULL;
}


void apply(struct person *head,
             void (*f)(struct person*, void*),
                                         void* arg)
{
    for ( ; head; head = head->next)
        f(head, arg);
}


void print_person(struct person *pers, void *arg)
{
    char *fmt = arg;

    printf(fmt, pers->name, pers->born_year);
}


void count(struct person *pers, void *arg)
{
    int *counter = arg;

    (*counter)++;
}



void free_all(struct person *head)
{
    struct person *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


struct person* del_by_name(struct person *head,
                                         const char *name)
{
    struct person *cur, *prev = NULL;

    for (cur = head; cur; cur = cur->next)
    {
        if (strcmp(cur->name, name) == 0)
        {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;
            free(cur);
            return  head;
        }
        prev = cur;
    }

    return NULL;
}

          
int main(void)
{
    struct person *head = NULL;
    struct person *node;
    int n = 0;

    node = create_person("Ivanov", 1995);
    assert(node);
    head = add_front(head, node);

    node = create_person(SEARCH_NAME, 1994);
    assert(node);
    head = add_front(head, node);

    node = create_person("Petrov", 1995);
    assert(node);
    head = add_front(head, node);

    apply(head, print_person, "%s %d\n");

    printf("\n");

    node = create_person("Vasechkin", 1996);
    assert(node);
    head = add_end(head, node);

    apply(head, print_person, "%s %d\n");

    printf("\n");

    apply(head, count, &n);

    printf("List contains %d element(s)\n", n);

    node = lookup(head, SEARCH_NAME);

    printf("%s is in %p element\n", SEARCH_NAME, node);

    head = del_by_name(head, SEARCH_NAME);

    node = lookup(head, SEARCH_NAME);

    printf("%s is in %p element\n", SEARCH_NAME, node);

    free_all(head);

    return 0;
}