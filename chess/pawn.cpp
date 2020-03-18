#include "pawn.h"

Pawn::Pawn() {

}

vector<pair<int,int>> Pawn::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    int dir[]={-1,0,1};

    if(getColor() == BLACK){
        for(int k = 0; k < 3; k++){
            int newX = x+1;
            int newY = y+dir[k];
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8 )){
                pair<int,int> pos(newX, newY);
                moves.push_back(pos);
            }
        }

        if(x == 1){
            pair<int,int> pos(3, y);
            moves.push_back(pos);
        }
    } else {
        for(int k = 0; k < 3; k++){
            int newX = x-1;
            int newY = y+dir[k];
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY<8)){
                pair<int,int> pos(newX, newY);
                moves.push_back(pos);
            }
        }

        if(x == 6){
            pair<int,int> pos(4, y);
            moves.push_back(pos);
        }
    }

    return moves;
}


