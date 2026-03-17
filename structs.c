#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define KEYS 31
#define MAXLENGTH 100

struct keyword {
	char* word;
	int count;
};

struct keyword words_array[KEYS]={
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

int getword (char *, int);
int binsearch (char *, struct keyword *, int);

int main(){
	int n;
	char word[MAXLENGTH];
	while (getword(word, MAXLENGTH) != EOF){	
		if (isalpha (word[0]))
			if ( (n = binsearch(word, words_array, KEYS)) >= 0)
		      		words_array[n].count++;	
	}
	for (n = 0; n < KEYS; n++)
		if (words_array[n].count > 0)
			printf("%s count is\t%d", words_array[n].word, words_array[n].count);
	return 0;
}

int binsearch (char* word, struct keyword* array, int n){
	int cond;
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if( (cond = strcmp (word, array[mid].word) ) < 0 )
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
