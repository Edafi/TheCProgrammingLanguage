#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
	if (strcmp(argv[1], "YES"))
		goto yes;
	else if (strcmp(argv[1], "NO"))
		goto no;
	yes:
		printf("You printed \"YES\"\n");
		return 0;
	no:
		printf("You printed \"YES\"\n");
		return 0;
}
