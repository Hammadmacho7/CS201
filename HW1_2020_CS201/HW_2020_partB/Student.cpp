//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <string>
using namespace std;

Student::Student(const unsigned int studentID, const string ffirstName, const string flastName):id(studentID), firstName(ffirstName), lastName(flastName)
{
    sizeOfCourses = 0;
    courses = NULL;
//		std::cout << "Film constructor call for - " << title << std::endl;
}
Student::~Student() {

}
void Student::getStudentInformation() {
    cout << "Student ID Number: " << id << ", " << "Student First Name: " << firstName << ", " << "Student Last Name: " << lastName << endl;

}
void Student::getStudentCourseInfo() {
    if ( sizeOfCourses > 0) {
        cout << "Studies: " << endl;
        for (int i = 0; i < sizeOfCourses; ++i) {
            cout << "courseID: " << courses[i].getCourseID() << ", " << "CourseName: " << courses[i].getCourseName() << endl;
        }
        cout << endl;
    }
    else{
        cout << "No Courses Taken Yet" << endl;
        cout << endl;
    }
}
int Student::getStudentID() {
    return id;
}
string Student::getStudentFirstName(){
    return firstName;
}
string Student::getStudentlirstName(){
    return lastName;
}

//for B part, helper methods
unsigned int Student::getNoOfCourses() {
    return noOfCourses;
}
unsigned int Student::getSize() { return noOfCourses; }

void Student::incrementSizeOfCourse() {
    sizeOfCourses++;
}
void Student::decrementSizeOfCourse() {
    sizeOfCourses--;
}

bool Student::addCourseToStudent(unsigned int courseId, string courseName){
    bool isAdable = true;
// create a course with given parameters
    Course course(courseId, courseName);
// check if student contains any matching courses
    if (sizeOfCourses > 0) {
// check if the id of the course is unique
        for (int i = 0; i < sizeOfCourses; i++) {
            if (courses[i].getCourseName() == courseName && courses[i].getCourseID() == courseId) {
                cout << "This Course with courseID" << " " << courseId << " " << "Has Already been taken by studentID: " << id << endl;
                return false;
            }
        }
// expand the courses and add the course
// create a template to copy elements of course
        Course *temp = new Course[sizeOfCourses];
        for (int i = 0; i < sizeOfCourses; i++) {
            temp[i] = courses[i];
        }
// free memory the courses
        delete [] courses;
// increase the size
        sizeOfCourses++;

        courses = new Course[sizeOfCourses];

        for (int i = 0; i < sizeOfCourses-1; i++) {
            courses[i] = temp[i];
        }

        courses[sizeOfCourses-1] = course;

        delete [] temp;
    }
    else {
// course collection is empty therefore you should initialize it
        sizeOfCourses = 0;
        courses = new Course[sizeOfCourses + 1];
        courses[sizeOfCourses] = course;
        sizeOfCourses++;
    }
    return isAdable;
}

int Student::checkCourse( unsigned int courseId){ //returns the index of the course
    for( int  i = 0; i < sizeOfCourses; ++i){
        if ( courses[i].getCourseID() == courseId)
        {
            return i;
        }

    }
    cout << "No such course is present with that courseID" << " " << courseId << endl;
    return -1;
}
int Student::checkCourseForShowCourse( unsigned int courseId){ //returns the index of the course
    for( int  i = 0; i < sizeOfCourses; ++i){
        if ( courses[i].getCourseID() == courseId)
        {
            return i;
        }

    }
    return -1;
}
int Student::checkCourseForCancel(unsigned int courseId) { //returns the index of the course
    for( int  i = 0; i < sizeOfCourses; ++i){
        if ( courses[i].getCourseID() == courseId)
        {
            return i;
        }

    }
   // cout << "No such course is present with that courseID" << " " << courseId << endl;
    return -1;
}

bool Student::clearCourse(unsigned int index) {

    if (sizeOfCourses > 0)
    {

        for (size_t i = index; i < sizeOfCourses - 1; i++) { //initially made contain to return index number
            courses[i] = courses[i + 1];
        }
        sizeOfCourses--;

        noOfCourses = sizeOfCourses;
        Course *temp = new Course[sizeOfCourses];
        for (size_t i = 0; i < sizeOfCourses; i++) {
            temp[i] = courses[i];
        }

        delete[] courses;
        courses = temp;
        temp = NULL; //avoid memory leak
    }
    else{
        //cout << "No Courses added to be cleared" << endl;
            return false;
    }


}
void Student::getCourseInfo(unsigned int courseId) {
    int check = checkCourse(courseId);
    if( check >= 0){
        cout << "courseID: " << courses[check].getCourseID() << ", with course name:" << courses[check].getCourseName() << endl;
     }
    else{
       cout <<  "No such course exists" << endl;
    }
}