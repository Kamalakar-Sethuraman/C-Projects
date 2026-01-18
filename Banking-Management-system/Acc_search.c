#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int search_by_Acc_num(ST *ptr, unsigned long long int n)
{
    int acc_num_found_flag = 0;

    while (ptr)
    {
        if (ptr->Acc_num == n)
        {
            printf("\n\t==========================================================================================================================================\n");
            printf("\t| %-16s | %-25s | %-12s | %-12s | %-30s | %-12s | %-12s |\n",
            "ACCOUNT NO", "NAME", "ACC TYPE", "BALANCE", "ADDRESS", "PHONE", "PIN");
            printf("\t===========================================================================================================================================\n");

            printf("\t| %-16llu | %-25s | %-12s | %-12llu | %-30s | %-12llu | %-12d |\n",
               ptr->Acc_num,
               ptr->Name,
               ptr->Acc_type,
               ptr->Balance,
               ptr->Address,
               ptr->Phone_num,
               ptr->pin_num);

            printf("\t==========================================================================================================================================\n");

            acc_num_found_flag = 1;

            return acc_num_found_flag;
        }
        ptr = ptr->next;
    }

    printf("\n\tAccount not found.Enter proper credential...\n");
    return acc_num_found_flag;
}
