/*	
 *	First of all we need to seperate the integer and fractional part of the float.
 *	e.g. 31.15 - We need to take the 31 in string, then 15 into another string 
 *	and then concantenation of the string1 + '.' + string2 into a output string.
 *
 *	The simpliest solution to this is typecast the copy of float input into int.
 *	That's the way how we get the integer part of it (I guess), and the fraction 
 *	we can get by substraction.
 */

#include <string.h>
#include "ftoa.h"
#include "itoa.h"
#include "dynamic_array.h"
#include <stdio.h>

char *ftoa(double input, char *output, int precision){
	int sign;		
	if(input < 0){	//Need to know positive or negative our input is.
		sign = -1;
		input *= -1;
	}
	double dtemp = input;
	int integer = (int) dtemp, fraction = {0};

	dtemp = input - integer * 1.0;
	while (precision--)
		dtemp *= 10;
	printf("fraction is %d\n", dtemp);
	fraction = (int) dtemp;
	char *s_integer, *s_fraction;
	unsigned int capacity = 100;
	s_integer = makeDynamicArray_char(capacity, sizeof(char *));
	s_fraction = makeDynamicArray_char(capacity, sizeof(char *));
	itoa(integer, s_integer);
	itoa(fraction, s_fraction);
	
	capacity = strlen(s_integer) + strlen(s_fraction) + 2; 
	// + 2: First one is for '\0', second one is for '.' 
	// between integer part and fraction part of float point digit.
	
	output = changeCapacityDynamicArray_char(output, capacity, sizeof(char *));
	strcpy(output, s_integer);
	strcat(output, ".");
	strcat(output, s_fraction);
	return output;
}
