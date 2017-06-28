//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H


#include <vector>
#include "../Board.h"

using namespace std;

class State {
public:
    State(const int action, const int depth, const int playerNum, const int *board, const int *scores);

    const int getAction() const;
    const int getDepth() const;
    const int getTurn() const;
    const Board *getBoard() const;
    const int *getScores() const;

    vector<int> actions();
    int utility();
    int isTerminal();

private:
    const int action;
    const int depth;
    const int turn;
    const Board* board;
    int scores[2];
};


#endif //GAME_STATE_H
