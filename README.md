# DIGITAL-LIBRARY
DIGITAL LIBRARY IS A LIBRARY MANAGEMENT SYSTEM BUILD USING  C PROGRAMMING(CREATED BY SANTOSH K. SHAH)
# Digital Library Management System

A simple yet robust console-based Digital Library Management System built entirely in C. This project demonstrates core programming concepts and focuses heavily on file handling to persist library data, including books, members, and transaction records.

## 📖 Project Description

This system provides the essential functionalities for managing a library. It allows librarians to add, search, and manage the book inventory, register and manage library members, and handle the process of issuing and returning books. All data is stored in text files, making it a great example of database management using the C language's file I/O capabilities.

## ✨ Features

* **Book Management:**
    * Add new books to the library inventory.
    * Search for books by ID or title.
    * Display the complete list of available books.
    * Update book information.
* **Member Management:**
    * Register new library members.
    * Search for members by ID.
    * Display a list of all registered members.
* **Transaction Management:**
    * Issue books to members.
    * Handle the return of books.
    * View all issue/return transaction history.
* **Data Persistence:**
    * All data is saved to `.dat` files (`books.dat`, `members.dat`, `transactions.dat`).
    * Data is loaded from files upon application startup, ensuring no data loss between sessions.

## 🛠️ Tech Stack

* **Language:** C
* **Core Concept:** File Handling (stdio.h)

## ⚙️ How to Compile and Run

You can compile the project using any standard C compiler like GCC.

1.  **Save the code:** Save the provided C code as `library.c`.
2.  **Open a terminal or command prompt.**
3.  **Navigate to the directory** where you saved the file.
4.  **Compile the code** using the following command:
    ```bash
    gcc library.c -o library
    ```
5.  **Run the executable:**
    * On Windows: `library.exe`
    * On Linux/macOS: `./library`

Upon the first run, the application will automatically create the necessary data files (`books.dat`, `members.dat`, `transactions.dat`) if they don't exist.

## 📂 File Handling Explained

The persistence of data in this project is achieved through **file handling**. Instead of a traditional database, we use flat files to store information. Here’s a breakdown of how it works:

* **Data Structures:** We define `struct`s for `Book`, `Member`, and `Transaction`. These structures represent the schema for our data.

* **File Pointers:** We use `FILE *` pointers as handles to interact with our data files.

* **Opening Files:** Files are opened using the `fopen()` function. We use different modes for different operations:
    * `"ab+"` (append binary + read): This mode is used for adding new records. It opens the file for both reading and appending. If the file doesn't exist, it creates one. The file pointer is positioned at the end of the file for writing.
    * `"rb+"` (read binary + write): This mode is used for reading and updating records. The file must exist.

* **Writing to Files:**
    * The `fwrite()` function is used to write binary data (the `struct`s) directly into the files.
    * `fwrite(&book_to_add, sizeof(struct Book), 1, file_pointer);`
    * This writes the memory block occupied by the `book_to_add` structure into the file.

* **Reading from Files:**
    * The `fread()` function is used to read binary data from the files into our `struct` variables.
    * `while(fread(&book_reader, sizeof(struct Book), 1, file_pointer) == 1)`
    * This reads records one by one in a loop until the end of the file is reached.

* **Updating Records:**
    * To update a record, we open the file in read/write mode (`rb+`).
    * We read through the records one by one.
    * When the target record is found, we use `fseek()` to move the file pointer *back* by the size of one record.
    * `fseek(file_pointer, -sizeof(struct Book), SEEK_CUR);`
    * Then, we use `fwrite()` to overwrite the old record with the new, updated data.

### Conceptual File Structure Diagram

This diagram illustrates how the C program interacts with the data files to create a persistent storage system.

![AI image of digital library](https://lh3.googleusercontent.com/gg-dl/AJfQ9KQpS8nuvAUzYNA9v4ig6-x4RPI3l0q1hBPA81Q9gNHHn_UmosMB4cTOR0s-8zb4sijxV2lp4mnYxFNcpp8NGOyuTNk1jlpBoOLE08olAVz6StrwnlirhO3CTozFC8a1w23Ynje8e1hOoLUIPWwGkxab3t4EFtic7FM7uonFiT2DXKmf_Q)
