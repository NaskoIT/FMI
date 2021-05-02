#include "person.h"

class Student : Person {
private:
    long facultyNumber;
    double grade;

public:
    Student(char *initName = "", char *initEgn = "", long initFacultyNumber = 0, double initGrade = 0);

    Student(const Student& student);

    Student& operator=(const Student& student);

    void printStudent() const;

    ~Student();
};
