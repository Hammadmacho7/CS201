//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#include <iostream>
#include <algorithm>
#include <string>
#include "SimpleReg.h"
using namespace std;

SimpleReg::SimpleReg():teamCount(0), head(NULL) {
   // cout << "object made" << endl;
}

SimpleReg::~SimpleReg() {
    if (head != NULL) {
        Node* curr = head;
        Node* check;
        while (curr != NULL) {
            check = curr->next; //the way to delete nodes
            delete curr;       //universal pattern to be followed
            curr = check;
        }
    }
}

void SimpleReg::addTeam(const string tName, const string tColor, const int tYear) {

    if (findTeam(tName) != NULL) {
        cout << "Team: " << tName << " already exists" << endl;
    }
    else if (tYear <= 1800)
        cout << "Team: " << tName << " cannot be founded in the past" << endl;
    else if (tYear >= 2020)
        cout << "Team: " << tName << " cannot be founded in the future" << endl;
    else if (head == NULL) {
                head = new Node;
        head->t.setTYear(tYear);
        head->t.setTColor(tColor);
        head->t.setTName(tName);
        head->next = NULL;
        teamCount++;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new Node;
        curr = curr->next;
        curr->t.setTColor(tColor);
        curr->t.setTName(tName);
        curr->t.setTYear(tYear);
        curr->next = NULL;
        teamCount++;
    }
}


void SimpleReg::removeTeam(const string teamName) {
    if (findTeam(teamName) == NULL) { //to mke sure
        cout << "Team " << teamName << " does not exist" << endl;
    }
    else {
        Node* remove = findTeam(teamName);
        Node* prev = head;
        if ( (prev == remove) && (prev->next == NULL)) { //if only single item
            delete prev;
            head = NULL;
        }
        else {
            for (Node *curr = head->next; curr != NULL; curr = curr->next) { //simple traverse
                if (curr == remove) {
                    Node* temp = curr->next;
                    prev->next = temp; //since curr is one setp ahead of prev
                    delete curr;
                }
                else if (prev == remove) {
                    Node* temp = prev->next;
                    head = temp;
                    delete prev;
                }
                prev = prev->next; //moved here
            }
            teamCount--;
        }
    }
}




void SimpleReg::displayAllTeams() const {

    if(!head)
        cout << "EMPTY" << endl;
    else {
        Node *cur = head;
        while(cur) {
            cout << "Team: " << cur->t.getTName() << ", " << cur->t.getTColor() << ", " << cur->t.getTYear() << endl;
            cur = cur->next;
        }
    }
}
// private function
/* this function returns the previous Node of the Node asked for */
SimpleReg::Node * SimpleReg::findTeam(const string tName) const {
    Node *cur = head;
    string tmpName = tName;
    string toFind = tName;
    transform(toFind.begin(), toFind.end(), toFind.begin(), ::toupper);
    while(cur) {
        string str = cur->t.getTName();
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        if(toFind == str)
            return cur;
        cur = cur->next;
    }
    return NULL;

}
