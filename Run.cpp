//
// Created by Jacob on 5/16/2019.
//

#include "Run.h"

Run::Run(){
    suit = null_suit;
}
void Run::add_card(Card* c) {
    if(suit == null_suit){
        cards.push_back(c);
        suit = c->suit;
    }
    else if(!cards.empty() && (c->suit == suit || c->value == 0)){
        cards.push_back(c);
    }
}
/*
 * More functions will be added (probably to Hand.cpp/.h) as I move on to developing rounds which need
 * runs for the player to lay down
 *
 * Similar to how the functions relating to sets were fleshed out working on Round 1
 */