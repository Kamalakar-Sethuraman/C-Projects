#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void add_middle(ST **ptr)
{
    ST *temp = malloc(sizeof(ST));
    printf("\nEnter name: ");
    scanf("%s", temp->name);
    printf("Enter marks:");
    scanf("%f",&temp->marks);

    temp->roll = find_next_roll(*ptr);
    if (temp->roll >= next_roll)
        next_roll = temp->roll + 1;

    temp->next = temp->prv = NULL;

    if (*ptr == NULL)
    {
        *ptr = temp;
    }
    else
    {
        ST *last = *ptr;
        while (last->next)
            last = last->next;
        last->next = temp;
        temp->prv = last;
    }

    printf("\nStudent added with Roll No: %d\n", temp->roll);
}

void load(ST **ptr)
{
    int max_roll = 0;

    FILE *fp = fopen("data.txt", "r");
    if (!fp)
    {
        printf("\nNo previous data found.\n");
        return;
    }

    ST temp;
    while (fscanf(fp, "%d %s %f", &temp.roll, temp.name, &temp.marks) == 3)
    {
        ST *new = malloc(sizeof(ST));
        *new = temp;
        new->next = new->prv = NULL;

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

        if (temp.roll > max_roll)
            max_roll = temp.roll;
    }

    next_roll = max_roll + 1;
    fclose(fp);
}

void load_csv(ST **ptr)
{
    int max_roll = 0;

    FILE *fp = fopen("student.csv", "r");
    if (!fp)
    {
        printf("No previous data found.\n");
        return;
    }

    ST temp;
    while (fscanf(fp, "%d %s %f", &temp.roll, temp.name, &temp.marks) == 3)
    {
        ST *new = malloc(sizeof(ST));
        *new = temp;
        new->next = new->prv = NULL;

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

        if (temp.roll > max_roll)
            max_roll = temp.roll;
    }

    next_roll = max_roll + 1;
    fclose(fp);
}


int find_next_roll(ST *head)
{
    int expected = 1;
    ST *ptr = head;

    while (ptr)
    {
        if (ptr->roll == expected)
        {
            expected++;
            ptr = head; // restart scanning from start
        }
        else
            ptr = ptr->next;
    }

    return expected; // first missing roll number
}


