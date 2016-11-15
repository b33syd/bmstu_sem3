struct date
{
    int day;
    int month;
    int year;
};

struct person
{
    char        name[32];
    struct date birthday;
};


struct point_2d
{
    double x, y;
};

void f(void)
{
    struct point_2d triangle[3];
}

