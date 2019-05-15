//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H
#include "Card.h"
#include <vector>

class Deck {
public:
    std::vector<Card*> cards;
    std::vector<Card*> discard;
    //int top_i;
   // int pile_i;

    Deck();
    void to_string();
    //void fill();
    void shuffle();
    Card* take_top();
    void add_to_discard_pile(Card* card);
    Card* pick_off_pile();
};


#endif //UNTITLED_DECK_H
