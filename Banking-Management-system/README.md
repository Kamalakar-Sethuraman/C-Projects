# 📘 Banking Management System (C Project)

## 🧾 Overview

This project is a **Banking Management System** built in **C language**. It utilizes **Doubly Linked Lists** to manage customer account data and **Singly Linked Lists** to track transaction history.
It features a robust **menu-driven interface** that simulates real-world banking operations such as depositing, withdrawing, transferring funds, and generating transaction reports, with data persistence using text files.

---

## 🧠 Features

* ➕ **Create Accounts:** Auto-generates unique 16-digit Account Numbers and 4-digit PINs.
* 🏦 **Banking Operations:** Support for **Deposits**, **Withdrawals**, and **Fund Transfers** between accounts.
* 📜 **Transaction History:** Logs every financial action (ID, Type, Amount, Timestamp) linked to the account.
* 📋 **View Details:** Display individual or all account holders with formatted output.
* ✏️ **Update Details:** Modify specific fields (Name, Address, Phone, PIN, etc.) or all details at once.
* 🔍 **Search & Delete:** Find accounts by Account Number or delete records efficiently.
* 💾 **Data Persistence:** Automatically loads and saves Account details and Transaction logs to `.txt` files.

---

## 🧩 Data Structures

The project uses two primary data structures:

**1. Account Data (Doubly Linked List)**
Used for navigation (Next/Previous) and efficient deletion.

```c
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

```

**2. Transaction History (Singly Linked List)**
Used to maintain a linear log of operations.

```c
typedef struct Transaction
{
    unsigned long long int Transaction_id;
    unsigned long long int Acc_num;
    char type[15]; // deposit, withdraw, debited, credited
    unsigned long long int amount;
    char datetime[40];
    struct Transaction *next;
} TR;

```

---

## 📁 File Structure

```
📂 Banking_Management_System
├── main.c              → Main program entry and menu loop
├── Header.h            → Structure definitions and function prototypes
├── implementations.c   → (Optional) Source file for function definitions
├── Accout_details.txt  → Database for storing account records
├── transactions.txt    → Database for storing transaction logs
└── README.md           → Project documentation

```

---

## ⚙️ Compilation & Execution

### 🖥️ Linux / macOS

```bash
gcc main.c -o bank
./bank

```

*(Note: If your functions are in separate `.c` files, use `gcc *.c -o bank`)*

### 🪟 Windows (MinGW / Code::Blocks)

```bash
gcc main.c -o bank.exe
bank.exe

```

---

## 🧭 Program Flow

1. **Initialization:** The program loads data from `Accout_details.txt` and `transactions.txt` into linked lists.
2. **Menu Interaction:** Users choose operations (Create, Deposit, Transfer, etc.).
3. **Processing:**
* **Transfers:** Verifies sender balance, deducts amount, adds to receiver, and logs transactions for both.
* **Updates:** Modifies specific nodes in the linked list.


4. **Termination:** On exit (or manual save), data is written back to the text files to ensure no data loss.

---

## 🧾 File Handling

* `load()`: Reads account data from `Accout_details.txt` parsing with `|` delimiter.
* `load_transactions()`: Reads history from `transactions.txt`.
* `save()`: Writes the current state of the linked list to the file.
* `save_transactions()`: Appends/Overwrites transaction logs.

---

## 🧰 Menu Interface

```
==========  BANKING MANAGEMENT MENU ==============
|          1.  Create a new account              |
|          2.  View all account details          |
|          3.  Delete a account                  |
|          4.  Delete all account details        |
|          5.  Search an account                 |
|          6.  Deposit Money                     |
|          7.  Update account details            |
|          8.  Withdraw money                    |
|          9.  Money Transfer                    |
|         10.  Transaction details               |
|         11.  Save Account details              |
|          0.  Exit                              |
==================================================

```

---

## 🚀 Future Enhancements

* 🔐 **Authentication:** Add a login system requiring the generated PIN for transactions.
* 🧮 **Interest Calculation:** Add logic for Savings vs Current account interest rates.
* 🛡️ **Input Validation:** robust checks for negative amounts or non-numeric inputs.
* 📄 **Mini Statement:** Generate a printable receipt for the last 5 transactions.

---

## 👨‍💻 Author

* Developed by **Kamalakar.S**
* Language: C
* Tested on: GCC / Code::Blocks
