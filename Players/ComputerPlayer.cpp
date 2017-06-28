//
// Created by Bijan Nikkhah on 6/25/2017 AD.
//

#include <iostream>
#include <climits>
#include <algorithm>
#include <tuple>
#include "ComputerPlayer.h"
#include "../Utils/State.h"

using namespace std;

ComputerPlayer::ComputerPlayer(const int *const scores, const int number, const int level)
        : Player(scores, number), level(level) {
    switch (level) {
        case 1:
            horizon = 4;
            break;
        case 2:
            horizon = 6;
            break;
        case 3:
            horizon = 8;
            break;
        default:
            horizon = 6;
            break;
    }
}

int ComputerPlayer::play(const int *board) {
    int move = search(new State(-1, 0, number, board, scores));
    cout << "I choose " << move + 1 << endl;
    return move;
}

int ComputerPlayer::search(State *s) {
    tuple<int, int> v = max_value(s, INT_MIN, INT_MAX);
    return get<0>(v);
}

tuple<int, int> ComputerPlayer::max_value(State *s, int a, int b) {
    if (s->isTerminal() || s->getDepth() >= horizon)
        return tuple<int, int>(s->getAction(), s->utility());

    tuple<int, int> v (s->getAction(), INT_MIN);
    vector<int> actions = s->actions();
    for (vector<int>::iterator it = actions.begin(); it != actions.end(); it++) {
        Board newBoard(s->getBoard());
        int pos = newBoard.play(*it);
        int newScores[2];
        for (int i = 0; i < 2; i++)
            newScores[i] = s->getScores()[i];
        newBoard.update(newScores);

        // In case this player's turn ends in opponents' box:
        if (pos / 7 != s->getTurn() && newBoard.getBoard()[pos] == 0) {
            newScores[pos / 7] -= 4;
            newScores[s->getTurn()] += 4;
        }

        tuple<int, int> tmp = min_value(
                new State(*it, s->getDepth() + 1, (s->getTurn() + 1) % 2, newBoard.getBoard(), newScores), a, b);

        if (s->getAction() == -1)
            v = (get<1>(v) < get<1>(tmp)) ? tmp : v;
        else
            get<1>(v) = (get<1>(v) < get<1>(tmp)) ? get<1>(tmp) : get<1>(v);

        if (get<1>(v) >= b)
            return v;
        a = (a < get<1>(v)) ? get<1>(v) : a;
    }
    return v;
}

tuple<int, int> ComputerPlayer::min_value(State *s, int a, int b) {
    if (s->isTerminal())
        return tuple<int, int>(s->getAction(), s->utility());

    tuple<int, int> v (s->getAction(), INT_MAX);
    vector<int> actions = s->actions();
    for (vector<int>::iterator it = actions.begin(); it != actions.end(); it++) {
        Board newBoard(s->getBoard());
        int pos = newBoard.play(*it);
        int newScores[2];
        for (int i = 0; i < 2; i++)
            newScores[i] = s->getScores()[i];
        newBoard.update(newScores);

        // In case this player's turn ends in opponents' box:
        if (pos / 7 != s->getTurn() && newBoard.getBoard()[pos] == 0) {
            newScores[pos / 7] -= 4;
            newScores[s->getTurn()] += 4;
        }

        tuple<int, int> tmp = max_value(
                new State(*it, s->getDepth() + 1, (s->getTurn() + 1) % 2, newBoard.getBoard(), newScores), a, b);
        get<1>(v) = (get<1>(v) < get<1>(tmp)) ? get<1>(v) : get<1>(tmp);
        if (get<1>(v) <= a)
            return v;
        b = (b < get<1>(v)) ? b : get<1>(v);
    }
    return v;
}
