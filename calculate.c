#include <stdio.h>

unsigned int array[2000] = {0};

unsigned int recursive_calculate(unsigned int value){
    static int i = 2;
    if (value > 10){
        array [value]= 3 * value + array[value - 1] + array[value - 2] % value; 
        return array[value];
    }
    else{
        array[value] = 6;
        array[value - 1] = 6;
        array[value - 2] = 6;
    }
    return 6;
}

int main(){
    int value = 2, fixed = 2000;
    while (value <= fixed){
        recursive_calculate(value);
        printf("%d)\t array = %u\n", value, array[value]);
        value++;
    }
    printf("%u\n", recursive_calculate(fixed) - recursive_calculate(fixed - 20));
    //printf("%u\n", array[fixed] - array[fixed-20]);
}   


/*
#include <stdio.h>

unsigned int recursive_calculate(unsigned int value){
    if (value < 11)
        return 6;
    else  if (value > 10)
        return (3 * value + recursive_calculate(value - 1) + recursive_calculate(value - 2) % value);
}

int main(){
    printf("%u\n", recursive_calculate(70) - recursive_calculate(50));
}
*/