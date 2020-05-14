#include "pawn.h"
#include <game.h>
extern Game * game;

vector<pair<int,int>> Pawn::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    int dir[]={-1,0,1};

    if(game->getCurrentMove() == BLACK){
        for(int k = 0; k < 3; k++){
            int newX = x+1;
            int newY = y+dir[k];
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8 )){
                pair<int,int> pos(newX, newY);
                if(isOpponent(pos) && newY != y)
                    moves.push_back(pos);
                else if(isEmpty(pos) && newY == y)
                    moves.push_back(pos);
            }
        }

        if(x == 1){
            pair<int,int> pos(3, y);
            if(isEmpty(pos))
                moves.push_back(pos);
        }
    } else {
        for(int k = 0; k < 3; k++){
            int newX = x-1;
            int newY = y+dir[k];
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY<8)){
                pair<int,int> pos(newX, newY);
                if(isOpponent(pos) && newY != y)
                    moves.push_back(pos);
                else if(isEmpty(pos) && newY == y)
                    moves.push_back(pos);
            }
        }

        if(x == 6){
            pair<int,int> pos(4, y);
            if(isEmpty(pos))
                moves.push_back(pos);
        }
    }

    return moves;
}


