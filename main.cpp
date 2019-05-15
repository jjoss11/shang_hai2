#include <iostream>
#include <string>

#include "Player.h"

int main() {
    Player* p;
    string p_name;

    cout << "New game of Shang-hai\n\n";
    cout << "Enter your name: ";
    cin >> p_name;

    p = new Player(p_name);

    Deck* d = new Deck();
    d->fill();
    d->shuffle(1000);

    for(int i = 0; i < 11; i++){
        p->hand->add(d->take_top());
    }
    cout << "Your hand\n";
    p->hand->to_string();
    return 0;
}