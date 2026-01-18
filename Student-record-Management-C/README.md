# 📘 Student Record Management System (C Project)

## 🧾 Overview
This project is a **Student Record Management System** built in **C language**, which uses **Doubly Linked Lists** to manage student data.  
It allows adding, deleting, updating, searching, sorting, and saving student records efficiently through a **menu-driven interface**.

---

## 🧠 Features
- ➕ Add new student records (auto-generated roll number)
- 📋 Display all student records
- 🔁 Reverse print records using doubly linked list
- 🔍 Search students by Roll Number, Name, or Marks
- ✏️ Update student details (Name / Marks / Both)
- ❌ Delete individual or all records
- 📊 Sort records by Roll Number, Name, or Marks (Ascending / Descending)
- 💾 Save and load records from text or CSV files

---

## 🧩 Data Structure
Each student record is represented as a **doubly linked list node**:

```c
typedef struct student {
    struct student *prv;
    int roll;
    char name[20];
    float marks;
    struct student *next;
} ST;
```

---

## 📁 File Structure

```
📂 Student_Record_Management
├── main.c        → Main program and menu system
├── Header.h      → Structure definition and function prototypes
├── record.txt    → Auto-generated file for data persistence
├── record.csv    → Optional CSV export file
└── README.md     → Project documentation
```

---

## ⚙️ Compilation & Execution

### 🖥️ Linux / macOS
```bash
gcc main.c -o student
./student
```

### 🪟 Windows (MinGW / Code::Blocks)
```bash
gcc main.c -o student.exe
student.exe
```

---

## 🧭 Program Flow

1. **Program Start:** Automatically loads records from `record.txt`
2. **Menu Operations:** Interactive menu for performing actions
3. **Add Record:** Automatically assigns roll number and stores data
4. **Search / Update / Delete:** Provides multiple search criteria
5. **Save:** Option to save data in `.txt` or `.csv` before exiting

---

## 🧾 File Handling
- `save()` → Writes records to `record.txt`
- `load()` → Loads records from `record.txt` at startup
- `save_csv()` → Exports records to CSV
- `load_csv()` → (Work in progress)

---

## 🧰 Example Menu

```
========== STUDENT RECORD MANAGEMENT ==========
|          1. Add a student record            |
|          2. Show all student records        |
|          3. Delete a specific record        |
|          4. Delete all records              |
|          5. Reverse print the data          |
|          6. Search for a student            |
|          7. Update a student record         |
|          8. Save records to file            |
|          9. Sort the records                |
|          0. Exit                            |
================================================
```

---

## 🚀 Future Enhancements
- Complete CSV loading function
- Input validation for marks and names
- GUI-based interface (future expansion)
- Export/import support for JSON format

---

## 👨‍💻 Author
Developed by **KMALAKAR.S**  
Language: C  
Tested on: GCC, Code::Blocks*

---
