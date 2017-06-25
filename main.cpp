#include <iostream>

#include "Game.h"
#include "HumanPlayer.h"

using namespace std;

int main() {
    Game game;

    Player *player1 = new HumanPlayer(0);
    game.addPlayer(player1, 0);
    Player *player2 = new HumanPlayer(1);
    game.addPlayer(player2, 1);

    int winner = game.start();
    cout << "The winner is: Player" << winner + 1 << endl;
    return 0;
}