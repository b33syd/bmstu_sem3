/*
Слайд 10
*/


#define N 10

void f_1(int a[N])
{
}

void f_2(int a[])
{
}

void f_3(int *a)
{
}

int main(void)
{
    int a[N];
    int b[25];

    f_1(a);
    f_1(b);

    f_2(a);
    f_2(b);

    f_3(a);
    f_3(b);

    return 0;
}