#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//  remove file - deletes files
int main(int argc, char *argv[]) {
    int file_descr;
    if ((file_descr = open(argv[1], O_RDONLY, 0666)) == -1) {
        fprintf(stderr, "Error: couldn't find a file %s", argv[1]);
        exit(1);
    }
    remove(argv[1]);
    return 0;
}
