#include <stdio.h>
#include "reverse.c"

void itob(int input, char *string, int base){
    int i = 0;
    do{
        string[i++] = (input%base > 9)? (input%base)%10 + 'A' : input%base + '0';
    } while(input /= base);
    string [i] = (input < 0)? '-' : '\0';
    reverse (string);
}

int main(){
    int input, base;
    char string[20] = {'a'};
    printf("Начальное число: ");
    scanf("%d", &input);
    printf("Основание: ");
    scanf("%d", &base);
    itob (input, string, base);
    printf("Итоговая строчка: %s\n", string);       
}