#include <string.h>
#include <stdio.h>

int main(void)
{
    char str_test_1[] = "   This   is a,,, test string!!!";
    char str_test_2[] = "\n   \n....\n,,,,\n?.!";
    char str_test_3[] = "";


    char *pword = strtok(str_test_1, "\n ,.!?");

    while (pword)
    {
        printf("[%s]\n", pword);

        pword = strtok(NULL, "\n ,.!?");
    }

    return 0;
}