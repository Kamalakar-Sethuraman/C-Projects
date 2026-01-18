#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void return_book(ST *book_head, ISSUE **issue_head)
{
    int Book_ID,User_ID;
    char return_date[20];

    printf("\nEnter the Book ID:");
    scanf("%d",&Book_ID);

    printf("\nEnter the User ID:");
    scanf("%d",&User_ID);

    ISSUE *temp = *issue_head, *prev = NULL;

    while(temp)
    {
        if((temp->Book_ID == Book_ID) && (temp->User_ID == User_ID))
        {
            if(prev == NULL)
            {
                *issue_head = temp->next;
            }

            else
            {
                prev->next = temp->next;
            }

            ST *bptr = book_head;
            while(bptr && (bptr->Book_ID != Book_ID))
                bptr = bptr->next;

            if(bptr)
            {
                bptr->Quantity++;
                bptr->Books_issued--;
            }

            //get_current_date(return_date);
            getchar();
            printf("\nEnter the return data: ");
            scanf("%s",return_date);

            int due_days = date_diff(temp->Due_date,return_date);
            int due_amount = bptr->fine * due_days;

            if(due_days <= 0)
            {
                printf("\n\tNo fine applicable...\n");
            }

            else
            {
                printf("\nFine amount %d has to be payed...\n",due_amount);
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nEnter the corrcet Book_ID and User_ID...\n");
}
