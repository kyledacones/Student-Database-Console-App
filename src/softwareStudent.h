#pragma once
#include <string>
#include "degree.h"
#include "student.h"

// Software Student Class

class SoftwareStudent : public Student {

public:
    SoftwareStudent();
    SoftwareStudent(string StudentID, 
        string firstName, 
        string lastName, 
        string emailAddress, 
        string studentAge, 
        int* daysInCourse, 
        DegreeType degreetype);
        

    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~SoftwareStudent();
};
