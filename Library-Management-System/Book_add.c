#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void Book_add_middle(ST **ptr)
{
	ST *temp = (ST *)malloc(sizeof(ST));

	getchar();

	printf("\nEnter the Book_name:");
	scanf("%[^\n]",temp->Book_name);

	getchar();
	printf("\nEnter the Author name:");
    scanf("%[^\n]",temp->Author_name);

    printf("\nEnter the quantity of books:");
    scanf("%d",&temp->Quantity);

    printf("\nEnter the Fine amount:");
    scanf("%d",&temp->fine);

    temp->Book_ID = find_next_Book_ID(*ptr);

    if (temp->Book_ID >= next_book_ID)
        next_book_ID = temp->Book_ID + 1;

	if( (*ptr == 0) || (temp->Book_ID < (*ptr)->Book_ID) )
	{
		temp->prv = 0;
		temp->next = *ptr;
		if(*ptr != 0)
		(*ptr)->prv = temp;

		*ptr = temp;
	}
	else
	{
		ST *last = *ptr;
		while((last->next != 0)&&(temp->Book_ID > (last->next->Book_ID)) )
		last = last->next;

		temp->prv = last;
		temp->next = last->next;
		if(last->next != 0)
		last->next->prv = temp;

		last->next = temp;
	}
}

int find_next_Book_ID(ST *head)
{
    int expected = 1;
    ST *ptr = head;

    while (ptr)
    {
        if (ptr->Book_ID == expected)
        {
            expected++;
            ptr = head; // restart scanning from start
        }
        else
            ptr = ptr->next;
    }

    return expected; // first Book_ID
}
