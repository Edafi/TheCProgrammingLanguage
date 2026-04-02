#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	printf("%s\n", *argv);
	int c = {0}, is_lower = 0;
	while (! isalpha(**argv))
		*(*argv)++;
	is_lower = islower(**argv) ? 1 : 0;
	printf("%d, %c\n", is_lower, **argv);
	while ( (c = getchar()) != EOF){
		if (is_lower)
			putchar(tolower(c));
		else
			putchar(toupper(c));
	}
}
