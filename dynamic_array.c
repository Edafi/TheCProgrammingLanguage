#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

 
char* makeDynamicArray_char(int capacity, int typeSize){
    char* ptr = (char*)calloc(capacity, typeSize);
    if(ptr == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return ptr;
}

char* changeCapacityDynamicArray_char(char *ptr, int capacity, int typeSize){
        ptr = (char *)realloc(ptr, capacity * typeSize);
        if(ptr == NULL){
            printf("Failed to allocate memory for dynamic array");
            exit(0);
        }
        else
            return ptr;
    }

char* checkStringCapacity (char string[], int *ptrCapacity, int length){
    int capacity = *ptrCapacity;
    if(length + MINSPACE >= capacity){
        capacity += DELTACAPACITY;
        *ptrCapacity = capacity;
        string = changeCapacityDynamicArray_char(string, capacity, sizeof(char));
    }
    else if(capacity - length - MINSPACE > DELTACAPACITY){
        capacity -= DELTACAPACITY;
        *ptrCapacity = capacity;
        string = changeCapacityDynamicArray_char(string, capacity,  sizeof(char));
    }
    return string;
}

int readLine(char **ptrString, int *ptrCapacity){
    int c, length = 0, capacity = *ptrCapacity;
    char *string = *ptrString;
    while((c = getchar()) != EOF){
        string = checkStringCapacity(string, ptrCapacity, length);
        string[length] = c;
        length++;
        if(c == '\n')
            break;
    }
    string[length] = '\0';
    *ptrString = string;
    if(c == EOF)
        length = -1;
    return length;
}

void outputString(char inputString[]){
    printf("%s", inputString);
}