#include "dynamic_array.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACKLENGHT 100
#define NUMBER 0

int stackIndex = 0, stackCapacity = STACKLENGHT;
double *stack = NULL;

void initStack_double(void){
    stack = makeDynamicArray_double(stackCapacity, sizeof(double));
}

void freeStack(void){
    free(stack);
}

void push(double value){
    if (stackIndex < STACKLENGHT)
        stack[stackIndex++] = value;
    else
        printf("Error - stack is overloaded\n");
}

double pop(void){
    if(stackIndex >= 0){
        double temp = stack[stackIndex--];
        return temp;
    }
    else {
        printf("Error - stack is empty\n");
        return 0.0;
    }
}

int getoperation(char *string){
    static int stringIndex = 0;
    int character, bufferCapacity = CAPACITY, bufferindex = 0;
    char *buffer = makeDynamicArray_char(bufferCapacity, sizeof(char));
    while((character = string[stringIndex++] ) == ' ' || character == '\t')
        ;
    if(isdigit(character))
        while(isdigit(character = string[stringIndex++])){
            checkStringCapacity(buffer, &bufferCapacity, bufferindex + 1);
            buffer[bufferindex++] = character;
        }
    if(character == '.'){
        while(isdigit(character = string[stringIndex++])){
            checkStringCapacity(buffer, &bufferCapacity, bufferindex + 1);
            buffer[bufferindex++] = character;
        }
    }
    if(isspace(character)){
        checkStringCapacity(buffer, &bufferCapacity, bufferindex + 1);
        buffer[bufferindex++] = '\0';
        return NUMBER;
    }
    
}