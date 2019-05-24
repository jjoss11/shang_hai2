//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_HAND_H
#define UNTITLED_HAND_H
#include "Deck.h"
#include "Card.h"
#include "Set.h"
#include <vector>
using namespace std;
class Hand {
public:
    vector<Card*> cards_in_hand;
    vector<Set*> sets_on_table;

    bool on_table;
    int card_ct;

    float value;

    Hand();
    void add(Card* card);
    void to_string();
    float calc_value();
    void run_sort();
    void set_sort();
   // bool num_sort(Card* a, Card* b);
    Card* remove(int i);
    int calc_num_sets();
    void add_new_set(Set* s);
    bool play_additional_card_check();
    bool check_sets(Card* c);
    int calc_natural_sets();
    int calc_one_joker_sets();
    int calc_two_joker_sets();
    int calc_pairs();
    int calc_jokers();
    int calc_singles();
};


#endif //UNTITLED_HAND_H
