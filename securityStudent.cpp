#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent(){
    setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string StudentID, string firstName, string lastName, string email, string age, int * days, DegreeType degreetype) {
    setDegreeType(SECURITY);
}

DegreeType SecurityStudent::getDegreeType() {
    return SECURITY;
}

void SecurityStudent::setDegreeType(DegreeType d) {
    this->type = SECURITY;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY\n";
}

SecurityStudent::~SecurityStudent() {
    Student::~Student();
}
