//
// Created by Jacob on 5/23/2019.
//

#include "monte_carlo_advisor.h"
#include <map>
void mc(Hand* o_hand, int sims){
    float max_value = -1;
    int max_index = -1;
    for(int i = 0; i < o_hand->cards_in_hand.size(); i++){
        //cout << "i is " << i << " ";
        int value = mc_expected_val(o_hand, i, sims);
        //cout << "value is " << value << endl;
         if(value > max_value){
             max_value = value;
             max_index = i;
         }
    }
    //o_hand->set_sort();
    //std::cout << "this is what the advisor thinks your hand is:\n";
    //o_hand->to_string();
    //std::cout << "the advisor wants you to discard the index: " << max_index << endl;
    std::cout << "We recommend you discard the ";

    o_hand->cards_in_hand[max_index]->to_string();
    std::cout << endl;
}
int mc_expected_val(Hand* o_hand, int discard, int sims){
    int* occurrences = new int[37];
    for(int i = 0; i < 37; i++)
        occurrences[i] = 0;

    int mc = 0;
    for(int j = 0; j < sims; j++) {
        Deck *deck = new Deck();
        Hand *h = new Hand();

        for(auto c : o_hand->cards_in_hand)
            h->cards_in_hand.push_back(c);
        for(auto s : o_hand->sets_on_table)
            h->sets_on_table.push_back(s);

        for (auto c : h->cards_in_hand) {
            deck->remove_card(c);
        }

        /*for (auto s : h->sets_on_table) {
            for(auto it = s->cards.begin(); it != s->cards.end(); it++){
                deck->remove_card(*it);
            }
        }*/
        h->set_sort();
        h->remove(discard);
        deck->shuffle();
        h->add(deck->take_top());

        int sim_val = h->calc_value();
        occurrences[sim_val]++;
    }
    for(int i = 0; i < 37; i++)
        mc += i*occurrences[i];

    return mc/sims;
}