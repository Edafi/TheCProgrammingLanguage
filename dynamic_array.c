#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

 
char* makeDynamicArray_char(int capacity, int typeSize){
    char* ptr = (char*) calloc(capacity, typeSize);
    if(ptr == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return ptr;
}

char* changeCapacityDynamicArray_char(char *ptr, int capacity, int typeSize){
        ptr = (char *) realloc(ptr, capacity * typeSize);
        if(ptr == NULL){
            printf("Failed to allocate memory for dynamic array");
            exit(0);
        }
        else
            return ptr;
    }

char* checkCapacityDynamicArray_char (char string[], int *ptrCapacity, int length){
    int capacity = *ptrCapacity;
    if(length + MINSPACE >= capacity){
        capacity += DELTACAPACITY;
        *ptrCapacity = capacity;
        string = changeCapacityDynamicArray_char(string, capacity, sizeof(char *));
    }
    else if(capacity - length - MINSPACE > DELTACAPACITY){
        capacity -= DELTACAPACITY;
        *ptrCapacity = capacity;
        string = changeCapacityDynamicArray_char(string, capacity,  sizeof(char *));
    }
    return string;
}

int readLine(char **ptrString, int *ptrCapacity){
    int c, length = 0, capacity = *ptrCapacity;
    char *string = *ptrString;
    while((c = getchar()) != EOF){
        string = checkCapacityDynamicArray_char(string, ptrCapacity, length);
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

double* makeDynamicArray_double(int capacity, int typeSize){
    double* pointer = (double*) calloc(capacity, typeSize);
    if(pointer == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return pointer;
}

double* checkArrayCapacity_double (double array[], int *ptrCapacity, int length){
    int capacity = *ptrCapacity;
    if(length + MINSPACE >= capacity){
        capacity += DELTACAPACITY;
        *ptrCapacity = capacity;
        array = changeCapacityDynamicArray_double(array, capacity, sizeof(char *));
    }
    else if(capacity - length - MINSPACE > DELTACAPACITY){
        capacity -= DELTACAPACITY;
        *ptrCapacity = capacity;
        array = changeCapacityDynamicArray_double(array, capacity,  sizeof(char *));
    }
    return array;
}

double* changeCapacityDynamicArray_double(double *pointer, int capacity, int typeSize){
    pointer = (double *) realloc(pointer, capacity * typeSize);
    if(pointer == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return pointer;
}

char** makePointerArray_char(int capacity, int typeSize){
    char** pointer = (char**) calloc(capacity, typeSize);
    if(pointer == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return pointer;
}

char** checkPointerArrayCapacity_char (char **array, int *ptrCapacity, int length){
    int capacity = *ptrCapacity;
    if(length + MINSPACE >= capacity){
        capacity += DELTACAPACITY;
        *ptrCapacity = capacity;
        array = changeCapacityPointerArray_char(array, capacity, sizeof(char **));
    }
    else if(capacity - length - MINSPACE > DELTACAPACITY){
        capacity -= DELTACAPACITY;
        *ptrCapacity = capacity;
        array = changeCapacityPointerArray_char(array, capacity,  sizeof(char **));
    }
    return array;
}

char** changeCapacityPointerArray_char (char **array, int capacity, int typeSize){
    array = (char **)realloc(array, capacity * typeSize);
    if(array == NULL){
        printf("Failed to allocate memory for dynamic array");
        exit(0);
    }
    else
        return array;
}

void deleteDynamicArray_char(char *ptr){
    free(ptr);    
}

void deletePointerArray_char(char **array, int capacity){
    if (array == NULL)
        return;
    while(capacity-- > 0){
        deleteDynamicArray_char(*array);
        array++;
    }
}