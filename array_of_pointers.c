#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

#define MAXLINES 5000

int readLines(char *lineptr[], int nlines);
void writeLines(char *lineptr[], int nlines);

void quickSort(char *lineptr[], int left, int right);

int main(){
    int arrayCapacity = MAXLINES;
    char **lineptr = makePointerArray_char(arrayCapacity, sizeof(char));
    int nlines;
    if((nlines = readLines(lineptr, MAXLINES)) >= 0){
        quickSort(lineptr, 0, nlines - 1);
        writeLines(lineptr, nlines);
        return 0;
    }
    else{
        printf("Error: input is too big to sort!");
        return 1;
    }
}

#define MAXLEN 1000
int readline(char *line, int maxLenght);
char *alloc(int);