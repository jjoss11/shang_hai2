//
// Created by Jacob on 5/14/2019.
//

#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;


Deck::Deck(){
    for(int i = 0; i < 104; i++){
        Card* temp = new Card();
        temp->value = i%13 +1;
        temp->suit = Suit(i%4);
        cards.push_back(temp);
    }
    Card* joker = new Card(0, null_suit);
    cards.push_back(joker);
    cards.push_back(joker);
    cards.push_back(joker);
    cards.push_back(joker);

   // srand(time(NULL));
    shuffle();

}

void Deck::to_string(){
    for(auto c: cards)
        c->to_string();
}
void Deck::shuffle(){
    srand((unsigned int)time(NULL));
    std::random_shuffle(cards.begin(), cards.end());
}
Card* Deck::take_top(){
    Card* result = cards.back();
    cards.pop_back();
    return result;
}
Card* Deck::pick_off_pile() {
    Card* result = discard.back();
    discard.pop_back();
    return result;
}
void Deck::add_to_discard_pile(Card* card) {
    discard.push_back(card);
}
void Deck::remove_card(Card* r_card){
    vector<Card*>::iterator it;
    for(it = cards.begin(); it != cards.end(); it++){
        if((*it)->equals(r_card)){
            cards.erase(it);
            break;
        }
    }

}