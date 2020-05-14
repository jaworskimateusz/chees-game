#include "bishop.h"

vector<pair<int,int>> Bishop::getPossiblePieceMoves(int x, int y) {
    moves.clear();
    //means direction where piece can move
    int dir[]={1,2,3,4,5,6,7};
    bool f1 = true, f2 = true, f3 = true, f4 = true;
    bool opponent = false;

    for(int k = 0; k < 7; k++){
        int newX = x+dir[k];
        int newY = y+dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f1){
            pair<int,int> pos(newX, newY);
            opponent = isOpponent(pos);
            if(opponent || isEmpty(pos))
                moves.push_back(pos);
            else
                f1 = false;
            if(opponent)
                f1 = false;

        }
        newX = x-dir[k];
        newY = y-dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f2){
            pair<int,int> pos(newX, newY);
            opponent = isOpponent(pos);
            if(opponent || isEmpty(pos))
                moves.push_back(pos);
            else
                f2 = false;
            if(opponent)
                f2 = false;
        }
        newX = x+dir[k];
        newY = y-dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f3){
            pair<int,int> pos(newX, newY);
            opponent = isOpponent(pos);
            if(opponent || isEmpty(pos))
                moves.push_back(pos);
            else
                f3 = false;
            if(opponent)
                f3 = false;
        }
        newX = x-dir[k];
        newY = y+dir[k];
        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f4){
            pair<int,int> pos(newX, newY);
            opponent = isOpponent(pos);
            if(opponent || isEmpty(pos))
                moves.push_back(pos);
            else
                f4 = false;
            if(opponent)
                f4 = false;
        }
    }
    return moves;
}
