#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TABLESIZE 100

struct nlist{										// This is something like map where is 
													// key (name) and value.
    struct nlist *nextElement;						// Next element of the list
 	char *name;
    char *value;
};

static struct nlist *hashTable[TABLESIZE];      	// Array of pointers to nlist struct

#define HASHSEED 42
// A K&R Hash function

u_short hash(char *string){
	u_short hashValue;
	
	for (hashValue = 0; *string != '\0'; string++)
		hashValue = *string + HASHSEED * hashValue;
	return hashValue % TABLESIZE;
}

struct nlist *lookup(char *string){
	struct nlist *pointerNext;
	
	for (pointerNext = hashTable[hash(string)]; pointerNext != NULL; pointerNext = pointerNext -> nextElement)
		if (strcmp(string, pointerNext -> name) == 0)
			return pointerNext;						// We found element from #define
	return NULL;									// No occurrence have been found
}

struct nlist *install(char *name, char *value){
	struct nlist *pointerNext;
	unsigned int hashValue;

	if ((pointerNext = lookup(name)) == NULL){		// We didn't find the name in hashTable
		pointerNext = (struct nlist *) malloc(sizeof(struct nlist *));	// Init the new element
		if (pointerNext == NULL || (pointerNext -> name = strdup(name)) == NULL)	
													// If created element is NULL or stedup can't allocate space for name or value we return NULL
			return NULL;
		hashValue = hash(name);						// Creating new hash for index
		pointerNext -> nextElement = hashTable[hashValue];	// Moving the old one element with the same hash to the next position
		hashTable[hashValue] = pointerNext;			// Adding  new element to the table
	}
	else											// We found the name in hashTable
		free((void *) pointerNext -> value);		// Deleting value just to insert a new one
	if((pointerNext -> value = strdup(value)) == NULL)
		return NULL;
	return pointerNext;
}

void print_hashtable(void){
	struct nlist *element;
	int index = 0;
	for (element = hashTable[index]; index != TABLESIZE; element = hashTable[++index]){
		while (element != NULL){
			printf ("index: %d; name: %s; value: %s\n", index, element -> name, element -> value);
			element = element -> nextElement;
		}
	}
}

void undef(char *name){
	struct nlist *element = (struct nlist *) calloc(1, sizeof(struct nlist *));
	if ((element = lookup(name)) != NULL){
		printf("Have found the element %s\n", name);
		unsigned short hashValue = hash(name);
		element = hashTable[hashValue];
		struct nlist *next = (struct nlist *) malloc(sizeof(struct nlist *));
		for (next = element->nextElement; element->nextElement != NULL && strcmp(next->name, name) != 0 && strcmp(element->name, name) != 0; element = next, next = next -> nextElement)
			printf("Element is %s\n", element -> name);
		if (next == NULL)
			hashTable[hashValue] = NULL;
		else if (strcmp(next->name, name) == 0)
			element->nextElement = next->nextElement;
		else
			hashTable[hashValue] = next;
	}
	else
		printf("Haven't found the element %s\n", name);
}

int main(){
	struct nlist *pi = install("pi", "3.141592");
	struct nlist *e = install("e", "2.1828");
	struct nlist *pa = install("pa", "It's a potograph inside a photograph");
	struct nlist *eeeeee = install("eeeeee", "pee-pee poo-poo");
	struct nlist *eeeeeee = install("eeeeeee", "poo-pee pee-poo");
	struct nlist *aaq = install("aaq", "aaq value");
  	print_hashtable();
	//printf("%s\n", hashTable[hash("aaq")] -> name);
	undef("aaq");
	print_hashtable();
}
