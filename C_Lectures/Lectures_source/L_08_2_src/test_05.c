/*
Слайд 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 1;
    double d = 5.0;
    int *p = &a;
    /*
    // error: initialization from incompatible pointer type
    int *p_err = &d;
    */

    int *q = p;
    /*
    // error: initialization from incompatible pointer type
    double *q_err = p;
    */

    int *r = NULL;
    int *r_ok = 0;
    /*
    // error: initialization makes pointer from integer without a cast
    int *r_err = 12345;
    */

    return 0;
}