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
/*void Deck::fill(){
    int card_ct = 0;
    for(int d = 0; d < 2; d++){
        for (int v = 1; v < 14; v++) {
            for (int s = 0; s <= 3; s++) {
                cards[card_ct]->value = v;
                cards[card_ct]->suit = Suit(s);

                card_ct++;
            }
        }
    }
    cards[104]->value = 0;
    cards[104]->suit = null_suit;

    cards[105]->value = 0;
    cards[105]->suit = null_suit;

    cards[106]->value = 0;
    cards[106]->suit = null_suit;

    cards[107]->value = 0;
    cards[107]->suit = null_suit;

}*/

void Deck::to_string(){
    for(auto c: cards)
        c->to_string();
}
auto rng = std::default_random_engine{};
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