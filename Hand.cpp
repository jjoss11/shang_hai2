//
// Created by Jacob on 5/14/2019.
//
#include <iostream>
#include <algorithm>
#include "Hand.h"
using namespace std;
bool num_sort(Card *a, Card *b) {
    return a->value > b->value;
}
bool suit_sort(Card *a, Card* b){
    if(a->suit == b->suit)
        return a->value > b->value;
    else
        return a->suit < b->suit;
}
Hand::Hand(){
    on_table = false;
    card_ct = 11;
}
void Hand::add(Card* c){
    cards_in_hand.push_back(c);
    card_ct++;
}
Card* Hand::remove(int i){
    Card* result = *(cards_in_hand.begin() + (i-1));
    cards_in_hand.erase(cards_in_hand.begin() + (i-1));
    card_ct--;
    return result;
}
void Hand::to_string(){
    int count = 1;
    for(auto c : cards_in_hand){
        cout << "[" << count << "] ";
        c->to_string();
        count++;
    }
    cout << "\n";
}
float Hand::calc_value() {
    int nat_sets = calc_natural_sets();
    int pairs = calc_pairs();
    int jokers = calc_jokers();
    int useless = calc_singles();
    if(useless == 0)
        useless = 1;
    return (float)(3*nat_sets + 2*pairs + jokers)/ (float)useless;
}
void Hand::set_sort() {
   sort(cards_in_hand.begin(), cards_in_hand.end(), num_sort);
}
void Hand::run_sort() {
    sort(cards_in_hand.begin(), cards_in_hand.end(), suit_sort);
}
void Hand::add_new_set(Set *s) {
    sets_on_table.push_back(s);
}
bool Hand::play_additional_card_check() {
    for(auto c : cards_in_hand){
        for(auto s : sets_on_table){
            if(check_sets(c))
                return true;
        }
    }
    return false;
}
bool Hand::check_sets(Card* c){
    for(auto s : sets_on_table){
        if(s->rank == c->value || c->value == 0)
            return true;
    }
    return false;
}
int Hand::calc_num_sets() {
    int num_sets = 0;
    num_sets += calc_natural_sets();
    num_sets += max(calc_one_joker_sets(), calc_two_joker_sets());

    return num_sets;
}
int Hand::calc_natural_sets(){
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
    return min(calc_pairs(), calc_jokers());
}
int Hand::calc_two_joker_sets() {
    int jokers = calc_jokers();
    if (jokers < 2)
        return 0;
    else {

        return min(calc_singles(), jokers / 2);
    }
}
int Hand::calc_pairs(){
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
    int num_jokers = 0;

    for(auto c : cards_in_hand){
        if(c->value == 0)
            num_jokers++;
    }

    return num_jokers;
}
int Hand::calc_singles(){
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