#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void delete_node(ST **ptr)
{
    int roll_d,choice_delete, roll_name_delete;
    char name_d[20], delete_choice;

    if (*ptr == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    else
    {
    printf("\nDo you want to delete by roll number or name?\n");
    printf("1.Delete by roll number.\n");
    printf("2.Delete by name.\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice_delete);
    if(choice_delete == 1)
        {
            printf("\nEnter the roll number:");
            scanf("%d", &roll_d);
            search_by_roll(*ptr,roll_d);
            printf("\nAre you sure want to delete the record(Y/N)?");
            scanf(" %c",&delete_choice);
            if((delete_choice == 'y')||(delete_choice == 'Y'))
                delete_by_roll(ptr,roll_d);
            else
                return;
        }
    else if(choice_delete == 2)
        {
            printf("\nEnter the name:");
            scanf("%s",name_d);
            search_name_count = 0;
            search_name_count = search_by_name_count(*ptr,name_d);
            if(search_name_count == 0)
            {
                printf("\nNo record found to delete...\n");
                //return;
            }
            else if(search_name_count == 1)
            {
                search_by_name(*ptr,name_d);
                printf("\nAre you sure want to delete the record(Y/N)?");
                scanf(" %c",&delete_choice);
                if((delete_choice == 'y')||(delete_choice == 'Y'))
                {
                    delete_by_name(ptr,name_d);
                }
                else
                {
                    printf("\nRecord not deleted...\n");
                    return;
                }
            }
            else
            {
                search_by_name(*ptr,name_d);
                printf("\nMultiple records with the same name.");
                printf("So,enter the roll number to delete the specific record:");
                scanf("%d",&roll_name_delete);
                printf("\nAre you sure want to delete the record(Y/N)?");
                scanf(" %c",&delete_choice);
                if((delete_choice == 'y')||(delete_choice == 'Y'))
                {
                    delete_by_roll(ptr,roll_name_delete);
                }
                else
                {
                    printf("\nRecord not deleted...\n");
                    return;
                }
        }
    }
    else
        printf("\nInvalid choice.Try again.\n");
}
}

void delete_by_roll(ST **ptr, int n)
{
    ST *temp = *ptr;
    while (temp)
    {
        if (temp->roll == n)
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

void delete_by_name(ST **ptr,char *name_d)
{
   ST *temp = *ptr;

    while (temp)
    {
        if ((strcmp(temp->name,name_d))==0)
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


void delete_all(ST **ptr)
{
    ST *temp = *ptr;
    while (temp)
    {
        ST *next = temp->next;
        free(temp);
        temp = next;
    }
    *ptr = NULL;
    next_roll = 1;
}



