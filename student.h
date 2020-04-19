#pragma once
#include <string>
#include "degree.h"
using std::string;

//Student Class 

class Student {
protected:
    string studentID;
    string firstName;
    string lastName;
    string email;
    string age;
    int* days;
    DegreeType type;

public:
    const static int daysArraySize = 3;
    

    Student();
    Student(string ID, string firstName, string lastName, string email, string age, int days[], DegreeType type); 
    

    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getAge();
    int* getDays();
    
    virtual DegreeType getDegreeType() = 0;


    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(string age);
    void setDays(int days[]);
    virtual void setDegreeType(DegreeType d) = 0;
    

    virtual void print() = 0;

    ~Student();
};
