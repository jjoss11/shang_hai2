//
// Created by Jacob on 5/14/2019.
//

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(){
    name = "null";
    score = 0;
    hand = new Hand();
}
Player::Player(string n){
    name = n;
    score = 0;
    hand = new Hand();
}


