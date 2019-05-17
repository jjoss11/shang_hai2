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
    }
}
bool Set::add_card(Card *c) {
    if(rank != -1 && c->value == rank)
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
    for(auto card : cards){
        if(c->equals(card))
            return true;
    }
    return false;
}