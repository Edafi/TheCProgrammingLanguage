#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void putstring (char *string);

// Minimalistic version of printf 
void minprintf(char *format, ...) {
	va_list ap;
	char *string, *svalue;
	int ivalue;
	float fvalue;

	va_start(ap, format); 	// Set the ap to the arg after format
	for (string = format; *string; string++) {
		if (*string != '%') {
			putchar(*string);
			continue;
		}
		switch (*++string) {
		case 'd':
			ivalue = va_arg(ap, int);
			svalue = strdup(itoa(ivalue));
			putstring(svalue);
			break;
		case 'f':
			fvalue = va_arg(ap, float);
			svalue = strdup(ftoa(fvalue));
			putstring(svalue);
			break;
		case 's':
			svalue = va_arg(ap, char*);
			putstring(svalue);
			break;
		default:
			putstring("Error: Don't know the specification for this %\n");
			break;
		}
	}
}

void putstring (char *string) {
	for (; *string; string++)
		putchar(*string);
}
