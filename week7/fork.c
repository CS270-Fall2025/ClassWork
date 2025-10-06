#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("My pid is %d\n", getpid());
    fork();
    fork();
    fork();
    printf("My pid is %d\n", getpid());
    return 0;
}
