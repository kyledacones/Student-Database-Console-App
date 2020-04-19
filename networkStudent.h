#pragma once
#include <string>
#include "degree.h"
#include "student.h"

// The Network Student Class

class NetworkStudent : public Student {
public:
    NetworkStudent();
    NetworkStudent(string StudentID, 
                    string firstName, 
                    string lastName, 
                    string emailAddress, 
                    string studentAge, 
                    int* daysInCourse, 
                    DegreeType degreetype);
    
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~NetworkStudent();
};
