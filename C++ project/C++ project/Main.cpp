#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "University.h"
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>  
#include <chrono>
#include <thread>
#include <cstdlib>


using namespace std;

// Bye bye animation

void wavingStickman() {

    string frames[] = {

R"(

     O
    /|\
____/_\_____

)",

R"(

     O/
    /|
____/_\_____

)",

R"(

     O
    /|\
____/_\_____

)",

R"(

     O/
    /|
____/_\_____

)"
    };

    for (int i = 0; i < 12; i++) {

#ifdef _WIN32
        system("cls");
#endif
        cout << "Bye bye!";
        cout << frames[i % 4];


        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

// Drawing a box (for UI)

static void drawLine(int width) {
    cout << "+";
    for (int i = 0; i < width; i++) cout << "~";
    cout << "+\n";
}

static void drawTextLine(const string& text, int width) {
    int len = (int)text.length();
    int padding = (width > len) ? (width - len) : 0;
    int left = padding / 2;
    int right = padding - left;

    cout << "$";
    for (int i = 0; i < left; i++) cout << " ";
    cout << text;
    for (int i = 0; i < right; i++) cout << " ";
    cout << "$\n";
}

static void drawBox(const string& text, int width = 40) {
    drawLine(width);
    drawTextLine(text, width);
    drawLine(width);
}

static void drawMenu(const string& title, const string options[], int size) {
    int width = 30; 

    drawLine(width);
    drawTextLine(title, width);
    drawLine(width);

    for (int i = 0; i < size; i++) {

        string text = options[i];

        drawLine(width);
        drawTextLine(text, width);
        drawLine(width);

        cout << "\n";
    }
}

// Safe input

static int safeIntInput() {
    int value;
    while (true) {
        if (cin >> value) return value;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter a number: ";
    }
}

bool adminLogin();
bool studentLogin(University& uni, int& studentId);
void adminMenu(University& uni);
void studentsModule(University& uni);
void teachersModule(University& uni);
void employeesModule(University& uni);
void studentMenu(University& uni, int studentId);

int main() {
    University uni;

    while (true) {
        string mainOptions[] = {
            "1. Login as Admin",
            "2. Login as Student",
            "0. Exit"
        };
        drawMenu("UNIVERSITY MANAGEMENT SYSTEM", mainOptions, 3);

        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1:
            if (adminLogin())
                adminMenu(uni);
            else
                cout << "Wrong credentials!\n";
            break;

        case 2: {
            int studentId;
            if (studentLogin(uni, studentId))
                studentMenu(uni, studentId);
            break;
        }

        case 0:
            cout << "Exiting...\n";
            wavingStickman();
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

// Login for admin and student

bool adminLogin() {
    string user, pass;
    drawBox("ADMIN LOGIN");
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;
    return (user == "admin" && pass == "1234");
}

bool studentLogin(University& uni, int& studentId) {
    int id;
    string password;
    drawBox("STUDENT LOGIN");
    cout << "Enter Student ID: "; id = safeIntInput();
    cout << "Enter Password: ";   cin >> password;

    if (uni.loginStudent(id, password)) {
        studentId = id;
        cout << "\nLogin successful!\n";
        return true;
    }
    cout << "\nInvalid ID or password!\n";
    return false;
}

// Admin panel

void adminMenu(University& uni) {
    while (true) {
        string options[] = {
            "1. Students Module",
            "2. Teachers Module",
            "3. Employees Module",
            "0. Logout"
        };
        drawMenu("ADMIN PANEL", options, 4);
        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1: studentsModule(uni);  break;
        case 2: teachersModule(uni);  break;
        case 3: employeesModule(uni); break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// Student section

void studentsModule(University& uni) {
    while (true) {
        string options[] = {
            "1. List Students",
            "2. Add Student",
            "3. Update Student",
            "4. Delete Student",
            "5. Search Student",
            "0. Back"
        };
        drawMenu("STUDENTS MODULE", options, 6);
        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1: uni.displayStudents(); break;
        case 2: uni.addStudent();      break;
        case 3: uni.updateStudent();   break;
        case 4: uni.deleteStudent();   break;
        case 5: uni.searchStudent();   break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// Teacher section

void teachersModule(University& uni) {
    while (true) {
        string options[] = {
            "1. List Teachers",
            "2. Add Teacher",
            "3. Update Teacher",
            "4. Delete Teacher",
            "5. Search Teacher",
            "0. Back"
        };
        drawMenu("TEACHERS MODULE", options, 6);
        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1: uni.displayTeachers(); break;
        case 2: uni.addTeacher();      break;
        case 3: uni.updateTeacher();   break;
        case 4: uni.deleteTeacher();   break;
        case 5: uni.searchTeacher();   break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// Employees section

void employeesModule(University& uni) {
    while (true) {
        string options[] = {
            "1. List Employees",
            "2. Add Employee",
            "3. Update Employee",
            "4. Delete Employee",
            "5. Search Employee",
            "0. Back"
        };
        drawMenu("EMPLOYEES MODULE", options, 6);
        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1: uni.displayEmployees(); break;
        case 2: uni.addEmployee();      break;
        case 3: uni.updateEmployee();   break;
        case 4: uni.deleteEmployee();   break;
        case 5: uni.searchEmployee();   break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// Student dashboard

void studentMenu(University& uni, int studentId) {
    while (true) {
        string options[] = {
            "1. View My Details",
            "2. View My Subjects",
            "3. View My Assignments",
            "0. Logout"
        };
        drawMenu("STUDENT DASHBOARD", options, 4);
        cout << "Enter choice: ";
        int choice = safeIntInput();

        switch (choice) {
        case 1: uni.viewMyDetails(studentId);          break;
        case 2: uni.viewStudentSubjects(studentId);    break;
        case 3: uni.viewStudentAssignments(studentId); break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}