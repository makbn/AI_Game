//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() : n(2) {
    board = new int[n * 7];
    for (int i = 0; i < n * 7; i++)
        board[i] = 4;
}

Board::Board(const int *board) : n(2) {
    this->board = new int[n * 7];
    for (int i = 0; i < n * 7; i++)
        this->board[i] = board[i];
}

Board::Board(const Board *board) : n(2) {
    this->board = new int[n * 7];
    for (int i = 0; i < n * 7; i++)
        this->board[i] = board->getBoard()[i];
}

Board::~Board() {
    delete[] board;
}

const int *Board::getBoard() const {
    return board;
}

int Board::play(int box) {
    if (board[box] == 0)
        return -1;

    int pos = box;
    do {
        int marbles = board[pos];
        board[pos] = 0;
        for (int i = 0; i < marbles; i++) {
            pos = (pos + 1) % (n * 7);
            board[pos]++;
        }
        marbles = board[pos];
    } while (board[pos] != 1 && board[pos] != 4);
    return pos;
}

void Board::update(int *score) {
    for (int i = 0; i < n; i++){
        for (int j = i * 7; j < (i + 1) * 7; j++)
            if (board[j] == 4) {
                board[j] = 0;
                score[i] += 4;
            }
    }
}

void Board::print() const {
    // TODO: Modify for more than two players.
    cout << board[0];
    for (int i = 1; i < 7; i++)
        cout << ", " << board[i];
    cout << endl;
    cout << board[13];
    for (int i = 12; i >= 7; i--)
        cout << ", " << board[i];
    cout << endl;
}
