//
// Created by Hammad Khan Musakhel on 4/9/20.
//

#ifndef CS201_COURSE_H
#define CS201_COURSE_H
#include <string>
#include <iostream>

using namespace std;

class Course{

public:
    // Constructor
    Course(const unsigned int fcourseID = 0, const string fcourseName = "");
    // Copy Constructor

    // Destructor

    // Functions
    string getCourseName();
    unsigned int getCourseID();
    void getCourseInfo(); // will include the students as well



private:
    //Student *students;
    string courseName;
    unsigned int courseID;
};
#endif //CS201_COURSE_H
