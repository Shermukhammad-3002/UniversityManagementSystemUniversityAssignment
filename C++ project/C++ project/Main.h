#include <iostream>
using namespace std;

// Function declarations (UI only)
void loginScreen();
void adminLoginScreen();
void studentLoginScreen();
void adminDashboard();
void studentDashboard();

int main() {
    loginScreen();
    return 0;
}

// ================= START SCREEN =================
void loginScreen() {
    int choice;

    while (true) {
        cout << "\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
        cout << "|                                  |\n";
        cout << "|      UNIVERSITY SYSTEM LOGIN     |\n";
        cout << "|                                  |\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n";

        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
        cout << "|                                  |\n";
        cout << "|      1. Login as Admin           |\n";
        cout << "|                                  |\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n";

        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
        cout << "|                                  |\n";
        cout << "|      2. Login as Student         |\n";
        cout << "|                                  |\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            adminLoginScreen();
            break;
        case 2:
            studentLoginScreen();
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    }
}

// ================= ADMIN LOGIN =================
void adminLoginScreen() {
    string username, password;

    cout << "\n";
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
    cout << "|         ADMIN LOGIN                  |\n";
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // UI ONLY (no validation yet)
    cout << "\nLogging in as Admin...\n";

    adminDashboard();
}

// ================= STUDENT LOGIN =================
void studentLoginScreen() {
    string name, password;

    cout << "\n";
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
    cout << "|        STUDENT LOGIN             |\n";
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Password: ";
    cin >> password;

    // UI ONLY
    cout << "\nLogging in as Student...\n";

    studentDashboard();
}

// ================= ADMIN DASHBOARD =================
void adminDashboard() {
    int choice;

    while (true) {
        cout << "\n";
        cout << "+==================================+\n";
        cout << "|          ADMIN DASHBOARD        |\n";
        cout << "+==================================+\n";
        cout << "| 1. Add Student                 |\n";
        cout << "| 2. View Students              |\n";
        cout << "| 3. Search Student             |\n";
        cout << "| 4. Update Student             |\n";
        cout << "| 5. Delete Student             |\n";
        cout << "|                                  |\n";
        cout << "| 9. Main Menu                  |\n";
        cout << "| 0. Logout (Back)              |\n";
        cout << "+==================================+\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n[Add Student Screen]\n";
            break;

        case 2:
            cout << "\n[View Students Screen]\n";
            break;

        case 3:
            cout << "\n[Search Student Screen]\n";
            break;

        case 4:
            cout << "\n[Update Student Screen]\n";
            break;

        case 5:
            cout << "\n[Delete Student Screen]\n";
            break;

        case 9:
            return; // goes back to login/main menu system

        case 0:
            cout << "\nLogging out...\n";
            return;

        default:
            cout << "\nInvalid choice!\n";
        }
    }
}

// ================= STUDENT DASHBOARD =================
void studentDashboard() {
    int choice;

    while (true) {
        cout << "\n";
        cout << "+==================================+\n";
        cout << "|        STUDENT DASHBOARD        |\n";
        cout << "+==================================+\n";
        cout << "| 1. View My Details            |\n";
        cout << "| 2. View My Marks              |\n";
        cout << "|                                  |\n";
        cout << "| 9. Main Menu                  |\n";
        cout << "| 0. Back / Logout              |\n";
        cout << "+==================================+\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n[Student Details Screen]\n";
            break;

        case 2:
            cout << "\n[Student Marks Screen]\n";
            break;

        case 9:
            return;

        case 0:
            cout << "\nLogging out...\n";
            return;

        default:
            cout << "\nInvalid choice!\n";
        }
    }
}