//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#include "Student.h"


#include <iostream>
#include <string>
using namespace std;

Student::Student(const unsigned int studentID, const string ffirstName, const string flastName):id(studentID), firstName(ffirstName), lastName(flastName)
{

//		std::cout << "Film constructor call for - " << title << std::endl;
}
Student::~Student() {

}
void Student::getStudentInformation() {
    cout << "Student ID Number: " << id << ", " << "Student First Name: " << firstName << ", " << "Student Last Name: " << lastName;
    cout << endl;
}
int Student::getStudentID() {
    return id;
}
