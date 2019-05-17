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