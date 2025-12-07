#include <linux/limits.h>
#include<stdio.h>
#include <stdlib.h>

//  Under this comment are some kinda templates for functions. In C we can't use templates like in C++, and I don't want to copy-paste functions with diffence in data type in params. 

#define MAKE_DYNAMIC_ARRAY(DATA_TYPE)                                                               \
    DATA_TYPE* makeDynamicArray_##DATA_TYPE(int capacity, int typeSize){            \
        DATA_TYPE* ptr = (DATA_TYPE *)malloc(capacity * typeSize);                                             \
        if(ptr == NULL){                                                                            \
            printf("Failed to allocate memory for dynamic array");                                  \
            return NULL;                                                                            \
        }                                                                                           \
        else                                                                                        \
            return ptr;                                                                             \
    }
MAKE_DYNAMIC_ARRAY(int)
MAKE_DYNAMIC_ARRAY(char)

#define CHANGE_CAPACITY_DYNAMIC_ARRAY(DATA_TYPE)                                                    \
    DATA_TYPE* changeCapacityDynamicArray_##DATA_TYPE(DATA_TYPE *ptr, int capacity, int typeSize){  \
        ptr = (DATA_TYPE *)realloc(ptr, capacity * typeSize);                                            \
        if(ptr == NULL){                                                                            \
            printf("Failed to allocate memory for dynamic array");                                  \
            return NULL;                                                                            \
        }                                                                                           \
        else                                                                                        \
            return ptr;                                                                             \
    }
CHANGE_CAPACITY_DYNAMIC_ARRAY(int)
CHANGE_CAPACITY_DYNAMIC_ARRAY(char)



void outputString(char inputString[]){
    printf("%s", inputString);
}

void copyString(char inputString[], char copyString[]){
    int i = 0;
    while((copyString[i] = inputString[i]) != '\0')
        ++i;
}

int readLine(char string[], int limit){
    int c, length = 0;
    while((c = getchar()) != EOF && length < limit - 1){
        string[length] = c;
        length++;
        if(c == '\n')
            break;
    }
    return length;
}

int main(){
    int length = 0, maxlength = 0, capacity = 10;
    int typeSize = sizeof(int);                     // I'm using int for char, because EOF not in range of char. 
    int *string, *maxString;                        // Same shit here. Int pointers for dynamic arrays of symbols, probably like a string, but not sure.

    

    //while((length = readLine(string, MAXLENGTH)) > 0){
    //    if(length > maxlength){
    //        maxlength = length;
    //        copyString(string, maxString);
    //    }
    //}
    //printf("\nThe longest with \\n: %d characters\n", maxlength);
    //outputString(maxString);
}