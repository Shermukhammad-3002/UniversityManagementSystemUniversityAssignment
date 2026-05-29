class StudentManager {
public:
    void addStudent();
    void displayStudents();
    void updateStudent();
    void deleteStudent();
    void searchStudent();

private:
    Student students[100];
    int count = 0;
};