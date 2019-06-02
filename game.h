//
// Created by Jacob on 6/2/2019.
//

#ifndef SHANG_HAI2_GAME_H
#define SHANG_HAI2_GAME_H
#include "Player.h"
#include "monte_carlo_advisor.h"

//1 human, 2 ai player game
Player *p;
Player *ai_1, *ai_2;
vector<Player*> ai;

Deck *d;


void play_round(int round);
bool laydown_check(int round);
Set *get_set();
void lay_down(int round);
void ai_lay_down(Player* ai_n, int round);      //need to determine a way for the ai to enter its requirements to lay down

#endif //SHANG_HAI2_GAME_H
