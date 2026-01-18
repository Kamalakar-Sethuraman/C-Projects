#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void update(ST *ptr, int up_Book_ID,int update_choice)
{
    if(update_choice == 1)  //to update only the Book name
    {
        while (ptr)
            {
                if (ptr->Book_ID == up_Book_ID)
                {
                    getchar();
                    printf("\nEnter new Book name: ");
                    scanf("%[^\n]", ptr->Book_name);
                    printf("\n\tBook name updated successfully.\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    else if(update_choice == 2)  //to update only the Author name
    {
        while (ptr)
            {
                if (ptr->Book_ID == up_Book_ID)
                {
                    getchar();
                    printf("\nEnter Updated Author name: ");
                    scanf("%[^\n]", ptr->Author_name);
                    printf("\n\tAuthor name updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

        else if(update_choice == 3)  //to update only the Qunatity
    {
        while (ptr)
            {
                if (ptr->Book_ID == up_Book_ID)
                {
                    printf("\nEnter the new available quantity: ");
                    scanf("%d", &ptr->Quantity);
                    printf("\n\tNew Availabe quantity updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

        else if(update_choice == 4)  //to update only the Fine
    {
        while (ptr)
            {
                if (ptr->Book_ID == up_Book_ID)
                {
                    printf("\nEnter the new Fine Amount: ");
                    scanf("%d", &ptr->fine);
                    printf("\n\tNew Fine amount updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }


    else if(update_choice == 5)  //to update all
    {
        while (ptr)
            {
                if (ptr->Book_ID == up_Book_ID)
                {
                    getchar();
                    printf("\nEnter the updated Book name: ");
                    scanf("%[^\n]", ptr->Book_name);

                    getchar();
                    printf("\nEnter the updated Author name: ");
                    scanf("%[^\n]", ptr->Author_name);

                    printf("\nEnter the new available quantity: ");
                    scanf("%d", &ptr->Quantity);

                    printf("\nEnter the new Fine Amount: ");
                    scanf("%d", &ptr->fine);

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

void update_by_Book_name(ST *ptr, char *book_name, int update_choice)
{
        if(update_choice == 1)  //to update only the Book name
    {
        while (ptr)
            {
                if (strcmp(ptr->Book_name,book_name) == 0)
                {
                    getchar();
                    printf("\nEnter new Book name: ");
                    scanf("%[^\n]", ptr->Book_name);
                    printf("\n\tBook name updated successfully.\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    else if(update_choice == 2)  //to update only the Author name
    {
        while (ptr)
            {
                if (strcmp(ptr->Book_name,book_name) == 0)
                {
                    getchar();
                    printf("\nEnter Updated Author name: ");
                    scanf("%[^\n]", ptr->Author_name);
                    printf("\n\tAuthor name updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

        else if(update_choice == 3)  //to update only the Qunatity
    {
        while (ptr)
            {
                if (strcmp(ptr->Book_name,book_name) == 0)
                {
                    printf("\nEnter the new available quantity: ");
                    scanf("%d", &ptr->Quantity);
                    printf("\n\tNew Availabe quantity updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

        else if(update_choice == 4)  //to update only the Fine
    {
        while (ptr)
            {
                if (strcmp(ptr->Book_name,book_name) == 0)
                {
                    printf("\nEnter the new Fine Amount: ");
                    scanf("%d", &ptr->fine);
                    printf("\n\tNew Fine amount updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }


    else if(update_choice == 5)  //to update all
    {
        while (ptr)
            {
                if (strcmp(ptr->Book_name,book_name) == 0)
                {
                    getchar();
                    printf("\nEnter the updated Book name: ");
                    scanf("%[^\n]", ptr->Book_name);

                    getchar();
                    printf("\nEnter the updated Author name: ");
                    scanf("%[^\n]", ptr->Author_name);

                    printf("\nEnter the new available quantity: ");
                    scanf("%d", &ptr->Quantity);

                    printf("\nEnter the new Fine Amount: ");
                    scanf("%d", &ptr->fine);

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
