#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ftoa.h"
#include "itoa.h"
#include "atoi.h"
#include "dynamic_array.h"

void putstring (char *string);

// Minimalistic version of printf 
void minprintf(char *format, ...) {
	int capacity = 100;

	va_list ap;
	char *string, *s_value, *s_precision;
	int i_value, precision = 4;
	double d_value;

	s_value = makeDynamicArray_char(capacity, sizeof(char *));
	s_precision = makeDynamicArray_char(capacity, sizeof(char *));

	va_start(ap, format); 	// Set the ap to the arg after format
	for (string = format; *string; string++) {
		if (*string != '%') {
			putchar(*string);
			continue;
		}
		// Getting precision before %f
		int index = 0;
		while (isdigit(*++string)){
			checkCapacityDynamicArray_char(s_precision, &capacity, index);
			s_precision[index] = *string;
			index++;
		}
		if (index > 0){
			*(s_precision + index + 1) = '\0';
			precision = (atoi_sm(s_precision) > 0) ? atoi(s_precision) : 4;
		}
		
		switch (*string) {
		case 'd':
			i_value = va_arg(ap, int);
			itoa(i_value, s_value);
			putstring(s_value);
			break;
		case 'f':
			d_value = va_arg(ap, double);
			ftoa(d_value, s_value, precision);
			putstring(s_value);
			break;
		case 's':
			s_value = va_arg(ap, char*);
			putstring(s_value);
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

int main(void){
	int capacity = 100;
	char *string = makeDynamicArray_char(capacity, sizeof(char *));
	strcpy(string, "Hello World");
	
	int i_test = 2133;
	double d_test = 13.2;
	minprintf("Testing double: %2f\n", d_test);
}
