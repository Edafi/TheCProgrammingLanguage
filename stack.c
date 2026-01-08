#include "dynamic_array.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACKLENGHT 100
#define NUMBER '0'

int stackIndex = 0, stackCapacity = STACKLENGHT + MINSPACE;
double *stack = NULL;

void initStack(void){
    extern double *stack;
    extern int stackCapacity;
    stack = makeDynamicArray_double(stackCapacity, sizeof(double));
}

void freeStack(void){
    extern double *stack;
    free(stack);
}

void push(double value){
    extern double *stack;
    extern int stackIndex;
    if (stackIndex < STACKLENGHT)
        stack[stackIndex++] = value;
    else{
        printf("Error - stack is overloaded\n");
        exit(0);
    }
}

double pop(void){
    extern double *stack;
    extern int stackIndex;
    if(stackIndex >= 0){
        double temp = stack[--stackIndex];
        return temp;
    }
    else {
        printf("Error - stack is empty\n");
        return 0.0;
    }
}

char *buffer = NULL;
int bufferCapacity = CAPACITY, bufferIndex = 0;
void initBuffer(void){
    extern char *buffer;
    buffer = makeDynamicArray_char(bufferCapacity, sizeof(char));
}

void freeBuffer(void){
    extern char *buffer;
    free(buffer);
}

char* getBuffer(void){
    extern char *buffer;
    return buffer;
}

int getoperation(char *string){
    extern int bufferCapacity, bufferIndex;
    extern char *buffer;
    static int stringIndex = 0;

    bufferIndex = 0;
    int character;
    initBuffer();
    while((character = string[stringIndex] ) == ' ' || character == '\t' || character == '\n')
        stringIndex++;
    if((character == '+' || character == '-') && isdigit(string[stringIndex + 1])){
        checkStringCapacity(buffer, &bufferCapacity, bufferIndex + 1);
        buffer[bufferIndex++] = character;
        character = string[stringIndex + 1];
        stringIndex++;
    }
    if(isdigit(character))
        while(isdigit(character = string[stringIndex])){
            checkStringCapacity(buffer, &bufferCapacity, bufferIndex + 1);
            buffer[bufferIndex++] = character;
            stringIndex++;
        }
    if(character == '.'){
        buffer[bufferIndex++] = character;
        stringIndex++;
        while(isdigit(character = string[stringIndex])){
            checkStringCapacity(buffer, &bufferCapacity, bufferIndex + 1);
            buffer[bufferIndex++] = character;
            stringIndex++;
        }
    }
    if(isspace(character)){
        checkStringCapacity(buffer, &bufferCapacity, bufferIndex + 1);
        buffer[bufferIndex++] = '\0';
        return NUMBER;
    }
    if(character == '\n' || character == EOF || character == '\0')
        return EOF;
    stringIndex++;
    return character;
}