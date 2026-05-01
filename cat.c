#include <stdio.h>
#include <stdlib.h>

// cat: output files in a row in terminal
int main(int argc, char *argv[]) {
	FILE *f_pointer;
	void filecopy(FILE *, FILE *);
	char *prog_name = argv[0];			// Name of out program

	if (argc == 1) 		// No filename args => stdin
		filecopy(stdin, stdout);
	else {
		while (--argc > 0) {
			if ( (f_pointer = fopen(*++argv, "r") ) == NULL) {
				fprintf(stderr, "%s: can't open a file %s\n", prog_name, *argv);
				exit (1);
			}
			else {
				#define MINUS_SPACE 45
				for (int i; i < MINUS_SPACE; i++)
					putc('-', stdout);
				printf("%s", *argv);
				for (int i; i < MINUS_SPACE; i++)
					putc('-', stdout);
				putc('\n', stdout);
				filecopy(f_pointer, stdout);
				fclose(f_pointer);
			}
		}
	}
	if (ferror(stdout));
	return 0;
}

void filecopy(FILE *input_pointer, FILE *output_pointer) {
	int c;
	while ( (c = getc(input_pointer)) != EOF)
		putc(c, output_pointer);
	//putc('\n', output_pointer);
}
