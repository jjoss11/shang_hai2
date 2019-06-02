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
    for(int i = 0; i < 104; i++){   //Shang hai is played with 2 full decks of cards including jokers,
        Card* temp = new Card();    //so two of each card and 4 jokers are needed
        temp->value = i%13 +1;
        temp->suit = Suit(i%4);
        cards.push_back(temp);
    }
    Card* joker = new Card(0, null_suit);
    cards.push_back(joker);
    cards.push_back(joker);
    cards.push_back(joker);
    cards.push_back(joker);

    shuffle();  //cards are added to the deck in a specific order so the deck needs to be shuffled

}

void Deck::to_string(){ //not actually used in game, purely for testing shuffle function
    for(auto c: cards)
        c->to_string();
}

void Deck::shuffle(){
    int times = 1000; // arbitrary number of times to call the vector shuffle function, could be any # really
    while(times > 0) {
        srand((unsigned int) time(nullptr)); // reset seed to get a random shuffling each time
        auto rng = default_random_engine{unsigned(rand())};
        std::shuffle(cards.begin(), cards.end(), rng);
        times--;
    }
}

Card* Deck::take_top(){ //pops card of "top" of the deck
    Card* result = cards.back();
    cards.pop_back();
    return result;
}

Card* Deck::pick_off_pile() { // pops top of discard pile
    Card* result = discard.back();
    discard.pop_back();
    return result;
}

void Deck::add_to_discard_pile(Card* card) {    // takes a card and adds it to top of discard pile
    discard.push_back(card);
}

void Deck::remove_card(Card* r_card){ // for MC advisor, removes a specific card from the deck.
    vector<Card*>::iterator it;
    for(it = cards.begin(); it != cards.end(); it++){
        if((*it)->equals(r_card)){
            cards.erase(it);
            break;
        }
    }

}