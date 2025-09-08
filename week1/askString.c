/*Exercise: Write a program that asks the user for the size of the input, dynamically allocates the array to hold this size, then asks the user for the string, stores this string in a dynamically allocated array, and prints it back.
Example of output:
Enter the size of input: 50
Please, enter the string: I like NIC
You entered: I like NIC
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter the size of input: ");
    int size;
    scanf("%d", &size);

    char * str= malloc(sizeof(char)*size);
    if (!str){
        fprintf(stderr,"memory allocation error!");
        exit(1);
    }
    printf("Please, enter the string: ");
    getchar();//remove \n from the input buffer
    if(fgets(str, size, stdin)){
        printf("You entered: %s", str);
    }
    free(str);
}