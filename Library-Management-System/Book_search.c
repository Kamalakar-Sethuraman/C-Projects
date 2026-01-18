#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int search_by_Book_ID(ST *ptr, int Search_Book_ID)
{
    int roll_found_flag = 0;

    while (ptr)
    {
        if (ptr->Book_ID == Search_Book_ID)
        {
               printf("\n\t==================================================================================================\n");
               printf("\t| %-8s | %-25s | %-20s | %-10s | %-10s| %-10s|\n", "BOOK ID", "BOOK NAME", "AUTHOR NAME","QUANTITY", "BOOKS ISSUED", "FINE");
               printf("\t=====================================================================================================\n");

               printf("\t| %-8d | %-25s | %-20s | %-10d | %-10d| %-8d|\n",ptr->Book_ID,ptr->Book_name,ptr->Author_name,ptr->Quantity,ptr->Books_issued,ptr->fine);

               printf("\t======================================================================================================\n");

               roll_found_flag = 1;

               return roll_found_flag;
        }
        ptr = ptr->next;
    }

    return roll_found_flag;
}

int search_by_name_count(ST *ptr, char *name_search)
{
    int name_match_count = 0, found_flag = 0;
    while (ptr)
    {
        if((strcmp(ptr->Book_name,name_search)==0))
        {
                found_flag = 1;
                ++name_match_count;
        }
        ptr = ptr->next;
    }
    return name_match_count;
}

void search_by_Book_name(ST *ptr, char *name_book)
{
    int name_found_flag = 0;

      printf("\n\t==================================================================================================\n");
      printf("\t| %-8s | %-25s | %-20s | %-10s | %-10s| %-10s|\n", "BOOK ID", "BOOK NAME", "AUTHOR NAME","QUANTITY", "BOOKS ISSUED", "FINE");
      printf("\t=====================================================================================================\n");

    while (ptr)
    {
        if((strcmp(ptr->Book_name,name_book)==0))
        {
                printf("\t| %-8d | %-25s | %-20s | %-10d | %-10d| %-8d|\n",ptr->Book_ID,ptr->Book_name,ptr->Author_name,ptr->Quantity,ptr->Books_issued,ptr->fine);
                name_found_flag = 1;
        }
        ptr = ptr->next;
    }

   printf("\t=====================================================================================================\n");


    if(name_found_flag == 0)
        printf("Record not found.\n");
}

void search_by_Author_name(ST *ptr, char *name_author)
{
    int name_found_flag = 0;

      printf("\n\t==================================================================================================\n");
      printf("\t| %-8s | %-25s | %-20s | %-10s | %-10s| %-10s|\n", "BOOK ID", "BOOK NAME", "AUTHOR NAME","QUANTITY", "BOOKS ISSUED", "FINE");
      printf("\t=====================================================================================================\n");

    while (ptr)
    {
        if((strcmp(ptr->Author_name,name_author)==0))
        {
                printf("\t| %-8d | %-25s | %-20s | %-10d | %-10d| %-8d|\n",ptr->Book_ID,ptr->Book_name,ptr->Author_name,ptr->Quantity,ptr->Books_issued,ptr->fine);
                name_found_flag = 1;
        }
        ptr = ptr->next;
    }

   printf("\t=====================================================================================================\n");


    if(name_found_flag == 0)
        printf("Record not found.\n");
}
