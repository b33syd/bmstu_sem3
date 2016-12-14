/*
К слайду 23
*/

#define NAME_LEN        20
#define TITLE_LEN       20
#define PUBLISHER_LEN   10

struct library_item
{
    int number;
    int item_type;

    union
    {
        struct
        {
            char author[NAME_LEN + 1];
            char title[TITLE_LEN + 1];
            char publisher[PUBLISHER_LEN + 1];
            int year;
        } book;

        struct
        {
            char title[TITLE_LEN + 1];
            int year;
            int volume;
        } magazine;

    } item;
};