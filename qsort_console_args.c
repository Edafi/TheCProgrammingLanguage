#include <stdio.h>
#include "strcpy.c"
#include "strcmp.c"
#include "dynamic_array.h"
#include "numcmp.c"

#define MAXLINES 5000
#define MAXLEN 1000
char *g_stringArray[MAXLINES];

int readLines (char *ptrLine[], int nlines);
void writeLines (char *ptrLine[], int nlines, int reverse);

void quickSort(void *pointerArray[], int left, int right, int (*comp) (void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0, reverse = 0, lower = 0;
    int letter, exit = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (letter = *++argv[0])
            switch (letter) {
                case 'r':
                    reverse = 1;
                    break;
                case 'n':
                    numeric = 1;
                    break;
                case 'f':
                    lower = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", letter);
                    exit = 1;
                    break;
            }
    
    if(exit == 1){
        printf("Usage: qsort_console_args [OPTION] [SORTING ELEMENTS]\n");
        printf("-r                                 Sorting in reverse.\n");
        printf("-n                                 Sorting numbers, using atof.\n");
        printf("-f                                 Converting and sorting text with all letters to lowercase.\n");
    }
    else{
        /*
        TO DO:
                1. Написать еще одну реализацию функции strcmp_deafult с имплементацией приравнивания строчных и прописных букв.
                2. Реализовать использование различных функции в зависимости от включеных флагов (не забыть, что сортировка по флагу -n и обычная не должны совмещаться) 
        */
        /*  Занимается typecasting для фуннкций   */
        int (*pointerFunction) (void *, void *);
        if(numeric)
            pointerFunction = (int (*) (void *, void *)) numcmp;
        else if(lower)
            pointerFunction = (int (*) (void *, void *)) strcmp_lower;
        else
            pointerFunction = (int (*) (void *, void *)) strcmp_default;
        

        if ( (nlines = readLines(g_stringArray, MAXLINES)) >=0 ){
            //quickSort((void **) g_stringArray, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp_SELFMADE));
            quickSort((void **) g_stringArray, 0, nlines - 1, pointerFunction);  
            writeLines(g_stringArray, nlines, reverse);
            return 0;
        }
        else{
            printf("Error: input is too big for sorting.");
            return 1;
        }
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

void writeLines(char *lineptr[], int nlines, int reverse){
    printf("\n");
    if(reverse)
        while(nlines-- > 0)
            printf("%s", lineptr[nlines]);    
    else
        while(nlines-- > 0)
            printf("%s", *lineptr++);
}
