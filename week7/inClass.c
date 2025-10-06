#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int A[] = {1, 2, 3, 4, 5, 6};
    int sum = 0, product = 1, pid;

    if ((pid=fork()) == 0)
    {
        for (int i = 0; i < 6; i++) 
        {
            sum += A[i];
        }
        sleep(3);
        printf("This is child process computed sum %d \n", sum);
    }
    if (pid < 0) 
    {
        fprintf(stderr, "problem creating a process \n");
    }
    if (pid > 0) 
    {
        for (int i = 0; i < 6; i++)
        {
            product *= A[i];
        }
        printf("The parent process completed the product %d \n", product);
        sleep(4);
    }
 
    return 0;
}
