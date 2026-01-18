#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void print(ST *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\tNo account records available...\n");
        return;
    }

    printf("\n\t==========================================================================================================================================\n");
    printf("\t| %-16s | %-25s | %-12s | %-12s | %-30s | %-12s | %-12s |\n",
           "ACCOUNT NO", "NAME", "ACC TYPE", "BALANCE", "ADDRESS", "PHONE", "PIN");
    printf("\t===========================================================================================================================================\n");

    while (ptr != NULL)
    {
        printf("\t| %-16llu | %-25s | %-12s | %-12llu | %-30s | %-12llu | %-12d |\n",
               ptr->Acc_num,
               ptr->Name,
               ptr->Acc_type,
               ptr->Balance,
               ptr->Address,
               ptr->Phone_num,
               ptr->pin_num);
        ptr = ptr->next;
    }

    printf("\t==========================================================================================================================================\n");
}


