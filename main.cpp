#include <iostream>

#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

int main() {
    Game game;

//    Player *player1 = new HumanPlayer(game.getScores(), 0);
    Player *player1 = new ComputerPlayer(game.getScores(), 0, 1);
    game.addPlayer(player1, 0);
    Player *player2 = new ComputerPlayer(game.getScores(), 1, 1);
    game.addPlayer(player2, 1);

    int winner = game.start();
    cout << "The winner is: Player" << winner + 1 << endl;
    return 0;
}
