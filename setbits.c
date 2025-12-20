#include <stdint.h>
#include <stdio.h>

//setbits copy last n bits of value y and put them into value x from p (included) position to p-n (not included).
unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
    return (((~0U << (p+1)) | ~(~0U << (p+1-n))) & x) | (~(~0U << n) & y) << (p+1-n);
}

void printBinary(unsigned int n) {
    for (int i = (sizeof(n) * 8) - 1; i >= 0; i--) {
        putchar((n & (1U << i)) ? '1' : '0');
    }
    printf("\n");
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n){
    unsigned int copiedSides = (((~0U << (p+1)) | ~(~0 << (p+1-n))) & x);
    unsigned int copiedCenter = (~((~0U << (p+1)) | ~(~0 << (p+1-n))) & x);
    unsigned int oneCenter =  ~((~0U << (p+1)) | ~(~0 << (p+1-n)));
    return (~copiedCenter & oneCenter) | copiedSides;
}

unsigned int rightrot(unsigned int x, unsigned int n){
    return (x>>n) | ((~(~0U << n) & x) << (sizeof(x) * 8 - n));
}

unsigned int leftrot(unsigned int x, unsigned int n){
    return (x<<n) | ((~(~0U >> n) & x) >> (sizeof(x) * 8 - n));
}

int bitCountEdited(unsigned int x){
    int bits = 0;
    for (; x!=0; x &= x-1)
            bits++;
    return bits;
}

int bitCount(unsigned int x){
    int bits = 0;
    for (; x!=0; x >>= 1)
        if(x & 01)
            bits++;
    return bits;
}

int main(){
    unsigned int x, p, n, y;
    //scanf("%u %u %u %u", &x, &p, &n, &y);
    scanf("%u", &x);
    printBinary(x);
    printf("%d %d\n", bitCount(x), bitCountEdited(x));

    //printBinary(y);
    //printBinary(setbits(x, p, n, y));
    //x = setbits(x, p, n, y);
    
    //printBinary(invert(x, p, n));
    //x = invert(x, p, n);
    
    //x = leftrot(x, n);
    //printf("%u \n", x);
}