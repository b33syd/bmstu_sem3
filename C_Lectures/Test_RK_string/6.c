#include <stdio.h>
/*
1234567890 abcd.
234567890 abcd.
1234567
34567

*/
int main(void)
{
    char note[] = "1234567890 abcd.";
    char *ptr = note;

    puts(ptr);
    // Ответ


    puts(++ptr);
    // Ответ


    note[7] = '\0';

    puts(note);
    // Ответ


    puts(++ptr);
    // Ответ


    return 0;
}
