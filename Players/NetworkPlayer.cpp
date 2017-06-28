//
// Created by white on 6/24/17.
//

#include <iostream>
#include <cstring>
#include "NetworkPlayer.h"

using namespace std;

NetworkPlayer::NetworkPlayer(const int *scores, const int number, Socket *s) : Player(scores, number) {
    socket=s;
}


int NetworkPlayer::play(const int *board) {
    int move = 0;
    char *iStream = new char[1];
    iStream[0] = 0;
    cout << "Trying to get move";
    while (strlen(iStream) < 1) {
        cout << ".";
        iStream = socket->socketReceive();
    }
    if (strlen(iStream) > 0) {
        move = iStream[0] - '0';
        cout << "Move :" << move << endl;
    }
    return move - 1;
}

