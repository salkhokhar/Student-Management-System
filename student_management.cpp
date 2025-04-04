#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string major;
};

// Function to load students from file
void loadStudents(vector<Student>& students, const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "No existing student record file found. Starting fresh.\n";
        return;
    }
    string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Student s;
        string token;
        getline(ss, token, ',');
        s.id = stoi(token);
        getline(ss, token, ',');
        s.name = token;
        getline(ss, token, ',');
        s.age = stoi(token);
        getline(ss, token, ',');
        s.major = token;
        students.push_back(s);
    }
    infile.close();
}

// Function to save students to file
void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream outfile(filename);
    for (const auto& s : students) {
        outfile << s.id << "," << s.name << "," << s.age << "," << s.major << "\n";
    }
    outfile.close();
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter student ID: ";
    cin >> s.id;
    cin.ignore(); // clear newline
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter student age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter student major: ";
    getline(cin, s.major);
    students.push_back(s);
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id 
             << ", Name: " << s.name 
             << ", Age: " << s.age 
             << ", Major: " << s.major << "\n";
    }
}

// Function to delete a student by ID
void deleteStudent(vector<Student>& students) {
    cout << "Enter the student ID to delete: ";
    int id;
    cin >> id;
    auto it = remove_if(students.begin(), students.end(), [id](const Student& s) {
        return s.id == id;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student record deleted.\n";
    } else {
        cout << "Student with ID " << id << " not found.\n";
    }
}

// Function to update a student record by ID
void updateStudent(vector<Student>& students) {
    cout << "Enter the student ID to update: ";
    int id;
    cin >> id;
    cin.ignore();
    bool found = false;
    for (auto& s : students) {
        if (s.id == id) {
            found = true;
            cout << "Enter new name (leave blank to keep current: " << s.name << "): ";
            string name;
            getline(cin, name);
            if (!name.empty()) s.name = name;
            
            cout << "Enter new age (enter 0 to keep current: " << s.age << "): ";
            int age;
            cin >> age;
            cin.ignore();
            if (age != 0) s.age = age;
            
            cout << "Enter new major (leave blank to keep current: " << s.major << "): ";
            string major;
            getline(cin, major);
            if (!major.empty()) s.major = major;
            
            cout << "Student record updated.\n";
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << id << " not found.\n";
    }
}

// Function to search for a student by ID
void searchStudent(const vector<Student>& students) {
    cout << "Enter the student ID to search: ";
    int id;
    cin >> id;
    cin.ignore();
    bool found = false;
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Found Student: " 
                 << "ID: " << s.id 
                 << ", Name: " << s.name 
                 << ", Age: " << s.age 
                 << ", Major: " << s.major << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << id << " not found.\n";
    }
}

int main() {
    vector<Student> students;
    const string filename = "students.txt";
    loadStudents(students, filename);

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudent(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                searchStudent(students);
                break;
            case 5:
                displayStudents(students);
                break;
            case 6:
                saveStudents(students, filename);
                cout << "Records saved. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
