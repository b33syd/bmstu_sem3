/*
К слайду 23
*/

#define NAME_LEN        20
#define TITLE_LEN       20
#define PUBLISHER_LEN   10


struct book_t
{
    char    author[NAME_LEN + 1];
    char    title[TITLE_LEN + 1];
    char    publisher[PUBLISHER_LEN + 1];
    int     year;
};


struct magazine_t
{
    char    title[TITLE_LEN + 1];
    int     year;
    int     volume;
};


union item_t
{
    struct book_t       book;
    struct magazine_t   magazine;    
};


typedef enum { KIND_BOOK, KIND_MAGAZINE } kind_item_t;


struct library_item_t
{
    int          number;
    kind_item_t  kind;
    union item_t item;
};