#include "roster.h"
#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using std::cout;
using std::cerr;

int main() {
    cout << "C867-Scripting & Programming: Applications\n";
    cout << "Language: C++\n";
    cout << "Student ID: A5\n";
    cout << "Name: John Doe\n";
    cout << "\n";

    Roster * classRoster = new Roster(numStudents);
    cout << "Adding students from the data table:";

    
    for (int i = 0; i < numStudents; i++) {
            classRoster->add(studentData[i]);
	}
    cout << " DONE.\n";
    cout << "\n";

    cout << "Displaying all students:\n";
    cout << "\n";

   
    classRoster->printAll();
    cout << "\n";

    classRoster->printAverageDaysInCourse("A5");
    cout << "\n";

    classRoster->printInvalidEmails();
    cout << "\n";

    classRoster->printByDegreeType(SOFTWARE);
    cout << "\n";

    cout << "Removing A3:\n";
    cout << "\n";

    if (classRoster->remove("A3")) {
        classRoster->printAll();
        cout << "\n";
        }
        else cout << "Student not found!\n";

    cout << "Removing A3:\n";
    cout << "\n";

    if (classRoster->remove("A3")) {
        classRoster->printAll();
        }
        else cout << "Student not found!\n";

	return 0;
}

Roster::Roster() {
    this->capacity = 5;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[capacity];
}

void Roster::add(string row) {
	if (lastIndex < capacity) {
            lastIndex++;
            int darray[Student::daysArraySize];

            if (row[4] == 'o') {
                this->classRosterArray[lastIndex] = new SecurityStudent();
                classRosterArray[lastIndex]->setDegreeType(SECURITY);
            }

                else if (row[4] == 'r') {
                    this->classRosterArray[lastIndex] = new SecurityStudent();
                    classRosterArray[lastIndex]->setDegreeType(SECURITY);
                }

                else if (row[4] == 'u') {
                    this->classRosterArray[lastIndex] = new NetworkStudent();
                    classRosterArray[lastIndex]->setDegreeType(NETWORK);
                }

                else {
                    this->classRosterArray[lastIndex] = new SoftwareStudent();
                    classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
                }

            int rhs = studentData[lastIndex].find(",");
            classRosterArray[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));

            int lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setAge(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            classRosterArray[lastIndex]->setDays(darray);
	}
}


void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}


bool Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
            if (this->classRosterArray[i]->getID() == studentID) {
                found = true;
                Student* stu = classRosterArray[i];
                this->classRosterArray[i] = this->classRosterArray[lastIndex];
                (classRosterArray[lastIndex]) = stu;
		            lastIndex--;
            }
    }
    return found;
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getID() == studentID) {
            found = true;
            int* d = classRosterArray[i]->getDays();
            cout << "Student ID: " << studentID << ", averages " << (d[0] + d[1] + d[2]) / 3 << " days in a course.\n";
	      }
    }
    if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails:\n";
    cout << "\n";
    for (int i = 0; i < 5; i++) {
	bool foundAt = false;
	bool foundPeriod = false;
	bool foundSpace = false;
        string email = "";
        email = (*classRosterArray[i]).getEmail();
		for (char &c : email) {
                    if (c == '@') {
                        foundAt = true;
                    }
                    if (c == '.') {
                        foundPeriod = true;
                    }
                    if (c == ' ') {
                        foundSpace = true;
                    }
		}
                if (foundAt == false) {
                    cout << (*classRosterArray[i]).getEmail() << " - missing an @ symbol.\n";
                }
                if (foundPeriod == false) {
                    cout << (*classRosterArray[i]).getEmail() << " - missing a period.\n";
                }
                if (foundSpace == true) {
                    cout << (*classRosterArray[i]).getEmail() << " - no spaces allowed.\n";
		}
    }
}


void Roster::printByDegreeType(DegreeType d) {
    cout << "Showing students in degree program: " << degreeTypeStrings[d] << "\n";
    cout << "\n";

    for (int i = 0; i <= lastIndex; i++) {
            if (this->classRosterArray[i]->getDegreeType() == d) this->classRosterArray[i]->print();
	}
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
            delete this->classRosterArray[i];
    }
    delete this;
}
