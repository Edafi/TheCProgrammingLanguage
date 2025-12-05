#include <stdio.h>
#include <stdbool.h>

#define INWORD 1
#define OUTWORD 0

int main(){
    int input, words = 0;
    bool state = OUTWORD;
    while((input = getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t'){
            if(state == INWORD){
                putchar('\n');
            }
            state = OUTWORD;
        }
        else if(state == OUTWORD){
            state = INWORD;
            putchar(input);
            ++words;
        }
        else if(state == INWORD)
            putchar(input);
   }
   printf("\nTotal words: %d", words);
}