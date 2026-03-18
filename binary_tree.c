#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGHT 100
struct treeNode* tree_add (struct treeNode *, char *);
struct treeNode* tree_create_node (void);
void tree_print (struct treeNode*);
int getword (char *word, int lim);
char* save_word (char *);

struct treeNode{
    char *word;
    int count;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

int main(){
    struct treeNode *root;
    char word[MAXLENGHT];

    root = NULL;
    while (getword(word, MAXLENGHT) != EOF){
        if (isalpha(*word))
            root = tree_add(root, word);
    }
    tree_print(root);
    return 0;
}

struct treeNode *tree_add (struct treeNode *node, char *word){
    int stringComp;

    if (node == NULL){      // New word 
        node = tree_create_node();
        node->word = save_word(word);
    }
    else if ( (stringComp = strcmp(word, node->word)) == 0)
        node->count++;
    else if (stringComp > 0)
        node->rightChild = tree_add(node->rightChild, word);
    else
        node->leftChild = tree_add(node->leftChild, word);
    return node;
}

// Creating a new tree node and returning a pointer to this new node.
struct treeNode* tree_create_node (void){
    struct treeNode *newNode = calloc(1, sizeof(struct treeNode));
    
    newNode->word=NULL;
    newNode->count = 1;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    
    return newNode;
}

char* save_word (char *word){
    char *newPointer = calloc(MAXLENGHT, sizeof(char *));
    strcpy(newPointer, word);
    return newPointer; 
}

// In K&R shorter version, only with one comparision
void tree_print (struct treeNode *node){
    if(node != NULL){
        tree_print(node->leftChild);
        printf("%s:\t%d\n", node->word, node->count);
        tree_print(node->rightChild);
    }
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