#include <assert.h>
#include <stdio.h>
#include "list.h"

          
int main(void)
{
    struct list_node *head = NULL, *node;
    int num;

    // 1
    node = create_node(1);
    assert(node);
    head = add_front(head, node);

    // 2
    node = create_node(2);
    assert(node);
    head = add_front(head, node);

    // 3
    node = create_node(3);
    assert(node);
    head = add_front(head, node);

    // 4
    node = create_node(4);
    assert(node);
    head = add_front(head, node);

    // Вывод списка
    print(head);

    // Поиск значения

    num  = 3;
    node = lookup(head, num);

    if (node)
        printf("Found %d at %p address\n", node->num, node);
    else
        printf("%d not found in list\n", num);

    num  = 100;
    node = lookup(head, num);

    if (node)
        printf("Found %d at %p address\n", node->num, node);
    else
        printf("%d not found in list\n", num);

    free_all(head);
    head = NULL;

    return 0;
}