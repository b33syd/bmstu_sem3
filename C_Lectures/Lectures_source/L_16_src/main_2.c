#include <stdlib.h>
#include <stdio.h>
#include "list.h"


struct data
{
    int num;

    struct list_head list;
};


int main(void)
{
    //
    // ����������� ���������� ��� "���������" ������
    //

    struct data num_list;

    INIT_LIST_HEAD(&num_list.list);

    //
    // ���������� ��������� � ������
    //

    struct data *item;

    for (int i = 0; i < 10; i++)
    {
        // 1. ��������� ������ ��� ������
        item = malloc(sizeof(*item));
        if (!item)
            break;

        // 2. ������������� ������

        item->num = i;

        INIT_LIST_HEAD(&item->list);
        // ���� "�����" ����� ��������, ������ ��� ���� next � prev 
        // ���������������� � ������� list_add

        // 3. ���������� ������ �������� item � ������ ��������� ������ num_list
        list_add(&(item->list), &num_list.list);

        // ����� ���� �� ������������ � list_add_tail
    }

    //
    // ��������� (������) ��������� ������
    //

    struct list_head *iter;

    list_for_each(iter, &num_list.list)
    {
        item = list_entry(iter, struct data, list);

        printf("[LIST] %d\n", item->num);
    }

    printf("\n");

    list_for_each_entry(item, &num_list.list, list)
        printf("[LIST] %d\n", item->num);

    printf("\n");

    //
    // ������������
    //

    struct list_head *iter_safe;

    list_for_each_safe(iter, iter_safe, &num_list.list)
    {
        item = list_entry(iter, struct data, list);
        // ������� ������� ������
        list_del(iter);

        free(item);
    }

    return 0;
}
