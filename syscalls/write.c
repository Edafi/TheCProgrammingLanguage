#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//  ssize_t write(size_t count, int file_descriptor, const void buf[count], size_t count);
//  
//  write() writes up to count bytes from the buffer starting at buf
//  to the file referred to by the file descriptor fd.
//  
//  On success, the number of bytes written is returned.  On error, -1
//  is returned, and errno is set to indicate the error.
//
int main() {
    int bytes_wr, file_descr;
    file_descr = open("read_test", O_APPEND | O_RDWR | O_CREAT, 0644);
    if (file_descr < 0) {
        perror("r1");
        exit(1);
    } 

    bytes_wr = write(file_descr, "hello, world!\n", strlen("hello, world!\n"));
    fsync(file_descr);
    fprintf(stdout, "write() returned amount of written bytes - %d\n", bytes_wr);
    close(file_descr);

    int fd[2];
    char buffer_1[12] = "hello pal!\n", buffer_2[12];
    for (int i = 0; i < 2; ++i)
        fd[i] = open("read_test",  O_RDWR);
    write(fd[0], buffer_1, strlen(buffer_1));
    fsync(file_descr);
    write(1, buffer_2, read(fd[1], buffer_2, strlen(buffer_1)));
    
    for (int i = 0; i < 2; ++i)
        close(fd[i]);
    return 0;
}
