# 📘 Library Management System (C Project)

## 🧾 Overview

This project is a **Library Management System** built in **C language**. It utilizes **Doubly Linked Lists** to efficiently manage book records and **Singly Linked Lists** to track library users and active book issues.
The system features a **menu-driven interface** that handles core library operations such as adding books, issuing loans, processing returns, calculating fines, and managing user databases, with data persistence using text files.

---

## 🧠 Features

* ➕ **Book Management:** Add new books with auto-generated IDs, Author Name, Quantity, and Fine rates.
* 📚 **Issue & Return:** Issue books to registered users and process returns with automatic fine calculation based on due dates.
* 👥 **User Management:** Register new users (borrowers) and maintain a directory of library members.
* 🔍 **Search System:** Search for books by **Book ID**, **Book Name**, or **Author Name**.
* ✏️ **Update Details:** Modify book information (Name, Author, Quantity, Fine) individually or in bulk.
* 📉 **Stock Tracking:** Automatically decrements stock when issued and increments upon return.
* 💾 **Data Persistence:** Automatically loads and saves Books, Users, and Issue records to `.txt` files (`Books_data.txt`, `User_data.txt`, `Issued_Books_data.txt`).

---

## 🧩 Data Structures

The project uses three primary data structures:

**1. Book Data (Doubly Linked List)**
Used for efficient sorting and deletion of book records.

```c
typedef struct Book
{
    struct Book *prv;
    int Book_ID;
    char Book_name[50];
    char Author_name[50];
    int Quantity;
    int Books_issued;
    int fine;
    struct Book *next;
} ST;

```

**2. User Data (Singly Linked List)**
Stores registered library members.

```c
typedef struct User
{
    int User_ID;
    char User_name[50];
    struct User *next;
} USER;

```

**3. Issue Records (Singly Linked List)**
Tracks active book loans, including dates.

```c
typedef struct Issue
{
    int Issue_ID;
    int Book_ID;
    int User_ID;
    char Book_name[50];
    char User_name[50];
    char Issued_date[20];
    char Due_date[20];
    struct Issue *next;
} ISSUE;

```

---

## 📁 File Structure

```
📂 Library_Management_System
├── main.c                  → Main program entry and menu loop
├── Header.h                → Structure definitions and function prototypes
├── Book_add.c              → Functions for adding new books
├── Book_delete.c           → Functions for removing books
├── Book_search.c           → Search logic (ID, Name, Author)
├── Book_update.c           → Update book details
├── Books_Issue.c           → Logic for issuing books to users
├── Book_return.c           → Logic for returning books & calculating fines
├── Books_User_add.c        → User management functions
├── Book_save.c             → File handling (Save/Load)
├── Book_get_current_date.c → Date utility functions
├── Books_data.txt          → Database for book records
├── User_data.txt           → Database for registered users
├── Issued_Books_data.txt   → Database for currently issued books
└── README.md               → Project documentation

```

---

## ⚙️ Compilation & Execution

### 🖥️ Linux / macOS

```bash
gcc main.c Book_*.c Books_*.c -o library
./library

```

### 🪟 Windows (MinGW / Code::Blocks)

```bash
gcc main.c Book_*.c Books_*.c -o library.exe
library.exe

```

---

## 🧭 Program Flow

1. **Initialization:** The program loads data from `Books_data.txt`, `User_data.txt`, and `Issued_Books_data.txt` into linked lists.
2. **Menu Interaction:** Users select operations (Add Book, Issue Book, Return Book, etc.).
3. **Processing:**
* **Issuing:** Checks stock availability, verifies user ID, creates an issue record, and updates book quantity.
* **Returning:** Calculates date difference between `Due_date` and return date to compute fines, then restores stock.


4. **Termination:** On exit (or manual save), all linked lists are written back to their respective text files.

---

## 🧾 File Handling

* `save()` / `load()`: Manages `Books_data.txt` (CSV format: `ID,Name,Author,Qty,Issued,Fine`).
* `save_user()` / `load_user()`: Manages `User_data.txt`.
* `save_issued_books()` / `load_issue()`: Manages `Issued_Books_data.txt`.

---

## 🧰 Menu Interface

```
========== LIBRARY MANAGEMENT MENU ===============
|          1.  Add a new book                    |
|          2.  View all Books                    |
|          3.  Remove a Book                     |
|          4.  Delete all Books                  |
|          5.  Search a Book                     |
|          6.  Issue a Book                      |
|          7.  Update a Book details             |
|          8.  Return a Book                     |
|          9.  List issued Books                 |
|         10.  Add a new user                    |
|         11.  Display all Users                 |
|         12.  Save                              |
|          0.  Exit                              |
==================================================

```

---

## 🚀 Future Enhancements

* 📅 **Advanced Date Handling:** Integrate real-time clock validation to prevent future-dated returns.
* 🔐 **Admin Authentication:** Password protection for sensitive operations (Delete All, Update Fine).
* 📊 **Reports:** Generate "Most Issued Books" or "Defaulters List" reports.
* 🌐 **GUI:** Implement a graphical interface using GTK or Qt.

---

## 👨‍💻 Author

* Developed by **Kamalakar.S**
* Language: C
* Tested on: GCC / Code::Blocks
