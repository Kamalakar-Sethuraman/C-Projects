#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void print(ST *ptr) // ST *ptr = hptr;
{
    if (ptr == NULL)
    {
        printf("\n\tNo records available...\n");
        return;
    }

    printf("\n\t==================================================================================================\n");
    printf("\t| %-8s | %-25s | %-20s | %-10s | %-10s| %-6s|\n", "BOOK ID", "BOOK NAME", "AUTHOR NAME","QUANTITY", "BOOKS ISSUED", "FINE");
    printf("\t==================================================================================================\n");

    while (ptr != NULL)
    {
        printf("\t| %-8d | %-25s | %-20s | %-10d | %-10d| %-8d|\n",
               ptr->Book_ID,
               ptr->Book_name,
               ptr->Author_name,
               ptr->Quantity,
               ptr->Books_issued,
               ptr->fine);
        ptr = ptr->next;
    }

    printf("\t==================================================================================================\n");
}

