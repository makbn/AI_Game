//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "Board.h"
#include "socketClient.cpp"

class Player {
public:
    Player(const int number);

    virtual int play(const int *board) = 0;

protected:
    const int n;
    const int number;
};


#endif //GAME_PLAYER_H
