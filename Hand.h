//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_HAND_H
#define UNTITLED_HAND_H
#include "Deck.h"
#include <vector>
using namespace std;
class Hand {
public:
    vector<Card*> cards_in_hand;
    vector<Card*> cards_on_table;

    int card_ct;

    Hand();
    void add(Card* card);
    void to_string();
    int calc_value();
    void sort();
    Card* remove(int i);
};


#endif //UNTITLED_HAND_H
