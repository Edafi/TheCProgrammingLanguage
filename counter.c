#include <stdio.h>

int main(){
    int digits[10], spaces, otherCharacters=0, input;
    for(int i=0; i<10; ++i){
        digits[i] = 0;
    }
    while((input = getchar())!=EOF){
        if(input == ' ' || input == '\t' || input == '\n')
            ++spaces;
        else if(input >= '0' && input <= '9')
            ++digits[input - '0'];
        else
            ++otherCharacters;
    }
    printf("Digits:\n");
    for(int i=0; i<10; ++i){
        printf("%d: %d\n", i, digits[i]);
    }
    printf("Spaces: %d\nOrdinary symbols: %d\n", spaces, otherCharacters);
}