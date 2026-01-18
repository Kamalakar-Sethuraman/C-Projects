#include "Header.h"

void load(ST **head)
{
    FILE *fp = fopen("Accout_details.txt", "r");
    if (!fp)
    {
        printf("No previous account data found.\n");
        return;
    }

    char line[600];

    while (fgets(line, sizeof(line), fp))
    {
        ST *new = malloc(sizeof(ST));
        if (!new) return;
        memset(new, 0, sizeof(ST));

        // Split by '|'
        char *token = strtok(line, "|");
        if (!token) continue;
        new->Acc_num = strtoull(token, NULL, 10);

        token = strtok(NULL, "|");
        strcpy(new->Name, token ? token : "");

        token = strtok(NULL, "|");
        strcpy(new->Acc_type, token ? token : "");

        token = strtok(NULL, "|");
        new->Balance = strtoull(token, NULL, 10);

        token = strtok(NULL, "|");
        strcpy(new->Address, token ? token : "");

        token = strtok(NULL, "|");
        new->Phone_num = strtoull(token, NULL, 10);

        token = strtok(NULL, "|");
        new->pin_num = token ? atoi(token) : 0;

        // Trim spaces
        trim(new->Name);
        trim(new->Acc_type);
        trim(new->Address);

        // Insert node
        new->next = NULL;
        new->prv = NULL;

        if (*head == NULL)
        {
            *head = new;
        }
        else
        {
            ST *last = *head;
            while (last->next) last = last->next;
            last->next = new;
            new->prv = last;
        }
    }

    fclose(fp);
    printf("Accounts data loaded successfully.\n");
}

void trim(char *s)
{
    while (*s == ' ' || *s == '\n') s++;

    char *end = s + strlen(s) - 1;
    while (end > s && (*end == ' ' || *end == '\n'))
        *end-- = '\0';
}


void load_transactions(TR **head)
 {
    FILE *fp = fopen("transactions.txt", "r");
    if (!fp) {
        printf("No previous transaction data found.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        TR *new_node = malloc(sizeof(TR));
        if (!new_node) return;
        memset(new_node, 0, sizeof(TR));

        char *token = strtok(line, "|");
        if (!token) continue;
        new_node->Transaction_id = strtoull(token, NULL, 10);

        token = strtok(NULL, "|");
        new_node->Acc_num = token ? strtoull(token, NULL, 10) : 0;

        token = strtok(NULL, "|");
        strcpy(new_node->type, token ? token : "");

        token = strtok(NULL, "|");
        new_node->amount = token ? strtoull(token, NULL, 10) : 0;

        token = strtok(NULL, "\n");  // Last field may have '\n'
        strcpy(new_node->datetime, token ? token : "");

        trim(new_node->type);
        trim(new_node->datetime);

        // Insert at end
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
        } else {
            TR *last = *head;
            while (last->next)
                last = last->next;
            last->next = new_node;
        }
    }

    fclose(fp);
    printf("Transactions History loaded successfully.\n");
}

