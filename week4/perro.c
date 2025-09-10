#include <stdio.h>
#include <errno.h>

int main () {
   FILE * pf;
   pf = fopen ("unexist.txt", "r");
    
   if (pf == NULL) {
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
   } else {
        fclose (pf);
   }  
   return 0;
}
