#include "pawnknight.h"
#include <game.h>
extern Game * game;

PawnKnight::PawnKnight()
{

}

vector<pair<int,int>> PawnKnight::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    int dir[]={-2, -1, 1, 2};

    for(int k = 0; k < 4; k++){
        for(int l = 0; l < 4; l++){
            if(abs(dir[k]) != abs(dir[l])){
                int newX = x-dir[k];
                int newY = y-dir[l];

                if((newX >= 0 && newX < 8) && (newY >= 0 && newY<8)){
                    pair<int,int> pos(newX, newY);
                    moves.push_back(pos);
                }
            }
        }
    }

    int dirTwo[]={-1,0,1};

    if(game->getCurrentMove() == BLACK){
        for(int k = 0; k < 3; k++){
            int newX = x+1;
            int newY = y+dirTwo[k];
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
            int newY = y+dirTwo[k];
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
