#include <assert.h>
#include <stdio.h>
#include "list.h"

          
int main(void)
{
    struct list_node *head = NULL, *node;

    // 1
    node = create_node(1);
    assert(node);
    head = add_end(head, node);

    // 2
    node = create_node(2);
    assert(node);
    head = add_end(head, node);

    // 3
    node = create_node(3);
    assert(node);
    head = add_end(head, node);

    // 4
    node = create_node(4);
    assert(node);
    head = add_end(head, node);

    // Вывод списка
    print(head);

    free_all(head);
    head = NULL;

    return 0;
}