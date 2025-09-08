#include <stdio.h>
#define max(A,B) A>B ? A : B

int main()
{
    printf("The max of 5-2 and 7-3 plus 4 is %d\n", max(5-2,7-3)+4);
}