// zombieProblem.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork(); 

    if (pid > 0) // pid is non-zero, MUST be the parent
    {

    }
    else if (pid == 0) // child process
    {
        printf("I am about to execute ls \n");
        execlp("/bin/sh", "/bin/sh", NULL);
        printf("I am done with the ls \n");
    }
}
