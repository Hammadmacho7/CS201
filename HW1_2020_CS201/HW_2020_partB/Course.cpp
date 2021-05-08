//
// Created by Hammad Khan Musakhel on 4/9/20.
//

#include "Course.h"

using namespace std;

Course::Course(const unsigned int fcourseID, string fcourseName) : courseID(fcourseID), courseName(fcourseName){

}
unsigned int Course::getCourseID() {
    return courseID;
}
string Course::getCourseName() {
    return courseName;
}
void Course::getCourseInfo() {
    cout << getCourseID() << ", " << getCourseName();
}