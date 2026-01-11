#include <stddef.h>
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *pointerBuffer = allocbuf;

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - pointerBuffer >= n){
        pointerBuffer += n;
        return pointerBuffer - n;
    }
    else {
        return 0;
    }
}

void afree (char *pointer){
    if(pointer >= allocbuf && pointer < allocbuf + ALLOCSIZE)
        pointerBuffer = pointer;
}