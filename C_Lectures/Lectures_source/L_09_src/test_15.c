/*
������ 24 - 26
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n_words(char *s)
{
    int k = 0, n = strlen(s);

    for (int i = 0; i < n; i++)
        if (!strchr("\n ,.!?", s[i])) // ������� ������ - ��-�����������!
            if (i == 0 || strchr("\n ,.!?", s[i - 1])) // � ���������� - �����������.
                k++;

    return k;
}


int split(char *s, char *w[])
{
    int k = 0, n = strlen(s);

    for (int i = 0; i < n; i++)
        if (strchr("\n ,.!?", s[i])) // ������� ������ - �����������
            // �������� ��� �� ������� ����� ������.
            s[i] = 0; 
        else // ������� ������ - �� �����������.
            if (i == 0 || s[i - 1] == 0) // � ���������� - �����������
                // � ������ ���� ���������� ����� �������� �������.
                w[k++] = s + i; 

    return k;
}


void print_words(char *s)
{
    int k = n_words(s);

    if (k == 0) 
        return; // ��� ���� - ������ �� ������

    // ����� ������ - ����� ��������� (k) �� ������ ������ ��������
    // (sizeof(w[0]))
    char **w = malloc(k * sizeof(w[0]));

    split(s, w);

    for (int i = 0; i < k; i++)
        printf("[%s]\n", w[i]);

    free(w);
}


int main(void)
{
    char str_test_1[] = "   This   is a,,, test string!!!";
    char str_test_2[] = "\n   \n....\n,,,,\n?.!";
    char str_test_3[] = "";

    print_words(str_test_1);
    print_words(str_test_2);
    print_words(str_test_3);

    return 0;
}
