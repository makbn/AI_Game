//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#ifndef GAME_HUMANPLAYER_H
#define GAME_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const int number);

    int play(const int *board) override;
};


#endif //GAME_HUMANPLAYER_H
