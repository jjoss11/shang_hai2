//
// Created by Jacob on 5/14/2019.
//

#include "Deck.h"
#include <iostream>
#include <ctime>

using namespace std;


Deck::Deck(){
    top_i = 0;
    pile_i = 0;
    for(int i = 0; i < 54*2; i++){
        cards[i] = new Card();
        discard[i] = new Card();
    }
}
void Deck::fill(){
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

}

void Deck::to_string(){
    for(int i = 0; i < 54*2; i++) {
        cards[i]->to_string();
        cout << "\n";
    }
}
void Deck::shuffle(int shuffle_count){
    srand(time(NULL));
    for(int i = 0; i < shuffle_count; i++){
        int index_1 = rand()%(54*2);
        int index_2 = rand()%(54*2);

        Card* temp_1 = cards[index_1];
        Card* temp_2 = cards[index_2];
        cards[index_1] = temp_2;
        cards[index_2] = temp_1;

    }
}
Card* Deck::take_top(){
    Card* result = cards[top_i];
    top_i++;
    return result;
}
Card* Deck::pick_off_pile() {
    Card* result = discard[pile_i];
    discard[pile_i] = new Card();
    pile_i--;
    return result;
}
void Deck::add_to_discard_pile(Card* card) {
    discard[pile_i] = card;
    pile_i++;
}