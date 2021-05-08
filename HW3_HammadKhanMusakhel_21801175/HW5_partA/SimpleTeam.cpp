//
// Created by Hammad Khan Musakhel on 5/12/20.
//
#include <iostream>
#include "SimpleTeam.h"
#include <algorithm>
using namespace std;

Team::Team(const string tName, const string tColor, const int tYear) {
    teamName = tName;
    teamColor = tColor;
    teamYear = tYear;
}

void Team::operator=(const Team &right) {
    if (&right != this) {
        teamYear = right.teamYear;
        teamColor = right.teamColor;
        teamName = right.teamName; //equalling all the variables on thte other side of the operator


    }
}

string Team::getTName() {
    return teamName;
}
int Team::getTYear() {
    return teamYear;
}

string Team::getTColor() {
    return teamColor;
}


void Team::setTYear(const int tYear) {
    teamYear = tYear;
}

void Team::setTColor(const string tColor) {
    teamColor = tColor;
}

void Team::setTName(const string tName) {
    teamName = tName;
}





