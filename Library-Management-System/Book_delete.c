#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void delete_Book(ST **ptr)
{
    int Book_ID_d,choice_delete, Book_ID_name_delete;
    char name_d[20], delete_choice;

    if (*ptr == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    else
    {
    printf("\nDo you want to delete by Book ID or name?\n");
    printf("1.Delete by Book ID.\n");
    printf("2.Delete by Book name.\n");
    printf("3.Back to main menu.\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice_delete);
    if(choice_delete == 1)
        {
            printf("\nEnter the Book ID:");
            scanf("%d", &Book_ID_d);
            search_by_Book_ID(*ptr,Book_ID_d);
            printf("\nAre you sure want to delete the record(Y/N)?");
            scanf(" %c",&delete_choice);
            if((delete_choice == 'y')||(delete_choice == 'Y'))
                delete_by_Book_ID(ptr,Book_ID_d);
            else
                return;
        }
    else if(choice_delete == 2)
        {
            getchar();
            printf("\nEnter the name:");
            scanf("%[^\n]",name_d);

            int name_count = 0;
            name_count = search_by_name_count(*ptr,name_d);
            if(name_count == 0)
            {
                printf("\nNo record found to delete...\n");
                //return;
            }
            else if(name_count == 1)
            {
                search_by_Book_name(*ptr,name_d);
                printf("\nAre you sure want to delete the record(Y/N)?");
                scanf(" %c",&delete_choice);
                if((delete_choice == 'y')||(delete_choice == 'Y'))
                {
                    delete_by_Book_name(ptr,name_d);
                }
                else
                {
                    printf("\nRecord not deleted...\n");
                    return;
                }
            }
            else
            {
                search_by_Book_name(*ptr,name_d);
                printf("\nMultiple Books with the same name.");
                printf("So,enter the book ID to delete the specific book:");
                scanf("%d",&Book_ID_name_delete);
                printf("\nAre you sure want to delete the record(Y/N)?");
                scanf(" %c",&delete_choice);
                if((delete_choice == 'y')||(delete_choice == 'Y'))
                {
                    delete_by_Book_ID(ptr,Book_ID_name_delete);
                }
                else
                {
                    printf("\nRecord not deleted...\n");
                    return;
                }
        }
    }

    else if(choice_delete == 3)
    {
      printf("\n\tBack to main menu...\n");
      return;
    }

    else
    {
        printf("Invalid Choice...\n");

    }
 }

}

void delete_by_Book_ID(ST **ptr, int n)
{
    ST *temp = *ptr;
    while (temp)
    {
        if (temp->Book_ID == n)
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
            printf("Record deleted successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

void delete_by_Book_name(ST **ptr,char *name_d)
{
   ST *temp = *ptr;

    while (temp)
    {
        if ((strcmp(temp->Book_name,name_d))==0)
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
            printf("Record deleted successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

void delete_all_Books(ST **ptr)
{
    ST *temp = *ptr;
    while (temp)
    {
        ST *next = temp->next;
        free(temp);
        temp = next;
    }
    *ptr = NULL;
    next_book_ID = 1;
}





