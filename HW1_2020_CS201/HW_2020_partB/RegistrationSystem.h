//
// Created by Hammad Khan Musakhel on 4/8/20.
//

#ifndef CS201_REGISTRATIONSYSTEM_H
#define CS201_REGISTRATIONSYSTEM_H
#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
using namespace std;

class RegistrationSystem{
private:
    Student *students;
    unsigned int noOfStudents;
    unsigned int Studentsize;
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
    bool addCourses( const int studentId, const int courseId, const string courseName );
    void withdrawCourse( const int studentId, const int courseId );
    void cancelCourse( const int courseId );
    void showCourse( const int courseId );

    //helper
    int containCourse(unsigned int studentID, unsigned courseID);

};




#endif //CS201_REGISTRATIONSYSTEM_H
