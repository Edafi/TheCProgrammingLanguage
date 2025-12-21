#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

int main(){
    int typeSize, size; //size in bytes of data type

    typeSize = sizeof(int);
    size = typeSize * CAPACITY;
    int *a = malloc(size);
    int *ptr = calloc(CAPACITY, typeSize);
    ptr = (int *)realloc(ptr, (CAPACITY + 10) * typeSize); 
    if(a != NULL){
        for(int i = 0; i < CAPACITY; ++i){
            a[i] = i;
            printf("%d ", a[i]);
        }
    }
    else {
        printf("Failed to allocate memory.\n");
    }
}