#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// is argv a FIRST IN LAST OUT?

int main (int argc, char *argv[]) {
    FILE *file_first, *file_second;
    char *programm_name = *argv;                      // Getting the name of this programm
    //printf("%s and %s\n", argv[1], argv[2]);
    if (argc == 3 ) {                                    // The user didn't input names of files
        if ((file_first = fopen(*++argv, "r")) != NULL && (file_second = fopen(*++argv, "r")) != NULL) {       // if files opened successfully    
            #define MAXLEN 1000                     // Len of string 
            char *string_first, *string_second;
            if ((string_first = calloc(MAXLEN, sizeof(char *))) && (string_second = calloc(MAXLEN, sizeof(char *)))) {
                int line = 1;
                while ( ( fgets(string_first, MAXLEN, file_first) ) && (  string_second = fgets(string_second, MAXLEN, file_second) ) ) {
                    if (strcmp(string_first, string_second) != 0){
                        fprintf(stdout, "In first file the difference begins from this %d line: %sIn second file the difference begins from %d line: %s", line, string_first, line, string_second);
                        return 0;
                    }
                    line++;
                }
                fprintf(stdout, "Both files are equalent of each other\n");
            }
            else {
                fprintf(stderr, "ERROR: Can not allocate memory for strings!\n");
                exit(1);
            }
        }
         else {
            fprintf(stderr, "ERROR: Can not open files\n");
            exit (2);   
        }
    }
    else {
        fprintf(stderr, "ERROR: Programm needs two input files - file_difference [file1] [file2]\n");
        exit(3);   
    }
}
