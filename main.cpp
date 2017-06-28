#include <iostream>

#include "Game.h"
#include "HumanPlayer.h"
#include "socketClient.cpp"
#include "NetworkPlayer.h"


using namespace std;

Socket * connectToServer(char *host, int port){
    Socket *socket=new Socket(host, port);
    bool  status= socket->socketConnect();
    if(status){
        cout<<"connected to :"<<host<<":"<<port<<" successfully!"<<endl;
        return socket;
    }else{
        cout<<"WTF dude?i can't connect to server!let me try again^_^"<<endl<<"trying";
        for(int i=0;i<5 && !status;i++){
            cout<<".";
            status = socket->socketConnect();
            if(status)
                cout<<endl<<"connected!"<<endl;
        }
    }

}


int getMyNumber(Socket *s){
    int myNumber=0;
    char *iStraem=new char[1];
    iStraem[0]=0;
    cout<<"trying to get my turn";
    while (strlen(iStraem)<1){
        cout<<".";
        iStraem=s->socketReceive();
    }
    if(strlen(iStraem)>0){
        myNumber=iStraem[0]- '0';
        cout<<"my turn number is :"<<myNumber<<endl;
    }
    return myNumber-1;

}

int main() {
    Game game;
    Socket *socket=connectToServer("localhost",3000);
    int myNumber=getMyNumber(socket);
    int enemyNumber=1-myNumber;
    if(myNumber==-1){
        return 0;
    }

    Player *player1 = new HumanPlayer(myNumber);
    game.addPlayer(player1, myNumber);

    Player *player2 = new NetworkPlayer(enemyNumber,socket);
    game.addPlayer(player2, enemyNumber);

    int winner = game.start();
    cout << "The winner is: Player" << winner + 1 << endl;
    return 0;
}


