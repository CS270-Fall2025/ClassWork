#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    printf("Original process with PID %d and PPID %d.\n", getpid(), getppid());
    pid = fork(); 

    if (pid > 0) // pid is non-zero, MUST be the parent
    {
        printf("Parent process with PID %d and PPID %d.\n", getpid(), getppid());
        printf("My child's PID is %d\n", pid);
    }
    else if (pid == 0) // child process
    {
        // sleep(5); // Make sure that the parent terminates first
        printf("Child process with PID %d and PPID %d.\n", getpid(), getppid());
    }
    printf("PID %d terminates.\n", getpid()); // both process with execute this
    return EXIT_SUCCESS;
}
