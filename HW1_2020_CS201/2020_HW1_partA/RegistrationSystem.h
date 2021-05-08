//
// Created by Hammad Khan Musakhel on 4/8/20.
//

#ifndef CS201_REGISTRATIONSYSTEM_H
#define CS201_REGISTRATIONSYSTEM_H
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class RegistrationSystem{
private:
    Student *students;
    unsigned int noOfStudents;
    unsigned int size;
public:
    //constructor
    RegistrationSystem();
    // Copy constructor
    RegistrationSystem(const RegistrationSystem &RegistrationSystemToCopy);
    // Destructor
    ~RegistrationSystem();
    // Functions
    bool addStudent(const unsigned int studentID, const string ffirstName, const string flastName);
    bool deleteStudent( const unsigned int studentID);
    void showAllStudents();
    int contain( unsigned int studentID);
    bool showStudent( unsigned int studentID);


};




#endif //CS201_REGISTRATIONSYSTEM_H
