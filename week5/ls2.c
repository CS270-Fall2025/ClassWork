#include <stdio.h>
#include <dirent.h>

void doLs(const char * dirName);

int main(int argc, char *argv[])
{
    if (argc == 1){
        doLs(".");
    }else{
        while(--argc){
            printf("\n%s:\n", *++argv);
            doLs(*argv);
        }
    }
}
/**
 * @brief List file in directory 
 * 
 * @param dirName name of directory
 */
void doLs(const char * dirName)
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir(dirName))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            printf("%s\n", pEntry->d_name);
        }
    }
}
