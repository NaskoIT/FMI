#include "student.h"

class TaxedStudent : public Student {
protected:
    double tax;

public:
    TaxedStudent(char *name = "", char *egn = "", long facultyNumber = 0, double grade = 0, double tax = 0);

    TaxedStudent &operator=(const TaxedStudent &taxedStudent);

    ~TaxedStudent();

    void printTaxedStudent() const;
};