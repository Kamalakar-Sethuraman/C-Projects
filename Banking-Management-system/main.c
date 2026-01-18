#include <stdio.h>
#include "Header.h"
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int choice_menu,up_choice;
    unsigned long long int d_acc_num, s_acc_num, u_acc_num, dep_acc_num, with_acc_num, sender_acc_num, rec_acc_num;
    char acc_op, exit_op;

     ST *hptr = NULL;
     TR *tlist = NULL;


     load(&hptr);
     load_transactions(&tlist);


    do
    {
        printf("\n\t==========  BANKING MANAGEMENT MENU ==============\n");
        printf("\t|          1.  Create a new account              |\n"); //done
        printf("\t|          2.  View all account details          |\n"); //done
        printf("\t|          3.  Delete a account                  |\n"); //done
        printf("\t|          4.  Delete all account details        |\n"); //done
        printf("\t|          5.  Search an account                 |\n"); //done
        printf("\t|          6.  Deposit Money                     |\n"); //done
        printf("\t|          7.  Update account details            |\n"); //done
        printf("\t|          8.  Withdraw money                    |\n"); //done
        printf("\t|          9.  Money Transfer                    |\n"); //done
        printf("\t|         10.  Transaction details               |\n"); //done
        printf("\t|         11.  Save Account details              |\n"); //done
        printf("\t|          0.  Exit                              |\n"); //done
        printf("\t==================================================\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice_menu);

       switch(choice_menu)
         {

         case 1:
             do
             {
                 Acc_add_middle(&hptr);
                 printf("Do you want to add another account(Y/N):");
                 scanf(" %c",&acc_op);
             }
             while((acc_op == 'Y') || (acc_op == 'y'));
             break;

         case 2:
             print(hptr);
             break;

         case 3:
             if(hptr == NULL)
             {
                 printf("\n\tNo records available to delete...\n");
                 break;
             }
             printf("\nEnter the account number to delete:");
             scanf("%llu",&d_acc_num);
             delete_by_Acc_num(&hptr, d_acc_num);
             break;

         case 4:
            delete_all_Acc(&hptr);
            break;

         case 5:
            printf("\nEnter the account number to search:");
            scanf("%llu", &s_acc_num);
            search_by_Acc_num(hptr,s_acc_num);
            break;

         case 6:
            printf("\nEnter the account number:");
            scanf("%llu",&dep_acc_num);
            Deposit_by_Acc_num(hptr,dep_acc_num,&tlist);
            break;

         case 7:
            printf("\n1.To update the Account holder's name.\n");
            printf("2.To update the Account type.\n");
            printf("3.To update the Address.\n");
            printf("4.To update the Balance.\n");
            printf("5.To update the Phone number.\n");
            printf("6.To update the pin number.\n");
            printf("7.To update all.\n");
            printf("\n\tEnter your choice:");
            scanf("%d",&up_choice);
            printf("\nEnter the account number to update:");
            scanf("%llu",&u_acc_num);
            update(hptr,u_acc_num,up_choice);
            printf("\n\tNew updated records below...\n");
            search_by_Acc_num(hptr,u_acc_num);
            break;

         case 8:
            printf("\nEnter the account number:");
            scanf("%llu",&with_acc_num);
            Withdraw_by_Acc_num(hptr,with_acc_num,&tlist);
            break;

         case 9:
            printf("\nEnter the sender account number:");
            scanf("%llu",&sender_acc_num);
            printf("\nEnter the receiver account number:");
            scanf("%llu",&rec_acc_num);
            Transfer_by_Acc_num(hptr,sender_acc_num,rec_acc_num,&tlist);
            break;

         case 10:
            print_transactions(tlist);
            break;

         case 11:
            save(hptr);
            save_transactions(tlist);
            printf("\nAccount details and Transaction History saved...\n");
            break;

         case 0:
            printf("\nDo you want to save before exit(Y/N):");
            scanf(" %c", &exit_op);
            if((exit_op == 'Y') || (exit_op == 'y'))
            {
                save(hptr);
                save_transactions(tlist);
                printf("\nAccount details and Transaction History saved...\n");
            }

            else
            {
                printf("\nClosing without saving...\n");
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
