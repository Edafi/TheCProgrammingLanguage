#include <stdlib.h>

/* numcmp - сравнение строк s1 и s2 по числовым значениям*/
int numcmp(char *left, char *right){
    double valueL, valueR;
    valueL = atof(left);
    valueR = atof(right);
    if(valueL < valueR)
        return -1;
    else if(valueL == valueR)
        return 0;
    else
        return 1;
}