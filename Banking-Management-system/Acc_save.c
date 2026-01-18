#include "Header.h"

void save_transactions(TR *ptr)
{
    FILE *fp = fopen("transactions.txt", "w");

    while (ptr)
    {
        fprintf(fp, "%llu | %llu | %s | %llu | %s\n",
                ptr->Transaction_id,
                ptr->Acc_num,
                ptr->type,
                ptr->amount,
                ptr->datetime);

        ptr = ptr->next;
    }

    fclose(fp);
}

void save(ST *ptr)
{
    FILE *fp = fopen("Accout_details.txt", "w");
    if (!fp) return;

    while (ptr)
    {
        fprintf(fp, "%llu | %s | %s | %llu | %s | %llu | %d\n",
                ptr->Acc_num,
                ptr->Name,
                ptr->Acc_type,
                ptr->Balance,
                ptr->Address,
                ptr->Phone_num,
                ptr->pin_num);

        ptr = ptr->next;   // ← THIS WAS MISSING
    }

    fclose(fp);
}


