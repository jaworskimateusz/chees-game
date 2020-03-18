#include "king.h"

vector<pair<int,int>> King::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    int dir[]={-1,0,1};

    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            int newX = x+dir[k];
            int newY = y+dir[l];
            if((newY >= 0 && newY<8) && (newX >= 0 && newX < 8) && !(dir[k] == 0 && dir[l] == 0)){
                pair<int,int> pos(newX, newY);
                moves.push_back(pos);
            }
       }
    }
    return moves;
}
