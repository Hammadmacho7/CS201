//
// Created by Hammad Khan Musakhel on 4/8/20.
//
#include <iostream>
#include <string>

#include "RegistrationSystem.h"
#include "Student.h"
using namespace std;

RegistrationSystem::RegistrationSystem(): Studentsize (0){
               students = NULL;
               Studentsize = 0;
               noOfStudents = 0;

}
//No copy constructor needed
RegistrationSystem::~RegistrationSystem() {
    delete [] students;
}
int RegistrationSystem::contain(unsigned int studentID) {
    for(unsigned int i = 0; i < Studentsize; i++) {
        if(students[i].getStudentID() == studentID )
        {
            return i; //return index number as well
        }
    }
    return -1;
}
bool RegistrationSystem::addStudent(const unsigned int studentID, const string ffirstName, const string flastName) {

    int check = contain(studentID); //checl >= if it is true, i.e contains the id
    if(check >= 0) {
        cout << "This ID already exists";
        return false;
    }

    Student *temp = students; //same stuff inside temp rn, pointer = pointer
    students = new Student[Studentsize + 1]; //as we are adding one student at a time
    for(size_t i = 0; i < Studentsize; i++) {
        students[i] = temp[i];
    }

    Studentsize++;
    noOfStudents= Studentsize;
    //no need of temp now
    if(temp != NULL) {
        delete [] temp;
        temp = NULL; //to avoid memory leak
    }

    Student newStudent(studentID, ffirstName, flastName);
    students[Studentsize - 1] = newStudent;
    return true;

}
bool RegistrationSystem::deleteStudent(const unsigned int studentID) {

    int check = contain(studentID);

    if(check >= 0) {
        cout << "Student with ID: "<< students[check].getStudentID() << " Deleted" << endl;
        for(size_t i = check; i < Studentsize - 1; i++) { //initially made contain to return index number
            students[i] = students[i + 1];
        }
        Studentsize--;

        noOfStudents = Studentsize;
        Student *temp = new Student[Studentsize];
        for(size_t i = 0; i < Studentsize; i++) {
            temp[i] = students[i];
        }

        delete [] students;
        students = temp;
        temp = NULL; //avoid memory leak


        return true;
    } else {
        cout << "No such ID: " << studentID << " exists" << endl;
        return false;
    }
}
void RegistrationSystem::showAllStudents() {
    if ( Studentsize > 0) {
        for (size_t i = 0; i < Studentsize; i++) {
            students[i].getStudentInformation();
            students[i].getStudentCourseInfo();
        }
    } else{
        cout << "no students added in the system";
    }
}
bool RegistrationSystem::showStudent(unsigned int studentID) {
    for(unsigned int i = 0; i < Studentsize; i++) {
        if(students[i].getStudentID() == studentID )
        {
            students[i].getStudentInformation();
            students[i].getStudentCourseInfo();
            return true;
        }
    }
    cout << "No such ID exists" << endl;
    cout << endl;
    return false;
}


//part B


bool RegistrationSystem::addCourses(const int studentId, const int courseId, const string courseName) {
    bool addable = false;
// music album with given title and artist name
    int check = contain(studentId);

// song with the given name, minutes, seconds
    Course c1(courseId, courseName);
// remember the index found of the music album
    int index = -1;
// check if the music album exist in the collection
    if (check >= 0) {

        addable = true;
        index = check;
    }

// continue if the music album in the collection
        if(addable)
        {
// check if the song name is unique in the songs of the music album
            addable = students[index].addCourseToStudent( courseId, courseName);
        }
        return addable;
}
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
        bool removable = false;

        int check = contain(studentId);

        int index = -1;

        if (check >= 0) {
            index = students[check].checkCourse(courseId); //index of the course
            if( index >= 0)
            {
                removable = true;
            }
            if (removable) {
                cout << "course with ID: " << courseId << " withdrawn from studentID: "<< studentId << endl;
                bool done = students[check].clearCourse(index);
            }

        } else{
            cout << "No such student ID exists" << endl;
        }


    }
void RegistrationSystem::cancelCourse(const int courseId) {
    int printx = 0;
    for( size_t i = 0; i < noOfStudents; i++)
    {
        int check = -1;
        bool removed;
        check = students[i].checkCourseForCancel(courseId);
        if( check >= 0) //present in that student if 0 0r more
        {
            removed = students[i].clearCourse(check);
            printx++;
        }
    }
    if( printx > 0)
    {
       cout << "Course with courseID: " << courseId << " has been cancelled" << endl;
    }
    else{
        cout << "Course with courseID: " << courseId << " doesn't exist" << endl;
    }
}
void RegistrationSystem::showCourse(const int courseId) {
    //what we have to do is to extract the info from students
    cout << "The course with courseId: " << courseId << " is taken by the following students: " << endl;
    int sees = 0;
    for (int i = 0; i < noOfStudents; i++)
    {
        int check = students[i].checkCourseForShowCourse(courseId);
        if ( check >= 0) {
            students[i].getStudentInformation();
            sees++;
        }
    }
    if( sees == 0)
    {
        cout << "No students take this course as it is not in the system" << endl;
    }
    cout << endl;
}