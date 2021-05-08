//
// Created by Hammad Khan Musakhel on 5/12/20.
//

#ifndef HW3_PARTB_PLAYER_H
#define HW3_PARTB_PLAYER_H
#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;

class Player {
public:
    Player(const string playerName = "", const string playerPosition = "");
    string getPName () const;
    void operator=(const Player &p);
    void setPName(const string playerName);
    void setPPosition (const string position);
    string getPPosition () const;

private:
    string pName;
    string pPosition;
};

#endif
#endif //HW3_PARTB_PLAYER_H
