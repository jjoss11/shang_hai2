//
// Created by Jacob on 5/14/2019.
//
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(){
    value = -1;
    suit = null_suit;
}
Card::Card(int v, Suit s){
    value = v;
    suit = s;
}

void Card::to_string(){
    switch(value) {
        case 11:
            cout << "J of ";
            break;
        case 12:
            cout << "Q of ";
            break;
        case 13:
            cout << "K of ";
            break;
        case 1:
            cout << "A of ";\
            break;
        case 0:
            cout << "Joker";
            break;
        default:
            cout << value << " of ";
            break;
    }
    switch(suit){
        case Spades:
            cout << "Spades";
            break;
        case Diamonds:
            cout << "Diamonds";
            break;
        case Hearts:
            cout << "Hearts";
            break;
        case Clubs:
            cout << "Clubs";
            break;
        default:
            break;
    }
    cout << "\n";
}