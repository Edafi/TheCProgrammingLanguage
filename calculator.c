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
    // TO DO: Надо замутить вложенный динамический массив строк, чтобы можно было
    // разделить string по пробелам и залить микро строчки в массив - массив указателей поидее. 
    while ((type = getoperation(string)) != EOF){
        switch (type){
            case NUMBER :{
                push(atof(string));
                break;
            }
            case '+' :{
                push(pop() + pop());
                break;
            }
            case '*' :{
                push(pop() * pop());
                break;
            }
            case '-' :{
                temp = pop();
                push (pop() - temp);
                break;
            }
            case '/' :{
                temp = pop();
                if(temp != 0.0f)
                    push(pop() / temp);
                else
                    printf("Error - Division by zero\n");
                break;
            }
            case '\n' :{
                printf("\t%.8g\n", pop());
                break;
            }
            default :{
                printf("Error - Unknown command %s\n", string);
                break;
            }
        }
    }
    free(string);
    return 0;
}