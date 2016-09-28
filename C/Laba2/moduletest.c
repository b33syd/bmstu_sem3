#include <stdio.h>
#include <stdlib.h>
#include "list.h"


#define FAILED -1;

#define OK 0

int test_create_node(int value)
{
    int status = OK;
    struct list *node = create_node(value);
    if (node)
    {
        if ((node->next != NULL) && (node->value != value))
        {
            status = FAILED
        };
    }

    free_all(node);
    return status;
}

int test_add_front()
{
    int status = OK;
    struct list *head = NULL;
    struct list *node = create_node(1);
    head = add_front(head, node);

    if (head->value != 1)
    {
        status = FAILED;
    }

    node = create_node(2);
    head = add_front(head, node);

    if ((head->value != 2) && (head->next->value != 1))
    {
        status = FAILED;
    }

    free_all(head);
    return status;
}

int test_add_end()
{
    int status = OK;
    struct list *head = NULL;
    struct list *node = create_node(1);
    head = add_end(head, node);

    if (head->value != 1)
    {
        status = FAILED;
    }

    node = create_node(2);
    head = add_end(head, node);

    if ((head->value != 1) && (head->next->value != 2))
    {
        status = FAILED;
    }

    free_all(head);
    return status;
}

int test_search_position()
{
    int status = OK;
    struct list *head = NULL;
    struct list *node;

    node = create_node(1);
    head = add_end(head, node);

    node = create_node(2);
    head = add_end(head, node);

    node = create_node(3);
    head = add_end(head, node);

    if (search_position_by_node(head, 1) != NULL)
    {
        status = FAILED
    };
    if (search_position_by_node(head, 2) != head)
    {
        status = FAILED
    };
    if (search_position_by_node(head, 3) != head->next)
    {
        status = FAILED
    };

    free_all(head);
    return status;
}

int test_insert()
{
    int status = OK;
    struct list *head = NULL;
    struct list *node;

    node = create_node(1);
    head = add_end(head, node);

    node = create_node(3);
    head = add_end(head, node);

    //вставка вперд
    node = create_node(0);
    head = insert_by_node(head, NULL, node);

    //вставка в серидину
    node = create_node(2);
    head = insert_by_node(head, head->next, node);

    //вставка в конец
    node = create_node(4);
    head = insert_by_node(head, head->next->next->next, node);
    
    //print(head );

    int i = 0;
    for (; head; head = head->next, i++)
    {
        if (head->value != i)
        {
            status = FAILED
        };
    }
    if (i != 5)
        status = FAILED;

    free_all(head);
    head = NULL;

    return status;
}

int compare(struct list *head, int *array, int length)
{
    int status = OK;
    int i = 0;


    for (; head; head = head->next, i++)
    {
        if (head->value != array[i])
        {
            status = FAILED
            break;
        };
        //printf("            %d\n",head->value );
    }
    //printf("%d\n %d\n",i,length );    

    if (length != i)
    {
        status = FAILED;
        //printf("inwork\n");
    }

    return status;
}

int test_read_list_from_file()
{
    int status = OK;
    struct list *head = NULL;
    FILE * file = fopen("tests/normal", "r");
    if (file)
    {
        status = read_list_from_file(&head, file);
    }

    int control_array1[] = { 2, 8, 18, 27, 30, 34, 34, 34, 34, 36, 41, 44, 44, 46, 49, 50, 52, 65, 68, 68, 72, 72, 73,
        75, 80, 90, 92, 93, 99, 99, 99, 100 };
   
    status = compare(head, control_array1, 32);

    free_all(head);
    head = NULL;

    return status;
}


int test_distributor()
{
    int status = OK;
    struct list *head = NULL, *even = NULL, *odd = NULL;
    FILE * file = fopen("tests/normal", "r");
    if (file)
    {
        status = read_list_from_file(&head, file);
    }
    distributor(head, &even, &odd);
    
    int control_array_even[] = { 2, 8, 18, 30, 34, 34, 34, 34, 36, 44, 44, 46, 50, 52, 68, 68, 72, 72, 80, 90, 92,100 };
    
    status = compare(even, control_array_even, 22);

    if (status == OK)
    {
        int control_array_odd[] = { 27, 41, 49, 65, 73, 75, 93, 99, 99, 99 };
        status = compare(odd, control_array_odd, 10);
    }
    free_all(head);
    free_all(even);
    free_all(odd);
    head = NULL;
    odd = NULL;
    even = NULL;

    return status;
}


char *answer(int val)
{
    char *answer = "FAILED";
    if (val == OK)
    {
        answer = "OK";
    }
    return answer;
}

int main()
{
    printf("test create_node %s\n", answer(test_create_node(6)));
    printf("test add_front %s\n", answer(test_add_front()));
    printf("test add_end %s\n", answer(test_add_end()));
    printf("test search_position %s\n", answer(test_search_position()));
    printf("test insert %s\n", answer(test_insert()));
    printf("test read_list_from_file %s\n", answer(test_read_list_from_file()));
    printf("test distributor %s\n", answer(test_distributor()));



    //printf("test count_file_length 2 %s\n", answer(test_count_file_length("tests/normal", 15)));

    //int control_array1[6] = { 1000, 1, 2, 3, 4, 5 };
    //   printf("test readfromfile 1 %s\n", answer(test_readfromfile("tests/first_max", 6, control_array1)));
    return 0;
}