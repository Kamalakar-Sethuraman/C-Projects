#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void Withdraw_by_Acc_num(ST *ptr, unsigned long long int n, TR **tlist)
{
    unsigned long long int Withdraw_amount = 0;
    int pin;

    while (ptr)
    {
        if (ptr->Acc_num == n)
        {
            printf("\n\tEnter your pin number:");
            scanf("%d",&pin);
            if(pin == ptr->pin_num)
            {


            printf("\n\t==============================================================================================================================\n");
            printf("\t| %-16s | %-25s | %-12s | %-12s | %-30s | %-12s |\n",
            "ACCOUNT NO", "NAME", "ACC TYPE", "BALANCE", "ADDRESS", "PHONE");
            printf("\t===============================================================================================================================\n");

            printf("\t| %-16llu | %-25s | %-12s | %-12llu | %-30s | %-12llu |\n",
               ptr->Acc_num,
               ptr->Name,
               ptr->Acc_type,
               ptr->Balance,
               ptr->Address,
               ptr->Phone_num);

            printf("\t===============================================================================================================================\n");

            printf("\nEnter the money you want to withdraw:");
            scanf("%llu",&Withdraw_amount);
            if(Withdraw_amount > ptr->Balance)
            {
                printf("\n\tInsufficient Balance...\n");
                printf("\n\tCurrent balance: %llu\n",ptr->Balance);
                return;
            }
            ptr->Balance = ptr->Balance - Withdraw_amount;
            add_transaction(tlist,n,"Withdraw",Withdraw_amount);

            printf("\n\tCurrent balance: %llu\n",ptr->Balance);

            return;
            }

            else
            {
                printf("\n\tWrong pin...Try again...\n");
                return;
            }
        }
        ptr = ptr->next;
    }

    printf("\n\tAccount not found.Enter proper credential...\n");
    return;
}

