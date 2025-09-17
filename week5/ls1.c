#include <stdio.h>
#include <dirent.h>

int main(int arc, char *argv[])
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir("."))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            printf("%s\n", pEntry->d_name);
        }
    }
    closedir(pDir);
}
