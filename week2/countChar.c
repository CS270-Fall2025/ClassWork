/**
 * @file charcount.c
 *
 * Write to stdout the number of chars in stdin.
 */
#include <stdio.h>

int main()
{
    int c;
    int charCount = 0;
    printf("Enter something or Ctrl+D to stop: \n");
    while (1)
    {
        c = getchar();
        if (c == EOF)
            break;
        ++charCount;
    }

    printf("You enter %d characters\n", charCount);
    return 0;
}
