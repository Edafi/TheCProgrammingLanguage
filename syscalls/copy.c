#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define PERMS 0666

void error(char *, ...);

// copy - copying file_1 in to file_2

int main(int argc,  char *argv[]) {
    int file_descr1, file_descr2, n;
    char buffer[BUFSIZ];            // BUFSIZ is given inside some ot this headers files

    if (argc != 3)
        fprintf(stderr, "Usage: copy from to\n");
    if ((file_descr1 = open(argv[1], O_RDONLY, 0)) == -1)
        fprintf(stderr, "copy: can't open a file %s", argv[1]);
    if ((file_descr2 = creat(argv[2], PERMS)) == -1)
        fprintf(stderr, "copy: can't create a file %s with permisions %03o", argv[2], PERMS);
    
    while ((n = read(file_descr1, buffer, BUFSIZ)) > 0)
        if (write(file_descr2, buffer, n) != n)
            fprintf(stderr, "copy: write fprintf on file %s", argv[2]);
    close(file_descr1);
    close(file_descr2);
    return 0; 
}

void error(char *format, ...) {
    va_list args;
    va_start(args, format);

    fprintf(stderr, "error: ");
    vfprintf(stderr, format, args);
    va_end(args);
    exit(1);
}
