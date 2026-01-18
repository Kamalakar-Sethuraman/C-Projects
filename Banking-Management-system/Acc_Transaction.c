#include "Header.h"

void add_transaction(TR **head, unsigned long long acc, char *type, unsigned long long amount)
{
    TR *newnode = malloc(sizeof(TR));

    newnode->Transaction_id = TR_id();
    newnode->Acc_num = acc;
    strcpy(newnode->type, type);
    newnode->amount = amount;

    get_datetime(newnode->datetime);

    newnode->next = *head;
    *head = newnode;
}

void print_transactions(TR *ptr)
{
    if (!ptr)
    {
        printf("\nNo transactions yet...\n");
        return;
    }

    printf("\n\t============================================================================================\n");
    printf("\t| %-16s | %-16s | %-12s | %-12s | %-20s |\n",
           "TRANSACTION ID", "ACC NUMBER", "TYPE", "AMOUNT", "DATE & TIME");
    printf("\t===============================================================================================\n");

    while (ptr)
    {
        printf("\t| %-16llu | %-16llu | %-12s | %-12llu | %-20s |\n",
               ptr->Transaction_id,
               ptr->Acc_num,
               ptr->type,
               ptr->amount,
               ptr->datetime);

        ptr = ptr->next;
    }

    printf("\t==============================================================================================\n");
}

unsigned long long TR_id()
{
    unsigned long long num = 0;
    for(int i = 0; i < 12; i++)
        num = num * 10 + (rand() % 10);
    return num;
}
