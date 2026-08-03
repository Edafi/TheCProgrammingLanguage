#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// is argv a FIRST IN LAST OUT?

int main (int argc, char *argv[]) {
    FILE *file_first, *file_second;
    char *programm_name = *argv;                      // Getting the name of this programm
    //printf("%s\n%s\n", *++argv, *++argv);
    if (argc != 2 ) {                                    // The user didn't input names of files
        fprintf (stderr, "%s needs two files to work -> flcmp [file_name1] [file_name2]\n", programm_name);
        exit(1);
    }
    else {
        if ((file_first = fopen(*++argv, "r")) && (file_second = fopen(*argv, "r"))) {       // if files opened successfully    
            #define MAXLEN 1000                     // Len of string 
            char *string_first, *string_second;
            if ((string_first = calloc(MAXLEN, sizeof(char *))) && (string_second = calloc(MAXLEN, sizeof(char *)))) {
                while (fgets(string_first, MAXLEN, file_first) && fgets(string_first, MAXLEN, file_first)) {
                    if (strcmp(string_first, string_second) != 0)
                        fprintf(stdin, "In first file the difference begins from this line: %s\n In second file the difference begins from this line: %s\n", string_first, string_second);
                }
                fprintf(stdout, "Both files are equalent of each other\n");
            }
            else {
                fprintf(stderr, "ERROR: Can not allocate memory for strings!\n");
                exit(2);
            }
        }
         else {
            fprintf(stderr, "ERROR: Can not open files\n");
            exit(3);   
         }
    }
    return 0;
}
