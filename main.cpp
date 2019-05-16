#include <iostream>
#include <string>

#include "Player.h"

void play_round();
bool laydown_check(int round);
Player* p;
Deck* d;

int main() {
    string p_name;

    /*cout << "New game of Shang-hai\n\n";
    cout << "Enter your name: ";
    cin >> p_name;

    p = new Player(p_name);*/
    p = new Player();

    play_round();

    return 0;
}

void play_round(){
    d = new Deck();
    //d->fill();
    //d->shuffle();
    for(int i = 0; i < 11; i++){
        p->hand->add(d->take_top());
    }
    cout << "Your hand starting off is:\n";
   // p->hand->to_string();
    p->hand->set_sort();

    //cout << "Your hand sorted is:\n";
    p->hand->to_string();

    d->add_to_discard_pile(d->take_top());
    while(p->hand->cards_in_hand.size() != 0){
        //cout << d->discard[d->pile_i]->value;
        cout << "The top of the discard pile is the ";
        d->discard.back()->to_string();
        cout << "\nWould you like this card, or draw a new card? Enter 1 for Pile, 2 for Off the Top: ";


        int choice;
        Card* pick;
        cin >> choice;
        if(choice == 1)
            pick = d->pick_off_pile();
        else if(choice == 2)
            pick = d->take_top();
        else
            "you did not enter a 1 or 2\n";

       // cout << "The card you picked was the ";
       // pick->to_string();
        p->hand->add(pick);
        p->hand->to_string();

        if(laydown_check(1)){
            cout << "You have enough cards in your hand to lay down, would you like too? Enter 1 for yes, 2 for no: ";
        }
        cout << "Enter the index of the card you would like to discard: ";

        int index;
        cin >> index;

        if(index > 0 && index <= p->hand->cards_in_hand.size()){
            p->hand->add(pick);
            d->add_to_discard_pile(p->hand->remove(index-1));
            p->hand->set_sort();
        }
        else
            cout << "you did not enter a valid index\n";

    }
}
bool laydown_check(int round){
    switch(round){
        case 1:
            return(p->hand->calc_num_sets() == 2);


    }
}
