#include "Player.h"
#include "monte_carlo_advisor.h"
#include <iostream>
#include <string>
using namespace std;

void play_round(int round);
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

    play_round(1);

    return 0;
}

void play_round(int round){
    d = new Deck();
    //d->fill();
    //d->shuffle();
    for(int i = 0; i < 11; i++){
        p->hand->add(d->take_top());
    }
   // cout << "Your hand starting off is:\n";
   // p->hand->to_string();
    p->hand->set_sort();

    //cout << "Your hand sorted is:\n";
    // p->hand->to_string();

    d->add_to_discard_pile(d->take_top());
    cout << "\n";
    while(!p->hand->cards_in_hand.empty()){
        //cout << d->discard[d->pile_i]->value;
        cout << "The top of the discard pile is the: ";
        d->discard.back()->to_string();
        cout << "\n\n";
        p->hand->to_string();
        cout << "\n";
        cout << "\nWould you like this card, or draw a new card? Enter 1 for Pile, 2 for Off the Top: ";


        int choice;
        Card* pick = new Card();
        cin >> choice;
        if(choice == 1)
            pick = d->pick_off_pile();
        else if(choice == 2)
            pick = d->take_top();
        else
            cout << "you did not enter a 1 or 2\n";

       cout << "\nThe card you picked was the ";
       pick->to_string();
       cout << "\n\n";
        p->hand->add(pick);
        p->hand->to_string();

        if(laydown_check(round) && !p->hand->on_table){
            int l_choice;
            cout << "You have enough cards in your hand to lay down, would you like to do so? Enter 1 for yes, 2 for no: ";
            cin >> l_choice;

            if(l_choice == 1){
                lay_down(round);
            }
        }
        int add_to_set = 1;
        while(p->hand->play_additional_card_check() && add_to_set == 1){
            cout << "You can play another card on what is already on the table, would you like too? Enter 1 for yes, 2 for no: ";
            cin >> add_to_set;
            if(add_to_set == 1){
                int index;
                cout << "Enter the index of the card you would like to lay down:";
                cin >> index;
                Card* play = p->hand->remove(index);

                for(auto s : p->hand->sets_on_table){
                    if(s->rank == play->value){
                        s->add_card(play);
                        break;
                    }
                }

            }
        }
        //p->hand->to_string();
        mc(p->hand, 1200);
        cout << "Enter the index of the card you would like to discard: ";
        int index;
        cin >> index;
        cout << "\n----------------------------------------------\n----------------------------------------------\n";
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
            return(p->hand->calc_num_sets() >= 2);
        case 2:
            return false;
        case 3:
            return false;
        case 4:
            return false;
        case 5:
            return false;
        case 6:
            return false;
        case 7:
            return false;
        default:
            cout << "you goofed\n";
            return false;
    }
}
void lay_down(int round){
    Set* set_1;
    Set* set_2;
    /*Set* set_3;
    Run* run_1;
    Run* run_2;
    Run* run3;*/

    switch(round){
        case 1:
            cout << "\n\n==========Set 1 of 2==========\n\n";
            set_1 = get_set();
            cout << "\n\n==========Set 2 of 2==========\n\n";
            set_2 = get_set();
            p->hand->add_new_set(set_1);
            p->hand->add_new_set(set_2);
            p->hand->on_table = true;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            cout << "you goofed\n";

    }
}
Set* get_set(){
    Set* s = new Set();
    int index;
    do {
        p->hand->to_string();
        cout << "Enter the index of first card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    }while(!s->add_card(p->hand->remove(index)));

    do {
        p->hand->to_string();
        cout << "Enter the index of second card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    }while(!s->add_card(p->hand->remove(index)));

    do {
        p->hand->to_string();
        cout << "Enter the index of third card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    }while(!s->add_card(p->hand->remove(index)));

    int more;
    do {
        p->hand->to_string();
        cout << "\nWould you like to add more cards to this set? Enter 1 for yes, enter 2 for no: ";
        cin >> more;
        cout << "\n";
        if (more == 1) {
            do {
                p->hand->to_string();
                cout << "Enter the index of the next card you would like to include in this set: ";
                cin >> index;
                cout << "\n";
            }while(!s->add_card(p->hand->remove(index)));
        }
    }while(more == 1);

    return s;
}
