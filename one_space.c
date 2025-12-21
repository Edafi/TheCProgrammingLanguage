#include <stdio.h>

int main(){
    int characters=0, letters=0, spaces=0, input, last_input;

    while((input=getchar()) != EOF){
        ++characters;
        if(input != ' ' && input != '\n'){
            ++letters;
            putchar(input);
        }

        else if(input == ' '){
            ++spaces;
            if(input == ' ' && last_input != ' '){
                putchar(input);
            }
            else if(input != ' ' && last_input == ' '){
                putchar(input);
            }
            
        }

        else if (input == '\n'){
            if(letters !=0 && characters > spaces){
                putchar(input);

            }
        }
        last_input = input;
    }
}