#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binPow.c"

#define ARRAYLENGTH 20

enum heximals {a = 10, b, c, d, e, f};

int main(){
    int c, length=0, decimalValue = 0, power;
    char string[ARRAYLENGTH] = {0};
    while(length < ARRAYLENGTH - 1 && (c = getchar()) != EOF && c != '\n' && c != ' '){
        c = tolower(c);
        string[length] = c;
        ++length;
    }
    if((c == EOF || c == '\n' || c == ' ') && length < ARRAYLENGTH)
        string[length] = '\0';
    power = length - 3;

    for(int i=2; i < ARRAYLENGTH; ++i){
        if(string[i] == 0 || string[i] == '\0')
            break;
        if(isdigit(string[i]))
            decimalValue += atoi(&string[i]) * binPow(16, power);
        else
            decimalValue += (int)(string[i] - 87) * binPow(16, power);
        --power;
        //printf("\n%d\n", decimalValue);
    }
    printf("\nInuput hex: %s\nDecimal value is: %d\n", string, decimalValue);
}