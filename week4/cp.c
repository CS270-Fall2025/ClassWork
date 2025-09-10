#include <stdio.h>
#include <sys/types.h> //open()
#include <sys/stat.h>//open()
#include <fcntl.h>//open()
#include <unistd.h> //read()
#include <stdlib.h> //exit()
#include <string.h> //strcm()

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];
    if (argc != 3 || strcmp(argv[1], "--help") == 0){
        printf("%s old-file new-file\n", argv[0]);
        exit(1);
    }

    /* Open input and output files */
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1){
        perror("Openning input file");
        exit(1);
    }     

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw- */

    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1){
        perror("Openning output file");
        exit(1);
    }
    /* Transfer data until we encounter the end of input or an error */
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0){
        if (write(outputFd, buf, numRead) != numRead){
            printf("couldn't write whole buffer");
            exit(1);
        }
    }
    if (close(inputFd) == -1)
        perror("close input");
    if (close(outputFd) == -1)
        perror("close output");
    return 0;
}
