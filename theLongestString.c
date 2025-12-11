#include <linux/limits.h>
#include<stdio.h>
#include <stdlib.h>

#define MINSPACE 2                                                                                  // Я думаю, что 2 или 3 достаточно, так как на конце массива чаров будет \n и \0,
                                                                                                    // но \n входит в длину строки, поэтому он считается. Остается одина свободная ячейка.
#define DELTACAPACITY 20                                                                            // Не знаю сколько добавлять ячеек памяти к новому массиву. Не хочу слишком много,
                                                                                                    // пустого пространства, а слишком мало, чтобы не занимать такты.

//  Under this comment are some kinda templates for functions. In C we can't use templates like in C++, and I don't want to copy-paste functions with diffence in data type in params. 

#define MAKE_DYNAMIC_ARRAY(DATA_TYPE)                                                               \
    DATA_TYPE* makeDynamicArray_##DATA_TYPE(int capacity, int typeSize){                            \
        DATA_TYPE* ptr = (DATA_TYPE *)calloc(capacity, typeSize);                                   \
        if(ptr == NULL){                                                                            \
            printf("Failed to allocate memory for dynamic array");                                  \
            exit(0);                                                                                \
        }                                                                                           \
        else                                                                                        \
            return ptr;                                                                             \
    }
MAKE_DYNAMIC_ARRAY(int)
MAKE_DYNAMIC_ARRAY(char)

#define CHANGE_CAPACITY_DYNAMIC_ARRAY(DATA_TYPE)                                                    \
    DATA_TYPE* changeCapacityDynamicArray_##DATA_TYPE(DATA_TYPE *ptr, int capacity, int typeSize){  \
        ptr = (DATA_TYPE *)realloc(ptr, capacity * typeSize);                                       \
        if(ptr == NULL){                                                                            \
            printf("Failed to allocate memory for dynamic array");                                  \
            exit(0);                                                                                \
        }                                                                                           \
        else                                                                                        \
            return ptr;                                                                             \
    }
CHANGE_CAPACITY_DYNAMIC_ARRAY(int)
CHANGE_CAPACITY_DYNAMIC_ARRAY(char)

char* checkStringCapacity (char string[], int *ptrCapacity, int length){
    int capacity = *ptrCapacity;
    if(length + MINSPACE >= capacity){
        capacity += DELTACAPACITY;
        *ptrCapacity = capacity;
        string = changeCapacityDynamicArray_char(string, capacity, sizeof(char));
    }
    return string;
}

void outputString(char inputString[]){
    printf("%s", inputString);
}

void copyString(char inputString[], char copyString[], int limit){
    int i = 0;
    while((copyString[i] = inputString[i]) != '\0' && i != limit)
        ++i;
}

int readLine(char **ptrString, char **ptrMaxString, int *ptrCapacity){
    int c, length = 0, capacity = *ptrCapacity;
    char *string = *ptrString, *maxString = *ptrMaxString;
    while((c = getchar()) != EOF){
        string = checkStringCapacity(string, ptrCapacity, length);
        maxString = checkStringCapacity(maxString, ptrCapacity, length);
        string[length] = c;
        length++;
        if(c == '\n')
            break;
    }
    string[length] = '\0';
    *ptrString = string;
    return length;
}

int main(){
    int length = 0, maxlength = 0, capacity = 10;
    //int *ptrCapacity = &capacity;                      
    char *string = NULL, *maxString = NULL;
    string = makeDynamicArray_char(capacity, sizeof(char));       
    maxString = makeDynamicArray_char(capacity, sizeof(char));
    // Передаю адрес capacity, чтобы  динамически его поменять в функции readline, если длина строки будет больше неообходимого.
    while((length = readLine(&string, &maxString, &capacity)) > 0){
        if(length + MINSPACE >= capacity){
            capacity += DELTACAPACITY;
            maxString = changeCapacityDynamicArray_char(maxString, capacity, sizeof(char));
        }
        if(length > maxlength){
            maxlength = length;
            maxString = changeCapacityDynamicArray_char(maxString, maxlength, sizeof(char));
            copyString(string, maxString, maxlength);
        }
    }

    printf("\nThe longest with \\n: %d characters\n", maxlength);
    outputString(maxString);
    printf("Capacity is equal to: %d", capacity);
    free(string);
    free(maxString);
}