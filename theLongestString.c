#include <linux/limits.h>
#include<stdio.h>

#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

void outputString(char inputString[MAXLENGTH]){
    int i = 0;
    while(inputString[i] != '\0'){
        putchar(inputString[i]);
        ++i;
    }
}

void copyString(char inputString[MAXLENGTH], char copyString[MAXLENGTH]){
    int i = 0;
    while((copyString[i] = inputString[i]) != '\0')
        ++i;
}

int readLine(char string[MAXLENGTH], int *flagEOF){
    int c, length = 0;
    while((c = getchar()) != EOF && length < MAXLENGTH - 1){
        string[length] = c;
        length++;
        if(c == '\n')
            break;
    }
    if(c == EOF)
        *flagEOF = TRUE;
    return length;
}

int main(){
    int c, length = 0, maxlength = 0, flagEOF = FALSE;
    char string[MAXLENGTH] = {0}, maxString[MAXLENGTH] = {0};
    while(!flagEOF){
        length = readLine(string, &flagEOF);
        if(length > maxlength){
            maxlength = length;
            copyString(string, maxString);
        }
    }
    printf("The longest with \\n: %d characters\n", maxlength);
    outputString(maxString);
}