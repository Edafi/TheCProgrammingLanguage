#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

//escape (s, t)     s - original, t - copy

void escape (char *string, char **pointerCopy, int *copyCapacity){
    int c, i = 0, j = 0;
    char *copy = *pointerCopy;
    while((c = string[i]) != '\0'){
        i++;
        copy = checkStringCapacity(copy, copyCapacity, j + MINSPACE);
        *pointerCopy = copy;
        switch (c){
            case '\t':{
                copy[j++] = '\\';
                copy[j++] = 't';
                break;
            }
            case '\a':{
                copy[j++] = '\\';
                copy[j++] = 'a';
                break;
            }
            case '\b':{
                copy[j++] = '\\';
                copy[j++] = 'b';
                break;
            }
            case '\e':{
                copy[j++] = '\\';
                copy[j++] = 'e';
                break;
            }
            case '\f':{
                copy[j++] = '\\';
                copy[j++] = 'f';
                break;
            }
            case '\n':{
                copy[j++] = '\\';
                copy[j++] = 'n';
                break;
            }
            case '\r':{
                copy[j++] = '\\';
                copy[j++] = 'r';
                break;
            }
            case '\v':{
                copy[j++] = '\\';
                copy[j++] = 'v';
                break;
            }
            case '\\':{
                copy[j++] = '\\';
                copy[j++] = '\\';
                break;
            }
            case '\'':{
                copy[j++] = '\\';
                copy[j++] = '\'';
                break;
            }
            case '\"':{
                copy[j++] = '\\';
                copy[j++] = '\"';
                break;
            }
            case '\?':{
                copy[j++] = '\\';
                copy[j++] = '\?';
                break;
            }
            default:{
                copy[j++] = c;
                break;
            }
        }
    }
    copy = checkStringCapacity(copy, copyCapacity, j + MINSPACE);
    copy[j] = '\0';
}

void unescape (char *string, char **pointerCopy, int *copyCapacity){
    int c, i = 0, j = 0;
    char *copy = *pointerCopy;
    while((c = string[i]) != '\0'){
        i++;
        copy = checkStringCapacity(copy, copyCapacity, j + MINSPACE);
        *pointerCopy = copy;
        if(c == '\\'){
            switch (string[i]){
                case 't':{
                    copy[j++] = '\t';
                    i++;
                    break;
                }
                case 'a':{
                    copy[j++] = '\a';
                    i++;
                    break;
                }
                case 'b':{
                    copy[j++] = '\b';
                    i++;
                    break;
                }
                case 'e':{
                    copy[j++] = '\e';
                    i++;
                    break;
                }
                case 'f':{
                    copy[j++] = '\f';
                    i++;
                    break;
                }
                case 'n':{
                    copy[j++] = '\n';
                    i++;
                    break;
                }
                case 'r':{
                    copy[j++] = '\a';
                    i++;
                    break;
                }
                case 'v':{
                    copy[j++] = '\v';
                    i++;
                    break;
                }
                case '\\':{
                    copy[j++] = '\\';
                    i++;
                    break;
                }
                case '\'':{
                    copy[j++] = '\'';
                    i++;
                    break;
                }
                case '\"':{
                    copy[j++] = '\"';
                    i++;
                    break;
                }
                case '\?':{
                    copy[j++] = '\?';
                    i++;
                    break;
                }
            }
        }
        else
            copy[j++] = c;
    }
    copy = checkStringCapacity(copy, copyCapacity, j + MINSPACE);
    copy[j] = '\0';
}

int main(){
    int originalCapacity = CAPACITY, copyCapacity = CAPACITY;
    int originalLength;
    char *string = makeDynamicArray_char(originalCapacity, sizeof(char));
    char *copy = makeDynamicArray_char(copyCapacity, sizeof(char));

    if((originalLength = readLine(&string, &originalCapacity)) > 0){
        escape(string, &copy, &copyCapacity);
    }
    printf("%s\n", copy);

    unescape(copy, &string, &originalCapacity);
    printf("%s\n", string);

    free(string);
    free(copy);
}