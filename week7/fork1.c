#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();  // int pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "the process creation failed\n"); 
    }
    else if (pid == 0)
    {
        printf("This is a message from the child\n");  
        printf("My PID is %d my parent PID is %d\n", getpid(), getppid());   
    
    }
    else
    {
        printf("This is a message from the parent\n");
        printf("My PID is %d my child PID is %d\n", getpid(), pid); 
	    //sleep(1);
    }
    return 0;
}
