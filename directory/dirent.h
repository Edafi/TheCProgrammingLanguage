#include "stat.h"
#include <sys/dir.h>
//#include <sys/stat.h>

#define NAME_MAX 14

typedef struct List_files {
    int inode;                  // file index
    char name[NAME_MAX + 1];    // name of the file
} Dirent;   

typedef struct Directory {
    int file_des;               // file descriptor of directory
    Dirent file;                // file
} Dir;

Dir *opendir(char *dirname);
Dirent *readdir(Dir *dir_file_des);
void closedir(Dir *dir_file_des);

int fstat(int file_des, Stat stat *);

Dir *opendir(char *dirname) {
    int file_des;
    Stat stbuf;
    Dir *dir_pointer;

    if ((file_des = open(dirname, O_RDONLY, 0)) == -1 || fstat(file_des, &stbuf) == -1 
        || (stbuf.st_mode & S_IFMT) != S_IFDIR 
        || (dir_pointer = (Dir *) malloc(sizeof(Dir))) == NULL)
        return NULL;
    dir_pointer->file_des = file_des;
    return dir_pointer;
}

void closedir(Dir *dir_pointer) {
    if (dir_pointer) {
        close(dir_pointer->file_des);
        free(dir_pointer);
    }
}

Dir *readdir(Dir *dir_pointer) {
    struct direct dir_buf;
    static Dirent d;

    while (read(dir_pointer->dile_des, (char *) &dir_buf, sizeof(dir_buf)) == sizeof(dir_buf)) {
        if (dirbuf.d_ino == 0)      // The buff is not filled
            continue;
        d.ino = dir_buf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';          // 100% end
        return &d;
    }
    return NULL;
}
