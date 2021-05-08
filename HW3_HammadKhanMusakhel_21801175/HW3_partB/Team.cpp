//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#include "Team.h"
#include <iostream>

bool Team::hasTeam(const string pName) {
    bool inTeam = false;
    for (PNode *curr = head; curr != NULL; curr = curr->next) {
        if (curr->p.getPName() == pName) {
            cout << curr->p.getPPosition() << ", " << teamName << ", " << teamColor << ", " << teamYear << endl;
            inTeam = true;
        }
    }

    return inTeam;
}

Team::PNode* Team::findPlayer(const string pName) {
    PNode *cur = head;
    string tmpName = pName;
    string toFind = pName;
    transform(toFind.begin(), toFind.end(), toFind.begin(), ::toupper);
    while(cur) {
        string str = cur->p.getPName();
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        if(toFind == str)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

Team::Team(const string tName, const string tColor, const int tYear) {

    head = NULL;
    tail = NULL;
    teamName = tName;
    teamColor = tColor;
    teamYear = tYear;
}

Team::~Team() {
    while(head) {
        removePlayerFrom(head->p.getPName());
    }
}

void Team::operator=(const Team &right) {
    teamName = right.teamName;
    if(right.head) {
        // copy head node
        head = new PNode;
        head->p = right.head->p;
        tail = head;
        head->prev = NULL;
        tail->next = NULL;

        // copy all other elements
        PNode *fCur = right.head->next;
        while(fCur) {
            PNode *newPlayer = new PNode;
            newPlayer->p = fCur->p;
            newPlayer->next = NULL;

            newPlayer->prev = tail;
            tail->next = newPlayer;
            tail = tail->next;

            fCur = fCur->next;
        }
    }
    else {
        head = tail = NULL;
    }
}

string Team::getTName() {
    return teamName;
}

string Team::getTColor() {
    return teamColor;
}

int Team::getTYear() {
    return teamYear;
}

void Team::setTName(const string tName) {
    teamName = tName;
}

void Team::setTColor(const string tColor) {
    teamColor = tColor;
}

void Team::setTYear(const int tYear) {
    teamYear = tYear;
}

void Team::addPlayerInto(const string pName, const string pPosition) {

    PNode *newNode = new PNode;

    PNode *prev = findPlayer(pName);
    if (prev) {
        cout << "Player: " << pName << " already exists in the system." << endl;
    }


    else{

        newNode->p.setPName(pName);
        newNode->p.setPPosition(pPosition);
        newNode->next = NULL;

        if(!head) {
            head = newNode;
        }

        else {
            PNode *lastNode = findPlayer("#getLast");
            lastNode->next = newNode;
        }
        //newNode = NULL; //points to null now as node linked in the list
    }
}

void Team::removePlayerFrom(const string pName) {
    PNode *cur = findPlayer(pName);
    string str = pName;
    if (findPlayer(pName) == NULL) { //warning displayed earlier
        cout << "Team " << teamName << " does not exist" << endl;
    }
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
        //cout << "Player: " << str << " " << "is deleted." << endl;
        cout << endl;


    }
}

void Team::displayPlayers() const {
    if (head == NULL) {
        cout << "EMPTY, no players added to team yet!";
        return;
    }
    for (PNode *curr = head; curr != NULL; curr = curr->next) {
        cout << curr->p.getPName() << ", " << curr->p.getPPosition() <<endl;
    }
}



