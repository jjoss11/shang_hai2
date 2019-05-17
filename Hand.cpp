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
}
int Hand::calc_value() {
    int total = 0;
    for(auto c : cards_in_hand){
        if(c->value = 1)
            total+=15;
        else if(c->value > 1 && c->value < 10)
            total+= 5;
        else if(c->value > 9 && c->value < 14)
            total+=10;
        else
            total+=50;
    }
    return total;
}

void Hand::set_sort() {
   sort(cards_in_hand.begin(), cards_in_hand.end(), num_sort);
}
void Hand::run_sort() {
    sort(cards_in_hand.begin(), cards_in_hand.end(), suit_sort);
}
int Hand::calc_num_sets(){
    int num_sets = 0;
    vector<int> num_count(13, 0);
    int num_jokers = 0;

    for(auto c : cards_in_hand){
        if(c->value != 0)
            num_count[c->value - 1]++;
        else
            num_jokers++;
    }

    for(auto i : num_count){
        if((i+num_jokers) >= 3)
            num_sets++;
    }

    return num_sets;

}
void Hand::add_new_set(Set *s) {
    sets_on_table.push_back(s);
}
bool Hand::play_additional_card_check() {
    bool flag = false;
    for(auto c : cards_in_hand){
        for(auto s : sets_on_table){
            if(check_sets(c))
                flag = true;
        }
    }
}
bool Hand::check_sets(Card* c){
    for(auto s : sets_on_table){
        if(s->rank == c->value)
            return true;
    }
    return false;
}