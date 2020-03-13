#ifndef GAME_H
#define GAME_H

#include "field.h"

class Game {

    Color currentMove;
public:
    Field fields[8][8];

public:
    Game();
    ~Game();
    Field getField(int x, int y);
    Color getCurrentMove();
    void setCurrentMove();
    void swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition);

};

#endif // GAME_H
