//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#include <iostream>
#include <string>

#include "RegistrationSystem.h"
using namespace std;

RegistrationSystem::RegistrationSystem(): students(NULL), noOfStudents(0), size(0) {

}
//No copy constructor needed
RegistrationSystem::~RegistrationSystem() {
    delete [] students;
}
int RegistrationSystem::contain(unsigned int studentID) {
    for(unsigned int i = 0; i < size; i++) {
        if(students[i].getStudentID() == studentID )
        {
            return i; //return index number as well
        }
    }
    return -1;
}
bool RegistrationSystem::addStudent(const unsigned int studentID, const string ffirstName, const string flastName) {

    int check = contain(studentID);
    if(check >= 0) {
        cout << "This ID already exists";
        return false;
    }

    Student *temp = students; //same stuff inside temp rn, pointer = pointer
    students = new Student[size + 1]; //as we are adding one student at a time
    for(size_t i = 0; i < size; i++) {
        students[i] = temp[i];
    }

    size++;
    noOfStudents= size;
    //no need of temp now
    if(temp != NULL) {
        delete [] temp;
        temp = NULL; //to avoid memory leak
    }

    Student newStudent(studentID, ffirstName, flastName);
    students[size - 1] = newStudent;
    return true;

}
bool RegistrationSystem::deleteStudent(const unsigned int studentID) {

    int check = contain(studentID);

    if(check >= 0) {
        for(size_t i = check; i < size - 1; i++) { //initially made contain to return index number
            students[i] = students[i + 1];
        }
        size--;
        noOfStudents = size;
        Student *temp = new Student[size];
        for(size_t i = 0; i < size; i++) {
            temp[i] = students[i];
        }

        delete [] students;
        students = temp;
        temp = NULL; //avoid memory leak
        cout << "Student Deleted";

        return true;
    } else {
        cout << "No such ID exists";
        return false;
    }
}
void RegistrationSystem::showAllStudents() {
    if ( size > 0) {
        for (size_t i = 0; i < size; i++) {
            students[i].getStudentInformation();
        }
    } else{
        cout << "no students added in the system";
    }
}
bool RegistrationSystem::showStudent(unsigned int studentID) {
    for(unsigned int i = 0; i < size; i++) {
        if(students[i].getStudentID() == studentID )
        {
            students[i].getStudentInformation();
            return true;
        }
    }
    cout << "No such ID exists";
    return false;
}