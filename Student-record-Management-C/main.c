#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int next_roll = 1;
int search_name_count = 0;
int search_mark_count = 0;

int main()
{
    ST *hptr = NULL;
    int choice_menu, roll_update, choice_search, roll_search;
    int choice_sort, choice_update;
    int roll_update_flag, roll_search_flag, roll_choice_update;
    int name_update_count, mark_update_count, mark_choice_update, name_choice_update, order;
    char choice_add, choice_save, name_search[20], name_update[20],save_choice, choice_update_add;
    float mark_update;

    load(&hptr);       //load from .txt file
    //load_csv(&hptr);   //load from csv.file   (working in this not completed)

    do
    {
        printf("\n\t========== STUDENT RECORD MANAGEMENT =============\n");
        printf("\t|          1. Add a student record               |\n");
        printf("\t|          2. Show all student records           |\n");
        printf("\t|          3. Delete a specific record           |\n");
        printf("\t|          4. Delete all records                 |\n");
        printf("\t|          5. Reverse print the data             |\n");
        printf("\t|          6. Search for a student               |\n");
        printf("\t|          7. Update a student record            |\n");
        printf("\t|          8. Save records to file               |\n");
        printf("\t|          9. Sort the records                   |\n");
        printf("\t|          0. Exit                               |\n");
        printf("\t==================================================\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice_menu);

        switch (choice_menu)
        {
        case 1:
            do
            {
                add_middle(&hptr);
                printf("\nAdd another record (Y/N)? ");
                scanf(" %c", &choice_add);
            } while (choice_add == 'y' || choice_add == 'Y');
            break;

        case 2:
            print(hptr);
            break;

        case 3:
            delete_node(&hptr);
            break;

        case 4:
            delete_all(&hptr);
            save(hptr);
            printf("All records deleted and file cleared.\n");
            break;

        case 5:
            printf("Printing the records in reverse order...\n");
            rev_print(hptr);
            break;

        case 6:
            printf("\nDo you want to search by roll number or name?\n");
            printf("1. Search by roll number\n");
            printf("2. Search by name\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice_search);

            if (choice_search == 1)
            {
                printf("\nEnter the roll number: ");
                scanf("%d", &roll_search);
                roll_search_flag = search_by_roll(hptr, roll_search);

                if (roll_search_flag == 0)
                    printf("\nData not found...\n");
            }
            else if (choice_search == 2)
            {
                printf("\nEnter the name: ");
                scanf("%s", name_search);
                search_by_name(hptr, name_search);
            }
            else
                printf("\nInvalid choice.Try again.\n");

            break;

        case 7:
            printf("\nEnter which record to search for update.\n");
            printf("\n1. Search by roll number\n");
            printf("2. Search by name\n");
            printf("3. Search by marks\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice_update);

            if (choice_update == 1)
            {
                printf("\nEnter roll number to update: ");
                scanf("%d", &roll_update);
                roll_update_flag = search_by_roll(hptr, roll_update);

                if (roll_update_flag == 1)
                {
                    printf("\nWhat do you want to update?\n");
                    printf("1. Update only Name\n");
                    printf("2. Update only Marks\n");
                    printf("3. Update both\n");
                    printf("Enter your choice: ");
                    scanf("%d", &roll_choice_update);

                    update(hptr, roll_update, roll_choice_update);
                }
                else
                {
                    printf("\nRecord not found.\n");
                    printf("\nDo you want to add it as a new record:");
                    scanf(" %c",&choice_update_add);
                    if((choice_update_add == 'y')||(choice_update_add == 'Y'))
                    {
                        add_middle(&hptr);
                        printf("New record successfully added.\n");
                    }

                    else
                    {
                        printf("\nTry again.\n");
                    }

                }
            }

            else if (choice_update == 2)
            {
                printf("Enter the name: ");
                scanf("%s", name_update);
                name_update_count = search_by_name_count(hptr, name_update);

                if (name_update_count == 0)
                {
                    printf("No record found with this name.\n");
                }
                else if (name_update_count == 1)
                {
                    printf("\nWhat do you want to update?\n");
                    printf("\n1. Update only Name\n");
                    printf("2. Update only Marks\n");
                    printf("3. Update both\n");
                    printf("Enter your choice: ");
                    scanf("%d", &name_choice_update);

                    if(name_choice_update == 1)
                        update_by_name(hptr, name_update, name_choice_update);
                    else if(name_choice_update == 2)
                        update_by_name(hptr, name_update, name_choice_update);
                    else if(name_choice_update == 3)
                        update_by_name(hptr, name_update, name_choice_update);
                    else
                        printf("\nInvalid option.Try again.\n");
                }
                else
                {
                    search_by_name(hptr,name_update);
                    printf("\nMultiple records found with same name.\n");
                    printf("Enter roll number to specify: ");
                    scanf("%d", &roll_update);
                    roll_update_flag = search_by_roll(hptr, roll_update);

                    if (roll_update_flag == 1)
                    {
                        printf("\nWhat do you want to update?\n");
                        printf("\n1. Update only Name\n");
                        printf("2. Update only Marks\n");
                        printf("3. Update both\n");
                        printf("Enter your choice: ");
                        scanf("%d", &roll_choice_update);

                        update(hptr, roll_update, roll_choice_update);
                    }
                }
            }

            else if (choice_update == 3)
            {
                printf("Enter the marks to update: ");
                scanf("%f", &mark_update);
                search_by_marks(hptr, mark_update);
                mark_update_count = search_count_by_marks(hptr, mark_update);

                if (mark_update_count == 0)
                {
                    printf("No record found with this mark.\n");
                }
                else if (mark_update_count == 1)
                {
                    printf("\nWhat do you want to update?\n");
                    printf("\n1. Update only Name\n");
                    printf("2. Update only Marks\n");
                    printf("3. Update both\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &mark_choice_update);

                    update_marks(hptr, mark_update, mark_choice_update);
                }
                else
                {
                    printf("\nMultiple records found with same marks.\n");
                    printf("\nEnter roll number to specify: ");
                    scanf("%d", &roll_update);
                    roll_update_flag = search_by_roll(hptr, roll_update);

                    if (roll_update_flag == 1)
                    {
                        printf("\nWhat do you want to update?\n");
                        printf("\n1. Update only Name\n");
                        printf("2. Update only Marks\n");
                        printf("3. Update both\n");
                        printf("\nEnter your choice: ");
                        scanf("%d", &roll_choice_update);

                        update(hptr, roll_update, roll_choice_update);
                    }
                }
            }
            else
                printf("\nInvalid choice.Try again\n");

            break;

        case 8:
            printf("\nDo you want to save in a .csv file(Y/N):");
            scanf(" %c",&save_choice);

            if((save_choice == 'y')||(save_choice == 'Y'))
            {
                save_csv(hptr);
                save(hptr);
            }
            else
                save(hptr);

            break;

        case 9:
            printf("\nHow do you want to sort the records?\n");
            printf("1. Sort by Roll Number\n");
            printf("2. Sort by Name\n");
            printf("3. Sort by Marks\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice_sort);
            if(!(choice_sort >= 1 && choice_sort <= 3))
            {
                printf("\nInvalid choice.Try again.\n");

            }
            else
            {
            printf("\nChoose the order");
            printf("\n1. Ascending\n2. Descending.\n\nEnter order: ");
            scanf("%d", &order);
            if(!(order >= 1 && order <= 2))
                printf("\nInvalid choice.Try again.\n");
            else
              sort_display(hptr, choice_sort, order);
            }

            break;

        case 0:
            printf("\nDo you want to save changes before exit (Y/N)? ");
            scanf(" %c", &choice_save);
            if (choice_save == 'y' || choice_save == 'Y')
            {
            printf("\nDo you want to save in a .csv file(Y/N):");
            scanf(" %c",&save_choice);

            if((save_choice == 'y')||(save_choice == 'Y'))
            {
                save_csv(hptr);
                save(hptr);  //Once the load_csv code is completed remove this//
            }
            else
                save(hptr);
            }
            else
                printf("Changes not saved.\n");

            printf("Program Ended. Goodbye!\n");
            break;

        default:
            printf("Invalid choice.Try again.\n");
            break;
        }

    } while (choice_menu != 0);

    return 0;
}
