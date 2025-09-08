#include <stdio.h>
#include "nano.h"

int main()
{
    printf("Enter the string: ");
    char buffer[100];
    scanf("%s", buffer);
    if (hasNano(buffer)){
        printf("String has \"nano\"\n");
    }else{
        printf("String does not have \"nano\"\n");
    }
}