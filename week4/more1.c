/**
 * @file more1.c
 * @author Ekaterina Miller
 * @brief Read and print 24 lines then pause for a few special commands
 * @remark Code adapted from Bruce Molay's Understanding Unix/Linux Programming
 * @version 0.1
 * @date 2024-09-6
 */
#include <stdio.h>
#include <stdlib.h>

#define PAGELEN 24
#define LINELEN 512

void doMore(FILE *);
int seeMore();

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 2){
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
    int reply;

    // more input
    while (fgets(line, LINELEN, fp))
    {
        // full screen?
        if (numOfLines == PAGELEN)
        {
            // y: ask user
            reply = seeMore();
            // n: done
            if (reply == 0)
            {
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
int seeMore()
{
    int c;
    printf("\033[7m more? \033[m");
    c = getchar();
    if (c == 'q'){
        return 0;
    }else if (c == ' '){
        //remove '\n' from the buffer
        getchar();
        return PAGELEN;
    }else if (c == '\n'){
        return 1;
    }else{
        return 0;
    }   
}
