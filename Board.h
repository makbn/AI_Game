//
// Created by Bijan Nikkhah on 6/24/2017 AD.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H


class Board {
public:
    Board();
    virtual ~Board();

    const int *getBoard() const;

    int play(int box);
    void update(int *score);

    void print();

private:
    const int n;
    int *board;
};


#endif //GAME_BOARD_H
