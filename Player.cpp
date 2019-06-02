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
    is_ai = true;
}
Player::Player(string n){
    name = n;
    score = 0;
    hand = new Hand();
    is_ai = false;
}
/*
 * I bet many of the functions in the game.cc/.h files should be moved to this class
 */

