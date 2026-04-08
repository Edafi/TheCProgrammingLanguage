#include <ctype.h>
#include <stdio.h>
#include "atoi.h"
/* Makes a string into an integer */
int atoi_sm(char *string){
    int i = 0, value = 0, sign;

    while(isspace(string[i]))
        ++i;
    sign = (string[i] == '-')? -1 : 1;
    if(string[i] == '+' || string[i] == '-')
        ++i;
    for(; isdigit(string[i]); ++i)
        value = 10 * value + (string[i] - '0');
    return sign * value;
}

//int main(){
//    int capacity = 25, value = 0;
//    char *string = makeDynamicArray_char(capacity, sizeof(char));
//    if(readLine( &string, &capacity))
//        value = atoi(string);
//    printf("%d\n", value);
//}
