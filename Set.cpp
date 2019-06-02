//
// Created by Jacob on 5/15/2019.
//

#include "Set.h"
#include <iostream>
Set::Set(){
    rank = -1;
}
void Set::to_string() {
    int i = 1;
    for(Card* c : cards){
        std::cout << "[" << i << "] ";
        c->to_string();
        i++;
        std::cout << "\t";
    }
    std::cout << "\n";
}
bool Set::add_card(Card *c) {
    //takes a card, checks to see if it legally fits in the set & adds it to the set
    if((rank != -1 && c->value == rank) || c->value == 0)
        cards.push_back(c);
    else if(rank == -1) {
        cards.push_back(c);
        rank = c->value;
    }
    else {
        std::cout << "ERROR in adding this card to the set, the value of the card does not match that of the rest of the cards in the set\n";
        return false;
    }
    return true;
}
bool Set::contains(Card *c) {
    //don't know if this is needed
    //checks to see if a given card, is already in a set
    for(auto card : cards){
        if(c->equals(card))
            return true;
    }
    return false;
}
