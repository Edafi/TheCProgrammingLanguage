#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
 	void filecopy(int, int);
    int file_descr;
    char *program_name = *argv;
    void filecopy(int , int);
    if (argc == 1)
        filecopy(0, 1);     // stdin is number 0, stdout is number 1
    else {
        while (--argc > 0) {
            if ( (file_descr = open(*++argv, O_RDONLY)) < 0 ) {
                fprintf(stderr, "Error: %s %s\n", *argv, strerror(errno));
                exit(errno);
            }
            else {
                #define MINUSLEN 65
                char *buffer = calloc (BUFSIZ, sizeof(char));
                for (int i = 0; i < MINUSLEN; i++)
                    write(1, "-", 1);
                fsync(1);
                write(1, *argv, strlen(*argv));
                for (int i = 0; i < MINUSLEN; i++)
                    write(1, "-", 1);
                write(1, "\n",1);
                //fsync(1);
                filecopy(file_descr, 1);
                close(file_descr);            
                }
            }
        }    
    return 0;
}

//  TO DO: make it work with file descriptors
void filecopy(int input, int output) {
    int bytes;
    char buffer [BUFSIZ] = {' '};
	while ((read(input, buffer, BUFSIZ)) >0) {
        write(output, buffer, strlen(buffer));
        memset(buffer, '\0', strlen(buffer)); 
    }
	//putc('\n', output_pointer);
}
