/*
����� 3
*/

#include <stdio.h>

int main(void)
{
    char *p = "abc", ch;

    printf("addr(p) %p, addr(\"abc\") %p\n", p, "abc");
    // addr(p) 0040a064, addr("abc") 0040a064

    ch = "abc"[1];

    printf("ch = %c\n", ch);
    // ch = b

    // ������ ������� ����������
    *p = 'j';
    // �.�. ��������� ���� �� ������� p ��� "const char *p"

    return 0;
}