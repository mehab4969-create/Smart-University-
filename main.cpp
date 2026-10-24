#include "SystemManager.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ---------- small helpers for safe input ----------
int readInt(const string& message) {
    int value;
    cout << message;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string readLine(const string& message) {
    string text;
    cout << message;
    getline(cin, text);
    return text;
}

// ---------- Students menu ----------
void studentsMenu(SystemManager& sys) {
    int choice;
    do {
        cout << "\n--- Students ---\n"
             << "1) Add  2) Show all  3) Search  4) Edit  5) Delete  0) Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) {
            int id = readInt("ID: ");
            string name = readLine("Name: ");
            string pass = readLine("Password: ");
            int level = readInt("Level: ");
            if (sys.addStudent(Student(id, name, pass, level))) cout << "Added.\n";
            else cout << "This ID already exists.\n";
        } else if (choice == 2) {
            sys.showStudents();
        } else if (choice == 3) {
            Student* s = sys.findStudent(readInt("ID: "));
            if (s) s->display(); else cout << "Not found.\n";
        } else if (choice == 4) {
            int id = readInt("ID: ");
            string name = readLine("New name: ");
            int level = readInt("New level: ");
            cout << (sys.editStudent(id, name, level) ? "Updated.\n" : "Not found.\n");
        } else if (choice == 5) {
            cout << (sys.deleteStudent(readInt("ID: ")) ? "Deleted.\n" : "Not found.\n");
        }
    } while (choice != 0);
}

// ---------- Doctors menu ----------
void doctorsMenu(SystemManager& sys) {
    int choice;
    do {
        cout << "\n--- Doctors ---\n"
             << "1) Add  2) Show all  3) Search  4) Edit  5) Delete  0) Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) {
            int id = readInt("ID: ");
            string name = readLine("Name: ");
            string pass = readLine("Password: ");
            string dept = readLine("Department: ");
            if (sys.addDoctor(Doctor(id, name, pass, dept))) cout << "Added.\n";
            else cout << "This ID already exists.\n";
        } else if (choice == 2) {
            sys.showDoctors();
        } else if (choice == 3) {
            Doctor* d = sys.findDoctor(readInt("ID: "));
            if (d) d->display(); else cout << "Not found.\n";
        } else if (choice == 4) {
            int id = readInt("ID: ");
            string name = readLine("New name: ");
            string dept = readLine("New department: ");
            cout << (sys.editDoctor(id, name, dept) ? "Updated.\n" : "Not found.\n");
        } else if (choice == 5) {
            cout << (sys.deleteDoctor(readInt("ID: ")) ? "Deleted.\n" : "Not found.\n");
        }
    } while (choice != 0);
}

// ---------- Courses menu ----------
void coursesMenu(SystemManager& sys) {
    int choice;
    do {
        cout << "\n--- Courses ---\n"
             << "1) Add  2) Show all  3) Search  4) Edit  5) Delete  0) Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) {
            int id = readInt("ID: ");
            string code = readLine("Code: ");
            string name = readLine("Name: ");
            int doctorId = readInt("Doctor ID: ");
            if (sys.addCourse(Course(id, code, name, doctorId))) cout << "Added.\n";
            else cout << "This ID already exists.\n";
        } else if (choice == 2) {
            sys.showCourses();
        } else if (choice == 3) {
            Course* c = sys.findCourse(readInt("ID: "));
            if (c) c->display(); else cout << "Not found.\n";
        } else if (choice == 4) {
            int id = readInt("ID: ");
            string name = readLine("New name: ");
            string code = readLine("New code: ");
            cout << (sys.editCourse(id, name, code) ? "Updated.\n" : "Not found.\n");
        } else if (choice == 5) {
            cout << (sys.deleteCourse(readInt("ID: ")) ? "Deleted.\n" : "Not found.\n");
        }
    } while (choice != 0);
}

// ---------- main ----------
int main() {
    SystemManager sys;
    int choice;

    do {
        cout << "\n===== University System =====\n"
             << "1) Students\n2) Doctors\n3) Courses\n4) Load sample data\n0) Exit\n";
        choice = readInt("Choice: ");

        if (choice == 1) studentsMenu(sys);
        else if (choice == 2) doctorsMenu(sys);
        else if (choice == 3) coursesMenu(sys);
        else if (choice == 4) sys.loadSampleData();
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
