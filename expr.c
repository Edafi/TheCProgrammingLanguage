#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]){
    int type, tempA, tempB, value;
    double temp, a, b;
    char* string;
    initStack();
    while(--argc > 0 && (string = *++argv)){
        type = getoperation_argv(string);
        switch (type){
            case NUMBER :
                push(atof(getBuffer()));
                freeBuffer();
                break;
            case '+' :
                push(pop() + pop());
                break;
            case '*' :
                push(pop() * pop());
                break;
            case '-' :
                temp = pop();
                push (pop() - temp);
                break;
            case '/' :
                temp = pop();
                if(temp != 0.0f){
                    push(pop() / temp);
                }
                else{
                    printf("Error - Division by zero\n");
                    freeStack();
                    exit(0);
                }
                break;
            case '%' :
                /*
                a%b = r
                a/b = n
                a = b*n + r
                */
                tempB = (int) pop();
                tempA = (int) pop();
                value = (tempA % tempB < 0 && tempA != tempB)? tempA - tempB * (tempA/tempB - 1) : tempA % tempB;
                printf("%d %d\n", tempA, tempB);
                if(tempA != 0.0f)
                    push(value);
                else{
                    printf("Error - Division by zero\n");
                    freeStack();
                    exit(0);
                }
                freeBuffer();
                break;
            default :
                printf("Error - Unknown command\n");
                freeBuffer();
                freeStack();
                exit(0);
                break;
        }   
    }
    printf("%.8g\n", pop());
    freeStack();
    return 0;
}