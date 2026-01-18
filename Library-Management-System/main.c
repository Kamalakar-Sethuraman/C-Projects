#include <stdio.h>
#include "Header.h"
#include <stdlib.h>

int next_book_ID = 1;
int next_User_ID = 1;
int next_Issue_ID =1;

int main()
{

     ST *hptr = NULL;
     USER *uptr = NULL;
     ISSUE *iptr = NULL;

     load(&hptr);       //load from .txt file
     load_user(&uptr);
     load_issue(&iptr);

    int choice_menu, choice_search, search_book_ID, update_choice;
    int update_by_book_ID, update_by_book_name;
    char add_choice, exit_choice, search_book_name[20], search_author_name[20], update_search_book_name[20];

    do
    {
        printf("\n\t========== LIBRARY MANAGEMENT MENU ===============\n");
        printf("\t|          1.  Add a new book                    |\n");  //working fine
        printf("\t|          2.  View all Books                    |\n");  //working fine
        printf("\t|          3.  Remove a Book                     |\n");  //working fine
        printf("\t|          4.  Delete all Books                  |\n");  //working fine
        printf("\t|          5.  Search a Book                     |\n");  //working fine
        printf("\t|          6.  Issue a Book                      |\n");  //written fine
        printf("\t|          7.  Update a Book details             |\n");  //working fine
        printf("\t|          8.  Return a Book                     |\n");  //working fine
        printf("\t|          9.  List issued Books                 |\n");  //working fine
        printf("\t|          10. Add a new user                    |\n");  //working fine
        printf("\t|          11. Display all Users                 |\n");  //working fine
        printf("\t|          12. Save                              |\n");  //working fine
        printf("\t|          0. Exit                               |\n");  //working fine
        printf("\t==================================================\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice_menu);

       switch(choice_menu)
         {
             case 1:
                 do
                 {
                    Book_add_middle(&hptr);
                    printf("\nDo you want to store another Book record(Y/N):");
                    scanf(" %c",&add_choice);
                 }
                 while((add_choice == 'y')||(add_choice == 'Y'));
                 break;

             case 2:
                 print(hptr);
                 break;

             case 3:
                delete_Book(&hptr);
                break;

             case 4:
                 delete_all_Books(&hptr);
                 printf("\n\tAll book records deleted successfully...\n");
                 break;

             case 5:
                printf("\nDo yo want to search by book ID or book name or author name");
                printf("\n1.By Book ID");
                printf("\n2.By Book name");
                printf("\n3.By Author name");
                printf("\n4.Back to main menu\n");
                printf("\nEnter your choice: ");
                scanf("%d",&choice_search);

                if(choice_search == 1)
                {
                    printf("\nEnter the Book ID to search: ");
                    scanf("%d",&search_book_ID);
                    search_by_Book_ID(hptr,search_book_ID);
                }

                else if(choice_search == 2)
                {
                    getchar();
                    printf("\nEnter the Book name to search: ");
                    scanf("%[^\n]", search_book_name );
                    search_by_Book_name(hptr,search_book_name);
                }

                else if(choice_search == 3)
                {
                    getchar();
                    printf("\nEnter the author name: ");
                    scanf("%[^\n]", search_author_name );
                    search_by_Author_name(hptr,search_author_name);
                }

                else if(choice_search == 4)
                {
                    printf("\n\tBack to Main menu...\n");
                    break;
                }

                else
                {
                    printf("Invalid choice...\n");
                }

                break;

             case 6:
                Issue_Book(hptr,&uptr,&iptr);
                break;

             case 7:

                printf("\nDo you want to update the Book details by searching Book ID or name");
                printf("\n1.By Book ID");
                printf("\n2.By Book name");
                printf("\n3.Back to main menu\n");

                printf("\nEnter your choice:");
                scanf("%d", &update_choice);

                if(update_choice == 1)
                {
                    int up_search_book_ID;

                    printf("\nEnter the Book_ID to update: ");
                    scanf("%d",&up_search_book_ID);

                    //search_by_Book_ID(hptr,search_book_ID);

                    printf("\nSelect what do you want to update");
                    printf("\n1.To Update Book name");
                    printf("\n2.To Update Author name");
                    printf("\n3.To Update Quantity");
                    printf("\n4.To Update Fine amount");
                    printf("\n5.To Update all\n");
                    printf("\n6.Back to main menu\n");
                    printf("\nEnter your choice:");
                    scanf("%d",&update_by_book_ID);

                    if((update_by_book_ID >=1) && (update_by_book_ID <=5))
                    {
                        update(hptr,up_search_book_ID,update_by_book_ID);
                    }

                    else
                    {
                        printf("\n\tBack to main menu...\n");
                    }
                   }

                   else if(update_choice == 2)
                   {
                    getchar();
                    printf("\nEnter the book name:");
                    scanf("%[^\n]",update_search_book_name);
                    search_by_Book_name(hptr,update_search_book_name);
                    printf("\nSelect what do you want to update");
                    printf("\n1.To Update Book name");
                    printf("\n2.To Update Author name");
                    printf("\n3.To Update Quantity");
                    printf("\n4.To Update Fine amount");
                    printf("\n5.To Update all");
                    printf("\n6.Back to main menu\n");
                    printf("\nEnter your choice:");
                    scanf("%d",&update_by_book_name);

                    if((update_by_book_name >=1) && (update_by_book_name <=5))
                    {
                        update_by_Book_name(hptr,update_search_book_name,update_by_book_name);
                    }

                    else
                    {
                        printf("\n\tBack to main menu...\n");
                    }
                   }

                   else if(update_choice ==3)
                   {
                       printf("\n\tBack to main menu\n");
                   }

                   else
                   {
                       printf("\n\tInvalid choice...\n");
                   }

                   break;

             case 8:
                return_book(hptr,&iptr);
                break;

             case 9:
                display_issued_books(iptr);
                break;

             case 10:
                user_add(&uptr);
                break;

             case 11:
                display_all_users(uptr);
                break;


             case 12:
                save(hptr);
                save_issued_books(iptr);
                save_user(uptr);
                break;

             case 0:
                printf("\nDo you want to save before exit(Y/N):");
                scanf(" %c", &exit_choice);
                if((exit_choice == 'y')||(exit_choice == 'Y'))
                {
                    save(hptr);
                    save_issued_books(iptr);
                    save_user(uptr);

                }
                else
                {
                    printf("\nClosing without saving...\n");
                    return 0;
                }
                break;

             default:
                 printf("\n\tInvalid Choice.Try again...\n");
                 break;
      }
    } while(choice_menu != 0);

      printf("\nProgram ended...Goodbye!!!!\n");
      return 0;

}
