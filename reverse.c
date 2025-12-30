#include <string.h>

/* reverse: reverses the string s. Argument is string s*/

void reverse(char string[]){
    int character;
    for(int i = 0, j = strlen(string); i < j; ++i, --j){
        character = string[i];
        string[s] = string[j];
        string[j] = character;
    }
}