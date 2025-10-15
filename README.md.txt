# Student Record Management System 🧑‍🎓

A simple command-line application built in **C** to manage student records, including adding, displaying, searching, updating, deleting, and sorting student data.

---

## 🚀 Features

This application provides a comprehensive set of functions for managing student data:

* **Add Students**: Dynamically add one or more student records.
* **Unique Matriculation Number**: Ensures that each student record has a unique matriculation number.
* **Display All Students**: Presents all stored student records in a formatted table.
* **Search by Matriculation Number**: Quickly find a student's record using their unique matriculation number.
* **Update Student Record**: Modify a student's three subject grades and recalculate their average.
* **Delete a Student**: Remove a student's record from the system.
* **Sort by Average Marks**: Sorts and displays all student records in descending order based on their average marks.
* **Dynamic Memory Management**: Uses `realloc` to efficiently manage memory for the growing list of student records.

---

## ⚙️ Prerequisites

To compile and run this program, you will need:

* A C compiler (e.g., **GCC**).

---

## 🛠️ Installation and Setup

1.  **Clone the Repository** (If applicable):
    ```bash
    # If the code is in a repository
    git clone <repository-url>
    cd <repository-name>
    ```
2.  **Save the Code**:
    Save the provided C code into a file named, for example, `student_management.c`.
3.  **Compile the Program** using a C compiler (like GCC):
    ```bash
    gcc student_management.c -o student_management
    ```
4.  **Run the Executable**:
    ```bash
    ./student_management
    ```

---

## 📖 Usage

Upon running the program, a menu will be displayed, prompting you to choose an action:

===== Student Record Management System =====

Add Students

Display All Students

Search by Matriculation Number

Update Student Record

Delete a Student

Sort by Average Marks

Exit
============================================


Enter the corresponding number for the operation you wish to perform.

| Option | Description |
| :---: | :--- |
| **1** | Prompts for the number of students to add, then collects **Name**, **Matriculation Number** (must be unique), and **3 Grades** for each. |
| **2** | Shows a table of all existing student records. |
| **3** | Asks for a matriculation number and displays the full record if found. |
| **4** | Asks for a matriculation number and allows you to update the 3 grades for that student. |
| **5** | Asks for a matriculation number and deletes the corresponding record. |
| **6** | Sorts all students and displays them based on their average marks in **descending order** (highest average first). |
| **7** | Frees allocated memory and exits the program. |

---

| **Author** | Rayyan Khattak |