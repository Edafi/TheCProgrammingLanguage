#include <linux/limits.h>
#include<stdio.h>

#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

void outputString(char inputString[]){
    //int i = 0;
    //while(inputString[i] != '\0'){
    //    putchar(inputString[i]);
    //    ++i;
    //}
    printf("%s", inputString);
}

void copyString(char inputString[], char copyString[]){
    int i = 0;
    while((copyString[i] = inputString[i]) != '\0')
        ++i;
}

int readLine(char string[], int limit){
    int c, length = 0;
    while((c = getchar()) != EOF && length < limit - 1){
        string[length] = c;
        length++;
        if(c == '\n')
            break;
    }
    return length;
}

int main(){
    int c, length = 0, maxlength = 0;
    char string[MAXLENGTH] = {0}, maxString[MAXLENGTH] = {0};
    while((length = readLine(string, MAXLENGTH)) > 0){
        if(length > maxlength){
            maxlength = length;
            copyString(string, maxString);
        }
    }
    printf("\nThe longest with \\n: %d characters\n", maxlength);
    outputString(maxString);
}