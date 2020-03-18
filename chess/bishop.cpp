#include "bishop.h"

Bishop::Bishop() {

}

vector<pair<int,int>> Bishop::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    //means direction where piece can move
    //
    int dir[]={1,2,3,4,5,6,7};

    for(int k = 0; k < 7; k++){
        //first case: x=4, y=4 then we have (5, 5); (6, 6) ...
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
    return moves;
}
