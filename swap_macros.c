#include <stdio.h>

#define swap(type, x, y){   \
    type temp = x;          \
    x = y;                  \
    y = temp;               \
}

int main(){
    int x = 25, y = 10;
    printf("x=%d, y=%d\n", x, y);
    swap(int, x, y);
    printf("x=%d, y=%d\n", x, y);
}