//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#include <iostream>

#include "CompleteReg.h"


CompleteReg::CompleteReg(): head(NULL), teamCount(0) {
}

CompleteReg::~CompleteReg() {
    while(head){
        removeTeam(head->t.getTName());
    }

}
CompleteReg::CompleteReg(const CompleteReg &systemToCopy) {
    teamCount = systemToCopy.teamCount;
    if (systemToCopy.head) {
        // copy head node
        head = new Node;
        head->t = systemToCopy.head->t;
        head->prev = NULL;
        tail = head;
        tail->next = NULL;
        // copy all other nodes
        Node *fCur = systemToCopy.head->next;
        while (fCur) {
            Node *newTeam = new Node;
            newTeam->t = fCur->t;
            newTeam->next = NULL;

            newTeam->prev = tail;
            tail->next = newTeam;
            tail = tail->next;

            fCur = fCur->next;
        }
    } else
        head = tail = NULL;
}


CompleteReg& CompleteReg::operator=(const CompleteReg &right) {
    if (this != &right) {
        teamCount = right.teamCount;
        // Delete all items of this object
        while (head) {
            removeTeam(head->t.getTName()); //avoid memory leak
        }
        if (right.head) {
            // copy head node
            head = new Node;
            head->t = right.head->t;
            head->prev = NULL;
            tail = head;
            tail->next = NULL;
            // copy all other nodes
            Node *fCur = right.head->next;
            while (fCur) {

                Node *newTeam = new Node;
                newTeam->t = fCur->t;
                newTeam->next = NULL;

                newTeam->prev = tail;
                tail->next = newTeam;
                tail = tail->next;

                fCur = fCur->next;
            }
        } else
            head = tail = NULL;
    }
}

Team& CompleteReg::operator[](const int index) {
    Node *curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->t;
}


void CompleteReg::addTeam(const string tName, const string tColor, const int tYear) {


    if (findTeam(tName) != NULL) {
        cout << "Team already exists" << endl;
        return;
    } else if (tYear >= 2020 || tYear <= 1800){
        cout << "Team cannot be founded in the past or in the future" << endl; return; }


    else {   // create a new Node
        Node *newTeam = new Node;
        newTeam->t.setTName(tName);
        newTeam->t.setTColor(tColor);
        newTeam->t.setTYear(tYear);
        newTeam->next = NULL;
        newTeam->prev = NULL;

        // if list is empty
        if (head == NULL) {
            head = newTeam;
            tail = newTeam; // tail also should be pointing to the first item
        } else {
            newTeam->prev = tail;
            tail->next = newTeam;
            tail = tail->next;
        }
        teamCount++;
        return;
    }

}

void CompleteReg::removeTeam(const string teamName) {
    if (findTeam(teamName) == NULL) {
        cout << "Team does not exist" << endl;
        return;
    }
    string str = teamName;
    Node *cur = findTeam(teamName);
    if(cur) {
        if(cur->prev == NULL)
            head = cur->next;
        else
            (cur->prev)->next = cur->next;

        if(cur->next == NULL)
            tail = cur->prev;
        else
            (cur->next)->prev = cur->prev;

        delete cur;
        cur = NULL;
        cout << "Team: " << str << " removed." << endl;
        cout << endl;
        teamCount--;
    }
}

void CompleteReg::displayAllTeams() const {
    if (head == NULL) { //this function is for all the teams
        cout << "The System has the following teams: !EMPTY!" << endl;
    } else {
        for (Node *curr = head; curr != NULL; curr = curr->next) {
            cout << curr->t.getTName() << ", " << curr->t.getTColor() << ", " << curr->t.getTYear()  << endl;
        }
    }
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPos) {
    Node *teamToAddInto = findTeam(tName);
    if (findTeam(tName) == NULL)
        cout << "Player not added because team does not exist" << endl;

    else
        teamToAddInto->t.addPlayerInto(pName, pPos);
}

void CompleteReg::removePlayer(const string tName, const string pName) {
    Node *ToRemove = findTeam(tName);
    if (ToRemove == NULL)
        cout << "Player not removed because team does not exist" << endl;
    else
        ToRemove->t.removePlayerFrom(pName);
}

void CompleteReg::displayTeam(const string teamName) const {
    Node *check = findTeam(teamName);
    if (check == NULL)
        cout << "--EMPTY--" << endl;
    else {
        cout << check->t.getTName() << ", " << check->t.getTColor() << ", " << check->t.getTYear() << endl;
        check->t.displayPlayers();
    }
}

void CompleteReg::displayPlayer(const string pName) const {
    cout << pName << "'s info: " << endl;
    bool inTeam = false;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->t.hasTeam(pName)) {
            inTeam = true;
        }
        else {
            inTeam = false;
        }
    }
    if (!inTeam) {
        cout << "EMPTY" << endl;
    }
}

CompleteReg::Node* CompleteReg::findTeam(const string tName) const {
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

