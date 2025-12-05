#include <stdio.h>

#define INWORD 1
#define OUTWORD 0
#define WORDS 150

int main(){
    int input, words = 0, wordsArray[WORDS], characters = 0, state = OUTWORD, maxLength = 0;
    for (int i = 0; i < WORDS; ++i){
        wordsArray[i] = 0;
    }

    while((input=getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t'){
            state = OUTWORD;
            if(characters != 0){
                wordsArray[words] = characters;
                ++words;
            }
            characters = 0;
        }
        else if((input - 'A' < 27 && input - 'A' >= 0) || (input - 'a' < 27 && input - 'a' >=0)){
            state = INWORD;
            ++characters;
            if(characters > maxLength)
                maxLength = characters;
        }
        else {
            state = OUTWORD;
        }
    }
    if(input == EOF && characters != 0){
        wordsArray[words] = characters;
        ++words;
        characters = 0;
        state = OUTWORD;
    }
    
    printf("\nMax length is: %d\n", maxLength);
    //horizontal histogram
    for(int i = 0; i < words; ++i){
        if(wordsArray[i] == 0)
            break;
        printf("%2d: ", i);
        for(int j = 0; j < wordsArray[i]; ++j)
            printf("#");
        printf("\n");
    }


    //vertical histogram
    for(int i = 0; i < maxLength; ++i){
        for(int j = 0; j < words; ++j){
            if(wordsArray[j] == 0)
                break;
            else if(wordsArray[j] >= maxLength - i)
                printf("#");
            else
                printf("-");
        }
        printf("\n");
    }
}