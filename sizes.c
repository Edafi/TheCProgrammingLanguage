#include <stdio.h>
#include <limits.h>
#include "binPow.c"

int main(){
    int bits = 8;
    long long rangeInt = binPow(2, (long long) (sizeof(int) * bits));        //range of int
    printf("from %lld to %lld\n", rangeInt/-2, rangeInt/2 -1);
    
    long long rangeShort = binPow(2, (long long) (sizeof(short) * bits));        //range of int
    printf("from %lld to %lld\n", rangeShort/-2, rangeShort/2 -1);

    long long rangeFloat = binPow(2, (long long)(sizeof(float) * bits));
    printf("from %lld to %lld\n", rangeFloat/-2, rangeFloat/2 -1);

    long double rangeDouble = binPow(2, (long double)(sizeof(double) * bits));
    printf("from %Lf to %Lf\n", rangeDouble/-2, rangeDouble/2 -1);

    printf("from limits %e\n", INT_MAX);
}