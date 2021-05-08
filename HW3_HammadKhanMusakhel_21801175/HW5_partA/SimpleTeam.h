//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#ifndef HW5_PARTA_SIMPLETEAM_H
#define HW5_PARTA_SIMPLETEAM_H
#include <string>

using namespace std;

class Team { //using team to keep things simple
public:
    Team(const string tName = "", const string tColor = "", const int tYear = 0);
    void operator=(const Team &t);
    string getTName();
    string getTColor();
    int getTYear();
    void setTName(const string tName);
    void setTColor(const string tColor);
    void setTYear(const int tYear);

private:
    string teamName; //the constants fpr each team, hence private
    string teamColor;
    int teamYear;
};

#endif //HW5_PARTA_SIMPLETEAM_H
