#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void sort_display(ST *head, int choice, int order)
{
    if (!head)
    {
        printf("No records to display.\n");
        return;
    }

    // Step 1: Count nodes
    int n = 0;
    ST *ptr = head;
    while (ptr)
    {
        n++;
        ptr = ptr->next;
    }

    // Step 2: Copy nodes into a temporary array
    ST *arr = malloc(n * sizeof(ST));
    ptr = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = *ptr;
        ptr = ptr->next;
    }

    // Step 3: Generic Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cmp = 0;

            switch (choice)
            {
                case 1: // Roll
                    cmp = (arr[i].roll > arr[j].roll) ? 1 : (arr[i].roll < arr[j].roll) ? -1 : 0;
                    break;

                case 2: // Name
                    cmp = strcmp(arr[i].name, arr[j].name);
                    break;

                case 3: // Marks
                    cmp = (arr[i].marks > arr[j].marks) ? 1 : (arr[i].marks < arr[j].marks) ? -1 : 0;
                    break;

                default:
                    printf("Invalid choice.\n");
                    free(arr);
                    return;
            }

            // For descending, invert comparison
            if ((order == 1 && cmp > 0) || (order == 2 && cmp < 0))
            {
                ST temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Step 4: Print sorted results
    printf("\n\t--------Sorted Student Records (%s)-----\t\n",(order == 1 ? "Ascending" : "Descending"));
    printf("\t-----------------------------------------------");
    printf("\n\t|%-10s| %-20s | %-10s|\n", "ROLL", "NAME", "MARKS");
    printf("\t-----------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("\t|%-10d| %-20s |%-11g|\n", arr[i].roll, arr[i].name, arr[i].marks);

    printf("\t-----------------------------------------------\n");

    free(arr);
}
