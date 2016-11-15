#include <assert.h>
#include <stdio.h>
#include "list.h"

          
int main(void)
{
    struct list_node *head = NULL, *node;

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

    // 5
    node = create_node(5);
    assert(node);
    head = add_front(head, node);

    // Вывод списка
    print(head);

    // Удаление из середины
    node = del_by_value(head, 3);
    if (node)
        head = node;

    print(head);

    // Удаление из "хвоста"
    node = del_by_value(head, 1);
    if (node)
        head = node;

    print(head);

    // Удаление из "головы"
    node = del_by_value(head, 5);
    if (node)
        head = node;

    print(head);

    // Удаление того, чего нет
    node = del_by_value(head, 100);
    if (node)
        head = node;

    print(head);

    free_all(head);
    head = NULL;

    return 0;
}