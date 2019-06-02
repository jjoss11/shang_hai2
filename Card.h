//
// Created by Jacob on 5/14/2019.
//

#ifndef UNTITLED_CARD_H
#define UNTITLED_CARD_H

typedef enum{null_suit = -1, Spades = 0, Hearts, Clubs, Diamonds}Suit;
class Card {
public:
    int value;  //values  A - K are integers 1 - 13, Jokers are 0
    Suit suit;  //self-explanatory, Jokers are null_suit

    Card();
    Card(int v, Suit s);
    void to_string();
    bool equals(Card* c);
};


#endif //UNTITLED_CARD_H
