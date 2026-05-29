#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    char password[50];
    float marks;
    char grade;
    char subjects[5][50];
    int subjectCount;
    char assignments[5][50];
    int assignmentCount;
};

#endif