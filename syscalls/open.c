#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
O_RDONLY	    Opens the file in read-only mode.
O_WRONLY	    Opens the file in write-only mode.
O_RDWR	        Opens the file in read and write mode.
O_CREAT	        Create a file if it doesn’t exist.
O_EXCL	        Prevent creation if it already exists.
O_APPEND	    Opens the file and places the cursor at the end of the contents.
O_ASYNC	        Enable input and output control by signal.
O_CLOEXEC	    Enable close-on-exec mode on the open file.
O_NONBLOCK	    Disables blocking of the file opened.
O_TMPFILE	    Create an unnamed temporary file at the specified path
*/

extern int errno;
#define MAXLEN 1024

int main() {
    char *file_name = "test_open";
    int file_descriptor;

    // The creat function recreate file if it exists, so it best IMHO use open with
    // O_CREAT instead of creat
    //
    //file_descriptor = creat(file_name, 0777);
    //if (file_descriptor == -1)
    //    fprintf(stdout, "Couldn't open a file %s\n", file_name);
    
   
        
    file_descriptor = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0777);
    fprintf(stdout, "file_descriptor = %d, file %s has been opened\n", file_descriptor, file_name);
    FILE *file = fdopen(file_descriptor, "r+");         // fdopen uses file descriptor to open a file 
    if (file == NULL) {
        fprintf(stderr, "Error: couldn't open a file %s\n", file_name);
        return 1;
    }

    fprintf(file, "Hello world!\n");
    fflush(file);
    rewind(file);
    
    size_t size = MAXLEN;
    char *line = (char *) calloc(MAXLEN, sizeof(char));
    while (getline(&line, &size, file) != -1)
        printf("Inside file - %s", line);
    
    fclose(file);
    free(line);
    return 0;
}
