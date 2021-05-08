#ifndef __COMPLETE_REG__H
#define __COMPLETE_REG__H
#include <string>
using namespace std;
#include "Team.h"

class CompleteReg {
public:
    CompleteReg();
    ~CompleteReg();
    CompleteReg(const CompleteReg &systemToCopy);
    CompleteReg &operator=(const CompleteReg &right);
    Team &operator[](const int index);
    void addTeam(const string tName, const string tColor, const int tyear);
    void removeTeam(string teamName);
    void displayAllTeams() const;
    void addPlayer(const string tName, const string pName, const string pPos);
    void removePlayer(const string tName, const string pName);
    void displayTeam(const string teamName) const;
    void displayPlayer(const string pName) const;
private:
    struct Node {
        Team t;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    int teamCount;
    Node *findTeam(string teamName) const;
};


#endif//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#ifndef HW3_PARTB_COMPLETEREG_H
#define HW3_PARTB_COMPLETEREG_H

#endif //HW3_PARTB_COMPLETEREG_H
