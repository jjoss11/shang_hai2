//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_CARD_H
#define UNTITLED_CARD_H

typedef enum{null_suit = -1, Spades = 0, Hearts, Clubs, Diamonds}Suit;
class Card {
public:
    int value;
    Suit suit;

    Card();
    Card(int v, Suit s);
    void to_string();
};


#endif //UNTITLED_CARD_H
