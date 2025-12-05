#include <stdio.h>

long long binPow(long long base, long long power){
    if(base == 1)
        return 1;
    else if(base == 0)
        return 0;
    if(power == 0)
        return 1;
    else if(power % 2){
        return base * binPow(base, power - 1);
    }
    else{
        return binPow(base, power/2) * binPow(base, power/2);
    }
}

int main(){
    long long base = {3}, power = {4};
    printf("%lld\n", binPow(base, power));
    return 0;
}