#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

//static int Issue_ID = 1;

void Issue_Book(ST *Book_head, USER **User_head, ISSUE **Issue_head)
{
    int Book_ID, User_ID;
    char issued_date[20], due_date[20], user_add_choice;

    ST *bptr = Book_head;
    USER *uptr = *User_head;

    get_current_date(issued_date);
    get_due_date(due_date);

    printf("\nEnter the Book ID to be issued: ");
    scanf("%d", &Book_ID);

    // 🔹 Find the Book
    while (bptr && bptr->Book_ID != Book_ID)
        bptr = bptr->next;

    if (!bptr)
    {
        printf("\n\tBook not found...\n");
        return;
    }

    printf("\nEnter the User ID of the borrower: ");
    scanf("%d", &User_ID);

    // 🔹 Find the User
    while (uptr && uptr->User_ID != User_ID)
    {
             uptr = uptr->next;
    }

    // 🔹 If user not found
    if (!uptr)
    {
        printf("\n\tUser not found.\n");
        printf("\nDo you want to create a new User account (Y/N): ");
        scanf(" %c", &user_add_choice);

        if (user_add_choice == 'y' || user_add_choice == 'Y')
        {
            uptr = user_add(User_head);   // ✅ capture returned pointer
            User_ID = uptr->User_ID;      // ✅ store correct ID
        }
        else
        {
            printf("\nInvalid user. Try again...\n");
            return;
        }
    }

    //return;

    if (bptr->Quantity <= 0)
    {
        printf("\nNo copies available...\n");
        return;
    }

    // 🔹 Create a new issue record
    ISSUE *temp = (ISSUE *)malloc(sizeof(ISSUE));
    if (!temp)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    //temp->Issue_ID = Issue_ID++;

    temp->Issue_ID = find_next_Issue_ID(*Issue_head);

    if (temp->Issue_ID >= next_Issue_ID)
        next_Issue_ID = temp->Issue_ID + 1;

    temp->Book_ID = Book_ID;
    strcpy(temp->Book_name, bptr->Book_name);
    temp->User_ID = uptr->User_ID;
    strcpy(temp->User_name, uptr->User_name);
    strcpy(temp->Issued_date, issued_date);
    strcpy(temp->Due_date, due_date);

    temp->next = *Issue_head;
    *Issue_head = temp;

    bptr->Quantity--;
    bptr->Books_issued++;

    printf("\n\tBook '%s' issued to the user '%s' successfully.\n",
           bptr->Book_name, uptr->User_name);
}

void display_issued_books(ISSUE *head)
{
    if (head == NULL)
    {
        printf("\n\tNo books have been issued yet.\n");
        return;
    }

    printf("\n\t---------------------------------------------------------------------------------------------\n");
    printf("\t| %-8s | %-20s | %-8s | %-20s | %-12s | %-12s |\n",
           "ISSUE ID", "BOOK NAME", "BOOK ID", "USER NAME", "ISSUED DATE", "DUE DATE");
    printf("\t---------------------------------------------------------------------------------------------\n");

    ISSUE *temp = head;
    while (temp)
    {
        printf("\t| %-8d | %-20s | %-8d | %-20s | %-12s | %-12s |\n",
               temp->Issue_ID,
               temp->Book_name,
               temp->Book_ID,
               temp->User_name,
               temp->Issued_date,
               temp->Due_date);

        temp = temp->next;
    }

    printf("\t---------------------------------------------------------------------------------------------\n");
}

int find_next_Issue_ID(ISSUE *issue_head)
{
    int expected = 1;
    ISSUE *iptr = issue_head;

    while (iptr)
    {
        if (iptr->Issue_ID == expected)
        {
            expected++;
            iptr = issue_head; // restart scanning from start
        }
        else
            iptr = iptr->next;
    }

    return expected; // first Issue_ID
}
