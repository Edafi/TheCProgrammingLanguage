#include<stdio.h>

#define MAXLENGTH 1000

int getstring(char string[MAXLENGTH], int *flagEOF){
    int c, length = 0;
    while((c = getchar()) != EOF){
        string[length] = c;
        length++;
        if(c == '\n'){
            break;
        }
    }
    return length;
}

int main(){
    int c, length = 0, maxlength = 0;
    char string[MAXLENGTH] = {' '}, maxString[MAXLENGTH];
    while(){

    }
}