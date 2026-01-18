#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Header.h"

void Transfer_by_Acc_num(ST *ptr, unsigned long long s_acc, unsigned long long r_acc, TR **tlist)
{
    unsigned long long amount;
    int pin;

    ST *sender = NULL;
    ST *receiver = NULL;

    // Search for BOTH accounts
    while (ptr)
    {
        if (ptr->Acc_num == s_acc)
            sender = ptr;

        if (ptr->Acc_num == r_acc)
            receiver = ptr;

        ptr = ptr->next;
    }

    // Validate both accounts
    if (sender == NULL)
    {
        printf("\nSender account not found!\n");
        return;
    }

    if (receiver == NULL)
    {
        printf("\nReceiver account not found!\n");
        return;
    }

    // PIN verification
    printf("\nEnter sender's PIN: ");
    scanf("%d", &pin);

    if (pin != sender->pin_num)
    {
        printf("\nIncorrect PIN! Transfer failed.\n");
        return;
    }

    // Amount input
    printf("\nEnter amount to transfer: ");
    scanf("%llu", &amount);

    if (sender->Balance < amount)
    {
        printf("\nInsufficient balance! Transfer failed.\n");
        return;
    }

    // Perform transfer
    sender->Balance -= amount;
    receiver->Balance += amount;

    add_transaction(tlist,sender->Acc_num,"Debited",amount);
    add_transaction(tlist,receiver->Acc_num,"Credited",amount);

    printf("\n\tTransfer Successful!\n");
    printf("\n\tRs.%llu transferred from %s to %s\n",amount, sender->Name, receiver->Name);
    printf("\n\tCurrent Balance of sender Rs.%llu\n",sender->Balance);
    printf("\n\tCurrent Balance of receiver Rs.%llu\n",receiver->Balance);

}
