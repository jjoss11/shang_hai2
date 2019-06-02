//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H
#include "Card.h"
#include <vector>

class Deck {
public:
    std::vector<Card*> cards;   //portion of deck with cards "face down" for players to draw from
    std::vector<Card*> discard; //discard pile

    Deck();
    void to_string();
    void shuffle();
    Card* take_top();
    void add_to_discard_pile(Card* card);
    Card* pick_off_pile();
    void remove_card(Card*);
};


#endif //UNTITLED_DECK_H
