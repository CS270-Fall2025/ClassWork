/**
 * @file more2.c
 * @author Ekaterina Miller
 * @brief Read and print 24 lines then pause for a few special commands
 *        feature of version 0.2: reads from /dev/tty for commands
 * @remark Code adapted from Bruce Molay's Understanding Unix/Linux Programming
 * @version 0.2
 * @date 2020-09-14
 */
#include <stdio.h>
#include <stdlib.h>

#define PAGELEN 24
#define LINELEN 512

void doMore(FILE *);
int seeMore(FILE *);

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 1){
        doMore(stdin);//read from stdin
    }else if (argc == 2){
        if ((fp = fopen(argv[1], "r")) != NULL){
            doMore(fp);
            fclose(fp);
        } else {
            exit(1);
        }
    } else {
        printf("WRONG USAGE: %s <file>\n", argv[0]);
    } 
    
    return 0;
}

/**
 * @brief Read PAGELEN lines, then call seeMore() for
 * further instructions
 * 
 * @param fp file pointer to data file
 */
void doMore(FILE *fp)
{
    char line[LINELEN];
    int numOfLines = 0;
    FILE *fptty;

    // cmd stream
    fptty = fopen("/dev/tty", "r");
    if (fptty == NULL)
    {
        exit(1);
    }

    // read line from input
    while (fgets(line, LINELEN, fp))
    {
        // full screen?
        if (numOfLines == PAGELEN)
        {
            // read user input from terminal
            int reply = seeMore(fptty);
            if (reply == 0){
                break;
            }
            numOfLines -= reply;
        }

        // show line
        if (fputs(line, stdout) == EOF)
        {
            exit(1);
        }

        // count it
        ++numOfLines;
    }
}

/**
 * @brief Print message, wait for response, return # of lines to advance
 * q means no, space means yes, CR means one line
 * 
 * @return int numbe of lines to advance
 */
int seeMore(FILE *cmd)
{
    int c;

    printf("\033[7m more? \033[m");
    c = getc(cmd);
    if (c == 'q'){
        return 0;
    }else if (c == ' '){
        //remove '\n' from the buffer
        getc(cmd);
        return PAGELEN;
    }else if (c == '\n'){
        return 1;
    }else{
        return 0;
    } 
}