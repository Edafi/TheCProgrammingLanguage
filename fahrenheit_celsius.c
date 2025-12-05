#include <stdio.h>

int main(){
    const float upper = 450, lower = 50.0, step = 5;
    float fahrenheit, celsius = 0.0f;
    fahrenheit = lower;

    const char column1[] = "Fahrenheit";
    const char column2[] = "Celsius"; 
    printf("|%10s|%10s|\n", column1, column2);
    while (fahrenheit <= upper){
        celsius = 5*(fahrenheit - 32)/9;
        printf("|%10.0f|%10.2f|\n", fahrenheit, celsius);
        fahrenheit += step;
    }
}