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
    bool flag_recursive;        // recursivly opening directorys and scan files
    bool flag_found;            // print the amount of found lines at end 
    char *flag_pattern;         // flag_pattern which we parse in input 
    char *flag_path;            // flag_path to the file
} CONFIG;

int scan_stdin(CONFIG *);
int scan_directory(CONFIG *);
bool is_directory(CONFIG *);
int scan_file(CONFIG *);
bool is_file(CONFIG *);

/*
    In main we are getting only flags for find (something like grep) 
*/

int main(int argc, char *argv[]) {
    int character, found = 0;
    size_t size = MAXLEN;
    CONFIG config = {0, 0, 0, 0, calloc(size, sizeof(char)), calloc(size, sizeof(char))};
    
    while (--argc > 0 && **++argv == '-') {
        if (strcmp(*argv, "--pattern") == 0) {      // Copying flag_pattern
            config.flag_pattern = strcpy(config.flag_pattern, *++argv);
            argc--;
            // fprintf(stdout, "%s\n", config.flag_pattern);
        }
        else if (strcmp(*argv, "--path") == 0) {    // Copying flag_path
            argc--;
            config.flag_path = strcpy(config.flag_path, *++argv);
        }
        else if (argc > 0) {              
            while (character = *++*argv)
                switch (character){
                    case 'x':
                        config.flag_except = 1;
                        break;
                    case 'l':
                        config.flag_lines = 1;
                        break;
                    case 'r':
                        config.flag_recursive = 1;
                        break;
                    case 'f':
                        config.flag_found = 1;
                    default:
                        fprintf (stderr, "Error: invalid flags, allowed flags:\n\tx - except flag_pattern and find any other lines without it.");
                        argc = 0;
                        found = -1;
                        return found;
                }        
        }
    }

    if (strcmp(config.flag_path, "") == 0){        // Input from stdin
        found += scan_stdin(&config);
    }
    else {                                              // Input from file or dir
        if (is_directory(&config))                      // Directory
            found += scan_directory(&config);
        else
            found += scan_file(&config);
    }
    return found;
}

int scan_stdin(CONFIG *conf) {
    size_t size = MAXLEN;
    char *line = calloc(size, sizeof(char));
    int line_n = 0, found = 0;
    while (getline(&line, &size, stdin) > 0) {
        line_n++;
        if ( (strstr(line, conf->flag_pattern) != NULL) != conf->flag_except) {
            if (conf->flag_lines)
                fprintf(stdout, "%d: ", line_n);
            fprintf(stdout, "%s", line);
            found++;
        }
    }
   return found; 
}

bool is_directory (CONFIG *conf) {
    DIR *directory;
    directory = opendir(conf->flag_path);
    if (directory == NULL)                    // Not directory
        return false;  
    closedir(directory);
    return true;
}

// TO DO: Fix recursive mode
int scan_directory(CONFIG *conf) {
    struct dirent *entry;
    DIR *directory = opendir(conf->flag_path);
    if (!directory)
        return 0;
    size_t size = MAXLEN;
    int found = 0;

    while ( (entry = readdir(directory)) ) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry-> d_name, "..") == 0)
            continue;
        
        char newpath[size];
        snprintf(newpath, size, "%s/%s", conf->flag_path, entry->d_name);
        
        CONFIG newConf = *conf;
        newConf.flag_path = newpath;
        
        //fprintf(stdout, "newpath: %s\n", newpath);
        //fprintf(stdout, "conf: %s, newConf: %s\n", conf->flag_path, newConf.flag_path);

        if (is_directory(&newConf)) {
            if (conf->flag_recursive)
                found += scan_directory(&newConf);   
        }
        else if (is_file(&newConf)) 
            found += scan_file(&newConf);
    }
    closedir(directory);
    return found;
}


bool is_file(CONFIG *conf) {
    FILE *file;
    
    if ( file = fopen(conf->flag_path, "r") )
        return true;
    else {
        //fprintf(stderr, "Error, can't open file %s", conf->flag_path);
        return false;
    }
}

int scan_file(CONFIG *conf) {
    //fprintf(stdout, "Hello from scan_file\n");
    FILE *file = fopen(conf->flag_path, "r");
    if (!file) 
        return 0;

    int found = 0, line_n = 0;
    size_t size = MAXLEN;
    char *line = calloc(size, sizeof(char));

    while (getline(&line, &size, file) > 0) {
        line_n++;
        if ( (strstr(line, conf->flag_pattern) != NULL) != conf->flag_except) {
            if (conf->flag_lines)
                fprintf(stdout, "%d: ", line_n);
            fprintf(stdout, "%s - %s", conf->flag_path, line);
            found++;
        }
    }
    free(line);
    fclose(file);
    return found;
}
