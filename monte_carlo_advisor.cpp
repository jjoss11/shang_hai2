//
// Created by Jacob on 5/23/2019.
//

#include "monte_carlo_advisor.h"
#include <map>
void mc(Hand* o_hand, int sims){
    int max_value = -1;
    int max_index = -1;

    //run the mc simulation, where each card in the hand is the one being discarded,
    //recommend to the player that they discard the card which theoretically gives
    //the player the highest value, no matter the new card being drawn to replace it
    for(int i = 0; i < o_hand->cards_in_hand.size(); i++){
        int value = mc_expected_val(o_hand, i, sims);
         if(value > max_value){
             max_value = value;
             max_index = i;
         }
    }

    std::cout << "We recommend you discard the ";

    o_hand->cards_in_hand[max_index]->to_string();
    std::cout << endl;
}
int mc_expected_val(Hand* o_hand, int discard, int sims){

    //array to store occurrences of each possible score that could appear
    //0 - 36 are the range possible values of a hand using the "algorithm" (loosest definition of the word) I came up with
    int* occurrences = new int[37];
    for(int i = 0; i < 37; i++)
        occurrences[i] = 0;

    int mc = 0;

    //simulation repeated a given number of times to get a statistically-sound expected value of a hand when a given card is discarded
    for(int j = 0; j < sims; j++) {
        //a new deck and hand are needed for each simulation
        Deck *deck = new Deck();
        Hand *h = new Hand();

        //make a copy of the original hand to the simulated hand
        for(auto c : o_hand->cards_in_hand)
            h->cards_in_hand.push_back(c);
        for(auto s : o_hand->sets_on_table)
            h->sets_on_table.push_back(s);

        //remove all the cards in the new deck that are in the users hand
        /*
         * for future reference:
         * remove all cards that the 2 other player have on the table, because that is what the user can see
         *
         * possibly remove all the cards in the discard pile from deck (or x number of cards from the top of the discard pile).
         * This could be a feature of a harder difficulty.
         * Most human players cannot remember every card in the discard pile as the game goes on
         */
        for (auto c : h->cards_in_hand) {
            deck->remove_card(c);
        }

        //sort the hand so the indeces match up, remove the test discard
        h->set_sort();
        h->remove(discard);
        deck->shuffle();
        h->add(deck->take_top());

        //calculate the value of the hand with the new card being drawn included
        int sim_val = h->calc_value();
        //increment the spot in the array of the value appearing
        occurrences[sim_val]++;
    }

    //calculate average value of the hand
    for(int i = 0; i < 37; i++)
        mc += i*occurrences[i];

    return mc/sims;
}