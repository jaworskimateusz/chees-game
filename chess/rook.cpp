#include "rook.h"

vector<pair<int,int>> Rook::getPossiblePieceMoves(int x, int y) {
    moves.clear();
    int dir[]={1,2,3,4,5,6,7};

    for(int k = 0; k < 7; k++) {
        int newX = x+dir[k];
        int newY = y;
        if(newX >= 0 && newX < 8){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newX = x-dir[k];
        if(newX >= 0 && newX < 8){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newX = x;
        newY = y+dir[k];
        if(newY >= 0 && newY < 8){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
        newY = y-dir[k];
        if(newY >= 0 && newY < 8){
            pair<int,int> pos(newX, newY);
            moves.push_back(pos);
        }
    }

    return moves;
}
