#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#define True 1
#define False 0;

void doLs(const char * dirName, int l);
int isLong(int argc, char *argv[]);
void showStatInfo(const char *fname, struct stat *buf);
int main(int argc, char *argv[])
{
    int l;
    if (argc == 1){
        doLs(".", 0);
    }else{
        l = isLong(argc, argv);
        if (argc==2 && l==True){
            doLs(".", l);
        }
        else{
            int i =1;
            while(i<argc){
                if (strncmp(argv[i], "-l", 2)!=0)
                {
                    printf("\n%s:\n", argv[i]);
                    doLs(argv[i], l);   
                }
                
            } 
        }        
    }
}
/**
 * @brief List file in directory 
 * 
 * @param dirName name of directory
 * @param l -l flag. if 1 display long information for the file
 */
void doLs(const char * dirName, int l)
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir(dirName))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            if (pEntry->d_name[0] != '.')
            {
                if (l){
                    struct stat info;
                    printf("%s\n", pEntry->d_name);
                    stat(pEntry->d_name, &info);
                    showStatInfo(pEntry->d_name, &info);
                }else{
                    printf("%s\n", pEntry->d_name);
                }
            }
        }
    }
}

void showStatInfo(const char *fname, struct stat *buf)
{
    printf("   mode: %o\n", buf->st_mode);
    printf("   links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("   group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("   modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}

int isLong(int argc, char *argv[])
{
    for (int i = 1; i<argc; i++){
        if (strncmp(argv[i], "-l", 2)==0){
            return True;
        }
    }
    return False;
}

