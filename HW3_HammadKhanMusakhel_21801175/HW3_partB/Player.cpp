//
// Created by Hammad Khan Musakhel on 5/12/20.
//
#include "PLayer.h"

Player::Player(const string playerName, const string playerPosition) {
    this->pName = playerName;
    this->pPosition = playerPosition;
}

void Player::operator=(const Player &right) {
    if (&right != this) {
        pPosition = right.pPosition;
        pName = right.pName;
    }
}

string Player::getPName () const {
    return pName;
}

void Player::setPName(const string playerName) {
    this->pName = playerName;
}

string Player::getPPosition () const {
    return pPosition;
}

void Player::setPPosition (const string position) {
    this->pPosition = position;
}
