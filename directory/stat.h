#include <sys/types.h>

char *name;

typedef struct Stat {
    dev_t       st_dev;     /* the information about index */
    ino_t       st_ino;     /* the index */
    short       st_mode;    /* mode bits */
    short       st_nlink;   /* amount of link to file */
    short       st_uid;     /* a owner's uid of file */
    short       st_gid;     /* a owner's group gid */ 
    dev_t       st_rdev;    /* for special file */
    off_t       st_size;    /* a size of file in symbols */ 
    time_t      st_atime;   /* the last time of call of the file */
    time_t      st_mtime;   /* the last time file modification */
    time_t      st_ctime;   /* the last time index modification */
}   Stat;

Stat stbuf;
int stat(char *, Stat *);
stat(name, &stbuf);
