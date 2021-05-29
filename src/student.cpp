#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = "";
    this->days = new int[daysArraySize];
    for (int i = 0; i<daysArraySize; i++) 
            this->days[i] = 0;
}

Student::Student(string ID, string firstName, string lastName, string email, string age, int days[], DegreeType type) {
    this->studentID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->days = new int[daysArraySize];
        
    for (int i = 0; i<3; i++) this->days[i] = days[i];
}

string Student::getID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

string Student::getAge() {
    return age;
}

int * Student::getDays() {
    return days;
}

void Student::setID(string ID) {
    studentID = ID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(string age) {
    this->age = age;
}

void Student::setDays(int days[]) {
    if (this->days != nullptr) {
            delete[] this->days;
            this->days = nullptr;
	}
    
    this->days = new int[daysArraySize];
    for (int i = 0; i<3; i++)
    this->days[i] = days[i];
}

void Student::print() {
    cout << left << "ID: " << setw(5) << studentID;
    cout << left << "First: " << setw(10) << firstName;
    cout << left << "Last: " << setw(10) << lastName;
    cout << left << "Email: " << setw(25) << email;
    cout << left << "Age: " << setw(5) << age;
    cout << left << "Days In Courses: (";
    cout << left << setw(3) << days[0];
    cout << left << setw(3) << days[1];
    cout << left << days[2] << ")" << setw(3) << " Degree: ";
}

Student::~Student() {
    if (days != nullptr) {
	delete[] days;
	days = nullptr;
	}
}
