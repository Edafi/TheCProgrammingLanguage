#include <string.h>
#include "reverse.h"
/* reverse: reverses the string s. Argument is string s*/

void reverse(char string[]){
    int character;
    for(int i = 0, j = strlen(string) - 1; i <= j; ++i, --j){
        character = string[i];
        string[i] = string[j];
        string[j] = character;
    }
}
