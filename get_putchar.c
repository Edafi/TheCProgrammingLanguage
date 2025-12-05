#include <stdio.h>

int main(){
    int c, characters = 0;
    while((c = getchar()) != EOF){
        printf("%c", c);
        ++characters;
    }
    printf("Charaters: %d", characters);
}