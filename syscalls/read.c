#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// read (int file_descriptor, char *buffer, int bytes);
// return values are:
// integer int - number of bytes read on success
// 0 - EOF
// -1 Error or signal enterrupt

int main() {
    char *file_name = "test_read";
    int file_descriptor;
    file_descriptor = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0644);
    FILE *file = fdopen(file_descriptor, "a+");

    if (file == NULL) {
        fprintf(stderr, "Error, couldn't open a file %s\n", file_name);
        return 1;
    }

    fprintf(file, "What's up pal?\n");
    fflush(file);   // Put the contained text from buffer to file/stdout/stderr and clears the buffer
    rewind(file);   // Resets the file cursor to the beggining of file/stdout?
    fclose(file);

    int read_bytes = 15, returned_bytes;
    size_t size = 1024;
    file_descriptor = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0644);
    char *line = (char*) calloc(size, sizeof(char));
    
    if (file_descriptor < 0) {
        perror("Error: something wrong with file descriptor, returning code 1\n");
        exit(1);
    }
    
    returned_bytes = read(file_descriptor, line, read_bytes);
    fprintf(stdout, "Called read(%d, line, %d). Return value is %d\n", file_descriptor, read_bytes, returned_bytes);
    line[returned_bytes] = '\0';
    fprintf(stdout, "Those bytes are as follows: %s\n", line);
    return 0;
}
