#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void save(ST *ptr)
{
    FILE *fp = fopen("Books_data.txt", "w");
    if (!fp)
    {
        printf("\nError opening file for saving!\n");
        return;
    }

    while (ptr != NULL)
    {
        // Use CSV-style format (comma-separated)
        fprintf(fp, "%d,%s,%s,%d,%d,%d\n",
                ptr->Book_ID,
                ptr->Book_name,
                ptr->Author_name,
                ptr->Quantity,
                ptr->Books_issued,
                ptr->fine);
        ptr = ptr->next;
    }

    fclose(fp);
    printf("\nBooks data saved successfully to Books_data.txt\n");
}

void save_issued_books(ISSUE *iptr)
{
    FILE *fp = fopen("Issued_Books_data.txt", "w");
    if (!fp)
    {
        printf("\nError opening file for saving!\n");
        return;
    }

    while (iptr != NULL)
    {
        // Use CSV-style format (comma-separated)
        fprintf(fp, "%d,%d,%d,%s,%s,%s,%s\n",
                iptr->Book_ID,
                iptr->User_ID,
                iptr->Issue_ID,
                iptr->Book_name,
                iptr->User_name,
                iptr->Issued_date,
                iptr->Due_date);
        iptr = iptr->next;
    }

    fclose(fp);
    printf("\nIssued books data saved successfully to Issued_Books_data.txt\n");
}

void save_user(USER *user_head)
{
    FILE *fp = fopen("User_data.txt", "w");
    if (!fp)
    {
        printf("\nError opening file for saving user details!\n");
        return;
    }

    while (user_head != NULL)
    {
        // Use CSV-style format (comma-separated)
        fprintf(fp, "%d,%s\n",
                user_head->User_ID,
                user_head->User_name);

        user_head = user_head->next;
    }

    fclose(fp);
    printf("\nUser data saved successfully to User_data.txt\n");
}

void load(ST **ptr)
{
    FILE *fp = fopen("Books_data.txt", "r");
    if (!fp)
    {
        printf("\nNo previous data found.\n");
        return;
    }

    int max_Book_ID = 0;
    ST temp;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%d,%d,%d\n",
                  &temp.Book_ID,
                  temp.Book_name,
                  temp.Author_name,
                  &temp.Quantity,
                  &temp.Books_issued,
                  &temp.fine) == 6)
    {
        ST *new = malloc(sizeof(ST));
        if (!new)
        {
            printf("\nMemory allocation failed while loading!\n");
            fclose(fp);
            return;
        }

        *new = temp;
        new->next = NULL;
        new->prv = NULL;

        if (*ptr == NULL)
            *ptr = new;
        else
        {
            ST *last = *ptr;
            while (last->next)
                last = last->next;
            last->next = new;
            new->prv = last;
        }

        if (temp.Book_ID > max_Book_ID)
            max_Book_ID = temp.Book_ID;
    }

    next_book_ID = max_Book_ID + 1;
    fclose(fp);

    printf("\nBooks data loaded successfully from Books_data.txt\n");
}

void load_user(USER **uhptr)
{
    FILE *fp = fopen("User_data.txt", "r");
    if (!fp)
    {
        printf("\nNo previous user data found.\n");
        return;
    }

    int max_User_ID = 0;
    USER temp;

    // Correct fscanf format
    while (fscanf(fp, "%d,%49[^\n]",
                  &temp.User_ID,
                  temp.User_name) == 2)
    {
        USER *new = malloc(sizeof(USER));
        if (!new)
        {
            printf("\nMemory allocation failed while loading!\n");
            fclose(fp);
            return;
        }

        *new = temp;
        new->next = NULL;

        // Insert at end
        if (*uhptr == NULL)
            *uhptr = new;
        else
        {
            USER *last = *uhptr;
            while (last->next)
                last = last->next;

            last->next = new;
        }

        if (temp.User_ID > max_User_ID)
            max_User_ID = temp.User_ID;
    }

    next_User_ID = max_User_ID + 1;
    fclose(fp);

    printf("\nUser data loaded successfully from User_data.txt\n");
}

void load_issue(ISSUE **ihptr)
{
    FILE *fp = fopen("Issued_Books_data.txt", "r");
    if (!fp)
    {
        printf("\nNo previous issue data found.\n");
        return;
    }

    ISSUE temp;
    int max_Issue_ID = 0;

    while (fscanf(fp, "%d,%d,%d,%49[^,],%49[^,],%19[^,],%19[^\n]",
                  &temp.Book_ID,
                  &temp.User_ID,
                  &temp.Issue_ID,
                  temp.Book_name,
                  temp.User_name,
                  temp.Issued_date,
                  temp.Due_date) == 7)
    {
        ISSUE *new = malloc(sizeof(ISSUE));
        if (!new)
        {
            printf("\nMemory allocation failed while loading issue data!\n");
            fclose(fp);
            return;
        }

        *new = temp;
        new->next = NULL;

        if (*ihptr == NULL)
            *ihptr = new;
        else
        {
            ISSUE *last = *ihptr;
            while (last->next)
                last = last->next;
            last->next = new;
        }

        if (temp.Issue_ID > max_Issue_ID)
            max_Issue_ID = temp.Issue_ID;
    }

    next_Issue_ID = max_Issue_ID + 1;
    fclose(fp);

    printf("\nIssue data loaded successfully from Issued_Books_data.txt\n");
}




