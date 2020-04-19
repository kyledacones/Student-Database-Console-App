#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent(){
    setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string StudentID, 
                                 string firstName, 
                                 string lastName, 
                                 string email, 
                                 string age, 
                                 int * days, 
                                 DegreeType degreetype) {
    setDegreeType(SOFTWARE);
}

DegreeType SoftwareStudent::getDegreeType() {
    return SOFTWARE;
}

void SoftwareStudent::setDegreeType(DegreeType d) {
    this->type = SOFTWARE;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE\n";
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
}
