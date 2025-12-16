#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

#define ASCIISYMBOLS 128

void completeSymbolSet (char *symbols, char set[]){
    int i=0;
    while(symbols[i] != '\0'){
        set[(int)symbols[i]] = 1;
        ++i;
    }
}

/*
squeeze (char s[], int c){
    int i, j;
    for(i = j = 0; s[i] != '\0'; ++i)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
*/

char* squeeze(char* string, char set[], int *pointerCapacity){
    int i, j;
    for(i = j = 0; string [i] != '\0'; ++i){
        int status = 0;
        for(int k = 0; k < ASCIISYMBOLS; ++k){
            if( set[k] == 1 && string [i] == (char)k ){
                status = 1;
                break;
            }
        }
        if(!status)
            string[j++] = string[i];
    }
    string[j] = '\0';
    string = checkStringCapacity(string, pointerCapacity, j);
    return string;
}

void printString(char *string){
    //int i = 0;
    //char c = string[i];
    //while(c != '\0'){
    //    prin
    //}
    printf("%s", string);
}

int main(){
    int editableLength = 0, deleteLength = 0, editableCapacity = 10, deleteCapacity = 10;
    char *editableString = NULL, *deleteCharString = NULL;
    editableString = makeDynamicArray_char(editableCapacity, sizeof(char));       
    deleteCharString = makeDynamicArray_char(deleteCapacity, sizeof(char));
    // Передаю адрес capacity, чтобы  динамически его поменять в функции readline, если длина строки будет больше неообходимого.
    //while((editableLength = readLine(&editableString, &editableCapacity)) > 0 && (deleteLength = readLine(&deleteCharString, &deleteCapacity)) > 0){
    //    ;
    //}

    editableLength = readLine(&editableString, &editableCapacity);
    deleteLength = readLine(&deleteCharString, &deleteCapacity);

    char asciiSymbolsSet[ASCIISYMBOLS] = {0};
    completeSymbolSet(deleteCharString, asciiSymbolsSet);
    free(deleteCharString);
    editableString = squeeze(editableString, asciiSymbolsSet, &editableCapacity);
    printString(editableString);


    free(editableString);
}