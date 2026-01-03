#include <ctype.h>
#include "binPow.c"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

double atof_selfmade (char string[]){
    double value, fraction, power = 0;
    int i, sign = 1, powerSign = 1;

    for (i = 0; isspace(string[i]); ++i){
        ; // Skipping spaces
    }
    if (string[i] == '-'){
        sign = -1;
        i++;
    } 
    else if (string[i] == '+')
        i++;
    for (value = 0.0; isdigit(string[i]); ++i){
        value = 10.0 * value + (string[i] - '0');
    }
    
    if (string[i] == '.')
        i++;
    for (fraction = 1.0; isdigit(string[i]); ++i){
        value = 10.0 * value + (string[i] - '0');
        fraction *= 10;
    }

    if(string[i] == 'e' && (string[i+1] == '-' || string[i+1] == '+')){
        powerSign = (string[i+1] == '-') ? -1 : 1;
        i += 2;
        for(power = 0.0; isdigit(string[i]); ++i){
           power = 10.0 * power + (string[i] - '0');
        }
    }

    long double ten = 10;
    return (sign * value / fraction) * binPow_double(ten, power * powerSign);
}

int main (){
    int capacity = CAPACITY;
    char *input = NULL;
    input = makeDynamicArray_char(capacity, sizeof(char));
    readLine(&input, &capacity);
    long double answer = atof_selfmade(input);
    printf("%Lf\n", answer);
    free(input);
}