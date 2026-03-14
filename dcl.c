/*
--------------ПРАВИЛА--------------
ОБЪЯВЛЕНИЯ: необяз. * ПРЯМ-ОБЪЯВЛ

ПРЯМ-ОБЪЯВЛ: ИМЯ
            (ОБЪЯВЛ)
            ПРЯМ-ОБЪЯВЛ()
            ПРЯМ-ОБЪЯВЛ[необяз. размер]
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];           // Тип последнего токена
char name[MAXTOKEN];            // Последний введенный токен
char datatype[MAXTOKEN];        // Тип идентификатора 
char out[1000];                 // Строка результата
                                // Токен - имя переменной, круглая скобка или квадратная скобка. 

int main(void){
    while (gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

// dcl - Синтактический анализ объявления
void dcl(void){
    int ns;
    for (ns = 0; gettoken() == '*')
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

// dirdcl - Синтактический анализ прямого объявления
void dirdcl(void){
    int type;
    
    if (tokentype == '('){   // Объявление
        dcl();
        if (tokentype != ')')
            printf("Error: expected ), but it's missing.");
    }
    else if (tokentype == NAME) // Имя переменной
        strcpy(name, token);
    else
        printf("Error: expected name of (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS){
        if (type == PARENS)
            strcat(out, " function returning");
        else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

// gettoken() - считывает следующий токен
int gettoken(void){
    int c, getch(void);
    void ungetch(int);
    char *pointer = token;  

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '('){
        if ((c = getch ()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        }
    }
}