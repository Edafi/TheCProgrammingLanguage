#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#define MAXLEN 1024
/*
    The main goal of structure CONFIG is to containe flags status
*/ 
typedef struct {
    bool flag_lines;            // print the flag_pattern on which line was found
    bool flag_except;           // print lines with out flag_pattern
    bool flag_flag_recursive;        // recursivly opening directorys and scan files
    bool flag_found;            // print the amount of found lines at end 
    char *flag_pattern = calloc(MAXLINE, sizeof(char *));    // flag_pattern which we parse in input 
    char *flag_path = calloc(MAXLINE, sizeof(char *));       // flag_path to the file
} CONFIG;

int scan_stdin(CONFIG *);
int scan_directory(CONFIG *);
bool is_directory(CONFIG *);
int scan_file(CONFIG *);
int is_file(CONFIG *);
void print_stdin(CONFIG *, char*);

/*
    In main we are getting only flags for find (something like grep) 
*/

int main(int argc, char *argv[]) {
    int character, found = 0;
    CONFIG config = {0, 0, 0, 0, "", ""};
    
    while (--argc > 0 && **++argv == '-') {
        if (strcmp(*argv, "--flag_pattern") == 0) {      // Copying flag_pattern
            config.flag_pattern = strcpy(config.flag_pattern, *++argv);
        }
        else if (strcmp(*argv, "--flag_path") == 0) {    // Copying flag_path
            config.flag_path = strcpy(config.flag_path, *++argv);
        }
        else if (agrc > 0) {              
            while (character = **++argv)
                switch (character){
                    case 'x':
                        config.flag_except = 1;
                        break;
                    case 'l':
                        config.flag_lines = 1;
                        break;
                    case 'r':
                        config.flag_flag_recursive = 1;
                        break;
                    case 'f':
                        config.flag_found = 1;
                    default:
                        fprintf (stderr, "Error: invalid flags, allowed flags:\n\tx - except flag_pattern and find any other lines without it.");
                        argc = 0;
                        found = -1;
                }        
        }
    }

    if (strcmp(config.flag_path, "") == 0)          // Input from stdin
        found = scan_stdin(&config);
    else {                                          // Input from file or dir
        if (is_directory(config.flag_path)) {       // Directory
            if (!config.flag_recursive) {
                scan_directory (&config);
            }
        }
    }
    return found;
}

int scan_stdin(CONFIG *conf) {
    size_t size = MAXLEN;
    char *line = calloc(size, sizeof(char*));
    int line_n, found = 0;
    while (getline(&line, size, stdin) > 0) {
        line_n++;
        if ( (strstr(line, conf->flag_pattern) != NULL) != conf->flag_except) {
            if (conf->flag_line)
                fprintf(stdout, "%d: ", line_n);
            fprintf(stdout, "%s", line);
            found++;
        }
    }
   return found; 
}

bool is_directory (CONFIG *conf) {
    struct dirent *entry;
    DIR *directory;

    directory = opendir(conf->flag_path);
    if (directory == NULL)                      // Not directory
        return false;  
    else
        return true;
}

// TO DO: Do the concat for filename and directory name, change config->flag_pathand = config->flag_path + entry-> name and  push it in scan_file(config)
int scan_directory(CONFIG *config) {
    struct dirent *entry;
    DIR *directory;

    int found = 0;

    directory = opendir(config->flag_path);
    while ( (entry = readdir(directory)) ) {
        if (!config->flag_recursive) {
            if (is_file(entry->d_name)) {
                str
                found += scan_file(entry->d_name);
            }
        }
    }
}
