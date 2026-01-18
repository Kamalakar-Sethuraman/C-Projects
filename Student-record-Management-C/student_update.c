#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void update(ST *ptr, int roll,int update_choice)
{
    if(update_choice == 1)  //to update only the name
    {
        while (ptr)
            {
                if (ptr->roll == roll)
                {
                    printf("Enter new name: ");
                    scanf("%s", ptr->name);
                    printf("Record updated successfully.\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    else if(update_choice == 2)  //to update only the marks
    {
        while (ptr)
            {
                if (ptr->roll == roll)
                {
                    printf("Enter mark: ");
                    scanf("%f",&ptr->marks);
                    printf("Record updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 3)  //to update bth
    {
        while (ptr)
            {
                if (ptr->roll == roll)
                {
                    printf("Enter new name: ");
                    scanf("%s",ptr->name);
                    printf("Enter new mark: ");
                    scanf("%f",&ptr->marks);
                    printf("Record updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }
}

void update_by_name(ST *ptr, char *name_update, int update_choice)
{
    while (ptr)
    {
        if (strcmp(ptr->name, name_update) == 0)
        {
            if (update_choice == 1)
            {
                printf("Enter new name: ");
                scanf("%s", ptr->name);
            }
            else if (update_choice == 2)
            {
                printf("Enter new marks: ");
                scanf("%f", &ptr->marks);
            }
            else if (update_choice == 3)
            {
                printf("Enter new name: ");
                scanf("%s", ptr->name);
                printf("Enter new marks: ");
                scanf("%f", &ptr->marks);
            }
            printf("Record updated successfully.\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("No matching record found.\n");
}


void update_marks(ST *ptr, float marks_update,int update_choice)
{
    if(update_choice == 1)  //to update only the name
    {
        while (ptr)
            {
                if (ptr->marks == marks_update)
                {
                    printf("Enter new name: ");
                    scanf("%s", ptr->name);
                    printf("Record updated successfully.\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    else if(update_choice == 2)  //to update only the marks
    {
        while (ptr)
            {
                if (ptr->marks == marks_update)
                {
                    printf("Enter mark: ");
                    scanf("%f",&ptr->marks);
                    printf("Record updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }

    else if(update_choice == 3)  //to update bth
    {
        while (ptr)
            {
                if (ptr->marks == marks_update)
                {
                    printf("Enter new name: ");
                    scanf("%s",ptr->name);
                    printf("Enter new mark: ");
                    scanf("%f",&ptr->marks);
                    printf("Record updated successfully.\n");
                    return;
                }
            ptr = ptr->next;
            }
    }
}

