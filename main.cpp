#include <iostream>
#include <string>

#include "Player.h"

void play_round();
bool laydown_check(int round);
Set* get_set();
void lay_down(int round);
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

       cout << "The card you picked was the ";
       pick->to_string();
        p->hand->add(pick);
        p->hand->to_string();

        if(laydown_check(1)){
            int choice;
            cout << "You have enough cards in your hand to lay down, would you like too? Enter 1 for yes, 2 for no: ";
            cin >> choice;

            if(choice == 1){
                lay_down(1);
            }
        }
        cout << "Enter the index of the card you would like to discard: ";
        int index;
        cin >> index;

        if(index > 0 && index <= p->hand->cards_in_hand.size()){
            d->add_to_discard_pile(p->hand->remove(index));
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
void lay_down(int round){
    switch(round){
        case 1:
            cout << "=====Set 1 of 2=====\n";
            Set* set_1 = get_set();
            cout << "=====Set 2 of 2=====\n";
            Set* set_2 = get_set();
            p->hand->add_new_set(set_1);
            p->hand->add_new_set(set_2);

    }
}
Set* get_set(){
    Set* s = new Set();
    int index;

    p->hand->to_string();
    cout << "Enter the index of first card you would like to include in your this set";
    cin >> index;
    s->add_card(p->hand->remove(index));

    p->hand->to_string();
    cout << "\nEnter the index of second card you would like to include in this set";
    cin >> index;
    s->add_card(p->hand->remove(index));

    p->hand->to_string();
    cout << "\nEnter the index of third card you would like to include in this set";
    cin >> index;
    s->add_card(p->hand->remove(index));

    int more;
    do {
        p->hand->to_string();
        cout << "\nWould you like to add more cards to this set? Enter 1 for yes, enter 2 for no: ";
        cin >> more;
        if (more == 1) {
            p->hand->to_string();
            cout << "Enter the index of next card you would like to include in this set";
            cin >> index;
            s->add_card(p->hand->remove(index));
        }
    }while(more == 1);

    return s;
}
