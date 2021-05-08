//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#ifndef CS201_STUDENT_H
#define CS201_STUDENT_H


#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Student{

private:
    Course *courses;
    unsigned int noOfCourses;
    unsigned int sizeOfCourses;

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

    void getStudentInformation(); //courses and their codes respectively
    int getStudentID();
    void getStudentCourseInfo();
    void getCourseInfo(unsigned int courseId);

    //helper functions
    bool addCourseToStudent(unsigned int courseId, string courseName);
    unsigned int getNoOfCourses();
    unsigned int getSize();
    void incrementSizeOfCourse();
    void decrementSizeOfCourse();
    int checkCourse( unsigned int courseId);
    bool clearCourse( unsigned int index);
    string getStudentFirstName();
    string getStudentlirstName();
    int checkCourseForCancel( unsigned int courseId); //returns the index of the course
    int checkCourseForShowCourse( unsigned int courseId);

};
#endif //CS201_STUDENT_H
