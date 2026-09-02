#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
  #include <unistd.h>
  off_t lseek(int fd, off_t offset, int whence);

  lseek() repositions the file offset of the open file description
  associated with the file descriptor fd to the argument offset
  according to the directive whence as follows:
        
        offset: 
        SEEK_SET
              The file offset is set to offset bytes (beggining of the file + whence).

        SEEK_CUR
              The file offset is set to its current location plus offset
              bytes (cursor position + whence).

        SEEK_END
              The file offset is set to the size of the file plus offset
              bytes (end of file + whence).

*/
int get (int, long, char*, int);

int main(int argc, char *argv[]) {
    int file_ds;
    if ( (file_ds = open(*++argv, O_RDONLY)) < 0) {
        fprintf(stderr, "Error %s %s\n", *argv, strerror(errno));
        exit (-1);
    }
    char buffer[BUFSIZ] = {' '};
    if (get(file_ds, 43, buffer, 100 * sizeof(char)))
        write(1, buffer, strlen(buffer));
    return 0;
}

int get (int file_des, long position, char *buf, int bytes) {
    if (lseek(file_des, position, 0) >= 0 )
        return read(file_des, buf, bytes);
    else
        return  -1;
}
