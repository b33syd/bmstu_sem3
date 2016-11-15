/*
Слайд 4
*/

int main(void)
{
    int a[3][3] =
    {
        {1, 2, 3},
        {4, 5}
    };

    int d[][2] =
    {
        {1, 2}
    };

    /*
    int e[][] =
    {
        {1, 2},
        {4, 5}
    };
    // error: array type has incomplete element type
    */

    int b[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // warning: missing braces around initializer [-Wmissing-braces]

    // c99
    int c[2][2] = {[0][0] = 1, [1][1] = 1};

    (void) a;
    (void) b;
    (void) c;
    (void) d;


    return 0;
}