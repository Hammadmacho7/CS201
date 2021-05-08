//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#ifndef HW3_PARTB_TEAM_H
#define HW3_PARTB_TEAM_H
#ifndef __TEAM_H
#define __TEAM_H
#include <string>
#include "PLayer.h"
using namespace std;

class Team {
public:
    Team(const string tName = "", const string tColor = "", const int tYear = 0);
    ~Team();
    void operator=(const Team &t);
    string getTName();
    string getTColor();
    int getTYear();
    void setTName(const string tName);
    void setTColor(const string tColor);
    void setTYear(const int tYear);
    void addPlayerInto(const string pName, const string pPosition);
    void removePlayerFrom(const string pName);
    void displayPlayers() const;

    bool hasTeam(const string playerName);

private:
    struct PNode { //Node for the player
        Player p; //object of player in team
        PNode *next;
        PNode *prev;
    };
    PNode *head;
    PNode *tail;
    PNode *findPlayer(const string pName);

    string teamName; //team's attributes
    string teamColor;
    int teamYear;
};

#endif
#endif //HW3_PARTB_TEAM_H
