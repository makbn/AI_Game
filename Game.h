//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H


#include "Player.h"
#include "Board.h"

class Game {
public:
    Game();
    virtual ~Game();
    bool addPlayer(Player *p, int number);

    int start();

private:
    const int n;
    Player **players;
    int *scores;
    Board *board;
    int turn;

    bool isFinished();
    int winner();
};


#endif //GAME_GAME_H
