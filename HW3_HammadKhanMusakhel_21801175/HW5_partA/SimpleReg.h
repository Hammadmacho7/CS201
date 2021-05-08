//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#ifndef HW5_PARTA_SIMPLEREG_H
#define HW5_PARTA_SIMPLEREG_H
#include <string>
#include "SimpleTeam.h"
using namespace std;


class SimpleReg {

public:
    SimpleReg();
    ~SimpleReg();
    void addTeam(const string tName, const string tColor, const int tYear);
    void removeTeam(const string teamName);
    void displayAllTeams() const;
private:
    struct Node {
        Team t;
        Node *next;
    };
    Node *head;
    int teamCount;
    Node *findTeam(const string teamName) const;
};

#endif //HW5_PARTA_SIMPLEREG_H
