#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TABLESIZE 100

struct nlist{										// This is something like map where is 
													// key (name) and value.
    struct nlist *nextList;							// Next element of the list
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
	
	for (pointerNext = hashTable[hash(string)]; pointerNext != NULL; pointerNext = pointerNext -> nextList)
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
		pointerNext -> nextList = hashTable[hashValue];	// Moving the old one element with the same hash to the next position
		hashTable[hashValue] = pointerNext;			// Adding  new element to the table
	}
	else											// We found the name in hashTable
		free((void *) pointerNext -> value);		// Deleting value just to insert a new one
	if((pointerNext -> value = strdup(value)) == NULL)
		return NULL;
	return pointerNext;
}

int main(){
    printf("short size is %ld", sizeof(int));
}
