#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "University.h"

using namespace std;

// Constructor for University class

University::University() {
    count = 0;
    tCount = 0;
    eCount = 0;

    memset(students, 0, sizeof(students));
    memset(teachers, 0, sizeof(teachers));
    memset(employees, 0, sizeof(employees));

    loadStudents();
    loadTeachers();
    loadEmployees();

    // Pre-loaded data
    if (count == 0 && tCount == 0 && eCount == 0) {

        students[0] = { 1, "Brecken",   "1234", 85, 'B', {}, 0, {}, 0 };
        students[1] = { 2, "Karim",     "1234", 92, 'A', {}, 0, {}, 0 };
        students[2] = { 3, "Kyle Crain","1234", 70, 'C', {}, 0, {}, 0 };
        students[3] = { 4, "Rahim",     "1234", 60, 'D', {}, 0, {}, 0 };
        students[4] = { 5, "Jade",      "1234", 78, 'B', {}, 0, {}, 0 };
        count = 5;

        teachers[0] = { 1, "Dr. Zere",        "Mathematics", 1200 };
        teachers[1] = { 2, "Dr. Camden",       "Physics",     1500 };
        teachers[2] = { 3, "Qadir Suleyman",   "Programming", 1300 };
        tCount = 3;

        employees[0] = { 1, "Ethan Winters",  "Administrator", 900 };
        employees[1] = { 2, "Chris Redfield", "Accountant",    1100 };
        employees[2] = { 3, "Jill Valentine", "IT Support",    1000 };
        eCount = 3;

        saveStudents();
        saveTeachers();
        saveEmployees();

        cout << "Default data loaded.\n";
    }
}

// Students

// Adding a student
void University::addStudent() {
    if (count >= 100) {
        cout << "Student limit reached!\n";
        return;
    }

    Student& s = students[count];
    memset(&s, 0, sizeof(Student));

    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(s.name, 50);

    cout << "Set Password: ";
    cin.getline(s.password, 50);

    cout << "\nHow many subjects? (max 5): ";
    cin >> s.subjectCount;
    if (s.subjectCount > 5) s.subjectCount = 5;
    cin.ignore();

    for (int i = 0; i < s.subjectCount; i++) {
        cout << "Enter Subject #" << i + 1 << ": ";
        cin.getline(s.subjects[i], 50);
    }

    cout << "\nHow many assignments? (max 5): ";
    cin >> s.assignmentCount;
    if (s.assignmentCount > 5) s.assignmentCount = 5;
    cin.ignore();

    for (int i = 0; i < s.assignmentCount; i++) {
        cout << "Enter Assignment #" << i + 1 << ": ";
        cin.getline(s.assignments[i], 50);
    }

    cout << "\nEnter Marks: ";
    cin >> s.marks;

    if (s.marks >= 90) s.grade = 'A';
    else if (s.marks >= 75) s.grade = 'B';
    else if (s.marks >= 60) s.grade = 'C';
    else s.grade = 'D';

    count++;
    cout << "\nStudent added successfully!\n";
    saveStudents();
}

// Displaying a student

void University::displayStudents() {
    if (count == 0) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n";
    cout << "+----+----------------------+--------+--------+\n";
    cout << "| ID | Name                 | Marks  | Grade  |\n";
    cout << "+----+----------------------+--------+--------+\n";

    for (int i = 0; i < count; i++) {
        cout << "| "
            << setw(2) << students[i].id << " | "
            << left << setw(20) << students[i].name << " | "
            << right << setw(6) << students[i].marks << " | "
            << setw(6) << students[i].grade << " |\n";
    }

    cout << "+----+----------------------+--------+--------+\n";
}

// Searching for a student

void University::searchStudent() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\n";
            cout << "+----+----------------------+--------+-------+\n";
            cout << "| ID | Name                 | Marks  | Grade |\n";
            cout << "+----+----------------------+--------+-------+\n";
            cout << "| "
                << setw(2) << students[i].id << " | "
                << left << setw(20) << students[i].name << " | "
                << right << setw(6) << students[i].marks << " | "
                << setw(5) << students[i].grade << " |\n";
            cout << "+----+----------------------+--------+-------+\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void University::viewStudentSubjects(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\nSubjects:\n";
            if (students[i].subjectCount == 0) {
                cout << "  No subjects assigned.\n";
                return;
            }
            for (int j = 0; j < students[i].subjectCount; j++)
                cout << "  - " << students[i].subjects[j] << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void University::viewStudentAssignments(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\nAssignments:\n";
            if (students[i].assignmentCount == 0) {
                cout << "  No assignments.\n";
                return;
            }
            for (int j = 0; j < students[i].assignmentCount; j++)
                cout << "  - " << students[i].assignments[j] << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Updating a student

void University::updateStudent() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudentByPointer(&students[i]);
            return;
        }
    }
    cout << "Student not found!\n";
}

void University::updateStudentByPointer(Student* s) {
    cin.ignore();

    cout << "Enter New Name: ";
    cin.getline(s->name, 50);

    cout << "Enter New Password: ";
    cin.getline(s->password, 50);

    cout << "\nHow many subjects? (max 5): ";
    cin >> s->subjectCount;
    if (s->subjectCount > 5) s->subjectCount = 5;
    cin.ignore();

    for (int i = 0; i < s->subjectCount; i++) {
        cout << "Enter Subject #" << i + 1 << ": ";
        cin.getline(s->subjects[i], 50);
    }

    cout << "\nHow many assignments? (max 5): ";
    cin >> s->assignmentCount;
    if (s->assignmentCount > 5) s->assignmentCount = 5;
    cin.ignore();

    for (int i = 0; i < s->assignmentCount; i++) {
        cout << "Enter Assignment #" << i + 1 << ": ";
        cin.getline(s->assignments[i], 50);
    }

    cout << "\nEnter New Marks: ";
    cin >> s->marks;

    if (s->marks >= 90) s->grade = 'A';
    else if (s->marks >= 75) s->grade = 'B';
    else if (s->marks >= 60) s->grade = 'C';
    else                     s->grade = 'D';

    cout << "\nStudent updated successfully!\n";
    saveStudents();
}

// Deleting a student

void University::deleteStudent() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            cout << "Student deleted successfully!\n";
            saveStudents();
            return;
        }
    }
    cout << "Student not found!\n";
}

// Part where student logs in

bool University::loginStudent(int id, string password) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id &&
            strcmp(students[i].password, password.c_str()) == 0)
            return true;
    }
    return false;
}

// View details button

void University::viewMyDetails(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\n+---- STUDENT PROFILE ----+\n";
            cout << "ID    : " << students[i].id << "\n";
            cout << "Name  : " << students[i].name << "\n";
            cout << "Marks : " << students[i].marks << "\n";
            cout << "Grade : " << students[i].grade << "\n";

            cout << "\nSubjects:\n";
            if (students[i].subjectCount == 0)
                cout << "  None\n";
            else
                for (int j = 0; j < students[i].subjectCount; j++)
                    cout << "  - " << students[i].subjects[j] << "\n";

            cout << "\nAssignments:\n";
            if (students[i].assignmentCount == 0)
                cout << "  None\n";
            else
                for (int j = 0; j < students[i].assignmentCount; j++)
                    cout << "  - " << students[i].assignments[j] << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}



void University::saveStudents() {
    ofstream file("students.dat", ios::binary);
    file.write((char*)&count, sizeof(count));
    file.write((char*)students, sizeof(Student) * count);
    file.close();
}

void University::loadStudents() {
    ifstream file("students.dat", ios::binary);
    if (!file) return;
    file.read((char*)&count, sizeof(count));
    file.read((char*)students, sizeof(Student) * count);
    file.close();
}

// Teachers

// Adding a teacher

void University::addTeacher() {
    if (tCount >= 100) {
        cout << "Teacher limit reached!\n";
        return;
    }

    Teacher& t = teachers[tCount];
    memset(&t, 0, sizeof(Teacher));

    cout << "Enter ID: ";
    cin >> t.id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(t.name, 50);

    cout << "Enter Subject: ";
    cin.getline(t.subject, 50);

    cout << "Enter Salary: ";
    cin >> t.salary;

    tCount++;
    cout << "Teacher added successfully!\n";
    saveTeachers();
}

// Displaying a teacher

void University::displayTeachers() {
    if (tCount == 0) {
        cout << "No teachers found.\n";
        return;
    }

    cout << "\n";
    cout << "+----+----------------------+----------------+----------+\n";
    cout << "| ID | Name                 | Subject        | Salary   |\n";
    cout << "+----+----------------------+----------------+----------+\n";

    for (int i = 0; i < tCount; i++) {
        cout << "| "
            << setw(2) << teachers[i].id << " | "
            << left << setw(20) << teachers[i].name << " | "
            << setw(14) << teachers[i].subject << " | "
            << right << setw(8) << teachers[i].salary << " |\n";
    }
    cout << "+----+----------------------+----------------+----------+\n";
}

// Searching a teacher

void University::searchTeacher() {
    int id;
    cout << "Enter Teacher ID: ";
    cin >> id;

    for (int i = 0; i < tCount; i++) {
        if (teachers[i].id == id) {
            cout << "\nFound:\n";
            cout << "Name   : " << teachers[i].name << "\n";
            cout << "Subject: " << teachers[i].subject << "\n";
            cout << "Salary : " << teachers[i].salary << "\n";
            return;
        }
    }
    cout << "Teacher not found!\n";
}

// Updating a teacher

void University::updateTeacher() {
    int id;
    cout << "Enter Teacher ID: ";
    cin >> id;

    for (int i = 0; i < tCount; i++) {
        if (teachers[i].id == id) {
            cin.ignore();
            cout << "Enter new name: ";
            cin.getline(teachers[i].name, 50);
            cout << "Enter new subject: ";
            cin.getline(teachers[i].subject, 50);
            cout << "Enter new salary: ";
            cin >> teachers[i].salary;
            cout << "Updated successfully!\n";
            saveTeachers();
            return;
        }
    }
    cout << "Teacher not found!\n";
}

// Deleting a teacher

void University::deleteTeacher() {
    int id;
    cout << "Enter Teacher ID: ";
    cin >> id;

    for (int i = 0; i < tCount; i++) {
        if (teachers[i].id == id) {
            for (int j = i; j < tCount - 1; j++)
                teachers[j] = teachers[j + 1];
            tCount--;
            cout << "Teacher deleted!\n";
            saveTeachers();
            return;
        }
    }
    cout << "Teacher not found!\n";
}

void University::saveTeachers() {
    ofstream file("teachers.dat", ios::binary);
    file.write((char*)&tCount, sizeof(tCount));
    file.write((char*)teachers, sizeof(Teacher) * tCount);
    file.close();
}

void University::loadTeachers() {
    ifstream file("teachers.dat", ios::binary);
    if (!file) return;
    file.read((char*)&tCount, sizeof(tCount));
    file.read((char*)teachers, sizeof(Teacher) * tCount);
    file.close();
}

// Employees

// Adding an employee

void University::addEmployee() {
    if (eCount >= 100) {
        cout << "Employee limit reached!\n";
        return;
    }

    Employee& e = employees[eCount];
    memset(&e, 0, sizeof(Employee));

    cout << "Enter ID: ";
    cin >> e.id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(e.name, 50);

    cout << "Enter Position: ";
    cin.getline(e.position, 50);

    cout << "Enter Salary: ";
    cin >> e.salary;

    eCount++;
    cout << "Employee added successfully!\n";
    saveEmployees();
}

// Adding an employee

void University::displayEmployees() {
    if (eCount == 0) {
        cout << "No employees found.\n";
        return;
    }

    cout << "\n";
    cout << "+----+----------------------+----------------+----------+\n";
    cout << "| ID | Name                 | Position       | Salary   |\n";
    cout << "+----+----------------------+----------------+----------+\n";

    for (int i = 0; i < eCount; i++) {
        cout << "| "
            << setw(2) << employees[i].id << " | "
            << left << setw(20) << employees[i].name << " | "
            << setw(14) << employees[i].position << " | "
            << right << setw(8) << employees[i].salary << " |\n";
    }
    cout << "+----+----------------------+----------------+----------+\n";
}

// Searching for an employee

void University::searchEmployee() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < eCount; i++) {
        if (employees[i].id == id) {
            cout << "\nEmployee Found:\n";
            cout << "Name    : " << employees[i].name << "\n";
            cout << "Position: " << employees[i].position << "\n";
            cout << "Salary  : " << employees[i].salary << "\n";
            return;
        }
    }
    cout << "Employee not found!\n";
}

// Updating an employee

void University::updateEmployee() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < eCount; i++) {
        if (employees[i].id == id) {
            cin.ignore();
            cout << "Enter new name: ";
            cin.getline(employees[i].name, 50);
            cout << "Enter new position: ";
            cin.getline(employees[i].position, 50);
            cout << "Enter new salary: ";
            cin >> employees[i].salary;
            cout << "Updated successfully!\n";
            saveEmployees();
            return;
        }
    }
    cout << "Employee not found!\n";
}

// Deleting an employee

void University::deleteEmployee() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < eCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < eCount - 1; j++)
                employees[j] = employees[j + 1];
            eCount--;
            cout << "Employee deleted successfully!\n";
            saveEmployees();
            return;
        }
    }
    cout << "Employee not found!\n";
}

void University::saveEmployees() {
    ofstream file("employees.dat", ios::binary);
    file.write((char*)&eCount, sizeof(eCount));
    file.write((char*)employees, sizeof(Employee) * eCount);
    file.close();
}

void University::loadEmployees() {
    ifstream file("employees.dat", ios::binary);
    if (!file) return;
    file.read((char*)&eCount, sizeof(eCount));
    file.read((char*)employees, sizeof(Employee) * eCount);
    file.close();
}