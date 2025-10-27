//passenv.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
extern char** environ;
int main(int argc, char* argv[], char* envp[])
{
    if (argc !=2){
        printf("USAGE: %s [1-3]", argv[0]);
        exit(1);
    }
    //construct the argument array
    char* ev[2] = {"./env", NULL};

    //construct environmental variable array
    char* newenv[3] = {"AAA=aaa", "BBB=bbb", NULL};

    switch(argv[1][0]){
        case '1'://passing no environmental variable
            execve(ev[0], ev, NULL);
        case '2'://passing a new set of environmental variables
            execve(ev[0], ev, newenv);
        case '3'://passing all environmental variable
            execve(ev[0], ev, environ);
        default:
            execve(ev[0], ev, NULL);
    }
}
