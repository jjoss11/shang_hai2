//
// Created by Jacob on 5/14/2019.
//
#include <iostream>
#include <algorithm>
#include "Hand.h"
using namespace std;
bool num_sort(Card *a, Card *b) {
    return a->value > b->value;
} //helper function for sorting cards in numerical order

bool suit_sort(Card *a, Card* b){
    if(a->suit == b->suit)
        return a->value > b->value;
    else
        return a->suit < b->suit;
} //helper function for sorting cards by suit

Hand::Hand(){ //starting off, the user will not have lain down and will have 11 cards in their hand
    on_table = false;
    card_ct = 11;
}

void Hand::add(Card* c){
    cards_in_hand.push_back(c);
    card_ct++;
}

Card* Hand::remove(int i){
    Card* result = *(cards_in_hand.begin() + i);
    cards_in_hand.erase(cards_in_hand.begin() + i);
    card_ct--;
    return result;
}//removes a card at a given index

void Hand::to_string(){
    int count = 1;
    for(auto c : cards_in_hand){
        cout << "[" << count << "] ";
        c->to_string();
        count++;
        cout << "\t";
    }
    cout << "\n";
}//prints cards in player's hand

int Hand::calc_value() {

    //creates a vector for each rank of card to store the hand in essentially a bar graph/frequency diagram
    vector<int> hand_vals(13, 0);
    int num_jokers = 0;

    //iterated through the hand and increments above vector for each type of card in hand
    for(auto c : cards_in_hand){
        if(c->value != 0)
            hand_vals[c->value - 1]++;
        else
            num_jokers++;
    }
    int val = 0;
    /*
     * This is the most subjective part of the code and needed for the MC ai
     * Only helps determine the value of a hand with regards to sets.
     *
     * if the card is part of a natural set (i.e. no jokers) multiply weight by 3
     * if the card is part of a pair or is a joker (multiply the weight by 2)
     *
     * Lowest value is 0. No pairs or Jokers, 11 single cards
     * Highest value is 36. Every card is a member of a natural set.
     *
     * There is certainly a better way of quantifying the value of a hand, taking into account
     * the score associated with each card and (for succeeding rounds) whether a card is a part of a run
     * but this is the best I could come up with
     */

    for(int i : hand_vals){
        if(i >= 3)
            val += 3*i;
        else if(i == 2)
            val += 2*i;
    }
    val += 2*num_jokers;

    return val;
}

void Hand::set_sort() {
   sort(cards_in_hand.begin(), cards_in_hand.end(), num_sort);
}//sorts a hand to make pairs and sets

void Hand::run_sort() {
    sort(cards_in_hand.begin(), cards_in_hand.end(), suit_sort);
}//sorts a hand for runs

void Hand::add_new_set(Set *s) {
    //used for laying down
    //transfers a set from cards_in_hand to sets_on_table
    sets_on_table.push_back(s);
}

bool Hand::play_additional_card_check() {
    //used after a player has laid down
    //checks to see if any cards in the player's hand could be added to the set on the table
    for(auto c : cards_in_hand){
        for(auto s : sets_on_table){
            if(check_sets(c))
                return true;
        }
    }
    return false;
}

bool Hand::check_sets(Card* c){
    //determines whether a given card can be added to player's sets on table
    //helper function for play_additional_card_check
    //can probably be private

    for(auto s : sets_on_table){
        if(s->rank == c->value || c->value == 0)
            return true;
    }
    return false;
}

int Hand::calc_num_sets() {
    //calculates the number of sets a user has in their hand
    int num_sets = 0;
    num_sets += calc_natural_sets();

    //used to so a user can't use one joker in two sets
    num_sets += max(calc_one_joker_sets(), calc_two_joker_sets());

    return num_sets;
}

int Hand::calc_natural_sets(){
    //determines how many groups of 3 or more of the same value of card are in a hand
    int num_sets = 0;
    vector<int> num_count(13, 0);

    for(auto c : cards_in_hand){
        if(c->value != 0)
            num_count[c->value - 1]++;
    }

    for(auto i : num_count){
        if(i >= 3)
            num_sets++;
    }
    return num_sets;
}

int Hand::calc_one_joker_sets(){
    //calculate how many sets using one joker can be made with the cards in hand

    /*
     * if a user has two pairs and only one joker => returns 1
     * if a user has one pair but two jokers => returns 1
     */
    return min(calc_pairs(), calc_jokers());
}

int Hand::calc_two_joker_sets() {
    //calculates the number of sets that can be made which have 2 jokers and one non-joker
    int jokers = calc_jokers();

    //only works if the user has at least 2 jokers
    if (jokers < 2)
        return 0;
    else {
        //same logic as calc_one_joker_sets, jokers/2 is used because it would require 2 jokers to make one set
        return min(calc_singles(), jokers / 2);
    }
}

int Hand::calc_pairs(){
    //same logic as calc_natural_sets but only returning the number of pairs instead of groups of 3+
    int num_pairs = 0;
    vector<int> num_count(13, 0);

    for(auto c : cards_in_hand){
        if(c->value != 0)
            num_count[c->value - 1]++;
    }

    for(auto i : num_count){
        if(i == 2)
            num_pairs++;
    }
    return num_pairs;
}

int Hand::calc_jokers(){
    //self-explanatory, can probably be private

    int num_jokers = 0;

    for(auto c : cards_in_hand){
        if(c->value == 0)
            num_jokers++;
    }

    return num_jokers;
}

int Hand::calc_singles(){
    //self-explanatory

    int num_sing = 0;
    vector<int> num_count(13, 0);

    for(auto c : cards_in_hand){
        if(c->value != 0)
            num_count[c->value - 1]++;

    }

    for(auto i : num_count){
        if(i == 1)
            num_sing++;
    }
    return num_sing;
}