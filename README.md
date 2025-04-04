# Student Management System

A simple console-based application written in C++ to manage student records. The system allows you to add, delete, update, search, and display student records, with data persistence achieved through file I/O. This project uses STL containers (like vectors) to handle data in memory.

## Features

- **Add Student:** Insert new student records (ID, name, age, and major).
- **Delete Student:** Remove a student record by specifying the student ID.
- **Update Student:** Modify details of an existing student.
- **Search Student:** Locate a student record by ID.
- **Display Students:** View all stored student records.
- **File Persistence:** Automatically loads records from and saves records to `students.txt`.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++` or `clang++`)
- Basic familiarity with console applications in C++

### Compilation

1. Open your terminal and navigate to the project directory.
2. Compile the project using the following command:

    ```bash
    g++ -o student_management student_management.cpp
    ```

   This command compiles `student_management.cpp` and produces an executable named `student_management`.

### Running the Application

Once compiled, run the application with:

```bash
./student_management
```

You will see a menu with the following options:
<ol>
  <li>Add Student</li>
  <li>Delete Student</li>
  <li>Update Student</li>
  <li>Search Student</li>
  <li>Display All Students</li>
  <li>Save & Exit</li>
</ol>

Follow the on-screen prompts to manage your student records.

<h3>Data Storage</h3>
<ul>
  <li>The application uses a file named <code>students.txt</code> for storing student records.</li>
  <li>Each student record is stored as a comma-separated line containing the student ID, name, age, and major.</li>
  <li>Data is loaded from the file at startup and saved back when you choose the "Save & Exit" option.</li>
</ul>

<h3>Project Structure</h3>
<ul>
  <li><strong>student_management.cpp:</strong> The main C++ source file containing the entire application code.</li>
  <li><strong>students.txt:</strong> A text file that stores student records. This file is created automatically if it does not exist.</li>
</ul>

<h3>Usage Example</h3>
<ul>
  <li><strong>Adding a Student:</strong> Select option 1, then enter the student's ID, name, age, and major when prompted.</li>
  <li><strong>Deleting a Student:</strong> Select option 2 and provide the ID of the student you wish to delete.</li>
  <li><strong>Updating a Student:</strong> Select option 3, input the ID, and then update the fields as necessary.</li>
  <li><strong>Searching for a Student:</strong> Select option 4 and enter the student ID to view the student's details.</li>
  <li><strong>Displaying All Students:</strong> Select option 5 to list all student records.</li>
  <li><strong>Saving and Exiting:</strong> Choose option 6 to save all changes to <code>students.txt</code> and exit the application.</li>
</ul>

