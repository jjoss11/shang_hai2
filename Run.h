//
// Created by Jacob on 5/16/2019.
//

#ifndef SHANG_HAI2_RUN_H
#define SHANG_HAI2_RUN_H
#include "Card.h"
#include <vector>

class Run {
public:
    Suit suit;
    std::vector<Card*> cards;

    Run();
    void add_card(Card* c);
};


#endif //SHANG_HAI2_RUN_H
