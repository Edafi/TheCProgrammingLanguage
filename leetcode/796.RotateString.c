#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool rotateString(char* s, char* goal) {
    char count = strlen(s);
    while (count-- > 0){
        if (strcmp(s, goal) == 0)
            return 1;
        char temp = *s;
        char i = 0;
        while (s[i + 1] != '\0'){
            s[i] = s[i+1];
            i++;
        }
        s[i] = temp; 
    }
	if (strcmp(s, goal) == 0)
    	return 1;
	else 
		return 0;
}

int main(){
	char *s, *goal;
	s = calloc(100, sizeof(char *));
	goal = calloc(100, sizeof(char *));

	scanf("%s %s", s, goal);
	printf("Result: %d, s = %s, goal = %s", rotateString(s, goal), s, goal);
}
