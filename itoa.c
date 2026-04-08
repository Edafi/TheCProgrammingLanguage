#include <stdio.h>
#include "reverse.h"
#include "itoa.h"
/*
 *	Itoa function convert integer into string.
 *	First argument is input integer value, second is pointer
 *	to the string in which must be stored output value. 
 */ 
char *itoa(int integerIntput, char *output){
    int i = 0, sign = 1;
    
    unsigned long long integerOutput = integerIntput;
    if(integerIntput<0){
        sign = -1;
        integerOutput = -1 * integerIntput;
    }

    do{
        output[i++] = integerOutput%10 + '0';
    } while ((integerOutput /= 10) > 0);
    if (sign < 0)
        output[i++] = '-';
    output[i] = '\0';
	reverse(output);
	return output;
}
/*
int main(){
    int input;
    char string[20] = {'a'};
    printf("Начальное число: ");
    scanf("%d", &input);
    itoa (input, string);
    reverse(string);
    printf("Итоговая строчка: %s", string);       
}
*/
