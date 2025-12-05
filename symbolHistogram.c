#include <stdio.h>

#define INWORD 1
#define OUTWORD 0
#define LETTERS 26
#define DIGITS 10

int main(){
    int input, lettersArray[LETTERS] = {0}, maxCount = 0, maxDigit = 0, digitsArray[DIGITS] = {0}, state = OUTWORD;

    while((input=getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t'){
            state = OUTWORD;
        }
        else if((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')){
            state = INWORD;
            if(input >= 'A' && input <= 'Z' )
                ++lettersArray[input - 'A'];
            else
                ++lettersArray[input - 'a'];
        }
        else if(input >= '0' && input <= '9'){
            ++digitsArray[input - '0'];
        }
    }
    
    for(int i = 0; i < LETTERS; ++i){
        if(maxCount < lettersArray[i])
            maxCount = lettersArray[i];
    }
        for(int i = 0; i < DIGITS; ++i){
        if(maxDigit < digitsArray[i])
            maxDigit = digitsArray[i];
    }

    printf("\n");

    //horizontal histogram
    //for(int i = 0; i < LETTERS; ++i){
    //    if(lettersArray[i] != 0){
    //        printf("%c: ", i + 'a');
    //        for(int j = 0; j < lettersArray[i]; ++j)
    //            printf("#");
    //        printf("\n");
    //    }
    //}
    //for(int i = 0; i < DIGITS; ++i){
    //    if(digitsArray[i] != 0){
    //        printf("%d: ", i);
    //        for(int j = 0; j < digitsArray[i]; ++j)
    //            printf("#");
    //        printf("\n");
    //    }
    //}

    //vertical histogram
    for(int i = 0; i < maxCount; ++i){
        for(int j = 0; j < LETTERS; ++j){
            if(lettersArray[j] != 0){
                if(lettersArray[j] >= maxCount - i)
                    printf("#");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < LETTERS; ++i)
        if(lettersArray[i] != 0)
            printf("%c", i + 'A');

    printf("\n");            
    for(int i = 0; i < maxDigit; ++i){
        for(int j = 0; j < DIGITS; ++j){
            if(digitsArray[j] != 0){
                if(digitsArray[j] >= maxDigit - i)
                    printf("#");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < DIGITS; ++i)
        if(digitsArray[i] != 0)
            printf("%d", i);
    printf("\n");
}