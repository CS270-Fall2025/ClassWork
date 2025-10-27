#include <stdio.h>
#include <stdlib.h>
#include "myTail.h"

int main(int argc, char * args[]){
    switch (argc){
        case 1: wrongArg(*args); exit(1);
        case 2: printTenLines(args[1]); break;//tail file
        case 3: wrongArg(*args); exit(1);
        case 4: lastOrFirst(args); break;//tail -n 5 line or tail -n +5 file
        default: wrongArg(*args); exit(1);
    }

    return 0;
}