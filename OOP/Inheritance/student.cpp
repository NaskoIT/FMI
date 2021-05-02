#include "student.h"

Student::Student(char *initName, char *initEgn, long initFacultyNumber, double initGrade) : Person(initName, initEgn) {
    cout << "Student constructor was invoked: " << initFacultyNumber << " " << initGrade << endl;
    facultyNumber = initFacultyNumber;
    grade = initGrade;
}

void Student::printStudent() const {
    printPerson();
    cout << "Faculty number: " << facultyNumber << endl;
    cout << "Grade: " << grade << endl;
}

Student::~Student() {
    cout << "Student destructor was invoked: " << facultyNumber << " " << grade << endl;
}

