#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 4
int main()
{
    // double x=1.0/3;
    // printf("x = %lf\n", x);
    // printf("x = %10.2lf", x);
    // printf("x = %lf", x);

    char string[]="I like NIC";
    printf("string = %.4s\n", string+2);

    char *word = malloc((SIZE+1)*sizeof(char));
    strncpy(word, string+2, SIZE);
    printf("word = %s\n", word);
    word[SIZE]='\0';

}