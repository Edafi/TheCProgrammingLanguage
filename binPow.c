#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define DIGITLENGHT 10

long double binPow_double(long double base, long long power){
    int negativeFlag = 0;
    long double answer = 1.0;
    negativeFlag = (power < 0)? 1 : 0;
    power = (power < 0)? power * (-1) : power;
    while(power > 0){
        if(power & 1){
            answer *= base;
            power--;
        }
        base *= base;
        power >>= 1;
    }
    return (negativeFlag == 0)? answer : 1/answer;
}

unsigned long long binPow_int(long long base, long long power){
    unsigned long long  answer = 1;
    while(power > 0){
        if(power & 1){
            answer *= base;
            power--;
        }
        base *= base;
        power >>= 1;
    }
    return answer;
}

int main(){
    int state = TRUE;
    unsigned long long base = {0}, power = {0};
    char baseS[DIGITLENGHT] = {'\0'}, powerS[DIGITLENGHT] = {'\0'};
    while (strcmp(baseS, "end") != 0 || strcmp(powerS, "end") != 0){
        scanf("%s %s", baseS, powerS);
        base = atoi(baseS);
        power = atoi(powerS);
        printf("%lld\n", binPow_int(base, power));
    }
}