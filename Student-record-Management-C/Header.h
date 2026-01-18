#ifndef HEADER_H
#define HEADER_H

typedef struct student
{
    struct student *prv;
    int roll;
    char name[20];
    float marks;
    struct student *next;
} ST;

extern int next_roll;
extern int search_name_count;
extern int search_mark_count;

void add_middle(ST **);
int find_next_roll(ST *);
void print(ST *);
void rev_print(ST *);
void delete_node(ST **);
void delete_all(ST **);
void delete_by_roll(ST **,int);
void delete_by_name(ST **,char *);
void save(ST *);
int count(ST *);
void load(ST **);
void search_by_name(ST *,char *);
int search_by_roll(ST *, int);
int search_by_name_count(ST *, char *);
void search_by_marks(ST *, float);
int search_count_by_marks(ST *, float);
void update(ST *, int, int);
void update_marks(ST *, float, int);
void update_by_name(ST *, char *, int);
void sort_display(ST *, int, int);
void save_csv(ST *);
void load_csv(ST **);

#endif
