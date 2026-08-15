#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Creating a new file or opening it if it exists (only write permission).
    // creat (const char *filename, mode_t mode) - https://www.man7.org/linux/man-pages/man3/creat.3p.html 
    // mode is a UNIX file permissions like 644.
    
    char *file_name= "test_creat";
    int file_descriptor = creat(file_name, 0644);

    if (file_descriptor == -1) {
        perror("Error: can't create file");
        return 1;
    }
    printf("File %s has been created!\n File descriptor is %d.\n", file_name, file_descriptor);
    close(file_descriptor);
    return 0; 
}
