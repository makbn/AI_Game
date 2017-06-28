//
// Created by white on 6/24/17.
//

#ifndef GAME_NETWORKPLAYER_H
#define GAME_NETWORKPLAYER_H


#include "Player.h"
#include "socketClient.cpp"

class NetworkPlayer : public Player {
public:
    NetworkPlayer(const int number,Socket *s);

    int play(const int *board) override;

};


#endif //GAME_NETWORKPLAYER_H
