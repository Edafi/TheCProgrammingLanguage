#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]){
    char *line = calloc(MAXLINE, sizeof(char));
    int found = 0;
    size_t capacity = MAXLINE; 

    if(argc != 2)
        printf("Invalid arguments. find <pattern>\n");
    else{
        while(getline(&line, &capacity, stdin) > 0){
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}