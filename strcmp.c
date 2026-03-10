#include <ctype.h>

int strcmp_default (char *first, char *second){
    for( ; *first == *second; first++, second++)
        if(*first == '\0')
            return 0;
    return *first - *second;
}

int strcmp_lower (char *first, char *second){
    for( ; *first == *second; first++, second++)
        if(*first == '\0')
            return 0;
    if(isalpha(*first) && isalpha(*second))
        return tolower(*first) - tolower(*second);
    else
        return *first - *second;
}