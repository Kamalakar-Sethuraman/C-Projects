#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void delete_by_Acc_num(ST **ptr, unsigned long long int n)
{
    ST *temp = *ptr;
    while (temp != 0)
    {
        if (temp->Acc_num == n)
        {
            if (*ptr == temp)
            {
                *ptr = temp->next;
                if (*ptr)
                    (*ptr)->prv = NULL;
            }
            else
            {
                temp->prv->next = temp->next;
                if (temp->next)
                    temp->next->prv = temp->prv;
            }
            free(temp);
            temp = NULL;
            printf("\n\tRecord deleted successfully.....\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

void delete_all_Acc(ST **ptr)
{
    ST *temp = *ptr;
    if(temp == 0)
    {
        printf("\n\tNo records availabe to delete...\n");
        return;
    }

    while (temp)
    {
        ST *next = temp->next;
        free(temp);
        temp = next;
    }
    *ptr = NULL;

    printf("\n\tAll records deleted successfully...\n");
}





