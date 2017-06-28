//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#include <iostream>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(const int *const scores, const int number) : Player(scores, number) {}

int HumanPlayer::play(const int *board) {
    int move;
    cout << "Player " << number + 1 << "'s turn" << endl;
    cout << "Please enter box number: ";
    cin >> move;
    return move - 1;
}
