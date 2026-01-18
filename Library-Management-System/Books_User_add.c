#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


USER* user_add(USER **user_head)
{
    USER *temp = malloc(sizeof(USER));

    getchar();
    printf("\nEnter the User name: ");
    scanf("%[^\n]", temp->User_name);

    temp->User_ID = find_next_User_ID(*user_head);

    if (temp->User_ID >= next_User_ID)
        next_User_ID = temp->User_ID + 1;

    temp->next = NULL;

    if (*user_head == NULL)
    {
        *user_head = temp;
    }
    else
    {
        USER *last = *user_head;

        while (last->next != NULL)
            last = last->next;

        last->next = temp;
    }

    printf("\nNew user %s successfully added with the User_ID %d...\n",
           temp->User_name, temp->User_ID);

    return temp;
}


void display_all_users(USER *user_head)
{
    if(!user_head)
    {
        printf("\n\tNo user registered...\n");
        return;
    }

    printf("\t--------------------------\n");
    printf("\t| %-10s | %-8s |\n", "User ID", "User Name");
    printf("\t--------------------------\n");

    while (user_head)
    {
        printf("\t|%-10d | %-11s|\n", user_head->User_ID, user_head->User_name);
        user_head = user_head->next;
    }
       printf("\t--------------------------\n");
}

int find_next_User_ID(USER *user_head)
{
    int expected = 1;
    USER *uptr = user_head;

    while (uptr)
    {
        if (uptr->User_ID == expected)
        {
            expected++;
            uptr = user_head; // restart scanning from start
        }
        else
            uptr = uptr->next;
    }

    return expected; // first Book_ID
}

