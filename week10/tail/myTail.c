#include "myTail.h"

void wrongArg(char * command){
    fprintf(stderr, "Usage: %s [-n [+]NUM] file\n", command);

}
/**
 * @brief Prints last ten lines from the file. Assume all lines less then 256 bytes
 * 
 * @param file 
 */
void printTenLines(char *file){
    printLastNLines(file, 10);
}

void printLastNLines(char * file, int n){
//printf("Printing last %d lines\n", n);
    int NUM_LINES=n;
    int fd = openFile(file);
    //char lines[NUM_LINES][MAX_LINE_LENGTH];
    char **lines = malloc(NUM_LINES * sizeof(char *));
    int linesStord=0;//will equal NUM_LINES, if file has more or equal then NUM_LINES lines
    int start=readFileIntoArray(lines, fd, &linesStord, NUM_LINES);
    printLines(lines, start, linesStord, NUM_LINES);
    freeMemory(lines, NUM_LINES);
}

void lastOrFirst(char * args[]){
    int plus=0;
    char numOfLines[10];
    if (strcmp(args[1], "-n")==0){
        if (args[2][0]=='+'){
            strcpy(numOfLines, args[2]+1);
            plus=1;
        } else{
            strcpy(numOfLines, args[2]);
        }

        if (isNumber(numOfLines)){
            int num=atoi(numOfLines);
            if (plus)
                printFirstNLines(args[3], num);
            else
                printLastNLines(args[3], num);
        }
        else{
            wrongArg(*args);
        }

    }else{
        wrongArg(*args);
    }
}

int openFile(char * file){
    int fd;
    if ((fd = open(file, O_RDONLY))== -1){
        perror(file);
        exit(1);
    }
    return fd;
}
/**
 * @brief This function reads file and stor last numLines in the 2D array
 * 
 * @param lines10 2D array
 * @param fd file descripter
 * @param linesStored determines when array was filled, next read will overwrite the array
 * @param numLines num of lines array can hold 
 * @return int position of the next line (first out of numLines to print)
 */
int readFileIntoArray(char ** linesArr, int fd, int * linesStored, int numLines){
    int full = 0;//array is not full
    char buffer[SIZE_BUFFER];
    int bytes;//actuale number of bytes read. if <SIZE_BUFFER, we done reading
    int storePos=0, partLine=0;
    int partialLen; //lenth of part string at the end of the buffer
    char *line=NULL;
    while ((bytes = read(fd, buffer, SIZE_BUFFER)) != 0){
        //go through the buffer and find '\n'
        int start = 0, pos = 0, len;
        //char line[MAX_LINE_LENGTH];
        while (pos<bytes){
            if (buffer[pos] =='\n'){
                len = pos + 1 - start;
                if (partLine==1){//line points at the begining of the line
                    //char secondPart[MAX_LINE_LENGTH];
                    char * secondPart = malloc(len+1);//allocate space for the second part of the string
                    strncpy(secondPart, buffer+start, len);//store the part of line in this space
                    secondPart[len]='\0';//need latter for strcpy
                    if (full==1)
                        free(linesArr[storePos]);
                    //allocate enough space to hold both part of line
                    linesArr[storePos]=malloc(partialLen+len+1 * sizeof(char));
                    strcpy(linesArr[storePos], line);//coppy line
                    linesArr[storePos][partialLen]='\0';//remove '\n'
                    strcat(linesArr[storePos], secondPart);
                    linesArr[storePos][partialLen+len]='\0';//just in case
                    //linesArr[storePos][10]='\0';
                    partLine=0;
                    //free memory
                    free(secondPart);
                    free (line);
                    secondPart=NULL;
                    line=NULL;
                    // printf("********Writing at position %d***********\n", storePos);
                    // printf("In array %s\n", linesArr[storePos]);
                } else{
                    if (full==1)
                        free(linesArr[storePos]);
                    linesArr[storePos]=malloc(len +1* sizeof(char));//point pointer to the newaly alocated space
                    strncpy(linesArr[storePos],buffer+start, len);//copy substring from buffer into this space
                    linesArr[storePos][len]='\0';
                    // printf("********Writing at position %d***********\n", storePos);
                    // printf("In buffer %.*s\n", len, buffer+start);
                    // printf("In array %s\n", linesArr[storePos]);
                }
                start = pos+1;//reset start
                storePos++;
                if (storePos==numLines){//fill the arrat
                    full=1;
                    storePos=0;//restart
                }
            }
            pos++;
        }
        //check for the part of line at the end of buffer
        if (buffer[pos-1]!='\n'){
            if (line==NULL){
                partialLen=pos-start;
                line = malloc(partialLen+2*sizeof(char));
                strncpy(line, buffer+start, partialLen+2);
                line[partialLen]='\n';
                line[partialLen+1]='\0';//need for strcan

            } else{//nonfinish line in buffer befor and in current buffer

                char * beforeLine = line;
                beforeLine[partialLen]='\0';//remove \n
                partialLen=partialLen+pos-start;
                line = malloc(partialLen+2*sizeof(char));

                char *newLine=malloc(pos-start+2*sizeof(char));
                strncpy(newLine, buffer+start, pos-start);
                newLine[pos-start]='\n';
                newLine[pos-start+1]='\0';//need for strcan

                strcat(line, newLine);//combine two pices

                //free memory
                free(beforeLine);
                free(newLine);
            }
            partLine=1;
        }

        if(bytes<SIZE_BUFFER){//we are done reading file
            if (partLine==1){//but ther is a part of line without '\n'
                if (full==1)
                    free(linesArr[storePos]);
                linesArr[storePos]=line;
                line=NULL;
                // printf("********Writing at position %d***********\n", storePos);
                // printf("In buffer %.*s\n", len, buffer+start);
                // printf("In array %s\n", linesArr[storePos]);
                storePos++;
                if (storePos==numLines){
                    storePos=0;
                }
            }
            break;
        }
            
    }

    *linesStored=(full) ? numLines : storePos;

    return full ? storePos : 0;
}

void printLines(char ** lines, int start, int count, int numLines){
    //int fd = open("/dev/tty", O_WRONLY);
    for (int i = 0; i < count; i++){
        //printf("%s",lines[start]);
        write(1, lines[start], strlen(lines[start]));
        start++;
        if (start == numLines){
            start = 0;
        }
    }
}

int isNumber(char * value){
    for (int i =0; i< strlen(value); i++){
        if (!isdigit(value[i]))
            return 0;
    }
    return 1;
}

void printFirstNLines(char * file, int n){
    printf("Printing first %d lines\n", n);
    int fd_in = openFile(file);
    int fd_out = open("/dev/tty", O_WRONLY);
    char buffer[SIZE_BUFFER];
    int bytes;//actuale number of bytes read. if <SIZE_BUFFER, we done reading
    int numOfLines=0;
    while (numOfLines<n){
        bytes = read(fd_in, buffer, SIZE_BUFFER);
        //go through the buffer and find '\n'
        int start = 0, pos = 0, len;
        while (pos<bytes && numOfLines<n){
            if (buffer[pos] =='\n'){
                len = pos+1 - start;
                write(fd_out, buffer+start, len);
                numOfLines++;
                start = pos+1;//reset start
            }
            pos++;
        }//end of buffer

        //check for the part of line at the end of buffer
        if (buffer[pos-1]!='\n'){
            len = pos+1 - start;
            write(fd_out, buffer+start, len);
        }

        if(bytes<SIZE_BUFFER){//we are done reading file
            break;
        }  
    }   
    close(fd_in);
    close(fd_out);       
}

void freeMemory(char **lines, int numLines){
    for (int i = 0; i<numLines;i++){
        free(lines[i]);
        lines[i]=NULL;
    }
}