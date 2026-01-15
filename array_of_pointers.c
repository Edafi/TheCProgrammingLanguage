#include <stdio.h>
#include "dynamic_array.h"
#include "strcpy.c"
#include "strcmp.c"

#define MAXLINES 5000

int readLines(char *[], int);
void writeLines(char *[], int);
void quickSort(char *[], int, int);
void swap(char *array[], int i, int j);

char **lineptr;

int main(){
    int arrayCapacity = MAXLINES;
    extern char **lineptr;
    lineptr = makePointerArray_char(arrayCapacity, sizeof(char **));
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
int readLine(char **ptrString, int *ptrCapacity);
char *alloc(int);

int readLines(char *lineptr[], int maxlines){
    int length, nlines, capacity = MAXLEN;
    char *string = makeDynamicArray_char(capacity, sizeof(char));
    nlines = 0;
    while( (length = readLine(&string, &capacity)) > 0){
        if(nlines >= MAXLINES){ //like a lot of lines 
           return -1;
        }
        else{
            char *pointer_char = makeDynamicArray_char(capacity, sizeof(char));
            //char** pointer_char = &string;
            strcpy_SELFMADE(string, pointer_char);
            lineptr[nlines++] = pointer_char;
        }
    }
    return nlines;
}

void writeLines(char *lineptr[], int nlines){
    printf("\n");
    while(nlines-- > 0){
       printf("%s", *lineptr++);
    }
    //for(int i = 0; i < nlines; i++)
    //    printf("%s\n", lineptr[i]);
}

void quickSort(char *array[], int left, int right){
    int i, last;
    if(left >= right)
        return;
    swap(array, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(strcmp_SELFMADE(array[i], array[left]) < 0)
            swap(array, ++last, i);
    swap(array, left, last);
    quickSort(array, left, last - 1);
    quickSort(array, last + 1, right);
}

void swap(char *array[], int i, int j){
    char *temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}