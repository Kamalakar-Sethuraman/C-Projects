#include "Header.h"

void Acc_add_middle(ST **ptr)
{
	ST *temp = (ST *)malloc(sizeof(ST));

	getchar();

	printf("\nEnter the Account holder name:");
	scanf("%[^\n]",temp->Name);

	getchar();
	printf("\nEnter the Account type:");
    scanf("%[^\n]",temp->Acc_type);

    printf("\nEnter the Balance amount:");
    scanf("%llu",&temp->Balance);

	getchar();
	printf("\nEnter the Address:");
    scanf("%[^\n]",temp->Address);

    printf("\nEnter the phone number:");
    scanf("%llu",&temp->Phone_num);


    temp->Acc_num = Acc_num();
    temp->pin_num = pin_num();

	if( (*ptr == 0) || (temp->Acc_num < (*ptr)->Acc_num) )
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
		while((last->next != 0)&&(temp->Acc_num > (last->next->Acc_num)) )
		last = last->next;

		temp->prv = last;
		temp->next = last->next;
		if(last->next != 0)
		last->next->prv = temp;

		last->next = temp;
	}
}

unsigned long long Acc_num()
{
    unsigned long long num = 0;
    for(int i = 0; i < 16; i++)
        num = num * 10 + (rand() % 10);
    return num;
}

unsigned long long pin_num()
{
    unsigned long long num = 0;
    for(int i = 0; i < 4; i++)
        num = num * 10 + (rand() % 10);
    return num;
}
