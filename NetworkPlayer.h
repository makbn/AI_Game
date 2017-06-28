//
// Created by white on 6/24/17.
//

#ifndef GAME_NETWORKPLAYER_H
#define GAME_NETWORKPLAYER_H


#include "Player.h"


class NetworkPlayer : public Player {
public:
    NetworkPlayer(const int number,Socket *s);

    NetworkPlayer(const int number);

    int play(const int *board) override;

    Socket *socket;

};


#endif //GAME_NETWORKPLAYER_H
