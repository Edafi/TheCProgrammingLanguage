#ifndef STACK_
#define STACK_

int getoperation(char string[]);
void push(double value);
double pop (void);
void initStack(void);
void freeStack(void);
void initBuffer(void);
void freeBuffer(void);
char* getBuffer(void);

#endif