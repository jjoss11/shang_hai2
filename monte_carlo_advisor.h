//
// Created by Jacob on 5/23/2019.
//

#ifndef SHANG_HAI2_MONTE_CARLO_ADVISOR_H
#define SHANG_HAI2_MONTE_CARLO_ADVISOR_H
#include "Hand.h"
#include <vector>

using namespace std;

void mc(Hand*, int);
void mc_card_combos(Hand*, vector<int>, int, int, int, int, vector<int>, vector<int>, vector<int>);
int mc_expected_val(Hand*, int, int);



#endif //SHANG_HAI2_MONTE_CARLO_ADVISOR_H
