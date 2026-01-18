#include "Header.h"

void get_datetime(char *buffer)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 40, "%d-%m-%Y %H:%M:%S", t);
}

