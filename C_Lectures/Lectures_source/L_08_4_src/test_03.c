#include <stdlib.h>
#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};


void print(struct date d)
{
    printf("%02d.%02d.%04d", d.day, d.month, d.year);
}


void print_ex(const struct date *d)
{
    printf("%02d.%02d.%04d", d->day, d->month, d->year);
}


struct date get_student_date(void)
{
    struct date d = {25, 1, 2017};

    return d;
}


int main(void)
{
    struct date today, *tomorrow, some_date;

    today.day   = 12;
    today.month = 9;
    today.year  = 2016;

    tomorrow = malloc(sizeof(struct date));
    if (!tomorrow)
        return -1;

    (*tomorrow).day = 13;
    tomorrow->month = 9;
    tomorrow->year  = 2016;

    some_date = *tomorrow;

    /*
    // error: invalid operands to binary == (have 'struct date' and 'struct date')
    if (some_date == *tomorrow)
        ;
    */

    print(today);

    printf("\n");

    print_ex(tomorrow);

    printf("\n");

    some_date = get_student_date();

    print_ex(&some_date);

    free(tomorrow);

    return 0;
}