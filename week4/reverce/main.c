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
    char * newBuffer= malloc((charRead+1)*sizeof(char));
    int end = 0, start = 0;
    start = end = charRead-1;
    int index = 0; //write position in new buffer
    if (buffer[charRead-1]=='\n'){
        newBuffer[index++] = '\n';
        end--;
        start--;
    }
    for (int i = end; i>-1; i--){
        if (buffer[i]!='\n'){
            start--;
        }else{
            strncpy(newBuffer+index, buffer+start, end-start+1);
            start = end = i-1;
            index += end-start+1;
        }
    }
    
    if(write(1, newBuffer, charRead)!=charRead){
        perror(("Problem writing"));
        exit(1);
    }


}