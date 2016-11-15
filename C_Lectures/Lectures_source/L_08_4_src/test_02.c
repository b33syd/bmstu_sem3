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

int main(void)
{
    struct date today = {19, 9, 2016};

    struct date day = {19};

    /*
    struct date year = {, , 2016};
    // error: expected expression before ',' token
    */

    struct person rector =
        {"Aleksandrov", {7, 4, 1951}};

    struct date holidays[] =
    {
        {4, 11, 2016}, 
        {5, 11, 2016},
        {6, 11, 2016}
    };

}