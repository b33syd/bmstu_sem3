/*
К слайдам 13-15
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct date
{
    int day;
    int month;
    int year;
};

void print(struct date d)
{
    printf("%02d.%02d.%04d\n", d.day, d.month, d.year);
}

void print_ex(const struct date *d)
{
    printf("%02d.%02d.%04d\n", d->day, d->month, d->year);
}

struct date get_student_date(void)
{
    struct date d = {25, 1, 2016};

    return d;
}

int main(void)
{
    struct date today, *tomorrow, some_date;

    today.day   = 28;
    today.month = 10;
    today.year  = 2015;

    tomorrow = malloc(sizeof(struct date));
    if (!tomorrow)
    {
        fprintf(stderr, "Memory allocation error");

        return -1;
    }

    tomorrow->day = 29;
    tomorrow->month = 10;
    (*tomorrow).year = 2015;

    some_date = today;

    /*
    if (today == *tomorrow)
    // error: invalid operands to binary == (have 'struct date' and 'struct date')
    {
        assert(0);
    }
    */

    print(today);

    print_ex(&some_date);

    some_date = get_student_date();

    print_ex(&some_date);

    free(tomorrow);

    /*
    {
        struct
        {
            int a;
        } a;

        struct
        {
            int a;
        } b;

        a = b;
        // error: incompatible types when assigning to type 'struct <anonymous>' from type 'struct <anonymous>'
    }
    */

    return 0;
}