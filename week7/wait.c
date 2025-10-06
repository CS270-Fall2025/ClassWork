// wait.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid;

    if ((pid = fork()) == 0)
    {
        printf("Child %d playing...\n", getpid());
        sleep(3);
        printf("Child %d is done playing!\n", getpid());
        //exit(12);
    }
    else
    {
        printf("Parent needs to go home and do something\n");
        printf("But child is playing...\n");
        int childStatus;
        int pidWait = wait(&childStatus);
        if (WIFEXITED(childStatus))
            //printf("child %d has terminated with status %d\n", pidWait, WEXITSTATUS(childStatus));
       printf("child %d has terminated with status %d\n", pidWait, childStatus>>8);

        printf("Parent is going home\n");
    }
    return 0;
}
