#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

void fsize(char *);
int stat(char *, Stat stat *);
void dirwalk(char *, void (*func_pointer) (char *));

/* printing size of files */
main(int argc, char *argv[]) {
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

void fsize(char *name) {
    Stat stbuf;
    
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

dirwalk(char *dir, void (*func_pointer) (char *)) {
    #define MAX_PATH 1024
    char name[MAX_PATH];
    Dirent *dir_pointer;
    Dir *dir_file_des;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dir_pointer = readdir(dir_file_des)) != NULL) {
        if (strcmp(dir_pointer->name, ".") == 0 || strcmp(dir_pointer->name, "..") == 0) 
            continue;
        if (strlen(dir) + strlen(dir_pointer->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dir_pointer->name);
        else {
            sprintf(name, "%s/%s", dir, dir_pointer->name);
            (*func_pointer) (name);
        }
    }
    closedir(dir_file_des);
}
