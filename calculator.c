#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include "stack.h"

#define MAXLENGTH_OPERATION 100
#define NUMBER '0'

int getoperation(char string[]);
void push(double value);
double pop (void);
void initStack(void);

// Калькулятор с обратной польской нотацией
// reverse polish notation
int main(){
    int type, stringCapacity = MAXLENGTH_OPERATION;
    double temp;
    char *string = makeDynamicArray_char(stringCapacity, sizeof(char));
    readLine(&string, &stringCapacity);
    initStack(); 
    while ((type = getoperation(string)) != EOF){
        switch (type){
            case NUMBER :{
                push(atof(getBuffer()));
                freeBuffer();
                break;
            }
            case '+' :{
                push(pop() + pop());
                freeBuffer();
                break;
            }
            case '*' :{
                push(pop() * pop());
                freeBuffer();
                break;
            }
            case '-' :{
                temp = pop();
                push (pop() - temp);
                freeBuffer();
                break;
            }
            case '/' :{
                temp = pop();
                if(temp != 0.0f)
                    push(pop() / temp);
                else{
                    printf("Error - Division by zero\n");
                    freeStack();
                    freeBuffer();
                    exit(0);
                }
                freeBuffer();
                break;
            }
            default :{
                printf("Error - Unknown command %s\n", string);
                freeBuffer();
                freeStack();
                exit(0);
                break;
            }
        }
    }
    free(string);
    printf("%.8g\n", pop());
    freeStack();
    freeBuffer();
    return 0;
}