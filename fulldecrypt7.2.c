#include <stdio.h>
#include <ctype.h>

int main(){
	int c = {0}, count = 0;
	while ( (c = getchar()) != EOF){
		if (count > 60){
			putchar('\n');
			count = 0;
		}
		if (isspace(c) || !isprint(c)){
			printf("%x", c);
			if (c == '\n')
				putchar('\n');
		}
		else
			putchar(c);
	}
}
