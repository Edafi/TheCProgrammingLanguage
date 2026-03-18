#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLENGTH 100

struct keyword {
	char *word;
	int count;
};

struct keyword array_keywords[]={
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
	int n, keywords = sizeof(array_keywords) / sizeof(struct keyword);
	char word[MAXLENGTH];
	while (getword(word, MAXLENGTH) != EOF){	
		if (isalpha (word[0]))
			if ( (n = binsearch(word, array_keywords, keywords)) >= 0)
		      		array_keywords[n].count++;	
	}
	for (n = 0; n < keywords; n++)
		if (array_keywords[n].count > 0){
			int count = 0;
			while(array_keywords[n].word[count] != '\0')
				count++;
			if (count >= 8)
				printf("%s\tcount is\t%d\n", array_keywords[n].word, array_keywords[n].count);
			else
				printf("%s\t\tcount is\t%d\n", array_keywords[n].word, array_keywords[n].count);
		}
	return 0;
}

int binsearch (char *word, struct keyword *array, int n){
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

int getword (char *word, int lim){
	int c, getch (void);
	void ungetch (int);
	char *pointer = word;

	while (isspace (c = getch()) )
		;
	if(c != EOF)
		*pointer++ = c;
	if (!isalpha (c)){
		*pointer = '\0';
		return c;
	}
	for ( ; --lim > 0; pointer++){
		if (!isalnum (*pointer = getch())){
			ungetch (*pointer);
			break;
		}
	}
	*pointer = '\0';
	return word[0];
}

#define BUFFSIZE 100
int buff[BUFFSIZE] = {' '};
int buffp = -1;

int getch(void){
  	if (buffp >= 0) {
    	return buff[buffp--];
  	}
  	else
    	return getchar();
}

void ungetch(int c){
	if (buffp >= 0)
		printf("ungetch: no character to un-get\n");
	else
    	buff[buffp++] = c;
}