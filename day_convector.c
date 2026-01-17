#include <stdlib.h>
#include <stdio.h>

static char daysTable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //regular year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     //leap year
};

int dayInYear(int dayInMonth, int month, int year){
    int days = 0, i = 1;
    char (*pointer_daysTable)[13] = daysTable;
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(; i < month; ++i)
        days += pointer_daysTable[leap][i];
    days += dayInMonth;
    return days;
}

void monthDay(int year, int yearDay, int *pointerMonth, int *pointerDay){
    int i = 1, leap;
    char (*pointer_daysTable)[13] = daysTable;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(i = 1; yearDay > pointer_daysTable[leap][i]; i++)
        yearDay -= pointer_daysTable[leap][i];
    *pointerDay = yearDay;
    *pointerMonth = i;
}

int main(){
    //int day, month, year;
    //scanf("%d %d %d", &day, &month, &year);
    //printf("%d", dayInYear(day, month, year));

    int day, year;
    
    int *pointerDay, *pointerMonth;
    pointerDay = malloc(sizeof(int));
    pointerMonth = malloc(sizeof(int));

    //int answerDay, answerMonth;
    scanf("%d %d", &day, &year);
    monthDay(year, day, pointerMonth, pointerDay);
    printf("%d %d", *pointerDay, *pointerMonth);
    printf("\n%p %p", &pointerDay, pointerDay);
}