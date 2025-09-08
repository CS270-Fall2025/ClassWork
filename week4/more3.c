/**
 * @file more2.c
 * @author Ekaterina Miller
 * @brief Read and print 24 lines then pause for a few special commands
 *        feature of version 0.2: reads from /dev/tty for commands
 * @remark Code adapted from Bruce Molay's Understanding Unix/Linux Programming
 * @version 0.3
 * @date 2024-09-6
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>//change canonical to non-canonical mode
#include <sys/ioctl.h>//terminal size

//#define PAGELEN 24
#define LINELEN 512

void doMore(FILE *, int pl);
int seeMore(FILE *, int pl);

int main(int argc, char **argv)
{
    //terminal size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int pagelen = w.ws_row - 1;

    FILE *fp;

    if (argc == 1){
        doMore(stdin, pagelen);//read from stdin
    }else if (argc == 2){
        if ((fp = fopen(argv[1], "r")) != NULL){
            doMore(fp, pagelen);
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
void doMore(FILE *fp, int pl)
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
        if (numOfLines == pl)
        {
            // read user input from terminal
            int reply = seeMore(fptty, pl);
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
 * @aknolegment https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only
 */
int seeMore(FILE *cmdp, int pl)
{
    int c;
    printf("\033[7m more? \033[m");

    int cmdd = fileno(cmdp);//get descripter from pointer
    static struct termios oldt, newt;
    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr(cmdd, &oldt);
    /*now the settings will be copied*/
    newt = oldt;

    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON);          

    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr( cmdd, TCSANOW, &newt);
    
    c = getc(cmdp);
    /*restore the old settings*/
    tcsetattr( cmdd, TCSANOW, &oldt);
    if (c == 'q'){
        printf("\n");
        return 0;
    }else if (c == ' '){
        //remove '\n' from the buffer
        //getc(cmd); no need
        printf("\n");
        return pl;
    }else if (c == '\n'){
        return 1;
    }else{
        return 0;
    } 
}