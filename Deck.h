//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H
#include "Card.h"

class Deck {
public:
    Card* cards [54*2];
    Card* discard [54*2];
    int top_i;
    int pile_i;

    Deck();
    void to_string();
    void fill();
    void shuffle(int shuffle_count);
    Card* take_top();
    void add_to_discard_pile(Card* card);
    Card* pick_off_pile();
};


#endif //UNTITLED_DECK_H
