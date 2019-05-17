//
// Created by Jacob on 5/15/2019.
//

#ifndef SHANG_HAI2_SET_H
#define SHANG_HAI2_SET_H

#include <vector>
#include <iostream>
#include "Card.h"
class Set {
public:
    int rank;
    std::vector<Card*> cards;

    Set();
    void to_string();
    bool add_card(Card* c);
    bool contains(Card* c);
};


#endif //SHANG_HAI2_SET_H
