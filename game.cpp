#include "game.h"
#include <iostream>
#include <string>

using namespace std;


int main() {

    /* in a real game, this would be needed but it got tedious to type in a new name
     * after every test
     *
     * string p_name;
     * cout << "New game of Shang-hai\n\n";
     * cout << "Enter your name: ";
     * cin >> p_name;
     * p = new Player(p_name);
     *
     *
    */


    p = new Player("Jacob");
    ai_1 = new Player();
    ai_2 = new Player();
    ai.push_back(ai_1);
    ai.push_back(ai_2);


    play_round(1); // play first round

    return 0;
}

void play_round(int round) {
    d = new Deck();                       // new shuffled deck needed for every round

    for (int i = 0; i < 11; i++) {        // deal each player 11 cards
        p->hand->add(d->take_top());
        ai_1->hand->add(d->take_top());
        ai_2->hand->add(d->take_top());
    }
    p->hand->set_sort();                  // because it is the first round (need two sets), sort the human player's hand by sets
                                          // no need to sort the ai's hands because it only helps the user to strategize

    d->add_to_discard_pile(d->take_top());// the rounds always start off with the top of the deck being flipped to the discard pile
    cout << "\n";


    while (!p->hand->cards_in_hand.empty() && !ai_1->hand->cards_in_hand.empty() && !ai_2->hand->cards_in_hand.empty()) {       //rounds end when one player has played all of their cards


        //start each turn by telling the user what the top of the discard pile is and what is in their hand
        cout << "The top of the discard pile is the: ";
        d->discard.back()->to_string();
        cout << "\n\n";
        p->hand->to_string();
        cout << "\n\n";

        //prompt user to take top of discard pile or top of deck
        cout << "Would you like this card, or draw a new card? Enter 1 for Pile, 2 for Off the Top: ";
        int choice;
        cin >> choice;

        Card *pick = new Card();
        if (choice == 1)
            pick = d->pick_off_pile();
        else if (choice == 2)
            pick = d->take_top();
        else
            cout << "you did not enter a 1 or 2\n";

        //let user know what the card they drew was and show them their hand with the card in it
        cout << endl << "The card you picked was the ";
        pick->to_string();
        cout << "\n\n";
        p->hand->add(pick);
        p->hand->to_string();


        //if the user has the required sets and/or runs to lay down, give them the opportunity to do so
        if (laydown_check(round) && !p->hand->on_table) {
            int l_choice;
            cout << "\nYou have enough cards in your hand to lay down, would you like to do so? Enter 1 for yes, 2 for no: ";
            cin >> l_choice;

            if (l_choice == 1) {
                lay_down(round);
            }
        }

        //if the user can add a card to those already on the table, let them
        int add_to_table = 1;
        while (p->hand->play_additional_card_check() && add_to_table == 1) {
            cout << "You can play another card on what is already on the table, would you like too? Enter 1 for yes, 2 for no: ";
            cin >> add_to_table;
            if (add_to_table == 1) {
                int index;
                cout << "Enter the index of the card you would like to lay down:";
                cin >> index;
                Card *play = p->hand->remove(index);

                for (auto s : p->hand->sets_on_table) {
                    if (s->rank == play->value) {
                        s->add_card(play);
                        break;
                    }
                }

            }
        }
        p->hand->set_sort();

        //mc advisor function to determine which card would be the best for the user to discard
        mc(p->hand, 12);

        //prompt user to discard
        cout << "Enter the index of the card you would like to discard: ";
        int index;
        cin >> index;
        cout << "\n--------------------------------------------------------------------------------------------\n";
        if (index > 0 && index <= p->hand->cards_in_hand.size()) {
            d->add_to_discard_pile(p->hand->remove(index - 1)); // index -1  is used as the parameter becase the cards are displayed to the user 1 - 12 but stored in the vector 0 - 11
            p->hand->set_sort();
        } else
            cout << "you did not enter a valid index\n";
    }
}

bool laydown_check(int round) {
    switch (round) {
        case 1:
            return (p->hand->calc_num_sets() >= 2); //2 sets are needed to lay down the first round
        case 2:
            //1 set and 1 run are needed
            return false;
        case 3:
            //2 runs
            return false;
        case 4:
            //3 sets
            return false;
        case 5:
            //2 sets and 1 run
            return false;
        case 6:
            //1 set and 2 runs
            return false;
        case 7:
            //3 runs
            return false;
        default:
            //somehow an integer other than 1-7 was entered into this laydown check
            cout << "you goofed\n";
            return false;
    }
}

void lay_down(int round) {
    //possible numbers of sets and runs needed for any given round
    Set *set_1;
    Set *set_2;
    /*Set* set_3;
    Run* run_1;
    Run* run_2;
    Run* run3;*/

    switch (round) {
        case 1:
            //prompt user to enter the two sets needed for the 1st round
            cout << "\n\n==========Set 1 of 2==========\n\n";
            set_1 = get_set();
            cout << "\n\n==========Set 2 of 2==========\n\n";
            set_2 = get_set();
            p->hand->add_new_set(set_1);
            p->hand->add_new_set(set_2);
            p->hand->on_table = true;
            break;
        case 2:       /* see laydown_check(int) method for requirements to lay down in remaining rounds */
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

Set *get_set() {        //fairly self-explanitory, prompt user to enter a set of 3 or more cards
    Set *s = new Set();
    int index;
    do {
        p->hand->to_string();
        cout << "Enter the index of first card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    } while (!s->add_card(p->hand->remove(index)));

    do {
        p->hand->to_string();
        cout << "Enter the index of second card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    } while (!s->add_card(p->hand->remove(index)));

    do {
        p->hand->to_string();
        cout << "Enter the index of third card you would like to include in this set: ";
        cin >> index;
        cout << "\n";
    } while (!s->add_card(p->hand->remove(index)));

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
            } while (!s->add_card(p->hand->remove(index)));
        }
    } while (more == 1);

    return s;
}
