//intmath.c
#include "intmath.h"

int gcd(int i, int j)
{
    assert(i > 0);
    assert(j > 0);

    int temp;
    while (j != 0)
    {
        temp = i % j;
        i = j;
        j = temp;
    }
    return i;
}

int lcm(int i, int j)
{
    assert(i > 0);
    assert(j > 0);

    return (i / gcd(i, j))*j;
}
