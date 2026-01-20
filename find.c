#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]){
    char *line = calloc(MAXLINE, sizeof(char));
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    size_t capacity = MAXLINE; 

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if(argc != 1)
        printf("Invalid arguments. find -x -n <pattern>\n");
    else{
        while(getline(&line, &capacity, stdin) > 0){
            lineno++;
            if((strstr(line, *argv) != NULL) != except){
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}