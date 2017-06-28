//
// Created by white on 6/24/17.
//

#include <iostream>
#include <cstring>
#include "NetworkPlayer.h"

using namespace std;

NetworkPlayer::NetworkPlayer(const int number, Socket *s) : Player(number) {
    socket=s;
}


int NetworkPlayer::play(const int *board) {
    int move = 0;
    char *iStream = new char[1];
    iStream[0] = 0;
    cout << "trying to get move";
    while (strlen(iStream) < 1) {
        cout << ".";
        iStream = socket->socketReceive();
    }
    if (strlen(iStream) > 0) {
        move = iStream[0] - '0';
        cout << "move :" << move << endl;
    }
    return move - 1;
}

