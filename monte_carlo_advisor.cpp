//
// Created by Jacob on 5/23/2019.
//

#include "monte_carlo_advisor.h"
#include <map>
void mc(Hand* o_hand, int sims){
    float max_value = -1;
    int max_index = -1;
    for(int i = 0; i < o_hand->cards_in_hand.size(); i++){
         float value = mc_expected_val(o_hand, i, sims);
         if(value > max_value){
             max_value = value;
             max_index = i;
         }
    }
    std::cout << "We recommend you discard the ";
    o_hand[max_index].to_string();
    std::cout << endl;
}
float mc_expected_val(Hand* o_hand, int discard, int sims){
    std::map<float, int> occurrences;

    for(int j = 0; j < sims; j++) {
        Deck *deck = new Deck();
        Hand *h = o_hand;

        for (auto c : h->cards_in_hand) {
            deck->remove_card(c);
        }
        for (auto s : h->sets_on_table) {
            for(auto it = s->cards.begin(); it != s->cards.end(); it++){
                deck->remove_card(*it);
            }
        }
        h->remove(discard + 1);
        h->add(deck->take_top());
        try{
            occurrences[h->calc_value()]++;
        }
        catch(exception e){
            occurrences[h->calc_value()] = 1;
        }
        int mcnum = 0;
        for(auto it = occurrences.begin(); it != occurrences.end(); it++){
            mcnum += it->first * it->second;
        }
        return float((float)mcnum / (float)sims);
    }

}