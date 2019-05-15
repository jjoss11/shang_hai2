#include <iostream>
#include <string>

#include "Player.h"

void play_round();
Player* p;
Deck* d;

int main() {
    string p_name;

    /*cout << "New game of Shang-hai\n\n";
    cout << "Enter your name: ";
    cin >> p_name;

    p = new Player(p_name);*/
    p = new Player();

    //play_round();
    d = new Deck();
    d->to_string();

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

    while(p->hand->cards_in_hand.size() != 0){
        //cout << d->discard[d->pile_i]->value;
        if(d->discard.size() == 0)
            cout << "There is no card on the discard pile, Enter 2 to take a card off the top: ";
        else {
            cout << "The top of the discard pile is the ";
            d->discard.back()->to_string();
            cout << "\nWould you like this card, or draw a new card? Enter 1 for Pile, 2 for Off the Top: ";
        }

        int choice;
        Card* pick;
        cin >> choice;
        if(choice == 1)
            pick = d->pick_off_pile();
        else if(choice == 2)
            pick = d->take_top();
        else
            "you did not enter a 1 or 2\n";

        cout << "The card you picked was the ";
        pick->to_string();

        p->hand->to_string();
        cout << "Enter the index of the card you would like to discard, if you'd like to discard the card you drew, enter 0: ";

        int index;
        cin >> index;

        if(index == 0){
            d->add_to_discard_pile(pick);
        }
        else if(index > 0 && index <= p->hand->cards_in_hand.size()){
            p->hand->add(pick);
            d->add_to_discard_pile(p->hand->remove(index-1));
            p->hand->set_sort();
        }
        else
            cout << "you did not enter a valid index\n";


    }

}
