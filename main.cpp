#include <iostream>
#include <cstring>

#include "Game.h"
#include "Players/HumanPlayer.h"
#include "Players/ComputerPlayer.h"
#include "Players/NetworkPlayer.h"


using namespace std;

Socket * connectToServer(char *host, int port) {
    Socket *socket = new Socket(host, port);
    bool status = socket->socketConnect();
    if (status) {
        cout << "Connected to :" << host << ":" << port << " successfully!" << endl;
        return socket;
    } else {
        cout << "WTF dude? I can't connect to server! Let me try again ^_^" << endl << "trying...";
        for(int i = 0; i < 5 && !status; i++){
            status = socket->socketConnect();
            if (status) {
                cout << endl << "Connected!" << endl;
                return socket;
            }
        }
    }
    return nullptr;
}


int getMyNumber(Socket *s){
    int myNumber = 0;
    char *iStraem = new char[1];
    iStraem[0] = 0;

    cout << "Trying to get my turn...";
    while (strlen(iStraem) < 1){
        iStraem = s->socketReceive();
    }

    if(strlen(iStraem) > 0){
        myNumber = iStraem[0] - '0';
        cout << "My turn number is: "<< myNumber << endl;
    }
    return myNumber - 1;
}

int main() {
    string ip = "172.21.44.241";
    char *cip = nullptr;
    strcpy(cip, ip.c_str());
    Socket *socket = connectToServer(cip, 8080);
    if (socket == nullptr) {
        cout << "Connection not found!" << endl;
        return 0;
    }
    int myNumber = getMyNumber(socket);
    int enemyNumber = 1 - myNumber;
    if(myNumber == -1) {
        cout << "Problem with getting number!" << endl;
        return 0;
    }

    Game game;

    Player *player1 = new HumanPlayer(game.getScores(), myNumber);
    game.addPlayer(player1, myNumber);
    Player *player2 = new NetworkPlayer(game.getScores(), enemyNumber, socket);
    game.addPlayer(player2, enemyNumber);

    int winner = game.start(socket, myNumber);
    cout << "The winner is: Player" << winner + 1 << endl;
    return 0;
}
