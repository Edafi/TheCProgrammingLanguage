#include <stdio.h>
#include <ctype.h>

int checkExpand(char leftChar, char rightChar){
    if(isdigit(leftChar) && isdigit(rightChar))
        return leftChar < rightChar;
    else if(islower(leftChar) && islower(rightChar))
        return leftChar < rightChar;
    else if(isupper(leftChar) && isupper(rightChar))
        return leftChar < rightChar;
    return 0;
}

void expand(char input[], char expanded[]){
    int i=0, j=0;
    while (input[i] != '\0'){
        if(i > 0 && input[i] == '-' && input[i+1] != '\0'){
            if(checkExpand(input[i-1], input[i+1])){
                for(char c = input[i-1] + 1; c < input[i+1]; c++)
                    expanded[j++]=c;
                ++i;
            }
            else
                expanded[j++] = input[i++];
        }
        else if(input[i] != '-'){
            expanded[j++] = input[i++];
        }
    }
}

int main() {
    char input[100] = {0}, output[1000] = {0};
    
    printf("Введите строку для развертывания: ");
    scanf("%99s", input);
    
    expand(input, output);
    
    printf("Исходная: %s\n", input);
    printf("Результат: %s\n", output);
    
    return 0;
}