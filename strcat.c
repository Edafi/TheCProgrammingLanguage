#include <stdio.h>

#define TESTSIZE 1000

void strcat_SELFMADE (char *string, char *copy){
    for(; *string; string++)
        ;
    if(*string == '\0')
        while((*string++ = *copy++))
            ;
    else
        printf("Something went wrong. strcat_SELFMADE");
}

int main(){
    char originalString[TESTSIZE] = "Hello Robbert.";
    char copyString[] = " How are you today?\n";
    printf("First string is - %s\n", originalString);
    printf("Second string is -%s\n", copyString);

    strcat_SELFMADE(originalString, copyString);
    printf("Merged string is - %s\n", originalString);
}