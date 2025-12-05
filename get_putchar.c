#include <stdio.h>

int main(){
    int c, characters, newLines = 0, spaces = 0, tabs = 0;          // = getchar();
    for(characters = 0; (c = getchar()) != EOF; characters ++){
        if(c == '\n')
            ++newLines;
        else if(c == ' ')
            ++spaces;
        else if(c == '\t')
            ++tabs;
    }
    //while((c = getchar()) != EOF){
    //    characters ++;
    //}
    if(c == EOF){
        printf("EOF char is: %c\t and EOF int is: %d\n", c, c);
        printf("Total characters: %d\n", characters);
        printf("Total new lines: %d\n", newLines);
        printf("Total new spaces: %d\n", spaces);
        printf("Total new tabs: %d\n", tabs);
    }
}