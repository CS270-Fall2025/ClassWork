/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Program reverce the lines in the file
 * @date 2025-09-11
 * @assumption File is small enough to fit in the buffer
 */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(int argc, char * argv[])
{
    int fd = open("test.txt", O_RDONLY);
    if (fd ==-1){
        perror("Can't open file: ");
        exit(1);
    }
    //printf("fd = %d\n", fd);

    char buffer[SIZE];
    int charRead;
    if ((charRead=read(fd, buffer, SIZE))==-1){
        perror("Problem with reading: ");
        exit(1);
    }
    //output will be the same number of characters (no '\n' after last line)
    char * newBuffer= malloc((charRead)*sizeof(char));
    int end = 0, start = 0;
    start = end = charRead-1; //set to the last character
    int index = 0; //write position in new buffer

    //check if file had a \n at the end, if it is, make first line empty
    if (buffer[charRead-1]=='\n'){
        newBuffer[index++] = '\n';
        end--;
        start--;
    }
    
    for (int i = end; i>0; i--){
        if (buffer[i]!='\n'){
            start--;
        }else{
            strncpy(newBuffer+index, buffer+start+1, end-start);
            index += end-start;
            newBuffer[index++]='\n';//put \n at the end of each line
            start = end = i-1;
        }
    }
    //last copy - first line from the buffer
    strncpy(newBuffer+index, buffer, end+1);
    
    if(write(1, newBuffer, charRead)!=charRead){
        perror(("Problem writing"));
        exit(1);
    }


}