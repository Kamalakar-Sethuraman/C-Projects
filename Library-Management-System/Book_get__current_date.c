#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "Header.h"

void get_current_date(char *issued_date)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(issued_date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    //printf("%s",date_str);
}

void get_due_date(char *due_date)
{
    time_t t = time(NULL);
    t += 7*24*60*60;
    struct tm tm = *localtime(&t);
    sprintf(due_date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int date_diff(char *issued_date, char *due_date)
{
    struct tm d1 = {0}, d2 = {0};

    // Parse "DD-MM-YYYY" format
    sscanf(issued_date, "%d-%d-%d", &d1.tm_mday, &d1.tm_mon, &d1.tm_year);
    sscanf(due_date, "%d-%d-%d", &d2.tm_mday, &d2.tm_mon, &d2.tm_year);

    // Adjust values for struct tm
    d1.tm_mon -= 1;       // months start from 0
    d1.tm_year -= 1900;   // years since 1900
    d2.tm_mon -= 1;
    d2.tm_year -= 1900;

    // Convert both to time_t
    time_t time1 = mktime(&d1);
    time_t time2 = mktime(&d2);

    // Calculate difference in seconds
    double diff = difftime(time2, time1);

    // Convert seconds → days
    return (int)(diff / (60 * 60 * 24));
}
