#include "a.h"


extern int f(int i)
{
    return i;
}


static int g(int i)
{
    return i * i;
}


int h(int i)
{
    return g(i);
}
