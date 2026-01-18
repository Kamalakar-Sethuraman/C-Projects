#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int search_by_name_count(ST *ptr, char *name_search)
{
    int search_name_count = 0, found_flag = 0;
    while (ptr)
    {
        if((strcmp(ptr->name,name_search)==0))
        {
                found_flag = 1;
                ++search_name_count;
        }
        ptr = ptr->next;
    }
    return search_name_count;
}


void search_by_name(ST *ptr, char *name_s)
{
    int name_found_flag = 0;

    printf("\t-----------------------------------------------");
    printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
    printf("\t-----------------------------------------------\n");

    while (ptr)
    {
        if((strcmp(ptr->name,name_s)==0))
        {
                printf("\t|%-10d| %-20s |%-11g|\n", ptr->roll, ptr->name, ptr->marks);
                name_found_flag = 1;
        }
        ptr = ptr->next;
    }

    printf("\t-----------------------------------------------\n");

    if(name_found_flag == 0)
        printf("Record not found.\n");
}

int search_by_roll(ST *ptr, int roll)
{
    int roll_found_flag = 0;

    while (ptr)
    {
        if (ptr->roll == roll)
        {
                printf("\t-----------------------------------------------");
                printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
                printf("\t-----------------------------------------------\n");
                printf("\t|%-10d| %-20s |%-11g|\n", ptr->roll, ptr->name, ptr->marks);
                printf("\t-----------------------------------------------\n");
                roll_found_flag = 1;
                return roll_found_flag;
        }
        ptr = ptr->next;
    }
    return roll_found_flag;
}

void search_by_marks(ST *ptr, float marks_search)
{
    printf("\t-----------------------------------------------");
    printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
    printf("\t-----------------------------------------------\n");

    while (ptr)
    {
        if (ptr->marks == marks_search)
        {
                printf("\t|%-10d| %-20s |%-11g|\n", ptr->roll, ptr->name, ptr->marks);
        }
        ptr = ptr->next;
    }
    printf("\t-----------------------------------------------\n");
}

int search_count_by_marks(ST *ptr, float mark_search)
{
    int search_mark_count = 0;
    while (ptr)
    {
        if(ptr->marks == mark_search)
        {
                ++search_mark_count;
        }
        ptr = ptr->next;
    }
    return search_mark_count;
}



