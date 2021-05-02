#include "student.h"

Student::Student(char *initName, char *initEgn, long initFacultyNumber, double initGrade) : Person(initName, initEgn) {
    cout << "Student constructor was invoked: " << initFacultyNumber << " " << initGrade << endl;
    facultyNumber = initFacultyNumber;
    grade = initGrade;
}

Student::Student(const Student &student) : Person(student) {
    facultyNumber = student.facultyNumber;
    grade = student.grade;
}

void Student::printStudent() const {
    printPerson();
    cout << "Faculty number: " << facultyNumber << endl;
    cout << "Grade: " << grade << endl;
}

Student::~Student() {
    cout << "Student destructor was invoked: " << facultyNumber << " " << grade << endl;
}

Student &Student::operator=(const Student &student) {
    if (this != &student) {
        Person::operator=(student);
        facultyNumber = student.facultyNumber;
        grade = student.grade;
    }
}

