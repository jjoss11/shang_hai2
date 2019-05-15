//
// Created by Jacob on 5/14/2019.
//
#include <iostream>
#include "Hand.h"
using namespace std;
Hand::Hand(){
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