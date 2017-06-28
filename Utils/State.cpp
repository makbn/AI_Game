//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#include "State.h"

State::State(const int action, const int depth, const int playerNum, const int *board, const int *scores)
        : action(action), depth(depth), turn(playerNum) {
    this->board = new Board(board);

    for (int i = 0; i < 2; i++)
        this->scores[i] = scores[i];
}

const int State::getAction() const {
    return action;
}

const int State::getDepth() const {
    return depth;
}

const int State::getTurn() const {
    return turn;
}

const Board *State::getBoard() const {
    return board;
}

const int *State::getScores() const {
    return scores;
}

vector<int> State::actions() {
    vector<int> out;
    for (int i = turn * 7; i < (turn + 1) * 7; i++)
        if (board->getBoard()[i] != 0)
            out.push_back(i);
    return out;
}

int State::utility() {
    int u[3];
    for (int i = 0; i < 3; i++)
        u[i] = 0;

    for (int i = turn * 7; i < (turn + 1) * 7; i++)
        switch (board->getBoard()[i]) {
            case 3:
                u[2]++;
                break;
            case 2:
                u[1]++;
                break;
            case 1:
                u[0]++;
                break;
            default:
                break;
        }
    return 3 * u[2] + 2 * u[1] + 1 * u[0] + 5 * (scores[turn] - scores[(turn + 1) % 2]);
}

int State::isTerminal() {
    for (int i = turn * 7; i < (turn + 1) * 7; i++)
        if (board->getBoard()[i] != 0)
            return false;
    return true;
}
