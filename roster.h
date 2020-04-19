#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

int numStudents = 5;


// Example Student Data 
string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,John,Doe,johndoe@student.edu,25,10,15,20,SOFTWARE"
};

class Roster {
public:
    int lastIndex;
    int capacity;
    
 
    Student** classRosterArray;
    
    Roster();
    Roster(int capacity);
    
    void add(string datarow);
    void printAll();
    bool remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeType(DegreeType d);
    
    ~Roster();
};
