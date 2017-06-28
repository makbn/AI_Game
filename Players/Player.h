//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "../Board.h"
#include "../Utils/SocketClient.cpp"

class Player {
public:
    Player(const int *scores, const int number);

    virtual int play(const int *board) = 0;

protected:
    const int n;
    const int number;
    const int *const scores;
};


#endif //GAME_PLAYER_H
