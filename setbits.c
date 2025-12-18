#include <stdint.h>
#include <stdio.h>

//setbits copy last n bits of value y and put them into value x from p (included) position to p-n (not included).
int setbits(int x, int p, int n, int y){
    return (((~0 << (p+1)) | ~(~0 << (p+1-n))) & x) | (~(~0 << n) & y) << (p+1-n);
}

void printBinary(unsigned int n) {
    for (int i = (sizeof(unsigned int) * 8) - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main(){
    unsigned int x, p, n, y;
    scanf("%d %d %d %d", &x, &p, &n, &y);
    printBinary(x);
    printBinary(y);
    printBinary(setbits(x, p, n, y));
    x = setbits(x, p, n, y);
    printf("%d \n", x);
}