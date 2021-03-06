//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() : n(2) {
    players = new Player*[n];
    for (int i = 0; i < n; i++)
        players[i] = nullptr;

    scores = new int[n];
    for (int i = 0; i < n; i++)
        scores[i] = 0;

    board = new Board();
    turn = 0;
}

Game::~Game() {
    delete[] players;
    delete[] scores;
    delete board;
}

bool Game::addPlayer(Player *p, int number) {
    if (players[number] == nullptr) {
        players[number] = p;
        return true;
    } else
        return false;
}

int *Game::getScores() const {
    return scores;
}

int Game::start() {
    return start(nullptr, -1);
}

int Game::start(Socket *s, int myTurnNumber) {
    for (int i = 0; i < n; i++)
        if (players[i] == nullptr)
            return -1;

    int iteration = 1;
    while (!isFinished()) {
        cout << "Turn: " << iteration << endl;
        cout << "Scores: " << scores[0];
        for (int i = 1; i < n; i++)
            cout << " " << scores[i];
        cout << endl;

        board->print();

        int move = -1;
        while (move < turn * 7 || move >= (turn + 1) * 7 || board->getBoard()[move] == 0)
            move = players[turn]->play(board->getBoard());
        if(s != nullptr && turn == myTurnNumber)
            sendMyAction(s, move);

        int pos = board->play(move);
        board->update(scores);
        // In case this player's turn ends in opponents' box:
        if (pos / 7 != turn && board->getBoard()[pos] == 0) {
            scores[pos / 7] -= 4;
            scores[turn] += 4;
        }

        turn = (turn + 1) % n;
        iteration++;
        cout << endl;
    }
    return winner();
}

bool Game::isFinished() {
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = i * 7; j < (i + 1) * 7; j++)
            if (board->getBoard()[j] != 0)
                flag = false;
        if (flag)
            return true;
    }
    return false;
}

int Game::winner() {
    for (int i = 0; i < n; i++)
        for (int j = i * 7; j < (i + 1) * 7; j++)
            scores[i] += board->getBoard()[j];

    int out = 0;
    int maxScore = scores[0];
    for (int i = 0; i < n; i++)
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            out = i;
        }
    return out;
}

void Game::sendMyAction(Socket *s, int move) {
    char *str = new char[16];
    snprintf(str, 16, "%d", move);
    s->socketSend(str);
}
