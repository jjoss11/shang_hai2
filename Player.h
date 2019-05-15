//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <iostream>
#include "Hand.h"
using namespace std;

class Player {
public:
    Hand* hand;
    int score;
    string name;

    Player();
    Player(string name);
    void to_string();
};


#endif //UNTITLED_PLAYER_H
