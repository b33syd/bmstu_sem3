/*
К слайдам 11, 12
*/

struct date
{
    int day;
    int month;
    int year;
};

#define NAME_LEN 15

struct person
{
    char name[NAME_LEN+1];
    struct date birth;
};


int main(void)
{
    struct date today = {28, 10, 2015};

    struct date day = {28};

    /*
    struct date year = {, , 2015};
    // error: expected expression before ',' token
    */

    struct person rector = {"Aleksandrov", {7, 4, 1951}};

    struct date holidays[] = {{1, 11, 2015}, {3, 11, 2015}, {8, 11, 2015}};

    struct date year = {.year = 2015};

    struct date yesterday = {.year = 2015, .month = 10, .day = 27};

    (void) today;
    (void) day;
    (void) rector;
    (void) holidays;
    (void) year;
    (void) yesterday;
}