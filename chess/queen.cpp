#include "queen.h"

Queen::Queen() {

}

vector<pair<int,int>> Queen::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    int dir[]={1,2,3,4,5,6,7};

    for(int k = 0; k < 7; k++){
        int newX = x+dir[k];
        int newY = y+dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newX = x-dir[k];
        newY = y-dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newX = x+dir[k];
        newY = y-dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newX = x-dir[k];
        newY = y+dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
    }

    for(int i = 0; i < 8; i++) {
        if(i != y) {
           pair<int,int> position(x, i);
           moves.push_back(position);
         }
         if(i != x) {
           pair<int,int> position(i, y);
           moves.push_back(position);
         }
    }

    return moves;
}
