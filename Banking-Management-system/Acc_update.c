#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void update(ST *ptr, unsigned long long int acc_num, int update_choice)
{
    if(update_choice == 1)  //to update only the Account Holder name
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    getchar();
                    printf("\nEnter new account holder name: ");
                    scanf("%[^\n]", ptr->Name);
                    printf("\n\tAccount holder name updated successfully...\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    else if(update_choice == 2)  //to update only the Account type
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    getchar();
                    printf("\nEnter the new account type: ");
                    scanf("%[^\n]", ptr->Acc_type);
                    printf("\n\tAccount type updated successfully...\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 3)  //to update only the Address
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    getchar();
                    printf("\nEnter the new address: ");
                    scanf("%[^\n]", ptr->Address);
                    printf("\n\tAddress updated successfully...\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 4)  //to update only the Balance
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    printf("\nEnter the new balance: ");
                    scanf("%llu", &ptr->Balance);
                    printf("\n\tAccount balance updated successfully...\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 5)  //to update only the phone number
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    printf("\nEnter the new phone number: ");
                    scanf("%llu", &ptr->Phone_num);
                    printf("\n\tNew Phone number updated successfully...\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 6)  //to update pin number
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    printf("\nEnter the new 4-digit pin number: ");
                    scanf("%d", &ptr->pin_num);
                    printf("\n\tNew pin number updated successfully...\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 7)  //to update all
    {
        while (ptr)
            {
                if (ptr->Acc_num == acc_num)
                {
                    getchar();
                    printf("\nEnter the Account Holder name: ");
                    scanf("%[^\n]", ptr->Name);

                    getchar();
                    printf("\nEnter the new account type: ");
                    scanf("%[^\n]", ptr->Acc_type);

                    getchar();
                    printf("\nEnter the new Address: ");
                    scanf("%[^\n]", ptr->Address);

                    printf("\nEnter the new balance: ");
                    scanf("%llu", &ptr->Balance);

                    printf("\nEnter the new phone number: ");
                    scanf("%llu", &ptr->Phone_num);

                    printf("\nEnter the new pin number: ");
                    scanf("%d", &ptr->pin_num);

                    return;
                }
            ptr = ptr->next;
            }

            printf("\n\tAll book details updated successfully...\n");
    }

    else
    {
        printf("\n\tInvalid choice...\n");
        return;
    }
}
