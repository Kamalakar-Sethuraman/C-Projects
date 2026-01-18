#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct Bank
{
    struct Bank *prv;
    unsigned long long int Acc_num;
    char Name[20];
    char Acc_type[20];
    unsigned long long int Balance;
    char Address[200];
    unsigned long long int Phone_num;
    int pin_num;
    struct Bank *next;
} ST;

typedef struct Transaction
{
    unsigned long long int Transaction_id;
    unsigned long long int Acc_num;
    char type[15]; // deposit,withdraw,debited,credited
    unsigned long long int amount;
    char datetime[40];  //date+time
    struct Transaction *next;

}TR;

void Acc_add_middle(ST **);
unsigned long long Acc_num();
unsigned long long pin_num();
void print(ST *);
void delete_by_Acc_num(ST **, unsigned long long int);
void delete_all_Acc(ST **);
int search_by_Acc_num(ST *, unsigned long long int);
void update(ST *, unsigned long long int, int);
void Deposit_by_Acc_num(ST *, unsigned long long int, TR **);
void Withdraw_by_Acc_num(ST *, unsigned long long int, TR **);
void Transfer_by_Acc_num(ST *, unsigned long long, unsigned long long, TR **);
void get_datetime(char *);
unsigned long long TR_id();
void add_transaction(TR **, unsigned long long , char *, unsigned long long);
void print_transactions(TR *);
void save_transactions(TR *);
void save(ST *);
void load(ST **);
void load_transactions(TR **);
void trim(char *s);

#endif
