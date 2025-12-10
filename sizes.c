#include <float.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "binPow.c"

#include <float.h>
#include <math.h>
#include <stdio.h>

void double_range(double *resNegtivePower, double *resPositivePower){
    double positiveStep = 2.0;
    *resNegtivePower = *resPositivePower = 1.0;

    while(1){
        double next = *resPositivePower * positiveStep;
        if(next == INFINITY) {
            positiveStep = 1.0 + (positiveStep - 1.0)/2.0;
        }
        else{
            *resPositivePower = next;
            positiveStep = positiveStep * 2.0;
        }
        if(fabs(positiveStep - 1.0) < 1e-12){
            break;
        }
    }
    
    // Поиск минимума
    double negativeStep = 0.5;
    while(1){
        double next = *resNegtivePower * negativeStep;
        if(next < DBL_MIN || next == 0.0) {
            negativeStep = 1.0 - (1.0 - negativeStep) / 2.0;
        }
        else{
            *resNegtivePower = next;
            negativeStep = negativeStep * 0.7;
        }
        if(fabs(negativeStep) < 1e-12 || negativeStep <= 0.0){
            break;
        }
    }
}

double float_range(){
    float step = 9.0, result = 1.0;
    while(1){
        float next = result * step;
        if(next == INFINITY)
            step = 1.0 + (step - 1.0)/2.0;              // Binary search begins
        else{
            result = next;
            step = 1.0 + (step - 1.0) * 2.0;
        }
        if(fabs(step - 1.0) < DBL_EPSILON)
            break;
    }
    return result;
}

int main(){
    /*
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
    */

    double rangeFloat = float_range(), rangeDoublePositive, rangeDoubleNegative;
    double_range(&rangeDoubleNegative, &rangeDoublePositive);

    printf("Найденное float: %.15e\n", rangeFloat);
    printf("Настоящее FLT_MAX:    %.15e\n", FLT_MAX);
    printf("Разница: %.15e\n", FLT_MAX - rangeFloat);

    printf("Найденное минимальное double: %.15e\n", rangeDoubleNegative);
    printf("Найденное максимаьное double: %.15e\n", rangeDoublePositive);
    printf("Настоящее минимальное DBL_MAX:    %.15e\n", DBL_MIN);
    printf("Настоящее максимальное DBL_MAX:    %.15e\n", DBL_MAX);
    printf("Разница минимальных: %.15e\n", DBL_MIN - rangeDoubleNegative);
    printf("Разница максимальных: %.15e\n", DBL_MAX - rangeDoublePositive);
}