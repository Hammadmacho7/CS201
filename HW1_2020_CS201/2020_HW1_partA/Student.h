//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#ifndef CS201_STUDENT_H
#define CS201_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    unsigned int id;
    string firstName;
    string lastName;
    

public:
    // Constructor
    Student(const unsigned int studentID = 0,
            const string ffirstName = "",
            const string flastName = "");
    // Copy Constructor

    // Destructor

    ~Student();
    // Functions

    void getStudentInformation();
    int getStudentID();
};
#endif //CS201_STUDENT_H
