#pragma once
#include <string>
#include "degree.h"
#include "student.h"

//Security Student Class

class SecurityStudent : public Student {

public:
    SecurityStudent();
    SecurityStudent(string StudentID, 
                    string firstName,
                    string lastName, 
                    string emailAddress, 
                    string studentAge, 
                    int* daysInCourse, 
                    DegreeType degreetype);
        
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~SecurityStudent();
};

