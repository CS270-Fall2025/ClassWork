//testintmath.c
#include <stdio.h>
#include "intmath.h"
//#include "intmath.h"

int main()
{
    int i, j;
    printf("Enter the first integer: ");
    scanf("%d", &i);
    printf("Enter the second integer: ");
    scanf("%d", &j);
    printf("Greatest common divisor: %d.\n", gcd(i, j));
    printf("Least common multiple: %d.\n", lcm(i, j));
    return 0;
}
