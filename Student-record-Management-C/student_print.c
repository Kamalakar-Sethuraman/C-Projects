#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void print(ST *ptr)
{
    if (!ptr)
    {
        printf("No records available.\n");
        return;
    }

    printf("\t-----------------------------------------------");
    printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
    printf("\t-----------------------------------------------\n");

    while (ptr)
    {
        printf("\t|%-10d| %-20s |%-11g|\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->next;
    }
    printf("\t-----------------------------------------------\n");
}

void rev_print(ST *ptr)
{
    if (!ptr)
    {
        printf("No records available.\n");
        return;
    }

    while (ptr->next)
        ptr = ptr->next;

    printf("\t-----------------------------------------------");
    printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
    printf("\t-----------------------------------------------\n");

    while (ptr)
    {
        printf("\t|%-10d| %-20s |%-11g|\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->prv;
    }

    printf("\t-----------------------------------------------\n");
}
