#include "knight.h"

vector<pair<int,int>> Knight::getPossiblePieceMoves(int x, int y) {
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
    return moves;
}
