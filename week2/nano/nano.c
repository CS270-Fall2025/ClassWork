#include "nano.h"

int hasNano(char * str)
{
    enum State{NOTHING, N, NA, NAN, NANO};
    enum State newState= NOTHING; 
    for (size_t i = 0; i<strlen(str); i++){
        switch(str[i]){
        case 'n': printf("n is found\n");
            break;
        case 'a': printf("a is found\n");
            break;
        case 'o': printf("0 is found\n");
            break;
        default: printf("default\n");     
        }
    } 
}