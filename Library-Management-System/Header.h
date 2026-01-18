#ifndef HEADER_H
#define HEADER_H

typedef struct Library
{
    struct Library *prv;
    int Book_ID;
    char Book_name[20];
    char Author_name[20];
    int Quantity;
    int Books_issued;
    int fine;
    struct Library *next;
} ST;

typedef struct User
{
    int User_ID;
    char User_name[20];
    struct User *next;

}USER;

typedef struct Issued_Books
{
    int Book_ID;
    int User_ID;
    int Issue_ID;
    char Book_name[20];
    char User_name[20];
    char Issued_date[20];
    char Due_date[20];
    struct Issued_Books *next;

}ISSUE;

extern int next_book_ID;
extern int search_name_count;
extern int next_User_ID;
extern int next_Issue_ID;


void Book_add_middle(ST **);
void print(ST *ptr);
int find_next_Book_ID(ST *);
int find_next_User_ID(USER *);
void save(ST *);
void save_issued_books(ISSUE *);
void save_user(USER *);
void load(ST **);
void load_user(USER **);
void load_issue(ISSUE **);
void delete_Book(ST **);
int search_by_Book_ID(ST *, int);
void delete_by_Book_ID(ST **, int);
int search_by_name_count(ST *, char *);
void search_by_Book_name(ST *, char *);
void delete_by_Book_name(ST **,char *);
void delete_all_Books(ST **);
void search_by_Author_name(ST *, char *);
void update(ST *, int, int);
void update_by_Book_name(ST *, char *, int);
void get_current_date(char *);
void get_due_date(char *);
int date_diff(char *, char *);
USER* user_add(USER **);
void display_all_users(USER *);
void Issue_Book(ST *, USER **, ISSUE **);
void display_issued_books(ISSUE *);
void return_book(ST *, ISSUE **);
int find_next_Issue_ID(ISSUE *);

#endif
