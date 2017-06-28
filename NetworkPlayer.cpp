//
// Created by white on 6/24/17.
//

#include <iostream>
#include <cstring>
#include "NetworkPlayer.h"

using namespace std;

NetworkPlayer::NetworkPlayer(const int number ,Socket *s) : Player(number) {

    int NetworkPlayer::play(const int *board) {
        int move=0;
        char *iStraem=new char[1];
        iStraem[0]=0;
        cout<<"trying to get move";
        while (strlen(iStraem)<1){
            cout<<".";
            iStraem=s->socketReceive();
        }
        if(strlen(iStraem)>0){
            move=iStraem[0]- '0';
            cout<<"move :"<<move<<endl;
        }
        return move-1;
    }

}
