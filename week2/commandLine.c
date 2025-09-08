#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("This program was called with %d arguments\n", argc-1);

    for (i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);
}
