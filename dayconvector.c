#include <stdio.h>

static char daysTable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //regular year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     //leap year
};

int dayInYear(int dayInMonth, int month, int year){
    int days = 0, i = 1;
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(; i < month; ++i)
        days += daysTable[leap][i];
    days += dayInMonth;
    return days;
}

void monthDay(int year, int yearDay, int *pmonth, int *pday){
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(i = 0; yearDay > daysTable[leap][i]; i++)
        yearDay -= daysTable[leap][i];
    *pday = yearDay;
    *pmonth = i;
}