#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Employee.h"

using namespace std;

class University {
private:
    Student students[100];
    Teacher teachers[100];
    Employee employees[100];

    int count;
    int tCount;
    int eCount;

public:
    University();

    // Students
    void addStudent();
    void displayStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void updateStudentByPointer(Student* s);
    void viewStudentSubjects(int id);
    void viewStudentAssignments(int id);
    void viewMyDetails(int id);
    bool loginStudent(int id, string password);
    void loadStudents();
    void saveStudents();

    // Teachers
    void addTeacher();
    void displayTeachers();
    void searchTeacher();
    void updateTeacher();
    void deleteTeacher();
    void loadTeachers();
    void saveTeachers();

    // Employees    
    void addEmployee();
    void displayEmployees();
    void searchEmployee();
    void updateEmployee();
    void deleteEmployee();
    void saveEmployees();
    void loadEmployees();
};

#endif