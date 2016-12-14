#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct data
{
    int value;

    struct list_head full_list;
    struct list_head odd_list;
};


int main(void)
{
    struct data *obj;
    struct list_head *iter, *iter_safe;

    LIST_HEAD(full_list);
    LIST_HEAD(odd_list);

    for (int count = 1; count < 11 ; count++)
    {
        obj = malloc(sizeof(struct data));
        if (!obj)
            break;

        obj->value = count;

        list_add(&obj->full_list, &full_list);

        if (obj->value % 2)
            list_add(&obj->odd_list, &odd_list);
    }

    printf("Print full list\n");

    list_for_each(iter, &full_list)
    {
        obj = list_entry(iter, struct data, full_list);
        printf("%d\n", obj->value);
    }

    printf("Print odd list\n");

    list_for_each_entry(obj, &odd_list, odd_list)
    {
        printf("%d\n", obj->value);
    }

    printf("Cleaning up\n");

    list_for_each_safe(iter, iter_safe, &full_list)
    {
        obj = list_entry(iter, struct data, full_list);

        list_del(iter);

        free(obj);
    }

    return 0;
}
