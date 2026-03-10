#include <stdio.h>
#include <string.h>
#include "strcpy.c"
#include "strcmp.c"
#include "dynamic_array.h"
#include "numcmp.c"

#define MAXLINES 5000
#define MAXLEN 1000
char *g_stringArray[MAXLINES];

int readLines (char *ptrLine[], int nlines);
void writeLines (char *ptrLine[], int nlines);

/*
TO DO:
    1.  Массив ptrLines является массивом указателей на строки.
        Реализовать создание, изминение размера и удаление динамического массива, а так же запись и чтение сторок из него.
    2.  Реализовать алгоритм сортировки строк в функции qsort_SELFMADE.
*/

void quickSort(void *pointerArray[], int left, int right, int (*comp) (void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp (argv[1], "-n") == 0)
        numeric = 1;
    if ( (nlines = readLines(g_stringArray, MAXLINES)) >=0 ){
        quickSort((void **) g_stringArray, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp_SELFMADE));
        writeLines(g_stringArray, nlines);
        return 0;
    }
    else{
        printf("Input too big for sorting");
        return 1;
    }
}

void quickSort(void *pointerArray[], int left, int right, int (*comp) (void *, void *)){
    int i, last;
    void swap(void *array[], int i, int j);
    
    if (left >= right)      // Если у нас меньше двух элементов в массиве, то ничего не делаем
        return;
    swap(pointerArray, left, (left + right)/2);
    last = left;
    for (i = left+1; i<= right; i++)
        if ( (*comp) (pointerArray[i], pointerArray[left]) <0)
            swap(pointerArray, ++last, i);
    swap(pointerArray, left, last);
    quickSort(pointerArray, left, last-1, comp);
    quickSort(pointerArray, last+1, right, comp);
}

void swap(void *array[], int i, int j){
    void *temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int readLines(char *lineptr[], int maxlines){
    int length, nlines, capacity = MAXLEN;
    char *string = makeDynamicArray_char(capacity, sizeof(char *));
    nlines = 0;
    while( (length = readLine(&string, &capacity)) > 0){
        if(nlines >= MAXLINES){ //like a lot of lines 
           return -1;
        }
        else{
            char *pointer_char = makeDynamicArray_char(capacity, sizeof(char *));
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
