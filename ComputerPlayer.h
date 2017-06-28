//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#ifndef GAME_COMPUTERPLAYER_H
#define GAME_COMPUTERPLAYER_H


#include "Player.h"
#include "utils/State.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const int *const scores, const int number, const int level);

    int play(const int *board) override;

private:
    const int level;
    int horizon;

    int search(State *s);
    tuple<int, int> max_value(State *s, int a, int b);
    tuple<int, int> min_value(State *s, int a, int b);
};


#endif //GAME_COMPUTERPLAYER_H
