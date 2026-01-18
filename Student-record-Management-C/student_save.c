#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void save(ST *ptr)
{
    if (!ptr)
    {
        printf("No records to save.\n");
        return;
    }

    // Step 1: Count number of records
    int n = 0;
    ST *temp = ptr;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    // Step 2: Copy into a temporary array
    ST *arr = malloc(n * sizeof(ST));
    temp = ptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = *temp;
        temp = temp->next;
    }

    // Step 3: Sort array by roll number (ascending)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].roll > arr[j].roll)
            {
                ST t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    // Step 4: Open file and save sorted data
    FILE *fp = fopen("data.txt", "w");
    if (!fp)
    {
        printf("\nError opening file for saving.\n");
        free(arr);
        return;
    }

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d %s %.2f\n", arr[i].roll, arr[i].name, arr[i].marks);

    fclose(fp);
    free(arr);

    printf("\nData saved successfully.\n");
}

void save_csv(ST *ptr)
{
    if (!ptr)
    {
        printf("No records to save.\n");
        return;
    }

    // Step 1: Count number of records
    int n = 0;
    ST *temp = ptr;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    // Step 2: Copy into a temporary array
    ST *arr = malloc(n * sizeof(ST));
    temp = ptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = *temp;
        temp = temp->next;
    }

    // Step 3: Sort array by roll number (ascending)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].roll > arr[j].roll)
            {
                ST t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    // Step 4: Open file and save sorted data
    FILE *fp = fopen("student.csv", "w");
    if (!fp)
    {
        printf("\nError opening file for saving.\n");
        free(arr);
        return;
    }

    fprintf(fp, "Roll,Name,Marks\n"); // Header line for Excel/Sheets

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d,%s,%.2f\n", arr[i].roll, arr[i].name, arr[i].marks);

    fclose(fp);
    free(arr);

    printf("\nData saved successfully in student.csv file.\n");
}
